#ifndef _HEAP_H_
#define _HEAP_H_
#include "shared.h"
#define HEAP_SIZE 15


typedef struct MinHeap
{
	ElementType *base;
	size_t capacity;
	size_t size;
}MinHeap;


void MinHeapInit(MinHeap *php);
void MinHeapInsert(MinHeap *php, ElementType x);
void MinHeapCreate(MinHeap *php, ElementType arr[], int n);
void MinHeapShiftUp(MinHeap *php, int start);
void MinHeapErase(MinHeap *php);
void MinHeapShiftDown(MinHeap *php,int start, int end);
ElementType MinHeapTop(MinHeap *php);
void MinHeapSort(MinHeap *php, int arr[], int n);
void MinHeapShow(MinHeap *php);
void MinHeapDestroy(MinHeap *php);

////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////

void MinHeapInit(MinHeap *php)
{
	assert(php != NULL);
	php->base = (ElementType *)malloc(sizeof(ElementType) * HEAP_SIZE);
	php->capacity = HEAP_SIZE;
	php->size = 0;
}

void MinHeapInsert(MinHeap *php, ElementType x)
{
	assert(php != NULL);
	if (php->size >= php->capacity)
	{
		printf("堆满了，不能插入！\n");
		return;
	}
	php->base[php->size] = x;
	MinHeapShiftUp(php, php->size);
	php->size++;
}

void MinHeapCreate(MinHeap *php, ElementType arr[], int n)
{
	php->capacity = n;
	php->base = (ElementType *)malloc(sizeof(ElementType) * n);
	for (int i = 0; i < n; i++)
		php->base[i] = arr[i];
	php->size = n;


	int start = (php->size / 2) -1; //最后一个分支
	while (start >= 0)
	{
		MinHeapShiftDown(php, start, n);
		start--;
	}
}

void MinHeapShiftUp(MinHeap *php, int start)//i:child  j:parent
{
	int i = start;
	int j = (i - 1) / 2;
	while (i > 0)
	{
		if (php->base[i] < php->base[j])
		{
			Swap(&php->base[i], &php->base[j]);
			i = j;
			j = (i - 1) / 2;
		}
		else
			break;
	}
}

void MinHeapErase(MinHeap *php)
{
	assert(php != NULL);
	php->base[0] = php->base[php->size - 1];
	MinHeapShiftDown(php, 0 , php->size - 1);
	php->size--;
}

void MinHeapShiftDown(MinHeap *php,int start, int n)//i : parent j : child
{
	int i = start;
	int j = 2 * i + 1;
	while (j < n)
	{
		if ((j + 1 < n) && (php->base[j] > php->base[j + 1]))
			j++;
		if (php->base[i] > php->base[j])
		{
			Swap(&php->base[i], &php->base[j]);
			i = j;
			j = 2 * i + 1;
		}
		else
			break;
	}
}

void MinHeapShow(MinHeap *php)
{
	for (size_t i = 0; i < php->size; i++)
		printf("%d ", php->base[i]);
	printf("\n");
}

ElementType MinHeapTop(MinHeap *php)
{
	assert(php != NULL && php->size !=0 );
	return php->base[0];
}

void MinHeapSort(MinHeap *php, int arr[], int n)
{
	MinHeapCreate(php, arr, n);
	int number = (int)php->size;
	while (number >= 2)
	{
		number--;
		Swap(&php->base[0], &php->base[number]);
		MinHeapShiftDown(php, 0, number);
	}
	for (int i = 0; i < n; i++)
		arr[i] = php->base[i];
}

void MinHeapDestroy(MinHeap *php)
{
	free(php->base);
	php->capacity = php->size = 0;
}



/**/

#endif // !_HEAP_H_
