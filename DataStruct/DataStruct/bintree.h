#ifndef _BINTREE_H_
#define _BINTREE_H_
#include "shared.h"
#define BinTreeElementType char


typedef struct BinTreeNode
{
	BinTreeElementType data;
	struct BinTreeNode *leftchild;
	struct BinTreeNode *rightchild;

}BinTreeNode;
typedef BinTreeNode* BinTree;

typedef BinTreeNode* LinkQueueElementType;
typedef struct LinkQueueNode
{
	LinkQueueElementType data;
	struct LinkQueueNode *link;
}LinkQueueNode;//链式队列

typedef struct LinkQueue
{
	LinkQueueNode *head;
	LinkQueueNode *tail;
}LinkQueue;
typedef BinTreeNode* LinkStackElementType;
typedef struct LinkStackNode
{
	LinkStackElementType data;
	struct LinkStackNode *next;
}LinkStackNode;

typedef LinkStackNode* LinkStack;


//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////

void LinkQueueInit(LinkQueue *plq)
{
	assert(plq != NULL);
	plq->head = plq->tail = NULL;
}

int LinkQueueIsEmpty(LinkQueue *plq)
{
	if (plq->head == NULL)
	{
		return -1;
	}
	return 0;
}

void LinkQueueEn(LinkQueue *plq, LinkQueueElementType x)
{
	LinkQueueNode *s = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
	s->data = x;
	s->link = NULL;
	if (plq->head == NULL)
	{
		plq->head = plq->tail = s;
	}
	else
	{
		plq->tail->link = s;
		plq->tail = s;
	}
}

void LinkQueueDe(LinkQueue *plq)
{
	assert(plq != NULL);
	if (LinkQueueIsEmpty(plq))
	{
		printf("空队，无法出队！\n");
		return;
	}
	LinkQueueNode *p = plq->head;
	plq->head = p->link;
	free(p);
}

LinkQueueElementType LinkQueueFront(LinkQueue *plq)
{
	assert(plq != NULL);
	assert(!LinkQueueIsEmpty(plq));
	return plq->head->data;
}

LinkQueueElementType LinkQueueBack(LinkQueue *plq)
{
	assert(plq != NULL);
	assert(!LinkQueueIsEmpty(plq));
	return plq->tail->data;
}

void LinkQueueDestroy(LinkQueue *plq)
{
	assert(plq != NULL);
	if (!LinkQueueIsEmpty(plq))
	{
		LinkQueueNode *p = plq->head;
		while (p != NULL)
		{
			plq->head = p->link;
			free(p);
			p = plq->head;
		}
	}
	plq->head = plq->tail = NULL;
}


/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

void LinkStackInit(LinkStack *pst)
{
	assert(pst != NULL);
	*pst = NULL;
}

bool LinkStackIsEmpty(LinkStack *pst)
{
	assert(pst != NULL);
	if (*pst == NULL)
	{
		return true;
	}
	return false;
}

void LinkStackPush(LinkStack *pst, LinkStackElementType x)
{
	assert(pst != NULL);
	LinkStackNode *s = (LinkStackNode *)malloc(sizeof(LinkStackNode));
	s->data = x;
	s->next = *pst;
	*pst = s;
}

void LinkStackPop(LinkStack *pst)
{
	assert(pst != NULL);
	if (*pst != NULL)
	{
		LinkStackNode *s = *pst;
		*pst = s->next;
		free(s);
		s = NULL;
	}
}

LinkStackElementType LinkStackTop(LinkStack *pst)
{
	assert(pst != NULL && *pst != NULL);
	return (*pst)->data;
}

void LinkStackDestroy(LinkStack *pst)
{
	assert(pst != NULL);
	LinkStackNode *s = *pst;
	while (s != NULL)
	{
		*pst = s->next;
		free(s);
		s = *pst;
	}
}


////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////

//二叉树的创建
void BinTreeInit(BinTree *t);
void BinTreeCreate(BinTree *t);
BinTree BinTreeCreate_1();
BinTree BinTreeCreate_2(const char *s, int *i);
//BinTree BinTreeCreate_3(const char *vlr, const char *lvr, int n);
//BinTree BinTreeCreate_4(const char *lvr, const char *lrv, int n);


//二叉树的遍历
void BinTreeVLR(BinTree t);
void BinTreeLVR(BinTree t);
void BinTreeLRV(BinTree t);
void BinTreeVLR_Nor(BinTree t);
void BinTreeLVR_Nor(BinTree t);
void BinTreeLRV_Nor(BinTree t);


//二叉树的算法
void BinTreeLevel(BinTree t);
int BinTreeSize(BinTree t);
int BinTreeHeight(BinTree t);
BinTreeNode* Left(BinTree *p);
BinTreeNode* Right(BinTree *p);
BinTreeNode* BinTreeFind(BinTree t, BinTreeElementType key);
BinTreeNode* BinTreeParent(BinTree t, BinTreeNode *p);
BinTreeNode* BinTreeClone(BinTree t);
bool Equal(BinTree t1, BinTree t2);

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

void BinTreeInit(BinTree *t)
{
	assert(t != NULL);
	*t = NULL;
}

void BinTreeCreate(BinTree *t)
{
	assert(t != NULL);
	BinTreeElementType item;
	scanf("%c", &item);
	if (item == '#')
		*t =NULL;
	else
	{
		BinTreeNode *p = (BinTreeNode *)malloc(sizeof(BinTreeNode));
		p->data = item;
		*t = p;
		BinTreeCreate(&(*t)->leftchild);
		BinTreeCreate(&(*t)->rightchild);
	}
}

BinTree BinTreeCreate_1()
{
	BinTreeElementType item;
	scanf("%c", &item);
	if ('#' == item)
		return NULL;
	else
	{
		BinTreeNode *p = (BinTreeNode *)malloc(sizeof(BinTreeNode));
		p->data = item;
		p->leftchild = BinTreeCreate_1();
		p->rightchild = BinTreeCreate_1();
		return p;
	}
}

BinTree BinTreeCreate_2(const char *s, int *i)
{
	if (s[*i] == '\0' || s[*i] == '#')
		return NULL;
	else
	{
		BinTreeNode *p = (BinTreeNode *)malloc(sizeof(BinTreeNode));
		assert(p != NULL);
		p->data = s[*i];
		(*i)++;
		p->leftchild = BinTreeCreate_2(s,i);
		(*i)++;
		p->rightchild = BinTreeCreate_2(s, i);
		return p;
	}
}

BinTree BinTreeCreate_3(const char *vlr, const char *lvr, int n)
{
	if (n == 0)
		return NULL;
	int k = 0;
	while (vlr[0] != lvr[k])
		k++;
	BinTreeNode *p = (BinTreeNode *)malloc(sizeof(BinTreeNode));
	p->data = vlr[0];
	p->leftchild = BinTreeCreate_3(vlr + 1, lvr, k);
	p->rightchild = BinTreeCreate_3(vlr + k + 1, lvr + k +1, n - k - 1);
	return p;
}

BinTree BinTreeCreate_4(const char *lvr, const char *lrv, int *m, int n)
{
	if (n == 0)
		return NULL;
	
	int k = 0;
	while (lrv[*m-1] != lvr[k])
		k++;
	BinTreeNode *p = (BinTreeNode *)malloc(sizeof(BinTreeNode));
	p->data = lvr[k];
	*m = *m - 1;
	p->rightchild = BinTreeCreate_4(lvr + k + 1, lrv, m, n - k - 1);
	p->leftchild = BinTreeCreate_4(lvr, lrv, m, k);
	return p;
}

void BinTreeVLR(BinTree t)//先序（根左右）
{
	if (t != NULL)
	{
		printf("%c ", t->data);
		BinTreeVLR(t->leftchild);
		BinTreeVLR(t->rightchild);
	}
}

void BinTreeLVR(BinTree t)//中序（左根右）
{
	if (t != NULL)
	{
		BinTreeLVR(t->leftchild);
		printf("%c ", t->data);
		BinTreeLVR(t->rightchild);
	}
}

void BinTreeLRV(BinTree t)//后序（左右根）
{
	if (t != NULL)
	{
		BinTreeLRV(t->leftchild);
		BinTreeLRV(t->rightchild);
		printf("%c ", t->data);
	}
}

void BinTreeLevel(BinTree t)
{
	assert(t != NULL);
	LinkQueue Q;
	LinkQueueInit(&Q);
	LinkQueueEn(&Q, t);
	while (!LinkQueueIsEmpty(&Q))
	{
		BinTreeNode *p = LinkQueueFront(&Q);
		LinkQueueDe(&Q);
		if (p->leftchild != NULL)
			LinkQueueEn(&Q, p->leftchild);
		if (p->rightchild != NULL)
			LinkQueueEn(&Q, p->rightchild);
		printf("%c ", p->data);
	}
	LinkQueueDestroy(&Q);
}

void BinTreeVLR_Nor(BinTree t)
{
	if (t != NULL)
	{
		LinkStack st;
		LinkStackInit(&st);
		LinkStackPush(&st, t);
		printf("VLR_Nor：");
		while (!LinkStackIsEmpty(&st))
		{
			BinTreeNode *s = LinkStackTop(&st);
			LinkStackPop(&st);
			printf("%c ", s->data);
			if (s->rightchild != NULL)
				LinkStackPush(&st, s->rightchild);
			if (s->leftchild != NULL)
				LinkStackPush(&st, s->leftchild);
		}
		printf("\n");
	}
}

void BinTreeLVR_Nor(BinTree t)//先将左一直放入，左要最先出，则保留栈顶，出栈，如果该数的右孩子不为空，则对它入栈
{
	if (t != NULL)
	{
		LinkStack st;
		LinkStackInit(&st);
		printf("LVR_Nor：");
		while (!LinkStackIsEmpty(&st) || t != NULL)
		{
			while (t != NULL)
			{
				LinkStackPush(&st, t);
				t = t->leftchild;
			}
			BinTreeNode *p = LinkStackTop(&st);
			LinkStackPop(&st);
			printf("%c ", p->data);
			if (p->rightchild != NULL)
				t = p->rightchild;
		} 
		printf("\n");
	}
}

void BinTreeLRV_Nor(BinTree t)
{
	if (t != NULL)
	{
		LinkStack st;
		LinkStackInit(&st);
		printf("LRV_Nor：");
		BinTreeNode *prev = NULL;
		do
		{
			while (t != NULL)
			{
				LinkStackPush(&st, t);
				t = t->leftchild;
			}
			BinTreeNode *p = LinkStackTop(&st);//释放该头节点时，要注意该节点的右孩子是否为空，若为空，就释放，不为空，就继续进行入栈
			if (p->rightchild == NULL || p->rightchild == prev)
			{
				LinkStackPop(&st);
				printf("%c ", p->data);
				prev = p;
			}
			else
				t = p->rightchild;
		} while (!LinkStackIsEmpty(&st));
		printf("\n");
	}
}

int BinTreeSize(BinTree t)
{
	if (t == NULL)
		return 0;
	else
		return 1 + BinTreeSize(t->leftchild) + BinTreeSize(t->rightchild);
}

int BinTreeHeight(BinTree t)
{
	if (t == NULL)
		return 0;
	else
	{
		int leftheight = BinTreeHeight(t->leftchild);
		int rightheigth = BinTreeHeight(t->rightchild);
		return (leftheight > rightheigth ? leftheight+1 : rightheigth+1);
	}
}

BinTreeNode* Left(BinTree *p)
{
	if (p == NULL || *p == NULL)
		return NULL;
	return (*p)->leftchild;
}

BinTreeNode* Right(BinTree *p)
{
	if (p == NULL || *p == NULL)
		return NULL;
	return (*p)->rightchild;
}

BinTreeNode* BinTreeFind(BinTree t, BinTreeElementType key)
{
	if (t == NULL || t->data == key)
		return t;
	BinTreeNode *p = BinTreeFind(t->leftchild, key);
	if (p != NULL)
		return p;
	return BinTreeFind(t->rightchild, key);
}

BinTreeNode* BinTreeParent(BinTree t, BinTreeNode *p)
{
	if (p == NULL || t == p)
		return NULL;
	if (t == NULL || t->leftchild == p || t->rightchild == p)
		return t;
	BinTreeNode *s = BinTreeParent(t->leftchild, p);
	if (s != NULL)
		return s;
	return BinTreeParent(t->rightchild, p);
}

BinTreeNode* BinTreeClone(BinTree t)
{
	if (t == NULL)
		return NULL;
	BinTreeNode *p = (BinTreeNode *)malloc(sizeof(BinTreeNode));
	assert(p != NULL);
	p->data = t->data;
	p->leftchild = BinTreeClone(t->leftchild);
	p->rightchild = BinTreeClone(t->rightchild);
	return p;
}

bool Equal(BinTree t1, BinTree t2)
{
	if (t1 == NULL && t2 == NULL)
		return true;
	if ((t1 == NULL && t2 != NULL) || (t1 !=NULL &&t2 == NULL )|| t1->data != t2->data)
		return false;
	bool flag = Equal(t1->leftchild, t2->leftchild);
	if (!flag)
		return false;
	flag = Equal(t1->rightchild, t2->rightchild);
	if (!flag)
		return false;
	return true;
}


#endif // !_BINTREE_H_
