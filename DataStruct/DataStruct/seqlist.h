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


void SeqlistInit(Seqlist *plist);//��ʼ��
void SeqlistDestroy(Seqlist *plist);//�ݻ�
void SeqlistPushBack(Seqlist *plist, ElementType x);//β��
void SeqlistPushFront(Seqlist *plist, ElementType x);//ͷ��
void SeqlistShow(Seqlist *plist);//��ʾ
void SeqlistPopBack(Seqlist *plist);//βɾ
void SeqlistPopFront(Seqlist *plist);//ͷɾ
void SeqlistInsertPos(Seqlist *plist, int pos,ElementType x);//λ�ò���
void SeqlistInsertVal(Seqlist *plist, ElementType x);//ֵ���룬����ǰ������
void SeqlistEraseBack(Seqlist *plist, int pos);//λ��ɾ��
void SeqlistEraseVal(Seqlist *plist, ElementType x);//ֵɾ��
int SeqlistFind(Seqlist *plist, ElementType x);//λ�ò���
void SeqlistLength(Seqlist *plist);//���ݳ���
void SeqlistCapacity(Seqlist *plist);//˳�������
void SeqlistSort(Seqlist *plist);//������������ʹ��qsort
void SeqlistReverse(Seqlist *plist);//���ݵ���
void SeqlistClear(Seqlist *plist);//�������
void SeqlistFront(Seqlist *plist);//�鿴ͷ������
void SeqlistBack(Seqlist *plist);//�鿴β������
void SeqlistBinaryFind(Seqlist *plist, ElementType x);//���ַ�����
void SeqlistEraseAll(Seqlist *plist,ElementType x);//���ָ��Ԫ��

////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////

void SeqlistInit(Seqlist *plist)
{
	assert(plist != NULL);
	plist->capacity = SEQNUMBER;
	plist->size = 0;
	plist->base = (ElementType *)malloc(sizeof(ElementType)*SEQNUMBER);
}

void SeqlistDestroy(Seqlist *plist)//�ݻ�
{
	assert(plist != NULL);
	free(plist->base);
	plist->base = NULL;
	plist->capacity = 0;
	plist->size = 0;
}

bool SeqlistInc(Seqlist *plist)//����
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
		printf("˳���������%d���ܲ���\n", x);
		return;
	}
	plist->base[plist->size] = x;
	plist->size++;
}

void SeqlistPushFront(Seqlist *plist, ElementType x)//ͷ��
{
	assert(plist != NULL);
	if (IsFull(plist) && !SeqlistInc(plist))
	{
		printf("˳���������%d���ܲ���\n", x);
		return;
	}
	for (size_t i = plist->size; i > 0; i--)
	{
		plist->base[i] = plist->base[i - 1];
	}
	plist->base[0] = x;
	plist->size++;
}

void SeqlistShow(Seqlist *plist)//��ʾ
{
	assert(plist != NULL);
	for (size_t i = 0; i < plist->size; i++)
	{
		printf("%d ", plist->base[i]);
	}
	printf("\n");
}

void SeqlistPopBack(Seqlist *plist)//βɾ
{
	assert(plist != NULL);
	if (IsEmpty(plist))
	{
		printf("����Ϊ�գ��޷�ɾ��\n");
		return;
	}
	plist->size--;
}

void SeqlistPopFront(Seqlist *plist)//ͷɾ
{
	assert(plist != NULL);
	if (IsEmpty(plist))
	{
		printf("����Ϊ�գ��޷�ɾ��\n");
		return;
	}
	for (size_t i = 0; i < plist->size; i++)
	{
		plist->base[i] = plist->base[i + 1];
	}
	plist->size--;
}

void SeqlistInsertPos(Seqlist *plist, int pos, ElementType x)//λ�ò���
{
	assert(plist != NULL);
	if (IsFull(plist))
	{
		printf("˳���������%d���ܲ���\n", x);
		return;
	}
	if ( pos<0 || pos>(int)plist->size)
	{
		printf("�����λ��%d�Ƿ���%d���ܲ���\n",pos,x);
		return;
	}
	for (size_t i = plist->size; i > (size_t) pos; i--)
	{
		plist->base[i] = plist->base[i - 1];
	}
	plist->base[pos] = x;
	plist->size++;
}

void SeqlistInsertVal(Seqlist *plist, ElementType x)//ֵ���룬����ǰ������
{
	assert(plist != NULL);
	qsort(plist->base, plist->size, sizeof(ElementType), cmp);
	if (IsFull(plist) && !SeqlistInc(plist))
	{
		printf("˳���������%d���ܲ���\n", x);
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

void SeqlistEraseBack(Seqlist *plist, int pos)//λ��ɾ��
{
	assert(plist != NULL);
	if (IsEmpty(plist))
	{
		printf("˳���Ϊ�գ�����ɾ����\n");
		return;
	}
	if (pos < 0 || pos > (int)plist->size)
	{
		printf("�����λ��%d�Ƿ�������ɾ��\n",pos);
		return;
	}
	for (size_t i = (size_t)pos; i < plist->size ; i++)
	{
		plist->base[i] = plist->base[i + 1];
	}
	plist->size--;
}

void SeqlistEraseVal(Seqlist *plist, ElementType x)//ֵɾ��
{
	assert(plist != NULL);
	if (IsEmpty(plist))
	{
		printf("����Ϊ�գ��޷�ɾ����\n");
	}
	int pos = SeqlistFind(plist, x);
	if (pos == -1)
	{
		printf("���ݲ����ڣ��޷�ɾ��\n");
		return;
	}
	SeqlistEraseBack(plist, pos);
}

int SeqlistFind(Seqlist *plist, ElementType x)//λ�ò���
{
	assert(plist != NULL);
	if (IsEmpty(plist))
	{
		printf("����Ϊ�գ��޷����ң�\n");
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

void SeqlistLength(Seqlist *plist)//���ݳ���
{
	assert(plist != NULL);
	printf("���ݳ���Ϊ��>%d\n", plist->size);
}

void SeqlistCapacity(Seqlist *plist)//˳�������
{
	assert(plist != NULL);
	printf("˳�������Ϊ��>%d\n", plist->capacity);
}

void SeqlistSort(Seqlist *plist)//������������ʹ��qsort
{
	assert(plist != NULL);
	if (IsEmpty(plist))
	{
		printf("����Ϊ�գ��޷�����!\n");
	}
	qsort(plist->base, plist->size, sizeof(ElementType), cmp);
}

void SeqlistReverse(Seqlist *plist)//���ݵ���
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

void SeqlistFront(Seqlist *plist)//�鿴ͷ������
{
	assert(plist != NULL);
	if (0 == plist->size )
	{
		printf("����Ϊ��\n");
		return;
	}
	printf("ͷ������Ϊ��>%d\n", plist->base[0]);
}

void SeqlistBack(Seqlist *plist)//�鿴β������
{
	assert(plist != NULL);
	if (0 == plist->size)
	{
		printf("����Ϊ��\n");
		return;
	}
	printf("β������Ϊ��>%d\n", plist->base[plist->size - 1]);
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
			printf("���ݲ��ҳɹ���Ϊ��>%d\n", plist->base[mid]);
			return;
		}
	}
	printf("����ʧ�ܣ�����%d������\n", x);
}

void SeqlistEraseAll(Seqlist *plist,ElementType x)//ɾ��ָ��Ԫ��
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


