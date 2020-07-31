#ifndef _SEQLIST_H_
#define _SEQLIST_H_
#include "shared.h"
#define SEQNUMBER 8

typedef struct Seqlist
{
	size_t size;
	size_t capacity;
	ElementType *base;
}Seqlist;


void SeqlistInit(Seqlist *plist);//初始化
void SeqlistDestroy(Seqlist *plist);//摧毁
void SeqlistPushBack(Seqlist *plist, ElementType x);//尾插
void SeqlistPushFront(Seqlist *plist, ElementType x);//头插
void SeqlistShow(Seqlist *plist);//显示
void SeqlistPopBack(Seqlist *plist);//尾删
void SeqlistPopFront(Seqlist *plist);//头删
void SeqlistInsertPos(Seqlist *plist, int pos,ElementType x);//位置插入
void SeqlistInsertVal(Seqlist *plist, ElementType x);//值插入，插入前先排序
void SeqlistEraseBack(Seqlist *plist, int pos);//位置删除
void SeqlistEraseVal(Seqlist *plist, ElementType x);//值删除
int SeqlistFind(Seqlist *plist, ElementType x);//位置查找
void SeqlistLength(Seqlist *plist);//数据长度
void SeqlistCapacity(Seqlist *plist);//顺序表容量
void SeqlistSort(Seqlist *plist);//数据排序，这里使用qsort
void SeqlistReverse(Seqlist *plist);//数据倒序
void SeqlistClear(Seqlist *plist);//清空数据
void SeqlistFront(Seqlist *plist);//查看头部数据
void SeqlistBack(Seqlist *plist);//查看尾部数据
void SeqlistBinaryFind(Seqlist *plist, ElementType x);//二分法查找
void SeqlistEraseAll(Seqlist *plist,ElementType x);//清除指定元素

////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////

void SeqlistInit(Seqlist *plist)
{
	assert(plist != NULL);
	plist->capacity = SEQNUMBER;
	plist->size = 0;
	plist->base = (ElementType *)malloc(sizeof(ElementType)*SEQNUMBER);
}

void SeqlistDestroy(Seqlist *plist)//摧毁
{
	assert(plist != NULL);
	free(plist->base);
	plist->base = NULL;
	plist->capacity = 0;
	plist->size = 0;
}

bool SeqlistInc(Seqlist *plist)//扩容
{
	assert(plist != NULL);
	ElementType *s = (ElementType *)realloc(plist->base, 2 * plist->capacity * sizeof(ElementType));
	if (NULL != s)
	{
		plist->base = s;
		plist->capacity = 2 * plist->capacity;
		return true;
	}
	return false;
}

bool IsFull(Seqlist *plist)
{
	assert(plist != NULL);
	return plist->size >= plist->capacity;
}

bool IsEmpty(Seqlist *plist)
{
	assert(plist != NULL);
	if (plist->size == 0)
	{
		return true;
	}
	return false;
}

void SeqlistPushBack(Seqlist *plist, ElementType x)
{
	assert(plist != NULL);
	if (IsFull(plist) && !SeqlistInc(plist))
	{
		printf("顺序表已满，%d不能插入\n", x);
		return;
	}
	plist->base[plist->size] = x;
	plist->size++;
}

void SeqlistPushFront(Seqlist *plist, ElementType x)//头插
{
	assert(plist != NULL);
	if (IsFull(plist) && !SeqlistInc(plist))
	{
		printf("顺序表已满，%d不能插入\n", x);
		return;
	}
	for (size_t i = plist->size; i > 0; i--)
	{
		plist->base[i] = plist->base[i - 1];
	}
	plist->base[0] = x;
	plist->size++;
}

void SeqlistShow(Seqlist *plist)//显示
{
	assert(plist != NULL);
	for (size_t i = 0; i < plist->size; i++)
	{
		printf("%d ", plist->base[i]);
	}
	printf("\n");
}

void SeqlistPopBack(Seqlist *plist)//尾删
{
	assert(plist != NULL);
	if (IsEmpty(plist))
	{
		printf("数据为空，无法删除\n");
		return;
	}
	plist->size--;
}

void SeqlistPopFront(Seqlist *plist)//头删
{
	assert(plist != NULL);
	if (IsEmpty(plist))
	{
		printf("数据为空，无法删除\n");
		return;
	}
	for (size_t i = 0; i < plist->size; i++)
	{
		plist->base[i] = plist->base[i + 1];
	}
	plist->size--;
}

void SeqlistInsertPos(Seqlist *plist, int pos, ElementType x)//位置插入
{
	assert(plist != NULL);
	if (IsFull(plist))
	{
		printf("顺序表已满，%d不能插入\n", x);
		return;
	}
	if ( pos<0 || pos>(int)plist->size)
	{
		printf("输入的位置%d非法，%d不能插入\n",pos,x);
		return;
	}
	for (size_t i = plist->size; i > (size_t) pos; i--)
	{
		plist->base[i] = plist->base[i - 1];
	}
	plist->base[pos] = x;
	plist->size++;
}

void SeqlistInsertVal(Seqlist *plist, ElementType x)//值插入，插入前先排序
{
	assert(plist != NULL);
	qsort(plist->base, plist->size, sizeof(ElementType), cmp);
	if (IsFull(plist) && !SeqlistInc(plist))
	{
		printf("顺序表已满，%d不能插入\n", x);
		return;
	}
	size_t end = plist->size - 1;
	while (end >= 0 && x < plist->base[end])
	{
		plist->base[end + 1] = plist->base[end];
		end--;
	}
	plist->base[end + 1] = x;
	plist->size++;
}

void SeqlistEraseBack(Seqlist *plist, int pos)//位置删除
{
	assert(plist != NULL);
	if (IsEmpty(plist))
	{
		printf("顺序表为空，不能删除！\n");
		return;
	}
	if (pos < 0 || pos > (int)plist->size)
	{
		printf("输入的位置%d非法，不能删除\n",pos);
		return;
	}
	for (size_t i = (size_t)pos; i < plist->size ; i++)
	{
		plist->base[i] = plist->base[i + 1];
	}
	plist->size--;
}

void SeqlistEraseVal(Seqlist *plist, ElementType x)//值删除
{
	assert(plist != NULL);
	if (IsEmpty(plist))
	{
		printf("数据为空，无法删除！\n");
	}
	int pos = SeqlistFind(plist, x);
	if (pos == -1)
	{
		printf("数据不存在，无法删除\n");
		return;
	}
	SeqlistEraseBack(plist, pos);
}

int SeqlistFind(Seqlist *plist, ElementType x)//位置查找
{
	assert(plist != NULL);
	if (IsEmpty(plist))
	{
		printf("数据为空，无法查找！\n");
	}
	size_t pos = 0;
	while (pos < plist->size && x != plist->base[pos])
	{
		pos++;
	}
	if (pos == plist->size)
	{
		return -1;
	}
	return pos;
}

void SeqlistLength(Seqlist *plist)//数据长度
{
	assert(plist != NULL);
	printf("数据长度为：>%d\n", plist->size);
}

void SeqlistCapacity(Seqlist *plist)//顺序表容量
{
	assert(plist != NULL);
	printf("顺序表容量为：>%d\n", plist->capacity);
}

void SeqlistSort(Seqlist *plist)//数据排序，这里使用qsort
{
	assert(plist != NULL);
	if (IsEmpty(plist))
	{
		printf("数据为空，无法排序!\n");
	}
	qsort(plist->base, plist->size, sizeof(ElementType), cmp);
}

void SeqlistReverse(Seqlist *plist)//数据倒序
{
	assert(plist != NULL);
	size_t start = 0;
	size_t end = plist->size - 1;
	while (start < end)
	{
		plist->base[end] ^= plist->base[start];
		plist->base[start] ^= plist->base[end];
		plist->base[end] ^= plist->base[start];
		start++, end--;
	}
}

void SeqlistClear(Seqlist *plist)
{
	assert(plist != NULL);
	plist->size = 0;
}

void SeqlistFront(Seqlist *plist)//查看头部数据
{
	assert(plist != NULL);
	if (0 == plist->size )
	{
		printf("数据为空\n");
		return;
	}
	printf("头部数据为：>%d\n", plist->base[0]);
}

void SeqlistBack(Seqlist *plist)//查看尾部数据
{
	assert(plist != NULL);
	if (0 == plist->size)
	{
		printf("数据为空\n");
		return;
	}
	printf("尾部数据为：>%d\n", plist->base[plist->size - 1]);
}

void SeqlistBinaryFind(Seqlist *plist, ElementType x)
{
	assert(plist != NULL);
	size_t start = 0;
	size_t end = plist->size;
	size_t mid = 0;
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (x < plist->base[mid])
		{
			end = mid - 1;
		}
		else if (x > plist->base[mid])
		{
			start = mid + 1;
		}
		else
		{
			printf("数据查找成功，为：>%d\n", plist->base[mid]);
			return;
		}
	}
	printf("查找失败，数据%d不存在\n", x);
}

void SeqlistEraseAll(Seqlist *plist,ElementType x)//删除指定元素
{
	assert(plist != NULL);
	if (plist->size <= 0)
	{
		return;
	}
	SeqlistSort(plist);
	size_t pos = SeqlistFind(plist, x);
	size_t count = 0;
	int tmp = 0;
	for (size_t i = pos; i < plist->size; i++)
	{
		tmp = 1;
		if (x == plist->base[i])
		{
			tmp = 0;
			count++;
		}
		if (tmp == 1)
		{
			break;
		}
	}
	tmp = count;
	int number = count + pos;
	for (; count > 0; count--)
	{
		plist->base[pos++] = plist->base[number++];
	}
	plist->base[pos-1] = plist->base[number-1];
	plist->size -= tmp;
}


#endif // !_SEQLIST_H_


