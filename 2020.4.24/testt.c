#include "test.h"

int Bitdiff(int m, int n)
{
	int x = m ^ n;//����������bitλ��ͬ�������������һ�¡�
	int count = 0;
	while (x)
	{
		count++;
		x &= (x - 1);
	}
	return count;
}


void All(int m)
{
	int i = 0;
	i = 31;
	printf("�����ƣ�");
	while (i>=0)
	{
		printf("%d ", (m >> i) & 1);
		i--;
	}
	printf("\n����λ��");
	for (i = 30; i >= 0; i -= 2)
	{
		printf("%d ", (m >> i) & 1);
	}
	printf("\nż��λ��");
	for (i = 31; i >= 1; i -= 2)
	{
		printf("%d ", (m >> i) & 1);
	}
	printf("\n");
}

void All1(int m)
{
	int i = 0;
	i = 31;
	printf("�����ƣ�");
	while (i >= 0)
	{
		printf("%d ", (m >> i) & 1);
		i--;
	}
	printf("\n����λ��");
	for (i = 0; i <=30; i += 2)
	{
		printf("%d ", (m >> i) & 1);
	}
	printf("\nż��λ��");
	for (i = 1; i <= 31; i += 2)
	{
		printf("%d ", (m >> i) & 1);
	}
	printf("\n");
}

int OneNumber(int m)
{
	int count = 0;
	while (m)
	{
		count++;
		m &= (m - 1);
	}
	return count;
}

void Swap(int *m, int *n)
{
	*m ^= *n;
	*n ^= *m;
	*m ^= *n;
}

//0000 0000 0000 0000 0000 0000 0000 0001
//0000 0000 0000 0000 0000 0000 1100 0111