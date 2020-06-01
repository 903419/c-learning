#include "main.h"

int SearchNumber(int(*arr)[4], int number)
{
	int i = 0;
	int j = 0;
	if (number <= arr[1][3])//二分一下
	{
		for (i = 0; i < 2; i++)
		{
			for (j = 0; j < 4; j++)
			{
				if (number == arr[i][j])
				{
					return 1;
				}
			}
		}
	}
	else
	{
		for (i = 2; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
			{
				if (number == arr[i][j])
				{
					return 1;
				}
			}
		}
	}
	return 0;
}



void Intermediate(void *base, int num, void(*rotate)(void *,int))
{
	rotate(base, num);
}

void Sinistral(void *a, int num)
{
	int i = 0;
	char m = *(char *)a;
	for (; i < num; i++)
	{
		if (i <= (num - 2))
		{
			*((char*)a + i) = *((char*)a + i + 1);
		}
		else
		{
			*((char*)a + i) = m;
		}
	}
}



int cmpInt(const void *a,const void *b)//回调函数
{
	if (((*(int *)a - *(int *)b)) > 0)
	{
		return 1;
	}
	else if (((*(int *)a - *(int *)b)) < 0)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

void print(int *a, int num)
{
	int i = 0;
	for (; i < num; i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}

void myqsort(void *base, int num, int size, int(*compare)(const void *, const void *))//实现回调函数的调用函数
{
	int i = 0;
	int j = 0;
	char *_base = (char *)base;
	for (; i < num - 1; i++)
	{
		int Flag = 1;
		for (j = 0; j < num - 1 - i; j++)
		{
			if (compare(_base + j * size, _base + (j + 1)*size) > 0)
			{
				Flag = 0;
				swap(_base + j * size, _base + (j + 1)*size);
			}
		}
		if (1 == Flag)
		{
			break;
		}
	}
}

void swap(void *a, void *b)
{
	*(int *)a ^= *(int *)b;
	*(int *)b ^= *(int *)a;
	*(int *)a ^= *(int *)b;
}