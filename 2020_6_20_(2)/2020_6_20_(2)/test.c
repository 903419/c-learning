#include "main.h"
#include "BubbleSort.h"

void InitiBook(MailList *pm)
{
	pm->count = 0;
	pm->capacity = 2;//电话薄的大小，可以任意配置。
	pm->data = (Info *)malloc(sizeof(Info) * pm->capacity);
}
void menu1()
{
	printf("##################################\n");
	printf("######      1.姓名查找      ######\n");
	printf("######      2.电话查找      ######\n");
	printf("##################################\n");

}
void menu2()
{
	printf("\n##################################\n");
	printf("######        0.退出        ######\n");
	printf("######      1.姓名修改      ######\n");
	printf("######      2.性别修改      ######\n");
	printf("######      3.年龄修改      ######\n");
	printf("######      4.电话修改      ######\n");
	printf("######      5.住址修改      ######\n");
	printf("##################################\n");

}

void menu3()
{
	printf("\n####################################\n");
	printf("######      0.不排序          ######\n");
	printf("######      1.以姓名排序      ######\n");
	printf("######      2.以性别排序      ######\n");
	printf("######      3.以年龄排序      ######\n");
	printf("######      4.以电话排序      ######\n");
	printf("######      5.以住址排序      ######\n");
	printf("####################################\n");
}

void menu4()
{
	printf("\n####################################\n");
	printf("######         1.扩容          ######\n");
	printf("######         2.不扩容        ######\n");
	printf("####################################\n");
}

int Check(MailList *pm)
{
	assert(pm);
	if (pm->capacity - 1 < pm->count)
	{
		printf("通讯录容量超过限制，不可再继续添加！\n");
		printf("是否选择扩容！\n");
		menu4();
		int choice = 0;
		scanf("%d", &choice);
		Info *ptr = NULL;
		switch (choice)
		{
		case 1:
			ptr = realloc(pm->data,sizeof(Info) * pm->capacity * 2);
			if (NULL != ptr)
			{
				pm->data = ptr;
				pm->capacity = 2 + pm->capacity;
				printf("扩容成功!\n");
				return 0;
			}
		case 2:
			return 1;
		default:
			printf("您的输入有误！\n");
			break;
		}
		return 1;
	}
	return 0;
}
void AddContact(MailList *pm)
{
	assert(pm);
	int ret=Check(pm);
	if (1 == ret)
	{
		exit(EXIT_FAILURE);
	}
	printf("-----------------------------------------\n");
	printf("请输入名字：>");
	scanf("%s", pm->data[pm->count].name);
	printf("\n请输入性别：>");
	scanf("%s", pm->data[pm->count].sex);
	printf("\n请输入年龄：>");
	scanf("%d", &pm->data[pm->count].age);
	printf("\n请输入电话：>");
	scanf("%s", pm->data[pm->count].telephone);
	printf("\n请输入住址：>");
	scanf("%s", pm->data[pm->count].address);
	pm->count++;
	printf("信息添加成功！\n");
	printf("-----------------------------------------\n");
}
void DeleteContact(MailList *pm)
{
	assert(pm);
	printf("请输入你要删除人的姓名：");
	char name[20];
	scanf("%s", &name);
	int i = 0;
	int judge = 0;
	for (; i < pm->count; i++)
	{
		if (0 == strcmp(name, pm->data[i].name))
		{
			pm->data[i] = pm->data[i + 1];
			judge = 1;
		}
	}
	pm->count--;
	if (1 == judge)
	{
		printf("删除成功！\n");
	}
	else
	{
		printf("此人的信息不存在,无法删除\n");
	}
}
void SeekContact(MailList *pm)
{
	assert(pm);
	menu1();
	printf("请输入你要查找的方式：>");
	int choice = 0;
	scanf("%d", &choice);
	if (1 == choice)
	{
		printf("请输入你要查找的姓名：>");
		char name[20];
		scanf("%s", &name);
		int i = 0;
		int judge = 0;
		for (; i < pm->count; i++)
		{
			if (0 == strcmp(name, pm->data[i].name))
			{
				printf("查找成功，此人的信息为：\n");
				ShowOneContact(pm, i);
				judge = 1;
			}
		}
		if (1 != judge)
		{
			printf("此人的信息不存在\n");
		}
	}
	else if (2 == choice)
	{
		printf("请输入你要查找的电话号码：>");
		char telephone[12];
		scanf("%s", &telephone);
		int i = 0;
		int judge = 0;
		for (; i < pm->count; i++)
		{
			if (0 == strcmp(telephone, pm->data[i].telephone))
			{
				printf("查找成功，此人的信息为：\n");
				ShowOneContact(pm, i);
				judge = 1;
			}
		}
		if (1 != judge)
		{
			printf("此人的信息不存在\n");
		}
	}
	else
	{
		printf("你输入的选择有误！");
	}
}
void ShowOneContact(MailList *pm, int number)
{
	assert(pm);
	printf("---------------------------------------------------------\n");
	printf("姓名：%s   ", pm->data[number].name);
	printf("性别：%s   ", pm->data[number].sex);
	printf("年龄：%d   ", pm->data[number].age);
	printf("电话：%s   ", pm->data[number].telephone);
	printf("住址：%s   ", pm->data[number].address);
	printf("\n---------------------------------------------------------\n");
	printf("\n");
}
void ModifyContact(MailList *pm)
{
	assert(pm);
	printf("请输入你要修改人的姓名：");
	char name[20];
	scanf("%s", &name);
	int i = 0;
	int judge = 0;
	for (; i < pm->count; i++)
	{
		if (0 == strcmp(name, pm->data[i].name))
		{
			printf("\n此人的信息为：\n");
			ShowOneContact(pm, i);
			menu2();
			printf("请输入你要修改的内容：");
			int choice = 0;
			scanf("%d", &choice);
			while (choice)
			{
				switch (choice)
				{
				case 1:
					printf("请输入修改的姓名:>");
					scanf("%s", &pm->data[i].name);
					printf("名字修改成功:>");
					ShowOneContact(pm, i);
					break;
				case 2:
					printf("请输入修改的性别:>");
					scanf("%s", &pm->data[i].sex);
					printf("性别修改成功:>");
					ShowOneContact(pm, i);
					break;
				case 3:
					printf("请输入修改的年龄:>");
					scanf("%d", &pm->data[i].age);
					printf("年龄修改成功:>");
					ShowOneContact(pm, i);
					break;
				case 4:
					printf("请输入修改的电话:>");
					scanf("%s", &pm->data[i].telephone);
					printf("电话修改成功:>");
					ShowOneContact(pm, i);
					break;
				case 5:
					printf("请输入修改的住址:>");
					scanf("%s", &pm->data[i].address);
					printf("住址修改成功:>");
					ShowOneContact(pm, i);
					break;
				default:
					printf("输入错误，请重新输入!\n");
					break;
				}
				menu2();
				printf("请输入你要修改的内容：");
				scanf("%d", &choice);
			}
			printf("修改成功，此人的信息变为：>\n");
			ShowOneContact(pm, i);
			judge = 1;
		}
		if (1 == judge)
		{
			break;
		}
	}

	if (1 != judge)
	{
		printf("此人的信息不存在,无法修改\n");
	}
}
void ShowContact(MailList *pm)
{
	assert(pm);
	printf("-----------------------------------------------------------\n");
	printf("\n|capacity:%-6d |count:%-6d |\n\n", pm->capacity, pm->count);
	int i = 0;
	for (; i < pm->count; i++)
	{
		printf("姓名：%s   ", pm->data[i].name);
		printf("性别：%s   ", pm->data[i].sex);
		printf("年龄：%d   ", pm->data[i].age);
		printf("电话：%s   ", pm->data[i].telephone);
		printf("住址：%s   ", pm->data[i].address);
		printf("\n");
	}
	printf("------------------------------------------------------------\n");
}
void ClearContact(MailList *pm)
{
	assert(pm);
	pm->count = 0;
}
void SortContact(MailList *pm)
{
	assert(pm);
	ShowContact(pm);
	menu3();
	printf("选择你排序的方式：>");
	int choice = 0;
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
		printf("\n以名字排序：>\n");
		BubbleSort(pm, pm->count, sizeof(Info), cmp_name);
		ShowContact(pm);
		break;
	case 2:
		printf("\n以性别排序：>\n");
		BubbleSort(pm, pm->count, sizeof(Info), cmp_sex);
		ShowContact(pm);
		break;
	case 3:
		printf("\n以年龄排序：>\n");
		BubbleSort(pm, pm->count, sizeof(Info), cmp_age);
		ShowContact(pm);
		break;
	case 4:
		printf("\n以电话排序：>\n");
		BubbleSort(pm, pm->count, sizeof(Info), cmp_telephone);
		ShowContact(pm);
		break;
	case 5:
		printf("\n以住址排序：>\n");
		BubbleSort(pm, pm->count, sizeof(Info), cmp_address);
		ShowContact(pm);
		break;
	default:
		printf("输入的选择有误！\n");
		break;
	}
}
void ReadContact(MailList *pm)
{
	assert(pm);
	//int c = 0;
	//int judge = 0;
	//FILE *fp = fopen("PhoneBook.txt", "r");
	//if (NULL == fp)
	//{
	//	perror("file open failed");
	//	exit(0);
	//}
	//while (1)
	//{
	//	if ((c = fgetc(fp)) == EOF)
	//	{
	//		pm->count--;
	//		printf("信息读取成功\n");
	//		break;
	//	}
	//	judge=Check(pm);
	//	if (0 == judge)
	//	{
	//		fscanf(fp, "%s", pm->data[pm->count].name);
	//		fscanf(fp, "%s", pm->data[pm->count].sex);
	//		fscanf(fp, "%d", &pm->data[pm->count].age);
	//		fscanf(fp, "%s", pm->data[pm->count].telephone);
	//		fscanf(fp, "%s", pm->data[pm->count].address);
	//		pm->count++;
	//	}
	//	else 
	//	{
	//		printf("未完全读取！\n");
	//		break;
	//	}
	//}

	FILE *fp = fopen("PhoneBook.txt", "rb");
	if (NULL == fp)
	{
		perror("file open failed");
		exit(0);
	}
	MailList temp;
	fread(&temp, sizeof(MailList), 1, fp);
	pm->capacity = temp.capacity;
	pm->count = temp.count;
	pm->data = (Info *)realloc(pm->data, temp.capacity * sizeof(Info));
	fread(pm->data, sizeof(Info), pm->count, fp);
	printf("读取成功！\n");
	fclose(fp);
}
void SaveContact(MailList *pm)
{
	assert(pm);
	FILE *fp = fopen("PhoneBook.txt", "wb");
	//if (NULL == fp)
	//{
	//	perror("file open failed");
	//	exit(0);
	//}
	//for (int i = 0; i < pm->count; i++)
	//{
	//	fprintf(fp, "%s\t", pm->data[i].name);
	//	fprintf(fp, "%s\t", pm->data[i].sex);
	//	fprintf(fp, "%d\t", pm->data[i].age );
	//	fprintf(fp, "%s\t", pm->data[i].telephone );
	//	fprintf(fp, "%s", pm->data[i].address );
	//	fprintf(fp, "\n");
	//}
	//printf("\n联系人存储成功！\n");
	if (NULL == fp)
	{
		perror("file open failed");
		exit(0);
	}
	fwrite(pm, sizeof(MailList), 1, fp);
	fwrite(pm->data, sizeof(Info), pm->count, fp);
	printf("存储成功！\n");
	fclose(fp);
}