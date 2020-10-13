#ifndef _SLIST_H_
#define _SLIST_H_

#include "shared.h"

typedef struct SlistNode
{
	ElementType data;
	struct SlistNode *next;
}SlistNode;


////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////


typedef SlistNode* SList;
void SlistIni(SList *phead);//�����ʼ��
void SlistShow(SList *phead);//��ʾ����
void SlistPushBack(SList *phead,ElementType x);//β�巨
void SlistPushFront(SList *phead, ElementType x);//ͷ�巨
void SlistPopBack(SList *phead);//βɾ
void SlistPopFront(SList *phead);//ͷɾ
void SlistInsertVal(SList *phead, ElementType x);//���룬����ǰ������
void SlistEraseVal(SList *phead, ElementType x);//ɾ��
SlistNode* SlistFind(SList *phead, ElementType x);//��������
size_t SlistLength(SList *phead);//�󳤶�
void SlistSort(SList *phead);//��������
void SlistReverse(SList *phead);//��������
void SlistClear(SList *phead);//�������
ElementType SlistFront(SList *phead);//��ͷԪ��
ElementType SlistBack(SList *phead);//��βԪ��
void SlistEraseAll(SList *phead, ElementType x);//���������ֵ��������һ����Ԫ��
void SlistDestroy(SList *phead);


/////////////////////////////////////////////////////////////////////��Ϊ��ͷ�ڵ�
/////////////////////////////////////////////////////////////////////��Ϊ��ͷ�ڵ�


void SlistIniHead(SList *phead);//ͷ�ڵ��ʼ��
void SlistHeadPushFront(SList *phead, ElementType x);//ͷ��
void SlistHeadPushBack(SList *phead, ElementType x);//β��
void SlistHeadShow(SList *phead);//��ʾ
void SlistHeadPopBack(SList *phead);//βɾ
void SlistHeadPopFront(SList *phead);//ͷɾ
void SlistHeadInsertVal(SList *phead, ElementType x);//ֵ���룬����ǰ������
void SlistHeadEraseVal(SList *phead, ElementType x);//ֵɾ��
SlistNode *SlistHeadFind(SList *phead, ElementType x);//�����ݣ��ɹ�����λ��
size_t SlistHeadLength(SList *phead);//�����ж೤
void SlistHeadSort(SList *phead);//��������
void SlistHeadReverse(SList *phead);//��������
void SlistHeadClear(SList *phead);//�������
void SlistHeadFront(SList *phead);//��ͷԪ��
void SlistHeadBack(SList *phead);//��βԪ��
void SlistHeadEraseAll(SList *phead, ElementType x);//ɾ��������ֵ��ͬ��Ԫ��
bool SlistIsEmpty(SList *phead);
void SlistHeadDestroy(SList *phead);//�ݻ�����


///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

SlistNode *BuySlistNode(ElementType x)
{
	SlistNode *s = (SlistNode *)malloc(sizeof(SlistNode));
	s->data = x;
	s->next = NULL;
	return s;
}

void SlistIni(SList *phead)//�����ʼ��
{
	assert(phead != NULL);
	*phead = NULL;
}

void SlistFree(SList *phead)//�ͷ�����
{
	assert(phead != NULL);
	SlistNode *p;
	SlistNode *q = *phead;
	while (q != NULL)
	{
		p = q;
		q = p->next;
		free(p);
	}
}

void SlistShow(SList *phead)//��ʾ����
{
	SlistNode *p = *phead;//��ͷ�ڵ�
	while (p != NULL)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	printf("OVER\n");
}

void SlistPushBack(SList *phead,ElementType x)//β�巨
{
	assert(phead != NULL);
	SlistNode *s = (SlistNode *)malloc(sizeof(SlistNode));
	assert(s != NULL);
	s->data = x;
	s->next = NULL;
	SlistNode *p = *phead;
	if (p == NULL)
	{
		*phead = s;
	}
	else
	{
		while (p->next != NULL)//�ҵ����һ���ڵ�
		{
			p = p->next;
		}
		p->next = s;
	}
}

void SlistPushFront(SList *phead, ElementType x)//ͷ�巨
{
	assert(phead != NULL);
	SlistNode *p = (SlistNode *)malloc(sizeof(SlistNode *)) ;
	assert(p!= NULL);
	p->data = x;
	p->next = *phead;
	*phead = p;

}

void SlistPopBack(SList *phead)//βɾ
{
	assert(phead != NULL);
	SlistNode *p = *phead;
	SlistNode *prev = NULL;
	if (p != NULL) {
		while (p->next != NULL)
		{
			prev = p;
			p = p->next;
		}
		if (prev == NULL)//��ʱֻ��һ���ڵ�
		{
			*phead = NULL;
		}
		else
		{
			prev->next = NULL;
		}
		free(p);
	}
}

void SlistPopFront(SList *phead)//ͷɾ
{
	assert(phead != NULL);
	SlistNode *p = *phead;
	if (p != NULL)
	{
		*phead = p->next;
		free(p);
	}
}

void SlistInsertVal(SList *phead, ElementType x)
{
	assert(phead != NULL);
	SlistNode *p = *phead, *prev = NULL;
	while (p != NULL && p->data < x)
	{
		prev = p;
		p = p->next;
	}
	SlistNode *s = (SlistNode *)malloc(sizeof(SlistNode));
	s->data = x;
	if (prev == NULL)
	{
		s->next = p;
		*phead = s;
	}
	else
	{
		prev->next = s;
		s->next = p;
	}
}

void SlistEraseVal(SList *phead, ElementType x)//ɾ��
{
	assert(phead != NULL);
	SlistNode *p = SlistFind(phead, x);
	if (p == NULL)
	{
		printf("��������ڣ��޷�ɾ��!\n");
		return;
	}
	SlistNode *prev = *phead;
	while (prev != p && prev->next != p)//����Ϊǰ������p��ǰ������һ��������p�������ڣ��ɶ�λǰ��
	{
		prev = prev->next;
	}
	if (prev == p)//������Ϊ��һ���ڵ�
	{
		*phead = p->next;
	}
	else //��Ϊ��һ����
	{
		prev->next = p->next;
	}
	free(p);
}

SlistNode* SlistFind(SList *phead, ElementType x)//��������
{
	assert(phead != NULL);
	SlistNode *p = *phead;
	while (p != NULL)
	{
		if (p->data == x)
		{
			return p;
		}
		p = p->next;
	}
	return NULL;
}

size_t SlistLength(SList *phead)//�󳤶�
{
	assert(phead != NULL);
	size_t count = 0;
	SlistNode *p = *phead;
	while(p != NULL)
	{
		count++;
		p = p ->next;
	}
	return count;
}

void SlistSort(SList *phead)//��������
{
#if 0
	assert(phead != NULL);
	SlistNode *p = *phead;
	SlistNode *q = (*phead)->next;
	for (p = *phead; p != NULL; p = p->next)
	{
		for (q = (*phead)->next; q->next != NULL; q = q->next)
		{
			if (cmp(&(q->data), &(q->next->data)) > 0)
			{
				Swap(&(q->data), &(q->next->data));
			}
		}
	}
#endif

	assert(phead != NULL);
	if (SlistLength(phead) <= 1)
	{
		return;
	}
	SlistNode *p = *phead,*tmp=*phead, *prev = NULL;
	SlistNode *q = p->next;
	p->next = NULL;
	while(q != NULL)
	{
		p = q;
		q = q->next;
		while (tmp != NULL && p->data > tmp->data)
		{
			prev = tmp;
			tmp = tmp->next;
		}
		if (prev != NULL)
		{
			p->next = prev->next;
			prev->next = p;
		}
		else
		{
			p->next = *phead;
			*phead = p;
		}
		tmp = *phead;
		prev = NULL;
	}
}

void SlistReverse(SList *phead)
{
	assert(phead != NULL);
	SlistNode *p = *phead;
	SlistNode *q = p->next;
	p->next = NULL;
	while (q != NULL)
	{
		p = q;
		q = q->next;
		p->next = *phead;
		*phead = p;
	}
}

void SlistClear(SList *phead)//�������
{
	assert(phead != NULL);
	SlistNode *p = *phead;
	SlistNode *q = NULL;
	while (p != NULL)
	{
		q = p;
		p = p->next;
		free(q);
	}
}

ElementType SlistFront(SList *phead)//��ͷԪ��
{
	assert(phead != NULL);
	//printf("��ͷԪ��Ϊ��>%d\n", (*phead)->data);
	return (*phead)->data;
}

ElementType SlistBack(SList *phead)//��βԪ��
{
	assert(phead != NULL);
	SlistNode *p = *phead;
	while (p->next != NULL)
	{
		p = p->next;
	}
	//printf("��βԪ��Ϊ��>%d\n", p->data);
	return p->data;
}

void SlistEraseAll(SList *phead, ElementType x)//���������ֵ��������һ����Ԫ��
{
	assert(phead != NULL);
	SlistSort(phead);//������
	SlistNode *p = *phead, *prev = NULL, *tmp = NULL;
	while (p != SlistFind(phead, x))
	{
		prev = p;
		p = p->next;
	}
	while (p != NULL && p->data == x)
	{
		tmp = p;
		p = p->next;
		free(tmp);
	}
	if (prev == NULL)
		*phead = p;
	else
		prev->next = p;
}

bool SlistIsEmpty(SList *phead)
{
	return *phead == NULL;
}

void SlistDestroy(SList *phead)
{
	assert(phead != NULL);
	SlistNode *p;
	SlistNode *q = *phead;
	while (q != NULL)
	{
		p = q;
		q = p->next;
		free(p);
	}
	*phead = NULL;
}

void SlistInsertAfter(SlistNode *pos, ElementType x)
{
	assert(pos != NULL);//posΪ��Ч����
	SlistNode *s = (SlistNode *)malloc(sizeof(SlistNode));
	s->data = x;
	s->next = pos->next;
	pos->next = s;
}

void SlistErasaeAfter(SlistNode *pos)
{
	assert(pos != NULL);
	if (pos->next != NULL)
	{
		free(pos->next);
		pos->next = NULL;
	}
}



/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////


void SlistIniHead(SList *phead)
{
	assert(phead != NULL);
	(*phead) = (SlistNode*)malloc(sizeof(SlistNode));
	(*phead)->next = NULL;
}

void SlistHeadPushFront(SList *phead, ElementType x)//��ͷ�ڵ㣬ͷ��
{
	assert(phead != NULL);
	SlistNode *p = (SlistNode *)malloc(sizeof(SlistNode));
	assert(p != NULL);
	p->data = x;
	SlistNode *q = *phead;
	//if (q->next == NULL)
	//{
	//	q->next = p;
	//	p->next = NULL;
	//	return;
	//}
	p->next = q->next;
	q->next = p;
}

void SlistHeadPushBack(SList *phead, ElementType x)//��ͷ�ڵ㣬β��
{
	assert(phead != NULL);
	SlistNode *q = *phead;
	while (q->next != NULL)
	{
		q = q->next;
	}
	SlistNode *p = (SlistNode *)malloc(sizeof(SlistNode));
	p->data = x;
	p->next = NULL;
	q->next = p;
}

void SlistHeadShow(SList *phead)
{
	assert(phead != NULL);
	SlistNode *p = *phead;
	while (p->next != NULL)
	{
		p = p->next;
		printf("%d->", p->data);
	}
	printf("over.\n");
}

void SlistHeadPopBack(SList *phead)
{
	assert(phead != NULL);
	if ((*phead)->next == NULL)
	{
		return;
	}
	SlistNode *p = (*phead)->next;
	SlistNode *prev = NULL;
	while (p->next != NULL)
	{
		prev = p;
		p = p->next;
	}
	prev->next = NULL;
	free(p);
}

void SlistHeadPopFront(SList *phead)
{
	assert(phead != NULL);
	if ((*phead)->next == NULL)
	{
		return;
	}
	SlistNode *p = (*phead)->next;
	(*phead)->next = p->next;
	free(p);
}

void SlistHeadInsertVal(SList *phead, ElementType x)
{
	assert(phead != NULL);
	SlistHeadSort(phead);
	SlistNode *p = (SlistNode *)malloc(sizeof(SlistNode));
	assert(p != NULL);
	p->data = x;
	SlistNode *q = (*phead)->next,*prev = NULL;
	while (q != NULL && q->data < x)
	{
		prev = q;
		q = q->next;
	}
	if (prev == NULL)
	{
		p->next = (*phead)->next;
		(*phead)->next = p;
	}
	else
	{
		p->next = prev->next;
		prev->next = p;
	}
}

void SlistHeadEraseVal(SList *phead, ElementType x)
{
	assert(phead != NULL);
	SlistNode *p = SlistHeadFind(phead, x);
	if (p == NULL)
	{
		printf("���ݲ����ڣ��޷�ɾ����\n");
		return;
	}
	SlistNode *q = (*phead)->next,*prev;
	if (q == p)
	{
		(*phead)->next = q->next;
		free(q);
		return;
	}
	else
	{
		while (q != NULL)
		{
			prev = q;
			q = q->next;
			if (q == p)
			{
				prev->next = q->next;
				free(q);
				return;
			}
		}
	}
}

SlistNode *SlistHeadFind(SList *phead, ElementType x)
{
	assert(phead != NULL);
	SlistNode *p = (*phead)->next;
	while (p != NULL)
	{
		if (p->data == x)
		{
			return p;
		}
		p = p->next;
	}
	return NULL;
}

size_t SlistHeadLength(SList *phead)
{
	assert(phead != NULL);
	SlistNode *p = (*phead)->next;
	size_t count = 0;
	while (p != NULL)
	{
		count++;
		p = p->next;
	}
	return count;
}

void SlistHeadSort(SList *phead)
{
	assert(phead != NULL);
	SlistNode *tmp = (*phead)->next,*p = (*phead)->next, *prev = NULL;
	SlistNode *q = p->next;
	p->next = NULL;
	while (q != NULL)
	{
		p = q;
		q = q->next;
		while (tmp != NULL && p->data > tmp->data)
		{
			prev = tmp;
			tmp = tmp->next;
		}
		if (prev == NULL)
		{
			p->next = (*phead)->next;
			(*phead)->next = p;
		}
		else
		{
			p->next = prev->next;
			prev->next = p;
			//tmp->next = NULL;
		}
		tmp = (*phead)->next;
		prev = NULL;
	}
}

void SlistHeadReverse(SList *phead)//����
{
	assert(phead != NULL);
	SlistNode *p = (*phead)->next;
	SlistNode *q = p->next;
	p->next = NULL;
	while (q != NULL)
	{
		p = q;
		q = q->next;
		p->next = (*phead)->next;
		(*phead)->next = p;
	}
}

void SlistHeadClear(SList *phead)
{
	assert(phead != NULL);
	SlistNode *p = (*phead)->next;
	SlistNode *prev = NULL;
	while (p != NULL)
	{
		prev = p;
		p = p->next;
		free(prev);
		prev = NULL;
	}
	(*phead)->next = NULL;
}

void SlistHeadFront(SList *phead)
{
	assert(phead != NULL);
	SlistNode *p = (*phead)->next;
	if (p != NULL)
	{
		printf("��ͷԪ��Ϊ��>%d\n", p->data);
	}
}

void SlistHeadBack(SList *phead)
{
	assert(phead != NULL);
	SlistNode *p = (*phead)->next;
	if (p == NULL)
	{
		printf("��Ϊ��\n");
		return;
	}
	while (p->next != NULL)
	{
		p = p->next;
	}
	printf("��βԪ��Ϊ��>%d\n", p->data);
}

void SlistHeadEraseAll(SList *phead, ElementType x)
{
	assert(phead != NULL);
	SlistHeadSort(phead);
	SlistNode *p = (*phead)->next, *tmp = NULL, *prev = *phead;
	while (p != SlistHeadFind(phead, x))
	{
		prev = p;
		p = p->next;
	}
	while (p != NULL && p->data == x)
	{
		tmp = p;
		p = p->next;
		free(tmp);
	}
	prev->next = p;
}

void SlistHeadDestroy(SList *phead)//�ݻ�
{
	assert(phead != NULL);
	SlistNode *p = (*phead)->next;
	SlistNode *prev = NULL;
	while (p != NULL)
	{
		prev = p;
		p = p->next;
		free(prev);
		prev = NULL;
	}
	free(*phead);
}


void SlistReverse(SList *phead)
{
	if (SlistLength(phead) <= 1)
		return;
	SlistNode *p = *phead;
	SlistNode *q = p->next;
	p->next = NULL;
	while (q != NULL)
	{
		p = q;
		q = q->next;
		p->next = *phead;
		*phead = p;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////

#endif // !_SLIST_H_
