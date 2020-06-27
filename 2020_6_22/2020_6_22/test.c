#include "main.h"

void TwoSingleAf(int *arr,int num,int *x, int *y)
{
	int result = arr[0];
	int i = 1;
	for (; i < num; i++)
	{
		result ^= arr[i];
	}
	int pos = 0;
	while (1)
	{
		if ((result >> pos) & 1)
		{
			break;
		}
		pos++;
	}
	for (i = 0; i < num; i++)
	{
		if ((arr[i] >> pos) & 1)
		{
			*x ^= arr[i];
		}
		else
		{
			*y ^= arr[i];
		}
	}
}


int Judgement = 0;
int my_atoi(const char *str)
{
	int symbol = 1;
	long long result = 0;
	while (*str == ' ' || *str == '\t')//空格或者缩进
	{
		str++;
	}
	if (*str == '-')
	{
		symbol = -1;
		str++;
	}
	if (*str == '+')
	{
		str++;
	}
	while (*str != '\0')
	{
		if (*str >= '0' && *str <= '9')
		{
			result = result * 10 + (*str - '0');
			if (result > INT_MAX || result < INT_MIN)
			{
				Judgement = 1;
				printf("Judgement=%d,数据太大溢出了\n", Judgement);
				return (int)result;
				break;
			}
		}
		else
		{
			break;
		}
		str++;
	}
	return (int)(result * symbol);
}