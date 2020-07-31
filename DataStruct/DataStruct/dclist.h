#ifndef _DCLIST_H_
#define _DCLIST_H_
#include "shared.h"

typedef struct DCListNode
{
	ElementType data;
	struct DCListNode *prev;
	struct DCListNode *next;
}DCListNode;

typedef DCListNode* DCList;

DCListNode *_BuyNode(ElementType v)
{
	DCListNode *_s = (DCListNode *)malloc(sizeof(DCListNode));
	_s->data = v;
	_s->next = _s->prev = _s;
	return _s;
}

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////


void DCListHeadIni(DCList *phead);//�����ʼ��
void DCListHeadPushBack(DCList *phead, ElementType x);//β�巨
void DCListHeadPushFront(DCList *phead, ElementType x);//ͷ�巨
void DCListHeadShow(DCList *phead);//��ʾ����
void DCListHeadPopBack(DCList *phead);//βɾ
void DCListHeadPopFront(DCList *phead);//ͷɾ
void DCListHeadInsertVal(DCList *phead, ElementType x);//���룬����ǰ������
void DCListHeadEraseVal(DCList *phead, ElementType x);//ɾ��
DCListNode* DCListHeadFind(DCList *phead, ElementType x);//��������
size_t DCListHeadLength(DCList *phead);//�󳤶�
void DCListHeadSort(DCList *phead);//��������
void DCListHeadReverse(DCList *phead);//��������
void DCListHeadClear(DCList *phead);//�������
void DCListHeadFront(DCList *phead);//��ͷԪ��
void DCListHeadBack(DCList *phead);//��βԪ��
void DCListHeadEraseAll(DCList *phead, ElementType x);//���������ֵ��������һ����Ԫ��
void DCListHeadDestroy(DCList *phead);


/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////


void DCListIni(DCList *phead);//�����ʼ��
void DCListPushBack(DCList *phead, ElementType x);//β�巨
void DCListPushFront(DCList *phead, ElementType x);//ͷ�巨
void DCListShow(DCList *phead);//��ʾ����
void DCListPopBack(DCList *phead);//βɾ
void DCListPopFront(DCList *phead);//ͷɾ
void DCListInsertVal(DCList *phead, ElementType x);//���룬����ǰ������
void DCListEraseVal(DCList *phead, ElementType x);//ɾ��
DCListNode* DCListFind(DCList *phead, ElementType x);//��������
size_t DCListLength(DCList *phead);//�󳤶�
void DCListSort(DCList *phead);//��������
void DCListReverse(DCList *phead);//��������
void DCListClear(DCList *phead);//�������
void DCListFront(DCList *phead);//��ͷԪ��
void DCListBack(DCList *phead);//��βԪ��
void DCListEraseAll(DCList *phead, ElementType x);//���������ֵ��������һ����Ԫ��
void DCListDestroy(DCList *phead);


//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////



void DCListHeadIni(DCList *phead)//�����ʼ��
{
	*phead = _BuyNode(0);
}

void DCListHeadPushBack(DCList *phead, ElementType x)//β�巨
{
	assert(phead != NULL);
	DCListNode *p = *phead;
	DCListNode *s = _BuyNode(x);
	assert(s != NULL);
	s->prev = p->prev;
	s->next = p;
	s->prev->next = s;
	s->next->prev = s;
}

void DCListHeadPushFront(DCList *phead, ElementType x)//ͷ�巨
{
	assert(phead != NULL);
	DCListNode *p = *phead;
	DCListNode *s = _BuyNode(x);
	assert(s != NULL);
	s->next = p->next;
	s->prev = p;
	s->next->prev = s;
	s->prev->next = s;
}

void DCListHeadShow(DCList *phead)//��ʾ����
{
	assert(phead != NULL);
	DCListNode *p = (*phead)->next;
	while (p != *phead)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	printf("Over.\n");
}

void DCListHeadPopBack(DCList *phead)//βɾ
{
	assert(phead != NULL);
	DCListNode *p = (*phead)->prev;
	if (p != *phead)
	{
		p->prev->next = p->next;
		p->next->prev = p->prev;
		free(p);
	}
}

void DCListHeadPopFront(DCList *phead)//ͷɾ
{
	assert(phead != NULL);
	DCListNode *p = (*phead)->next;
	if (p != *phead)
	{
		p->prev->next = p->next;
		p->next->prev = p->prev;
		free(p);
	}
}

void DCListHeadInsertVal(DCList *phead, ElementType x)//���룬����ǰ������
{
	assert(phead != NULL);
	DCListHeadSort(phead);
	DCListNode *s = _BuyNode(x);
	DCListNode *p = (*phead)->next;
	DCListNode *q = p->next;
	while (p->data < x && p != *phead)
	{
		p = p->next;
	}
	s->next = p;
	s->prev = p->prev;
	s->prev->next = s;
	s->next->prev = s;
}

void DCListHeadEraseVal(DCList *phead, ElementType x)//ɾ��
{
	assert(phead != NULL);
	DCListNode *p = DCListHeadFind(phead, x);
	if (p == NULL)
	{
		return;
	}
	p->prev->next = p->next;
	p->next->prev = p->prev;
	free(p);
}

DCListNode* DCListHeadFind(DCList *phead, ElementType x)//��������
{
	assert(phead != NULL);
	DCListNode *p = (*phead)->next;
	while (p->data != x && p != *phead)
	{
		p = p->next;
	}
	if (p == *phead)
	{
		return NULL;
	}
	return p;
}

size_t DCListHeadLength(DCList *phead)//�󳤶�
{
	assert(phead != NULL);
	size_t count = 0;
	DCListNode *p = (*phead)->next;
	while (p != *phead)
	{
		count++;
		p = p->next;
	}
	return count;
}

void DCListHeadSort(DCList *phead)//��������
{
	assert(phead != NULL);
	if (DCListHeadLength(phead) <= 1)
	{
		return;
	}
	DCListNode *p = (*phead)->next;
	DCListNode *q = p->next;
	p->next = p->prev;
	p->prev->prev = p;
	while (q != *phead)
	{
		p = q;
		q = q->next;
		DCListNode *tmp = (*phead)->next;
		while (p->data > tmp->data && tmp != *phead)
		{
			tmp = tmp->next;
		}
		p->prev = tmp->prev;
		p->next = tmp;
		p->prev->next = p;
		p->next->prev = p;
	}

}

void DCListHeadReverse(DCList *phead)//��������
{
	assert(phead != NULL);
	if (DCListHeadLength(phead) <= 1)
	{
		return;
	}
	DCListNode *p = (*phead)->next;
	DCListNode *q = p->next;
	p->next = p->prev;
	p->prev->prev = p;
	while (q != *phead)
	{
		p = q;
		q = q->next;
		p->prev = *phead;
		p->next = (*phead)->next;
		p->prev->next = p;
		p->next->prev = p;
	}
}

void DCListHeadClear(DCList *phead)//�������
{
	assert(phead != NULL);
	DCListNode *p = (*phead)->next;
	while (p != *phead)
	{
		p->prev->next = p->next;
		p->next->prev = p->prev;
		free(p);
		p = (*phead)->next;
	}
}

void DCListHeadFront(DCList *phead)//��ͷԪ��
{
	assert(phead != NULL);
	DCListNode *p = (*phead)->next;
	if (p != *phead)
	{
		printf("��ͷԪ��Ϊ��%d\n", p->data);
	}
}

void DCListHeadBack(DCList *phead)//��βԪ��
{
	assert(phead != NULL);
	DCListNode *p = (*phead)->prev;
	if (p != *phead)
	{
		printf("��ͷԪ��Ϊ��%d\n", p->data);
	}
}

void DCListHeadEraseAll(DCList *phead, ElementType x)//���������ֵ��������һ����Ԫ��
{
	assert(phead != NULL);
	DCListHeadSort(phead);
	DCListNode *p = (*phead)->next;
	if (p == *phead)
	{
		return;
	}
	while (p->data != x && p != *phead)
	{
		p = p->next;
	}
	while (p->data == x)
	{
		DCListNode *tmp = NULL;;
		p->prev->next = p->next;
		p->next->prev = p->prev;
		tmp = p;
		p = p->next;
		free(tmp);
	}
}

void DCListHeadDestroy(DCList *phead)
{
	assert(phead != NULL);
	DCListHeadClear(phead);
	free(*phead);
}

//void DCListHeadInsertPos(DCListNode *pos, ElementType x)//posΪFind���ҵ���λ�ã�һ������ͷ�ڵ�
//{
//	assert(pos != NULL);
//	DCListNode *p = pos;
//	DCListNode *s = (DCListNode*)malloc(sizeof(DCListNode));
//	s->data = x;
//	s->next = p;
//	s->prev = p->prev;
//	s->prev->next = s;
//	s->next->prev = s;
//}
void DCListErase(DCListNode *pos)//posΪFind���ҵ���λ�ã�һ������ͷ�ڵ�,����ɾ��
{
	assert(pos != NULL);
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
	pos = NULL;
}

/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////


void DCListIni(DCList *phead)//�����ʼ��
{
	*phead = NULL;
}

void DCListPushBack(DCList *phead, ElementType x)//β�巨
{
	assert(phead != NULL);
	if (*phead == NULL)
	{
		*phead = _BuyNode(x);
	}
	else
	{
		DCListNode *p = _BuyNode(x);
		p->next = *phead;
		p->prev = (*phead)->prev;
		p->prev->next = p;
		p->next->prev = p;
	}
}

void DCListPushFront(DCList *phead, ElementType x)//ͷ�巨
{
	assert(phead != NULL);
	if (*phead == NULL)
	{
		*phead = _BuyNode(x);
	}
	else
	{
		DCListNode *p = _BuyNode(x);
		p->next = *phead;
		p->prev = (*phead)->prev;
		p->prev->next = p;
		p->next->prev = p;
		*phead = p;
	}
}

void DCListShow(DCList *phead)//��ʾ����
{
	assert(phead != NULL);
	DCListNode *p = *phead;
	if (p == NULL)
	{
		return;
	}
	if (p!=NULL && p->next == *phead)
	{
		printf("%d->Over.\n", p->data);
		return;
	}
	while (p->next != *phead)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	printf("%d->Over.\n", p->data);
}

void DCListPopBack(DCList *phead)//βɾ
{
	assert(phead != NULL);
	DCListNode *p = (*phead)->prev;
	if (p == *phead)
	{
		free(*phead);
		*phead = NULL;
		return;
	}
	p->prev->next = p->next;
	p->next->prev = p->prev;
	free(p);
}

void DCListPopFront(DCList *phead)//ͷɾ
{
	assert(phead != NULL);
	DCListNode *p = *phead;
	if (p->next == *phead)
	{
		free(*phead);
		*phead = NULL;
		return;
	}
	p->next->prev = p->prev;
	p->prev->next = p->next;
	*phead = p->next;
	free(p);
}

void DCListInsertVal(DCList *phead, ElementType x)//���룬����ǰ������
{
	assert(phead != NULL);
	DCListNode *s = _BuyNode(x);
	DCListSort(phead);
	DCListNode *p = *phead,*tmp = *phead;
	DCListNode *q = p->next;
	if (p == q)
	{
		p->next = s;
		p->prev = s;
		s->next = p;
		s->prev = p;
		if (p->data > s->data)
		{
			*phead = s;
		}
		return;
	}
	p = *phead;
	while (s->data > p->data && p->next != *phead)
	{
		p = p->next;
	}
	if (p->next == *phead && s->data > p->data)
	{
		s->next = p->next;
		s->prev = p;
		s->prev->next = s;
		s->next->prev = s;
	}
	else  //(p->next == *phead && s->data < p->data)
	{
		s->next = p;
		s->prev = p->prev;
		s->prev->next = s;
		s->next->prev = s;
		if (p == *phead)
		{
			*phead = s;
		}
	}
}

void DCListEraseVal(DCList *phead, ElementType x)//ɾ��
{
	assert(phead != NULL);
	if (DCListLength(phead) <=0)
	{
		return;
	}
	if (DCListFind(phead, x) == *phead && (*phead)->next == *phead)
	{
		free(*phead);
		*phead = NULL;
		return;
	}
	if (DCListFind(phead, x) == *phead)
	{
		DCListNode *p = *phead;
		*phead = p->next;
		p->next->prev = p->prev;
		p->prev->next = p->next;
		free(p);
		p = NULL;
		return;
	}
	DCListNode *p = DCListFind(phead, x);
	p->next->prev = p->prev;
	p->prev->next = p->next;
	free(p);
	p = NULL;
}

DCListNode* DCListFind(DCList *phead, ElementType x)//��������
{
	assert(phead != NULL);
	if ((*phead)->data == x)
	{
		return *phead;
	}
	DCListNode *p = (*phead)->next;
	while (p != *phead && p->data != x)
	{
		p = p->next;
	}
	if (p->data == x)
	{
		return p;
	}
	return NULL;
}

size_t DCListLength(DCList *phead)//�󳤶�
{
	assert(phead != NULL);
	size_t count = 0;
	DCListNode *p = *phead;
	while (*phead !=NULL && p->next != *phead)
	{
		count++;
		p = p->next;
	}
	return count + 1;
}

void DCListSort(DCList *phead)//��������
{
	assert(phead != NULL);
	if (DCListLength(phead) <= 1)
	{
		return;
	}
	DCListNode *p = *phead,*s = *phead;
	DCListNode *tmp = *phead;
	DCListNode *q = p->next;
	DCListNode *r = q->next;
	p->next->next = p;
	p->prev = q;
	if (p->data > q->data)
	{
		*phead = q;
	}
	tmp = *phead;
	while (r != s)
	{
		p = r;
		r = r->next;
		while (p->data > tmp->data && tmp->next != *phead)
		{
			tmp = tmp->next;
		}
		if (tmp->next == *phead && p->data > tmp->data)
		{
			p->next = tmp->next;
			p->prev = tmp;
			p->prev->next = p;
			p->next->prev = p;
		}
		else  //(tmp->next == *phead && p->data < tmp->data)
		{
			p->next = tmp;
			p->prev = tmp->prev;
			p->prev->next = p;
			p->next->prev = p;
			if (tmp == *phead)
			{
				*phead = p;
			}
		}
		tmp = *phead;
	}
}

void DCListReverse(DCList *phead)//��������
{
	assert(phead != NULL);
	if (DCListLength(phead) <= 1)
	{
		return;
	}
	DCListNode *p = *phead, *s = *phead;
	DCListNode *tmp = *phead;
	DCListNode *q = p->next;
	DCListNode *r = q->next;
	p->next->next = p;
	p->prev = q;
	*phead = q;
	while (r != s)
	{
		p = r;
		r = r->next;
		p->next = *phead;
		p->prev = (*phead)->prev;
		p->next->prev = p;
		p->prev->next = p;
		*phead = p;
	}
}

void DCListClear(DCList *phead)//�������
{
	assert(phead != NULL);
	if (*phead == NULL)
	{
		return;
	}
	DCListNode *p = (*phead)->next;
	while (p != *phead)
	{
		p->prev->next = p->next;
		p->next->prev = p->prev;
		free(p);
		p = (*phead)->next;
	}
	free(*phead);
	*phead = NULL;
}

void DCListFront(DCList *phead)//��ͷԪ��
{
	assert(phead != NULL);
	if (*phead != NULL)
	{
		printf("��ͷԪ��Ϊ��%d\n", (*phead)->data);
	}
}

void DCListBack(DCList *phead)//��βԪ��
{
	assert(phead != NULL);
	if (*phead != NULL)
	{
		printf("��βԪ��Ϊ��%d\n", (*phead)->prev->data);
	}
}

void DCListEraseAll(DCList *phead, ElementType x)//���������ֵ��������һ����Ԫ��
{
	assert(phead != NULL);
	DCListSort(phead);
	if (*phead == DCListFind(phead, x))
	{
		DCListNode *p = *phead;
		while (p->data == x)
		{
			*phead = p->next;
			p->prev->next = p->next;
			p->next->prev = p->prev;
			free(p);
			p = NULL;
			p = *phead;
		}
	}
	else
	{
		DCListNode *p = DCListFind(phead, x);
		while (p->data == x)
		{
			DCListNode *s = p->next;
			p->prev->next = p->next;
			p->next->prev = p->prev;
			free(p);
			p = NULL;
			p = s;
		}
	}
}

void DCListDestroy(DCList *phead)
{
	assert(phead != NULL);
	if (*phead == NULL)
	{
		return;
	}
	DCListNode *p = (*phead)->next;
	while (p != *phead)
	{
		p->prev->next = p->next;
		p->next->prev = p->prev;
		free(p);
		p = (*phead)->next;
	}
	free(*phead);
}



/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////



#endif // !_DCLIST_H_
