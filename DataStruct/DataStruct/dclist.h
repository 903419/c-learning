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


void DCListHeadIni(DCList *phead);//链表初始化
void DCListHeadPushBack(DCList *phead, ElementType x);//尾插法
void DCListHeadPushFront(DCList *phead, ElementType x);//头插法
void DCListHeadShow(DCList *phead);//显示链表
void DCListHeadPopBack(DCList *phead);//尾删
void DCListHeadPopFront(DCList *phead);//头删
void DCListHeadInsertVal(DCList *phead, ElementType x);//插入，插入前先排序
void DCListHeadEraseVal(DCList *phead, ElementType x);//删除
DCListNode* DCListHeadFind(DCList *phead, ElementType x);//查找数据
size_t DCListHeadLength(DCList *phead);//求长度
void DCListHeadSort(DCList *phead);//链表排序
void DCListHeadReverse(DCList *phead);//链表逆置
void DCListHeadClear(DCList *phead);//清空链表
void DCListHeadFront(DCList *phead);//表头元素
void DCListHeadBack(DCList *phead);//表尾元素
void DCListHeadEraseAll(DCList *phead, ElementType x);//清除和输入值在链表中一样的元素
void DCListHeadDestroy(DCList *phead);


/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////


void DCListIni(DCList *phead);//链表初始化
void DCListPushBack(DCList *phead, ElementType x);//尾插法
void DCListPushFront(DCList *phead, ElementType x);//头插法
void DCListShow(DCList *phead);//显示链表
void DCListPopBack(DCList *phead);//尾删
void DCListPopFront(DCList *phead);//头删
void DCListInsertVal(DCList *phead, ElementType x);//插入，插入前先排序
void DCListEraseVal(DCList *phead, ElementType x);//删除
DCListNode* DCListFind(DCList *phead, ElementType x);//查找数据
size_t DCListLength(DCList *phead);//求长度
void DCListSort(DCList *phead);//链表排序
void DCListReverse(DCList *phead);//链表逆置
void DCListClear(DCList *phead);//清空链表
void DCListFront(DCList *phead);//表头元素
void DCListBack(DCList *phead);//表尾元素
void DCListEraseAll(DCList *phead, ElementType x);//清除和输入值在链表中一样的元素
void DCListDestroy(DCList *phead);


//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////



void DCListHeadIni(DCList *phead)//链表初始化
{
	*phead = _BuyNode(0);
}

void DCListHeadPushBack(DCList *phead, ElementType x)//尾插法
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

void DCListHeadPushFront(DCList *phead, ElementType x)//头插法
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

void DCListHeadShow(DCList *phead)//显示链表
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

void DCListHeadPopBack(DCList *phead)//尾删
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

void DCListHeadPopFront(DCList *phead)//头删
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

void DCListHeadInsertVal(DCList *phead, ElementType x)//插入，插入前先排序
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

void DCListHeadEraseVal(DCList *phead, ElementType x)//删除
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

DCListNode* DCListHeadFind(DCList *phead, ElementType x)//查找数据
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

size_t DCListHeadLength(DCList *phead)//求长度
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

void DCListHeadSort(DCList *phead)//链表排序
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

void DCListHeadReverse(DCList *phead)//链表逆置
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

void DCListHeadClear(DCList *phead)//清空链表
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

void DCListHeadFront(DCList *phead)//表头元素
{
	assert(phead != NULL);
	DCListNode *p = (*phead)->next;
	if (p != *phead)
	{
		printf("表头元素为：%d\n", p->data);
	}
}

void DCListHeadBack(DCList *phead)//表尾元素
{
	assert(phead != NULL);
	DCListNode *p = (*phead)->prev;
	if (p != *phead)
	{
		printf("表头元素为：%d\n", p->data);
	}
}

void DCListHeadEraseAll(DCList *phead, ElementType x)//清除和输入值在链表中一样的元素
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

//void DCListHeadInsertPos(DCListNode *pos, ElementType x)//pos为Find查找到的位置，一定不是头节点
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
void DCListErase(DCListNode *pos)//pos为Find查找到的位置，一定不是头节点,可以删除
{
	assert(pos != NULL);
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
	pos = NULL;
}

/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////


void DCListIni(DCList *phead)//链表初始化
{
	*phead = NULL;
}

void DCListPushBack(DCList *phead, ElementType x)//尾插法
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

void DCListPushFront(DCList *phead, ElementType x)//头插法
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

void DCListShow(DCList *phead)//显示链表
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

void DCListPopBack(DCList *phead)//尾删
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

void DCListPopFront(DCList *phead)//头删
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

void DCListInsertVal(DCList *phead, ElementType x)//插入，插入前先排序
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

void DCListEraseVal(DCList *phead, ElementType x)//删除
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

DCListNode* DCListFind(DCList *phead, ElementType x)//查找数据
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

size_t DCListLength(DCList *phead)//求长度
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

void DCListSort(DCList *phead)//链表排序
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

void DCListReverse(DCList *phead)//链表逆置
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

void DCListClear(DCList *phead)//清空链表
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

void DCListFront(DCList *phead)//表头元素
{
	assert(phead != NULL);
	if (*phead != NULL)
	{
		printf("表头元素为：%d\n", (*phead)->data);
	}
}

void DCListBack(DCList *phead)//表尾元素
{
	assert(phead != NULL);
	if (*phead != NULL)
	{
		printf("表尾元素为：%d\n", (*phead)->prev->data);
	}
}

void DCListEraseAll(DCList *phead, ElementType x)//清除和输入值在链表中一样的元素
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
