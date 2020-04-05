//#include <stdio.h>
//#pragma warning(disable:4996)
//int main()
//{
//	int i = 0;
//	int b = 0;
//	int j = 0;
//	for (i = 100; i < 201; i++)
//	{
//		b = 1;
//		for (j = 2; j < i/2; j++)
//		{
//			if (0 == i % j)
//			{
//				b = 0;
//				break;
//			}
//		}
//		if (1 == b)
//		{
//			printf("%d是素数\n", i);
//		}
//	}
//	return 0;
//}
//int main()
//{
//	int i = 0;
//	for (i = 1000; i < 2001; i++)
//	{
//		if ((0 == i % 4) && (i % 100 != 0) || (0 == i % 400))
//		{
//			printf("%d年是闰年\n", i);
//		}
//	}
//	return 0;
//}
#include <stdio.h>
#pragma warning(disable:4996)
#include <math.h>
int fun1(int x, int y)//辗转相除法
{
	int z;
	while (z = x % y)
	{
		x = y;
		y = z;
	}
	return y;
}
void fun2(int x, int y)//更相减损术
{
	int z = 0;
	while (x != y)
	{
		while (x % 2 == 0 && y % 2 == 0)
		{
			x = x / 2;
			y = y / 2;
			z++;
		}
		if (x > y)
			x = x - y;
		if (x < y)
			y = y - x;
	}
	if (z != 0) {
		printf("更相减损术：最大公约数为%d\n", 2 * z*x);
	}
	else {
		printf("更相减损术：最大公约数为%d\n", x);
	}
}
//最小公倍数
int fun3(int x, int y, int z) {
	return x * y / z;
}
void main()
{
	int a, b;
	printf("请输入两个整数\n");
	scanf("%d %d", &a, &b);
	printf("辗转相除法：最大公约数是%d\n", fun1(a, b));
	fun2(a, b);//更相减损术
	printf("最小公倍数是%d\n", fun3(a, b, fun1(a, b)));
	system("pause");
}
//int Gcd1(int x, int y) // 辗转相除
//{
//	if (0 == y)
//	{
//		return x;
//	}
//	else
//	{
//		return Gcd1(y, x%y);
//	}
//}
//int Gcd2(int x, int y)//更相减损  这个方法太麻烦了
//{
//	int t = 0;
//	int r = 0;
//	int n = 0;
//	if (x == y)
//	{
//		return x;
//	}
//	else
//	{
//		while (1)
//		{
//			if (x % 2 != 0 || y % 2 != 0)
//			{
//				break;
//			}
//			x = x / 2;
//			y = y / 2;
//			n = n + 1;
//		}
//		while (1)
//		{
//			if (x < y)
//			{
//				r = x;
//				x = y;
//				y = r;
//			}
//			t = x - y;
//			x = y;
//			y = t;
//			if (x == t)
//			{
//				break;
//			}
//		}
//		if (n != 0)
//		{
//			x = x * pow(2,n);
//		}
//		return x;
//	}
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int d = 0;
//	printf("input two numbers:");
//	scanf("%d %d", &a, &b);
//	printf("%d和%d的最大公约数为：%d\n", a, b, Gcd1(a, b));
//	printf("input two numbers:");
//	scanf("%d %d", &c, &d);
//	printf("%d和%d的最大公约数为：%d\n", c, d, Gcd2(c, d));
//	return 0;
//}