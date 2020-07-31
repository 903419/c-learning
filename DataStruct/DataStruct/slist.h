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
void SlistIni(SList *phead);//链表初始化
void SlistShow(SList *phead);//显示链表
void SlistPushBack(SList *phead,ElementType x);//尾插法
void SlistPushFront(SList *phead, ElementType x);//头插法
void SlistPopBack(SList *phead);//尾删
void SlistPopFront(SList *phead);//头删
void SlistInsertVal(SList *phead, ElementType x);//插入，插入前先排序
void SlistEraseVal(SList *phead, ElementType x);//删除
SlistNode* SlistFind(SList *phead, ElementType x);//查找数据
size_t SlistLength(SList *phead);//求长度
void SlistSort(SList *phead);//链表排序
void SlistReverse(SList *phead);//链表逆置
void SlistClear(SList *phead);//清空链表
ElementType SlistFront(SList *phead);//表头元素
ElementType SlistBack(SList *phead);//表尾元素
void SlistEraseAll(SList *phead, ElementType x);//清除和输入值在链表中一样的元素
void SlistDestroy(SList *phead);


/////////////////////////////////////////////////////////////////////上为无头节点
/////////////////////////////////////////////////////////////////////下为有头节点


void SlistIniHead(SList *phead);//头节点初始化
void SlistHeadPushFront(SList *phead, ElementType x);//头插
void SlistHeadPushBack(SList *phead, ElementType x);//尾插
void SlistHeadShow(SList *phead);//显示
void SlistHeadPopBack(SList *phead);//尾删
void SlistHeadPopFront(SList *phead);//头删
void SlistHeadInsertVal(SList *phead, ElementType x);//值插入，插入前先排序
void SlistHeadEraseVal(SList *phead, ElementType x);//值删除
SlistNode *SlistHeadFind(SList *phead, ElementType x);//找数据，成功返回位置
size_t SlistHeadLength(SList *phead);//链表有多长
void SlistHeadSort(SList *phead);//链表排序
void SlistHeadReverse(SList *phead);//链表逆置
void SlistHeadClear(SList *phead);//清空链表
void SlistHeadFront(SList *phead);//表头元素
void SlistHeadBack(SList *phead);//表尾元素
void SlistHeadEraseAll(SList *phead, ElementType x);//删除和输入值相同的元素
bool SlistIsEmpty(SList *phead);
void SlistHeadDestroy(SList *phead);//摧毁链表


///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

SlistNode *BuySlistNode(ElementType x)
{
	SlistNode *s = (SlistNode *)malloc(sizeof(SlistNode));
	s->data = x;
	s->next = NULL;
	return s;
}

void SlistIni(SList *phead)//链表初始化
{
	assert(phead != NULL);
	*phead = NULL;
}

void SlistFree(SList *phead)//释放链表
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

void SlistShow(SList *phead)//显示链表
{
	SlistNode *p = *phead;//无头节点
	while (p != NULL)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	printf("OVER\n");
}

void SlistPushBack(SList *phead,ElementType x)//尾插法
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
		while (p->next != NULL)//找到最后一个节点
		{
			p = p->next;
		}
		p->next = s;
	}
}

void SlistPushFront(SList *phead, ElementType x)//头插法
{
	assert(phead != NULL);
	SlistNode *p = (SlistNode *)malloc(sizeof(SlistNode *)) ;
	assert(p!= NULL);
	p->data = x;
	p->next = *phead;
	*phead = p;

}

void SlistPopBack(SList *phead)//尾删
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
		if (prev == NULL)//此时只有一个节点
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

void SlistPopFront(SList *phead)//头删
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

void SlistEraseVal(SList *phead, ElementType x)//删除
{
	assert(phead != NULL);
	SlistNode *p = SlistFind(phead, x);
	if (p == NULL)
	{
		printf("输出不存在，无法删除!\n");
		return;
	}
	SlistNode *prev = *phead;
	while (prev != p && prev->next != p)//条件为前驱不等p，前驱的下一个不等于p，若等于，可定位前驱
	{
		prev = prev->next;
	}
	if (prev == p)//该数就为第一个节点
	{
		*phead = p->next;
	}
	else //不为第一个点
	{
		prev->next = p->next;
	}
	free(p);
}

SlistNode* SlistFind(SList *phead, ElementType x)//查找数据
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

size_t SlistLength(SList *phead)//求长度
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

void SlistSort(SList *phead)//链表排序
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

void SlistClear(SList *phead)//清空链表
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

ElementType SlistFront(SList *phead)//表头元素
{
	assert(phead != NULL);
	//printf("表头元素为：>%d\n", (*phead)->data);
	return (*phead)->data;
}

ElementType SlistBack(SList *phead)//表尾元素
{
	assert(phead != NULL);
	SlistNode *p = *phead;
	while (p->next != NULL)
	{
		p = p->next;
	}
	//printf("表尾元素为：>%d\n", p->data);
	return p->data;
}

void SlistEraseAll(SList *phead, ElementType x)//清除和输入值在链表中一样的元素
{
	assert(phead != NULL);
	SlistSort(phead);//先排序
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
	assert(pos != NULL);//pos为有效参数
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

void SlistHeadPushFront(SList *phead, ElementType x)//有头节点，头插
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

void SlistHeadPushBack(SList *phead, ElementType x)//有头节点，尾插
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
		printf("数据不存在，无法删除！\n");
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

void SlistHeadReverse(SList *phead)//逆置
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
		printf("表头元素为：>%d\n", p->data);
	}
}

void SlistHeadBack(SList *phead)
{
	assert(phead != NULL);
	SlistNode *p = (*phead)->next;
	if (p == NULL)
	{
		printf("表为空\n");
		return;
	}
	while (p->next != NULL)
	{
		p = p->next;
	}
	printf("表尾元素为：>%d\n", p->data);
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

void SlistHeadDestroy(SList *phead)//摧毁
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
