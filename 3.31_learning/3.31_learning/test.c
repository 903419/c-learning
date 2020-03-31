#include <stdio.h>
#include<Windows.h>
//#define DOUBLE(x) x*x
int main()
{
	printf("%d\n", sizeof(char*));
	printf("%d\n", sizeof(short*));
	printf("%d\n", sizeof(int*));
	printf("%d\n", sizeof(float*));
	printf("%d\n", sizeof(long*));
	printf("%d\n", sizeof(double*));
	//int a = 10;
	//printf("%d\n", 10*DOUBLE(a + 1));
}