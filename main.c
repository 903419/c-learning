#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable:4996)

//n��k�η�
//int Power(int n, int k)//�ݹ�
//{
//	if (k == 1)
//	{
//		return n;
//	}
//	return n * Power(n, k - 1);
//}
//
//int Power1(int a, int b)//non�ݹ�
//{
//	int Mul = 1;
//	while (b > 0)
//	{
//		Mul *= a;
//		b--;
//	}
//	return Mul;
//}
//int main()
//{
//	srand((int)time(0));
//	int x = rand() % 10 + 1;
//	int y = rand() % 10 + 1;
//	printf("x=%d  y=%d\n", x, y);
//	printf("%d^%d=%d\n",x,y,Power(x, y));
//	printf("%d^%d=%d\n", x, y, Power1(x, y));
//	return 0;
//}


//쳲�������ʵ��
//int Fib(int n)//�ݹ�
//{
//	if (n <= 2)
//	{
//		return 1;
//	}
//	else return Fib(n - 1) + Fib(n - 2);
//}
//int Fib1(int n)//non�ݹ�
//{
//	int first = 1;
//	int second = 1;
//	int third = 1;
//	while (n>2)
//	{
//		third = first + second;
//		first = second;
//		second = third;
//		n--;
//	}
//	return third;
//}
//int main()
//{
//	srand((int)time(NULL));
//	int x = rand() % 20 + 1;
//	printf("%d\n", x);
//	printf("%d\n", Fib(x));
//	printf("%d\n", Fib1(x));
//	return 0;
//}

//һ�����ģ�ÿһ��λ֮��
//int Sum = 0;
//int Digitsum(int a)//�ݹ�
//{
//	if (a > 9)
//	{
//		Digitsum(a / 10);
//	}
//	return Sum += a % 10;
//}
//int Digitsum1(int a)//non�ݹ�
//{
//	int sum = 0;
//	while (a > 0)
//	{
//		sum += a % 10;
//		a /=  10;
//	}
//	return sum;
//}
//int main()
//{
//	srand((int)time(0));
//	int x = rand() % 10000 + 1;
//	printf("%d\n", x);
//	printf("%d\n",Digitsum(x));
//	printf("%d\n", Digitsum1(x));
//	return 0;
//}


//�ַ�������
//void Rstring(char *p,int n,int m)
//{
//	if (n <=m)
//	{
//		return 0;
//	}
//	char t;
//	t = *(p + n);
//	*(p + n) = *(p + m);
//	*(p + m) = t;
//	return Rstring(p, n - 1,m+1);
//}
//int main()
//{
//	char arr[] = { "abcdefghijk" };
//	int len = sizeof(arr) / sizeof(arr[0]) - 1 - 1;
//	int i = 0;
//	Rstring(&arr,len,i);
//	printf("%s", arr);
//	return 0;
//}

//ʵ���ַ����󳤶�
//int Strlen(char *p)//�ݹ�
//{
//	if (*p == '\0')
//	{
//		return 0;
//	}
//	else
//	{
//		return 1+Strlen(p + 1);
//	}
//}
//int Strlen1(char *p)//non�ݹ�
//{
//	int count = 0;
//	while (*p != '\0')
//	{
//		count++;
//		p++;
//	}
//	return count;
//}
//int main()
//{
//	char arr[] = { "abcdefg" };
//	printf("%d\n",Strlen(&arr));
//	printf("%d\n", Strlen1(&arr));
//	return 0;
//}


//�׳�
//int Factorial(int a)
//{
//	if (a == 1)
//		return 1;
//	else return a*Factorial(a - 1);
//}
//int Factorial1(int a)
//{
//	int mul = 1;
//	while (a >= 1)
//	{
//		mul *= a;
//		a--;
//	}
//	return mul;
//}
//
//int main()
//{
//	srand((int)time(0));
//    int x = rand() % 10 + 1;
//	printf("�ݹ飺%d��=%d\n",x,Factorial(x));
//	printf("non�ݹ飺%d��=%d\n", x, Factorial1(x));
//	return 0;
//}


//���һ������ÿһλ
//void Print(int a) //����
//{
//	if (a > 9)
//	{
//		Print(a / 10);
//	}
//	printf("%d\t", a % 10);
//}
//
//void Print1(int b)//����
//{
//	printf("%d\t", b % 10);
//	if (b > 9)
//	{
//		Print1(b / 10);
//	}
//}
//void Print2(int c)//non�ݹ�
//{
//	int a = sizeof(c);
//	int i = 0;
//	for (i = a - 1; i >= 0; i--)
//	{
//		int n = c / pow(10, i);
//		printf("%d\t", n % 10);
//	}
//}
//int main()
//{
//	srand((int)time(0));
//    int x = rand() % 10000 + 1;
//	printf("%d\n", x);
//    Print(x);
//	printf("\n");
//	Print1(x);
//	printf("\n");
//	Print2(x);
//	return 0;
//}

//void MulTable(int a)
//{
//	int i = a;
//	int j = 0;
//	for (i = 1; i <= a; i++)
//	{
//		printf("%d\|\t", i);
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%d\t", j, i, j*i);
//		}
//		printf("\n");
//	}
//	printf("\n");
//}
//
//int main()
//{
//	srand((int)time(0));
//    int x = rand() % 12 + 1;
//	MulTable(x);
//	return 0;
//}
//int Swap(int *a, int *b)
//{
//	*a ^= *b;
//	*b ^= *a;
//	*a ^= *b;
//}
//int main()
//{
//	srand((int)time(0));
//	int x = rand() % 10000 + 1;
//	int y = rand() % 10000 + 1;
//	printf("%d,%d\n", x, y);
//	Swap(&x, &y);
//	printf("%d,%d\n", x, y);
//	return 0;
//}
//void Leap(int x)
//{
//	if (((0 == x % 4) && (0 != x % 100)) || (0 == x % 400))
//	{
//		printf("%d�������꣡\n", x);
//	}
//	else
//	{
//		printf("%d�겻�����꣡\n", x);
//	}
//}
//
//int main()
//{
//	srand((int)time(0));
//	int year = rand() % 10000 + 1;
//	Leap(year);
//	return 0;
//}
//int IsSu(int x)
//{
//	int j = 0;
//	for (j = 2; j <= x / 2; j++)
//	{
//		if (0 == x % j)
//		{
//			return -1;
//			break;
//		}
//	}
//	return 1;
//}
//int main()
//{
//	//int i = 0;;
//	//for (i = 100; i < 201; i++)
//	//{
//	//	if (IsSu(i) != -1)
//	//	{
//	//		printf("%d ", i);
//	//	}
//	//}
//	//return 0;
//}