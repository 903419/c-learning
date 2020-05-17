#include "main.h"

int Soda(int x)
{
	int i = 0;
	int num = 0;//空瓶子计数
	int count = 0;//计数，走了多少次循环，就喝了多少瓶汽水
	for (i = x; i > 0; --i)
	{
		++num;//每走一次循环，空瓶子+1个
		if (2 == num)//空瓶子数为2时，可以换一瓶汽水
		{
			i++;//此时汽水加1
			num = 0;//空瓶子置0，也可以不置0，将判定条件改为0==num%2
		}
		count++;
	}
	return count;
}