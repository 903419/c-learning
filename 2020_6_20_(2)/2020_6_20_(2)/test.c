#include "main.h"
#include "BubbleSort.h"

void InitiBook(MailList *pm)
{
	pm->count = 0;
	pm->capacity = 3;//�绰���Ĵ�С�������������á�
	pm->data = (Info *)malloc(sizeof(Info) * pm->capacity);
}
void menu1()
{
	printf("##################################\n");
	printf("######      1.��������      ######\n");
	printf("######      2.�绰����      ######\n");
	printf("##################################\n");

}
void menu2()
{
	printf("\n##################################\n");
	printf("######        0.�˳�        ######\n");
	printf("######      1.�����޸�      ######\n");
	printf("######      2.�Ա��޸�      ######\n");
	printf("######      3.�����޸�      ######\n");
	printf("######      4.�绰�޸�      ######\n");
	printf("######      5.סַ�޸�      ######\n");
	printf("##################################\n");

}

void menu3()
{
	printf("\n####################################\n");
	printf("######      0.������          ######\n");
	printf("######      1.����������      ######\n");
	printf("######      2.���Ա�����      ######\n");
	printf("######      3.����������      ######\n");
	printf("######      4.�Ե绰����      ######\n");
	printf("######      5.��סַ����      ######\n");
	printf("####################################\n");
}

int Check(MailList *pm)
{
	if (pm->capacity -1 < pm->count)
	{
		printf("ͨѶ¼�����������ƣ������ټ������ӣ�\n");
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
	printf("���������֣�>");
	scanf("%s", &pm->data[pm->count].name);
	printf("\n�������Ա�>");
	scanf("%s", &pm->data[pm->count].sex);
	printf("\n���������䣺>");
	scanf("%d", &pm->data[pm->count].age);
	printf("\n������绰��>");
	scanf("%s", &pm->data[pm->count].telephone);
	printf("\n������סַ��>");
	scanf("%s", &pm->data[pm->count].address);
	pm->count++;
	printf("-----------------------------------------\n");
}

void DeleteContact(MailList *pm)
{
	printf("��������Ҫɾ���˵�������");
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
		printf("ɾ���ɹ���\n");
	}
	else
	{
		printf("���˵���Ϣ������,�޷�ɾ��\n");
	}
}

void SeekContact(MailList *pm)
{
	menu1();
	printf("��������Ҫ���ҵķ�ʽ��>");
	int choice = 0;
	scanf("%d", &choice);
	if (1 == choice)
	{
		printf("��������Ҫ���ҵ�������>");
		char name[20];
		scanf("%s", &name);
		int i = 0;
		int judge = 0;
		for (; i < pm->count; i++)
		{
			if (0 == strcmp(name, pm->data[i].name))
			{
				printf("���ҳɹ������˵���ϢΪ��\n");
				ShowOneContact(pm, i);
				judge = 1;
			}
		}
		if (1 != judge)
		{
			printf("���˵���Ϣ������\n");
		}
	}
	else if (2 == choice)
	{
		printf("��������Ҫ���ҵĵ绰���룺>");
		char telephone[12];
		scanf("%s", &telephone);
		int i = 0;
		int judge = 0;
		for (; i < pm->count; i++)
		{
			if (0 == strcmp(telephone, pm->data[i].telephone))
			{
				printf("���ҳɹ�������˵���ϢΪ��\n");
				ShowOneContact(pm, i);
				judge = 1;
			}
		}
		if (1 != judge)
		{
			printf("���˵���Ϣ������\n");
		}
	}
	else
	{
		printf("�������ѡ������");
	}
}
void ShowOneContact(MailList *pm, int number)
{
	printf("---------------------------------------------------------\n");
	printf("������%s   ", pm->data[number].name);
	printf("�Ա�%s   ", pm->data[number].sex);
	printf("���䣺%d   ", pm->data[number].age);
	printf("�绰��%s   ", pm->data[number].telephone);
	printf("סַ��%s   ", pm->data[number].address);
	printf("\n---------------------------------------------------------\n");
	printf("\n");
}

void ModifyContact(MailList *pm)
{
	printf("��������Ҫ�޸��˵�������");
	char name[20];
	scanf("%s", &name);
	int i = 0;
	int judge = 0;
	for (; i < pm->count; i++)
	{
		if (0 == strcmp(name, pm->data[i].name))
		{
			printf("\n���˵���ϢΪ��\n");
			ShowOneContact(pm, i);
			menu2();
			printf("��������Ҫ�޸ĵ����ݣ�");
			int choice = 0;
			scanf("%d", &choice);
			while (choice)
			{
				switch (choice)
				{
				case 1:
					printf("�������޸ĵ�����:>");
					scanf("%s", &pm->data[i].name);
					printf("�����޸ĳɹ�:>");
					ShowOneContact(pm, i);
					break;
				case 2:
					printf("�������޸ĵ��Ա�:>");
					scanf("%s", &pm->data[i].sex);
					printf("�Ա��޸ĳɹ�:>");
					ShowOneContact(pm, i);
					break;
				case 3:
					printf("�������޸ĵ�����:>");
					scanf("%d", &pm->data[i].age);
					printf("�����޸ĳɹ�:>");
					ShowOneContact(pm, i);
					break;
				case 4:
					printf("�������޸ĵĵ绰:>");
					scanf("%s", &pm->data[i].telephone);
					printf("�绰�޸ĳɹ�:>");
					ShowOneContact(pm, i);
					break;
				case 5:
					printf("�������޸ĵ�סַ:>");
					scanf("%s", &pm->data[i].address);
					printf("סַ�޸ĳɹ�:>");
					ShowOneContact(pm, i);
					break;
				default:
					printf("�����������������!\n");
					break;
				}
				menu2();
				printf("��������Ҫ�޸ĵ����ݣ�");
				scanf("%d", &choice);
			}
			printf("�޸ĳɹ������˵���Ϣ��Ϊ��>\n");
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
		printf("���˵���Ϣ������,�޷��޸�\n");
	}
}
void ShowContact(MailList *pm)
{
	printf("--------------------------------------------------------\n");
	int i = 0;
	for (; i < pm->count; i++)
	{
		printf("������%s   ", pm->data[i].name);
		printf("�Ա�%s   ", pm->data[i].sex);
		printf("���䣺%d   ", pm->data[i].age);
		printf("�绰��%s   ", pm->data[i].telephone);
		printf("סַ��%s   ", pm->data[i].address);
		printf("\n");
	}
	printf("---------------------------------------------------------\n");
}
void ClearContact(MailList *pm)
{
	pm->count = 0;
}
void SortContact(MailList *pm)
{
	ShowContact(pm);
	menu3();
	printf("ѡ��������ķ�ʽ��>");
	int choice = 0;
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
		printf("\n����������>\n");
		BubbleSort(pm, pm->count, sizeof(Info), cmp_name);
		ShowContact(pm);
		break;
	case 2:
		printf("\n���Ա�����>\n");
		BubbleSort(pm, pm->count, sizeof(Info), cmp_sex);
		ShowContact(pm);
		break;
	case 3:
		printf("\n����������>\n");
		BubbleSort(pm, pm->count, sizeof(Info), cmp_age);
		ShowContact(pm);
		break;
	case 4:
		printf("\n�Ե绰����>\n");
		BubbleSort(pm, pm->count, sizeof(Info), cmp_telephone);
		ShowContact(pm);
		break;
	case 5:
		printf("\n��סַ����>\n");
		BubbleSort(pm, pm->count, sizeof(Info), cmp_address);
		ShowContact(pm);
		break;
	default:
		printf("�����ѡ������\n");
		break;
	}
}