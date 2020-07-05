#include "main.h"


void menu()
{
	printf("###########################################\n");
	printf("######      欢迎来到通讯录管理系统   ######\n");
	printf("######          0.退出               ######\n");
	printf("######      1.添加联系人信息         ######\n");
	printf("######      2.显示所有联系人信息     ######\n");
	printf("######      3.查找指定联系人信息     ######\n");
	printf("######      4.修改指定联系人信息     ######\n");
	printf("######      5.删除指定联系人信息     ######\n");
	printf("######      6.清空所有联系人         ######\n");
	printf("######      7.排序所有联系人         ######\n");
	printf("######      8.读取文件联系人         ######\n");
	printf("######      9.存储联系人到文件       ######\n");
	printf("###########################################\n");

}

int main()
{
	menu();
	printf("请做出你的选择:>");
	int choice = 0;
	scanf("%d", &choice);
	MailList Book;
	InitiBook(&Book);
	while (0 != choice)
	{
		switch (choice)
		{
		case 1:
			AddContact(&Book);
			break;
		case 2:
			ShowContact(&Book);
			break;
		case 3:
			SeekContact(&Book);
			break;
		case 4:
			ModifyContact(&Book);
			break;
		case 5:
			DeleteContact(&Book);
			break;
		case 6:
			ClearContact(&Book);
			break;
		case 7:
			SortContact(&Book);
			break;
		case 8:
			ReadContact(&Book);
			break;
		case 9:
			SaveContact(&Book);
			break;
		default:
			printf("你的输入有错误！\n");
			break;
		}
		menu();
		printf("\n请做出你的选择:>");
		scanf("%d", &choice);
	}
	free(Book.data);
	return 0;
}