#ifndef _SCLIST_H_
#define _SCLIST_H_
#include "shared.h"

typedef struct SCListNode
{
	ElementType data;
	struct SCListNode *next;
}SCListNode;

typedef SCListNode* SCList;

SCListNode *_BuyNode(ElementType v)
{
	SCListNode *_s = (SCListNode *)malloc(sizeof(SCListNode));
	_s->data = v;
	_s->next = _s;
	return _s;
}


////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////


void SCListIni(SCList *phead);//�����ʼ��
void SCListPushBack(SCList *phead, ElementType x);//β�巨
void SCListPushFront(SCList *phead, ElementType x);//ͷ�巨
void SCListShow(SCList *phead);//��ʾ����
void SCListPopBack(SCList *phead);//βɾ
void SCListPopFront(SCList *phead);//ͷɾ
void SCListInsertVal(SCList *phead, ElementType x);//���룬����ǰ������
void SCListEraseVal(SCList *phead, ElementType x);//ɾ��
SCListNode* SCListFind(SCList *phead, ElementType x);//��������
size_t SCListLength(SCList *phead);//�󳤶�
void SCListSort(SCList *phead);//��������
void SCListReverse(SCList *phead);//��������
void SCListClear(SCList *phead);//�������
void SCListFront(SCList *phead);//��ͷԪ��
void SCListBack(SCList *phead);//��βԪ��
void SCListEraseAll(SCList *phead, ElementType x);//���������ֵ��������һ����Ԫ��
void SCListDestroy(SCList *phead);


////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////


void SCListHeadIni(SCList *phead);//�����ʼ��
void SCListHeadPushBack(SCList *phead, ElementType x);//β�巨
void SCListHeadPushFront(SCList *phead, ElementType x);//ͷ�巨
void SCListHeadShow(SCList *phead);//��ʾ����
void SCListHeadPopBack(SCList *phead);//βɾ
void SCListHeadPopFront(SCList *phead);//ͷɾ
void SCListHeadInsertVal(SCList *phead, ElementType x);//���룬����ǰ������
void SCListHeadEraseVal(SCList *phead, ElementType x);//ɾ��
SCListNode* SCListHeadFind(SCList *phead, ElementType x);//��������
size_t SCListHeadLength(SCList *phead);//�󳤶�
void SCListHeadSort(SCList *phead);//��������
void SCListHeadReverse(SCList *phead);//��������
void SCListHeadClear(SCList *phead);//�������
void SCListHeadFront(SCList *phead);//��ͷԪ��
void SCListHeadBack(SCList *phead);//��βԪ��
void SCListHeadEraseAll(SCList *phead, ElementType x);//���������ֵ��������һ����Ԫ��
void SCListHeadDestroy(SCList *phead);


////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////


void SCListIni(SCList *phead)//�����ʼ��
{
	assert(phead != NULL);
	*phead = NULL;
}

void SCListPushBack(SCList *phead, ElementType x)//β�巨
{
	assert(phead != NULL);
	SCListNode *p = (SCListNode *)malloc(sizeof(SCListNode));
	SCListNode *q = NULL;
	p->data = x;
	if (*phead == NULL)
	{
		*phead = p;
		(*phead)->next = *phead;
	}
	else
	{
		q = *phead;
		while (q->next != *phead)
		{
			q = q->next;
		}
		q->next = p;
		p->next = *phead;
	}
}

void SCListPushFront(SCList *phead, ElementType x)//ͷ��
{
	assert(phead != NULL);
	SCListNode *p = (SCListNode *)malloc(sizeof(SCListNode));
	SCListNode *q = NULL;
	p->data = x;
	if (*phead == NULL)
	{
		*phead = p;
		(*phead)->next = *phead;
	}
	else
	{
		q = *phead;
		while (q->next != *phead)
		{
			q = q->next;
		}
		p->next = *phead;
		*phead = p;
		q->next = p;
	}
}

void SCListShow(SCList *phead)
{
	assert(phead != NULL);
	SCListNode *p = *phead;
	while (p != NULL && p->next != *phead)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	if (p != NULL)
	{

		printf("%d->over\n",p->data);
	}
}

void SCListPopBack(SCList *phead)//βɾ
{
	assert(phead != NULL);
	if ((*phead)->next == *phead)
	{
		free(*phead);
		*phead = NULL;
	}
	else
	{
		SCListNode *p = *phead;
		SCListNode *prev = p;
		while (p->next != *phead)
		{
			prev = p;
			p = p->next;
		}
		prev->next = *phead;
		free(p);
	}
}

void SCListPopFront(SCList *phead)//ͷɾ
{
	assert(phead != NULL);
	if ((*phead)->next == *phead)
	{
		free(*phead);
		*phead = NULL;
	}
	else
	{
		SCListNode *p = *phead;
		SCListNode *q = p->next;
		while (p->next != *phead)
		{
			p = p->next;
		}
		free(*phead);
		*phead = q;
		p->next = q;
	}
}

void SCListInsertVal(SCList *phead, ElementType x)//���룬����ǰ������
{
	assert(phead != NULL);
	//SCListNode *p = (*phead)->next;
	//SCListNode *prev = NULL;
	//while (p != *phead && x > p->data)
	//{
	//	prev = p;
	//	p = p->next;
	//}
	//SCListNode *s = _BuyNode(x);
	//if (prev == NULL)
	//{
	//}
	
	SCListSort(phead);
	SCListNode *s = *phead;
	while (s->next != *phead)
	{
		s = s->next;
	}
	s->next = NULL;
	SCListNode *p = (SCListNode *)malloc(sizeof(SCListNode));
	p->data = x;
	SCListNode *prev = NULL;
	s = *phead;
	while (s != NULL && s->data < x)
	{
		prev = s;
		s = s->next;
	}
	if (prev == NULL)
	{
		p->next = *phead;
		*phead = p;
	}
	else
	{
		prev->next = p;
		p->next = s;
	}
	s = *phead;
	while (s->next != NULL)
	{
		s = s->next;
	}
	s->next = *phead;


}

void SCListEraseVal(SCList *phead, ElementType x)//ɾ��
{
	assert(phead != NULL);
	if (SCListFind(phead, x) == NULL)
	{
		printf("���ݲ����ڣ��޷�ɾ����\n");
		return;
	}
	SCListNode *s = *phead;
	while (s->next != *phead)
	{
		s = s->next;
	}
	s->next = NULL;
	SCListNode *p = *phead, *prev = NULL;
	while (p->data != x)
	{
		prev = p;
		p = p->next;
	}
	if (prev == NULL)
	{
		*phead = p->next;
		free(p);
	}
	else
	{
		prev->next = p->next;
		free(p);
	}
	s = *phead;
	while (s != NULL && s->next != NULL)
	{
		s = s->next;
	}
	if (s != NULL)
	{
		s->next = *phead;
	}
}

SCListNode* SCListFind(SCList *phead, ElementType x)//��������
{
	assert(phead != NULL);
	SCListNode *p = *phead;
	while (p->next != *phead)
	{
		if (p->data == x)
		{
			return p;
		}
		p = p->next;
	}
	if (p->data == x)
	{
		return p;
	}
	return NULL;
}

size_t SCListLength(SCList *phead)//�󳤶�
{
	assert(phead != NULL);
	SCListNode *p = *phead;
	size_t count = 0;
	while (p->next != *phead)
	{
		count++;
		p = p->next;
	}
	if (p != NULL)
	{
		count++;
	}
	return count;
}

void SCListSort(SCList *phead)//��������
{
	assert(phead != NULL);
	if (1 >= SCListLength(phead))
	{
		return;
	}
	SCListNode *p = *phead, *tmp = *phead, *prev=NULL;
	SCListNode *q = p->next;
	p->next = p;
	SCListNode *s = *phead;//�������¼�ʼ��ͷ�ڵ㣬q�����ߣ����������ֹͣ��
	while (q != s)
	{
		p = q;
		q = q->next;
		while (p->data > tmp->data && tmp->next !=*phead)
		{
			prev = tmp;
			tmp = tmp->next;
		}
		if (prev == NULL)//ǰ��Ϊ�գ��п�����ֻ��һ���ڵ�
		{
			if (p->data > tmp->data)//��ͷ�ڵ�󣬷��ں��
			{
				tmp->next = p;
				p->next = tmp;
			}
			else//��ͷ�ڵ�С��Ҫ����ͷ�ڵ�
			{
				p->next = *phead;
				while (tmp->next != *phead)
				{
					tmp = tmp->next;
				}
				tmp->next = p;
				*phead = p;
			}
		}
		else//ǰ����Ϊ�գ��п�����������󣬷���ĩβ���п��������м�
		{
			if (p->data > tmp->data)//��ĩβ
			{
				p->next = tmp->next;
				tmp->next = p;
			}
			else//���м�
			{
				p->next = prev->next;
				prev->next = p;
			}
		}
		tmp = *phead;
		prev = NULL;
	}


	//SCListNode *p = *phead, *tmp = *phead, *prev=NULL;
	//SCListNode *q = p->next;
	//SCListNode *s = *phead;
	//while (s->next != *phead)
	//{
	//	s = s->next;
	//}
	//s->next = NULL;
	//p->next = NULL;
	//while (q != NULL)
	//{
	//	p = q;
	//	q = q->next;
	//	while (tmp != NULL && p->data > tmp->data)
	//	{
	//		prev = tmp;
	//		tmp = tmp->next;
	//	}
	//	if (prev == NULL)
	//	{
	//		p->next = *phead;
	//		*phead = p;
	//	}
	//	else
	//	{
	//		p->next = prev->next;
	//		prev->next = p;
	//	}
	//	tmp = *phead;
	//	prev = NULL;
	//}
	//s = *phead;
	//while (s->next != NULL)
	//{
	//	s = s->next;
	//}
	//s->next = *phead;



}

void SCListReverse(SCList *phead)//��������
{
	assert(phead != NULL);
	if (1 >= SCListLength(phead))
	{
		return;
	}
	SCListNode *s = *phead;
	while (s->next != *phead)
	{
		s = s->next;
	}
	s->next = NULL;
	SCListNode *p = *phead;
	SCListNode *q = p->next;
	p->next = NULL;
	while (q != NULL)
	{
		p = q;
		q = q->next;
		p->next = *phead;
		*phead = p;
	}
	s = *phead;
	while (s->next != NULL)
	{
		s = s->next;
	}
	s->next = *phead;
}

void SCListClear(SCList *phead)//�������
{
	assert(phead != NULL);
	if (*phead == NULL)
	{
		return;
	}
	SCListNode *p = *phead;
	SCListNode *prev = p;
	while (p->next != *phead)
	{
		prev = p;
		p = p->next;
		free(prev);
	}
	free(p);

}

void SCListFront(SCList *phead)//��ͷԪ��
{
	assert(phead != NULL);
	if (SCListLength(phead) <= 0)
	{
		return;
	}
	printf("��ͷԪ��Ϊ��%d\n", (*phead)->data);
}

void SCListBack(SCList *phead)//��βԪ��
{
	assert(phead != NULL);
	if (SCListLength(phead) <= 0)
	{
		return;
	}
	SCListNode *p = *phead;
	while (p->next != *phead)
	{
		p = p->next;
	}
	printf("��βԪ��Ϊ��%d\n", p->data);
}

void SCListEraseAll(SCList *phead, ElementType x)//���������ֵ��������һ����Ԫ��
{
	assert(phead != NULL);
	if (SCListLength(phead) <= 0)
	{
		return;
	}
	SCListSort(phead);
	SCListNode *s = *phead;
	while (s->next != *phead)
	{
		s = s->next;
	}
	s->next = NULL;
	SCListNode *p = *phead, *tmp = *phead, *prev = NULL;
	while (p != SCListFind(phead, x))
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
	{
		*phead = p;
	}
	else
	{
		prev->next = p;
	}
	/*if (p == SCListFind(phead, x))
	{
		while (p != NULL && p->data == x)
		{
			prev = p;
			p = p->next;
			free(prev);
		}
		*phead = p;
	}
	else
	{
		p = SCListFind(phead, x);
		while (tmp->next != p)
		{
			tmp = tmp->next;
		}
		p = SCListFind(phead, x);
		while (p != NULL && p->data == x)
		{
			prev = p;
			p = p->next;
			free(prev);
		}
		tmp->next = p;
	}*/
	s = *phead;
	while (s != NULL && s->next != NULL)
	{
		s = s->next;
	}
	if (s != NULL)
	{
		s->next = *phead;
	}
}

void SCListDestroy(SCList *phead)
{
	assert(phead != NULL);
	if (*phead == NULL)
	{
		return;
	}
	SCListNode *p = *phead;
	SCListNode *prev = p;
	while (p->next != *phead)
	{
		prev = p;
		p = p->next;
		free(prev);
	}
	free(p);
}


////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////


void SCListHeadIni(SCList *phead)//�����ʼ��
{
	*phead = _BuyNode(0);
	(*phead)->next = *phead;
}

void SCListHeadPushBack(SCList *phead, ElementType x)//β�巨
{
	assert(phead != NULL);
	SCListNode *p = _BuyNode(x);
	assert(p != NULL);
	SCListNode *head = (*phead)->next;
	while (head->next != *phead)
	{
		head = head->next;
	}
	head->next = p;
	p->next = *phead;
}

void SCListHeadPushFront(SCList *phead, ElementType x)//ͷ�巨
{
	assert(phead != NULL);
	SCListNode *p = _BuyNode(x);
	assert(p != NULL);
	SCListNode *head = *phead;
	if (head->next != *phead)
	{
		p->next = (*phead)->next;
		(*phead)->next = p;
	}
	else
	{
		p->next = *phead;
		(*phead)->next = p;
	}
}

void SCListHeadShow(SCList *phead)//��ʾ����
{
	assert(phead != NULL);
	SCListNode *p = (*phead)->next;
	while (p != *phead && p!=NULL)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	printf("Over.\n");
}

void SCListHeadPopBack(SCList *phead)//βɾ
{
	assert(phead != NULL);
	SCListNode *p = (*phead)->next, *prev = NULL;
	if (p == *phead)
	{
		return;
	}
	while (p->next != *phead)
	{
		prev = p;
		p = p->next;
	}
	if (prev == NULL)
	{
		(*phead)->next = *phead;
		free(p);
	}
	else 
	{
		prev->next = *phead;
		free(p);
	}
}

void SCListHeadPopFront(SCList *phead)//ͷɾ
{
	assert(phead != NULL);
	SCListNode *p = (*phead)->next;
	if (p == *phead)
	{
		return;
	}
	(*phead)->next = p->next;
	free(p);
}

void SCListHeadInsertVal(SCList *phead, ElementType x)//���룬����ǰ������
{
	assert(phead != NULL);
	SCListHeadSort(phead);
	SCListNode *s = _BuyNode(x);
	SCListNode *p = (*phead)->next, *prev = NULL;
	while (p != *phead && p->data < x)
	{
		prev = p;
		p = p->next;
	}
	if (prev == NULL)
	{
		s->next = (*phead)->next;
		(*phead)->next = s;
	}
	else
	{
		s->next = prev->next;
		prev->next = s;
	}
}

void SCListHeadEraseVal(SCList *phead, ElementType x)//ɾ��
{
	assert(phead != NULL);
	SCListNode *p = (*phead)->next, *prev=NULL;
	if (p == *phead)
	{
		return;
	}
	while (p != *phead && p->data != x)
	{
		prev = p;
		p = p->next;
	}
	if (prev == NULL)
	{
		(*phead)->next = p->next;
		free(p);
	}
	else
	{
		prev->next = p->next;
		free(p);
	}

	//while (p->data != x && p->next != *phead)
	//{
	//	prev = p;
	//	p = p->next;
	//}
	//if (prev == NULL && p->data == x )
	//{
	//	(*phead)->next = p->next;
	//	free(p);
	//}
	//else
	//{
	//	if (p->data == x)
	//	{
	//		prev->next = p->next;
	//		free(p);
	//	}
	//}
}

SCListNode* SCListHeadFind(SCList *phead, ElementType x)//��������
{
	assert(phead != NULL);
	SCListNode *p = (*phead)->next;
	while (p != *phead)
	{
		if (p->data == x)
		{
			return p;
		}
		p = p->next;
	}
	return NULL;
}

size_t SCListHeadLength(SCList *phead)//�󳤶�
{
	assert(phead != NULL);
	SCListNode *p = (*phead)->next;
	size_t count = 0;
	while (p != *phead)
	{
		count++;
		p = p->next;
	}
	return count;
}

void SCListHeadSort(SCList *phead)//��������
{
	assert(phead != NULL);
	if (SCListLength(phead) <= 1)
	{
		return;
	}
	SCListNode *p = (*phead)->next,*tmp= (*phead)->next,*prev=NULL;
	SCListNode *q = p->next;
	p->next = *phead;
	while (q != *phead)
	{
		p = q;
		q = q->next;
		while (tmp != *phead && p->data > tmp->data)
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
		}
		tmp = (*phead)->next;
		prev = NULL;
	}
}

void SCListHeadReverse(SCList *phead)//��������
{
	assert(phead != NULL);
	if (SCListLength(phead) <= 1)
	{
		return;
	}
	SCListNode *p = (*phead)->next;
	SCListNode *q = p->next;
	p->next = *phead;
	while (q != *phead)
	{
		p = q;
		q = q->next;
		p->next = (*phead)->next;
		(*phead)->next = p;
	}
}

void SCListHeadClear(SCList *phead)//�������
{
	assert(phead != NULL);
	SCListNode *p = (*phead)->next,*prev = NULL;
	while (p != *phead)
	{
		prev = p;
		p = p->next;
		free(prev);
		prev = NULL;
	}
	(*phead)->next = *phead;
}

void SCListHeadFront(SCList *phead)//��ͷԪ��
{
	assert(phead != NULL);
	if (SCListLength(phead) <= 0)
	{
		return;
	}
	SCListNode *p = (*phead)->next;
	if (p != *phead)
	{
		printf("��ͷԪ��Ϊ��>%d\n", p->data);
	}
}

void SCListHeadBack(SCList *phead)//��βԪ��
{
	assert(phead != NULL);
	if (SCListLength(phead) <= 0)
	{
		return;
	}
	SCListNode *p = (*phead)->next;
	while(p->next != *phead)
	{
		p = p->next;
	}
	printf("��βԪ��Ϊ��>%d\n", p->data);
}

void SCListHeadEraseAll(SCList *phead, ElementType x)//���������ֵ��������һ����Ԫ��
{
	assert(phead != NULL);
	SCListHeadSort(phead);
	SCListNode *p = (*phead)->next, *prev = NULL,*q=NULL;
	SCListNode *s = SCListHeadFind(phead, x);
	while (p != s)
	{
		prev = p;
		p = p->next;
	}
	while (p != *phead && p->data == x)
	{
		q = p;
		p = p->next;
		free(q);
	}
	if (prev == NULL)
	{
		(*phead)->next = p;
	}
	else
	{
		prev->next = p;
	}
}

void SCListHeadDestroy(SCList *phead)
{
	assert(phead != NULL);
	SCListHeadClear(phead);
	free(*phead);
	*phead = NULL;
}


#endif // !_SCLIST_H_
