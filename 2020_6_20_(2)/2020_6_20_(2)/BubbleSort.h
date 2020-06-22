#ifndef _BUBBLESORT_H_
#define _BUBBLESORT_H_
#include "main.h"

int cmp_name(const void *s1, const void *p1)
{
	MailList *s2 = (MailList *)s1;
	MailList *p2 = (MailList *)p1;
	return strcmp(s2->data->name, p2->data->name);
}
int cmp_age(const void *s1, const void *p1)
{
	MailList *s2 = (MailList *)s1;
	MailList *p2 = (MailList *)p1;
	if ((s2->data->age - p2->data->age) > 0)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}
int cmp_sex(const void *s1, const void *p1)
{
	MailList *s2 = (MailList *)s1;
	MailList *p2 = (MailList *)p1;
	return strcmp(s2->data->sex, p2->data->sex);
}
int cmp_telephone(const void *s1, const void *p1)
{
	MailList *s2 = (MailList *)s1;
	MailList *p2 = (MailList *)p1;
	return strcmp(s2->data->telephone, p2->data->telephone);
}
int cmp_address(const void *s1, const void *p1)
{
	MailList *s2 = (MailList *)s1;
	MailList *p2 = (MailList *)p1;
	return strcmp(s2->data->address, p2->data->address);
}

void Swap(char *s1, char *s2, int width)
{
	int i = 0;
	for (; i < width; i++)
	{
		s1[i] ^= s2[i];
		s2[i] ^= s1[i];
		s1[i] ^= s2[i];
	}
}

void BubbleSort(void *base, int number, int width, int(*cmp)(const void *p, const void *p2))
{
	int i = 0;
	int j = 0;
	for (; i < number; i++)
	{
		for (j = 0; j < number - i - 1; j++)
		{
			if (cmp((char *)base + width * j, (char *)base + width * (j + 1)) > 0)
			{
				Swap((char *)base + width * j, (char *)base + width * (j + 1), width);
			}

		}
	}
}

#endif // !_BUBBLESORT_H_

