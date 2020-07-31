#ifndef _MAIN_H_
#define _MAIN_H_

#include <vld.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <malloc.h>
#include <string.h>
#pragma warning(disable:4996)

#define ElementType int

int cmp(const void *a, const void *b)
{
	return *(ElementType *)a - *(ElementType *)b;
}

void Swap(const void *a, const void *b)
{
	*(ElementType *)a ^= *(ElementType *)b;
	*(ElementType *)b ^= *(ElementType *)a;
	*(ElementType *)a ^= *(ElementType *)b;
}



#endif // !_MAIN_H_
