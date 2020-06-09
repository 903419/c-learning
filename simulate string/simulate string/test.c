#include "main.h"

int my_strlen(char *str)
{
	int count = 0;
	while (*str++)
	{
		count++;
	}
	return count;
}


void Cpy(char *str1, char *str2)
{
	while (*str2)
	{
		*str1 = *str2;
		str1++, str2++;
	}
	*str1 = *str2;
}


int Cmp(char *str1, char *str2)
{
	int num = 0;
	while (*str1 || *str2)
	{
		num = *(unsigned char*)str1 - *(unsigned char*)str2;
		str1++, str2++;
		if (num != 0)
		{
			break;
		}
	}
	if (num > 0)
	{
		return 1;
	}
	else if (num < 0)
	{
		return -1;
	}
	else
	{
		return 0;
	}

}

void Link(char *str1, char *str2, int num1, int num2)
{
	int i = 0;
	for (; i <= num2; i++)
	{
		str1[i + num1] = str2[i];
	}
}