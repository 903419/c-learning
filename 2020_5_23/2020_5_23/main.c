#include "main.h"


//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int d = 0;
//	int e = 0;
//	for (a = 1; a <= 5; a++)
//	{
//		for (b = 1; b <= 5; b++)
//		{
//			for (c = 1; c <= 5; c++)
//			{
//				for (d = 1; d <= 5; d++)
//				{
//					for (e = 1; e <= 5; e++)
//					{
//					    if (1==((2 == b) + (3 == a)) &&\
//							(1 == (2 == b) + (4 == e)) &&\
//							(1 == (1 == c) + (2 == d)) &&\
//							(1 == (5 == c) + (3 == d)) &&\
//							(1 == (4 == e) + (1 == a)))
//						{
//							if (120 == a * b * c * d * e)
//							{
//								printf("a=%d b=%d c=%d d=%d e=%d\n", a, b, c, d, e);
//							}
//						}
//					}
//				}
//			}
//		}
//	}
//	return 0;
//}


int main()
{
	char murderer;
	for (murderer = 'a'; murderer <= 'd'; murderer++)
	{
		if (3==((murderer != 'a') + (murderer == 'c') + (murderer == 'd') + (murderer != 'd')))
		{
			printf("������%c\n", murderer);
			break;
		}
	}
	return 0;
}

//������Ǣ�
//int main()
//{
//	int a[N][N] = { 0 };//��������
//	int n = 0;
//	printf("����Ҫ��ӡ��������>");
//	scanf("%d", &n);
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < n; i++)//ÿ�еĵ�һ�������һ��Ϊ1
//	{
//		a[i][0] = a[i][i] = 1;
//	}
//	for (i = 1; i < n; i++)//�м��i+1�е�j��Ԫ�ص��ڵ�i�е�j��Ԫ�غ͵�i�е�j-1��Ԫ�����
//	{
//		for (j = 1; j <= i - 1; j++)
//		{
//			a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
//		}
//	}
//	for (i = 0; i < n; i++)//���
//	{
//		for (j = 1; j <n-i; j++)
//		{
//			printf("   ");
//		}
//		for (j = 0; j <= i; j++)
//		{
//			printf("%6d", a[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}