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
//	printf("\n.....游戏开始.....\n");
//	printf("游戏规则:计算机会自动生成[1,1000]的数，你一共有5次机会!");
//	int x = rand() % 100 + 1;
//	int i = 0;
//	int num = 20;
//	//scanf("%d", &i);
//	while (num > 0) 
//	{
//		printf("\n请输入你猜的数字：");
//		scanf("%d", &i);
//		if (i > x)
//		{
//			printf("\n你猜大了!");
//			num--;
//		}
//		else if (i < x)
//		{
//			printf("\n你猜小了！");
//			num--;
//		}
//		else
//		{
//			printf("你猜对了，数字为%d", x);
//			printf("\n.....游戏结束.....\n");
//			break;
//		}
//		if (num != 0)
//		{
//			printf("你还有%d次机会\n", num);
//		}
//		if (num == 0)
//		{
//			printf("\n.....游戏失败.....\n");
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
	//	printf("请做出你的选择：");
	//	scanf("%d", &input);
	//	switch (input)
	//	{
	//	case 1:
	//		game();
	//		printf("\n要不要再玩一把\n");
	//		break;
	//	case 2:
	//		break;
	//	default:
	//		printf("输入错误！请重新输入：\n");
	//		break;
	//	}
	//}
	//模拟登录场景
	//char name[Size];
	//char psd[Size];
	////printf("请输入你的用户名和密码：");
	////scanf("%s %s", name, psd);
	//int count = 0;
	//int n = 2;
	//while (n != 0 && !count)
	//{
	//	count = 3;
	//	while (count > 0)
	//	{
	//		printf("请输入你的用户名和密码：");
	//		scanf("%s %s", name, psd);
	//		if (0 == strcmp(name, Name) && 0 == strcmp(psd, Psd))
	//		{
	//			printf("登录成功，欢迎进入\n");
	//			break;
	//		}
	//		else
	//		{
	//			count--;
	//			if (count > 0)
	//			{
	//				printf("请检查你的用户名或者密码,你还有%d次机会！\n", count);
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
	//					printf("请60s之后重试:%ds\r", i);
	//					Sleep(100);
	//				}
	//			}
	//			else
	//			{
	//				printf("今天你已经输入错误多次，请明天再试。\n");
	//			}
	//		}
	//	}
 //   }
	//字符向两端汇聚
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
	//二分查找
	//int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	//int size = sizeof(a) / sizeof(a[0]) - 1;
	//int n = 0;
	//printf("查找的数：");
	//scanf("%d", &n);
	//int ret = Research(a, size, n);
	//if (ret != 0)
	//{
	//	printf("找到了，数为：%d\n", a[Research(a, size, n)]);
	//}
	//else
	//{
	//	printf("输入错误，未找到\n");
	//}
	return 0;
}