#include "main.h"


void menu()
{
	printf("###########################################\n");
	printf("######      ��ӭ����ͨѶ¼����ϵͳ   ######\n");
	printf("######          0.�˳�               ######\n");
	printf("######      1.������ϵ����Ϣ         ######\n");
	printf("######      2.��ʾ������ϵ����Ϣ     ######\n");
	printf("######      3.����ָ����ϵ����Ϣ     ######\n");
	printf("######      4.�޸�ָ����ϵ����Ϣ     ######\n");
	printf("######      5.ɾ��ָ����ϵ����Ϣ     ######\n");
	printf("######      6.���������ϵ��         ######\n");
	printf("######      7.����������ϵ��         ######\n");
	printf("###########################################\n");

}

int main()
{
	menu();
	printf("���������ѡ��:>");
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
		default:
			printf("��������д���\n");
			break;
		}
		menu();
		printf("\n���������ѡ��:>");
		scanf("%d", &choice);
	}
	return 0;
}