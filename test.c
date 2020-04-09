#include <stdio.h>
#include <time.h>
int main()
{
	srand((int)time(0));
	int a[10];
	int i = 0;
	int Max = 0;
	for (i = 0; i < 10; i++)
	{
		a[i] = rand() % 1000 + 1;
		printf("%d\t", a[i]);
		if (a[i] > Max)
		{
			Max = a[i];
		}
	}
	printf("\n最大值为：%d\n", Max);
}
//int main()
//{
//	int i = 0;
//	float n = 0;
//	float sum = 0;
//	for (i = 1; i < 101; i++)
//	{
//		n = i;
//		if (0 != i % 2)
//		{
//			sum = sum + (1 / n);
//		}
//		else
//		{
//			sum = sum - (1 / n);
//		}
//	}
//	printf("%f\n", sum);
//}
//	int i = 0;
//	int count = 0;
//	int n = 0;
//	for (i = 1; i < 101; i++)
//	{
//		n = i;
//		if (9 == n % 10)
//		{
//			count++;
//		}
//		n /= 10;
//		if (9 == n)
//		{
//			count++;
//		}
//	}
//	printf("9的个数为：%d\n", count);
//	return 0;
//}
	//int i = 0;
	//int j = 0;
	//for (i = 1; i <= 9; i++)
	//{
	//	printf("%d\|\t", i);
	//	for (j = 1; j <= i; j++)
	//	{
	//		printf("%d*%d=%d\t", j, i,j*i);
	//	}
	//	printf("\n");
	//}
	//return 0;
//}