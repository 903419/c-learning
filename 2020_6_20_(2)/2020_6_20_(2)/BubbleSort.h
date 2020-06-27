#ifndef _BUBBLESORT_H_
#define _BUBBLESORT_H_
#include "main.h"

int cmp_name(const Info *s1, const Info *p1)
{
	return strcmp(s1->name, p1->name);
}
int cmp_age(const Info *s1, const Info *p1)
{
	if ((s1->age - p1->age) > 0)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}
int cmp_sex(const Info *s1, const Info *p1)
{
	return strcmp(s1->sex, p1->sex);
}
int cmp_telephone(const Info *s1, const Info *p1)
{
	return strcmp(s1->telephone, p1->telephone);
}
int cmp_address(const Info *s1, const Info *p1)
{
	return strcmp(s1->address, p1->address);
}

void Swap(void *s1, void *s2, int width)
{
	int i = 0;
	char *s3 = (char *)s1;
	char *s4 = (char *)s2;
	for (; i < width; i++)
	{
		s3[i] ^= s4[i];
		s4[i] ^= s3[i];
		s3[i] ^= s4[i];
	}
}

void BubbleSort(MailList *base, int number, int width, int(*cmp)(const Info *p, const Info *p2))
{
	int i = 0;
	int j = 0;
	for (; i < number; i++)
	{
		for (j = 0; j < number - i - 1; j++)
		{
			if (cmp(&base->data[j], &base->data[j+1]) > 0)
			{
				Swap(&base->data[j], &base->data[j+1],width);
			}

		}
	}
}

#endif // !_BUBBLESORT_H_

