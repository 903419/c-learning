#include<stdio.h>
#include<string.h>
#include<Windows.h>
#include<time.h>
#define Name "admin"
#define Psd "123"
#define Size 128
#pragma warning(disable:4996)
//int Research(int arr[], int location, int x)
//{
//	int i = location / 2;
//	while (i <= location && i >= 0)
//	{
//		if (x > arr[i])
//		{
//			i++;
//		}
//		else if (x < arr[i])
//		{
//			i--;
//		}
//		else
//		{
//			if (x == arr[i])
//			{
//				return i;
//				break;
//			}
//		}
//	}
//	return 0;
//}
//void menu()
//{
//	printf("******************************\n");
//	printf("***1.play      2.quit*********\n");
//	printf("******************************\n");
//}
//void game()
//{
//	printf("\n.....��Ϸ��ʼ.....\n");
//	printf("��Ϸ����:��������Զ�����[1,1000]��������һ����5�λ���!");
//	int x = rand() % 100 + 1;
//	int i = 0;
//	int num = 20;
//	//scanf("%d", &i);
//	while (num > 0) 
//	{
//		printf("\n��������µ����֣�");
//		scanf("%d", &i);
//		if (i > x)
//		{
//			printf("\n��´���!");
//			num--;
//		}
//		else if (i < x)
//		{
//			printf("\n���С�ˣ�");
//			num--;
//		}
//		else
//		{
//			printf("��¶��ˣ�����Ϊ%d", x);
//			printf("\n.....��Ϸ����.....\n");
//			break;
//		}
//		if (num != 0)
//		{
//			printf("�㻹��%d�λ���\n", num);
//		}
//		if (num == 0)
//		{
//			printf("\n.....��Ϸʧ��.....\n");
//		}
//	}
//}
int main()
{
	//int input = 0;
	//srand((int)time(0));
	//while (input != 2)
	//{
	//	menu();
	//	printf("���������ѡ��");
	//	scanf("%d", &input);
	//	switch (input)
	//	{
	//	case 1:
	//		game();
	//		printf("\nҪ��Ҫ����һ��\n");
	//		break;
	//	case 2:
	//		break;
	//	default:
	//		printf("����������������룺\n");
	//		break;
	//	}
	//}
	//ģ���¼����
	//char name[Size];
	//char psd[Size];
	////printf("����������û��������룺");
	////scanf("%s %s", name, psd);
	//int count = 0;
	//int n = 2;
	//while (n != 0 && !count)
	//{
	//	count = 3;
	//	while (count > 0)
	//	{
	//		printf("����������û��������룺");
	//		scanf("%s %s", name, psd);
	//		if (0 == strcmp(name, Name) && 0 == strcmp(psd, Psd))
	//		{
	//			printf("��¼�ɹ�����ӭ����\n");
	//			break;
	//		}
	//		else
	//		{
	//			count--;
	//			if (count > 0)
	//			{
	//				printf("��������û�����������,�㻹��%d�λ��ᣡ\n", count);
	//			}
	//		}
	//		if (0 == count)
	//		{
	//			n--;
	//			if (n != 0)
	//			{
	//				int i = 60;
	//				for (i; i > 0; i--)
	//				{
	//					printf("��60s֮������:%ds\r", i);
	//					Sleep(100);
	//				}
	//			}
	//			else
	//			{
	//				printf("�������Ѿ���������Σ����������ԡ�\n");
	//			}
	//		}
	//	}
 //   }
	//�ַ������˻��
	//char arr1[] = { "###############" };
	//char arr2[] = { "welcome to bit." };
	//int end = strlen(arr1) - 1;
	//int start = 0;
	//printf("%s\n%s\n", arr1, arr2);
	//for (; start <= end; end--, start++)
	//{
	//	arr1[start] = arr2[start];
	//	arr1[end] = arr2[end];
	//	Sleep(1000);
	//	printf("%s\r", arr1);
	//}
	//printf("\n");
	//���ֲ���
	//int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	//int size = sizeof(a) / sizeof(a[0]) - 1;
	//int n = 0;
	//printf("���ҵ�����");
	//scanf("%d", &n);
	//int ret = Research(a, size, n);
	//if (ret != 0)
	//{
	//	printf("�ҵ��ˣ���Ϊ��%d\n", a[Research(a, size, n)]);
	//}
	//else
	//{
	//	printf("�������δ�ҵ�\n");
	//}
	return 0;
}