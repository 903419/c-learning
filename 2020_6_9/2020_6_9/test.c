#include "main.h"

int Find(int (*arr)[5], int col, int row, int number)
{
	int j = row - 1;
	int i = 0;
	while (j >= 0 && i < col)
	{
		if (number < arr[i][j])
		{
			j--;
		}
		else if (number > arr[i][j])
		{
			i++;
		}
		else
		{
			return 1;
		}
	}
	return 0;
}

//3
void Assign(char *arr, char *double_string, int len, int count)
{
	int i = 0;
	for (; i < len; i++)
	{
		arr[i] = double_string[i + len - count];
	}
}

//2
void Rightrotate(char *arr, int len, int count)
{
	assert(arr);
	assert(len > 0);
	assert(count >= 0);
	count %= len;//去重
	Reverse(arr, len - count, len - 1);
	Reverse(arr, 0, len - 1-count);
	Reverse(arr, 0, len - 1);
}

void Reverse(char *arr, int start, int end)
{
	while (start<end)
	{
		arr[start] ^= arr[end];
		arr[end] ^= arr[start];
		arr[start] ^= arr[end];
		start++, end--;
	}
}

//1
//void rightrotate(char *arr, int len, int count)
//{
//	assert(arr);
//	assert(len>0);
//	assert(count >= 0);
//	count %= len;//去重
//
//	while (count)
//	{
//		char temp = arr[len-1];
//		int i = len-1;
//		for (; i > 0; i--)
//		{
//			arr[i] = arr[i-1];
//		}
//		arr[i] = temp;
//		count--;
//
//	}
//}