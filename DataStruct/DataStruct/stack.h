#ifndef _STACK_H_
#define _STACK_H_
#include "shared.h"
#define STACK_DEFAULT_SIZE 8

typedef struct SeqStack
{
	ElementType *base;
	size_t capacity;
	int top;
}SeqStack;

typedef struct LinkStackNode
{
	ElementType data;
	struct LinkStackNode *next;
}LinkStackNode;

typedef LinkStackNode* LinkStack;

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////


void SeqStackInit(SeqStack *pst);
bool SeqStackIsFull(SeqStack *pst);
bool SeqStackExpansion(SeqStack *pst);
int SeqStackIsEmpty(SeqStack *pst);
void SeqStackPush(SeqStack *pst, ElementType x);
void SeqStackPop(SeqStack *pst);
ElementType SeqStackTop(SeqStack *pst); 
void SeqStackShow(SeqStack *pst);
int  SeqStackSize(SeqStack *pst);
void SeqStackDestroy(SeqStack *pst);

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////


void LinkStackInit(LinkStack *pst);
//bool LinkStackIsFull(LinkStack *pst);
bool LinkStackIsEmpty(LinkStack *pst);
void LinkStackPush(LinkStack *pst, ElementType x);
void LinkStackPop(LinkStack *pst);
ElementType LinkStackTop(LinkStack *pst);
void LinkStackShow(LinkStack *pst);
int  LinkStackSize(LinkStack *pst);
void LinkStackDestroy(LinkStack *pst);


///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////


void SeqStackInit(SeqStack *pst)
{
	pst->base = (ElementType *)malloc(sizeof(ElementType)* STACK_DEFAULT_SIZE);
	pst->capacity = STACK_DEFAULT_SIZE;
	pst->top = 0;
}

bool SeqStackIsFull(SeqStack *pst)
{
	assert(pst != NULL);
	return pst->top == pst->capacity;
}

bool SeqStackExpansion(SeqStack *pst)
{
	assert(pst != NULL);
	ElementType *p = (ElementType *)realloc(pst->base, pst->capacity * 2 * sizeof(ElementType));
	if (p != NULL )
	{
		pst->capacity = pst->capacity * 2;
		pst->base = p;
		printf("À©ÈÝ³É¹¦£¡\n");
		return true;
	}
	return false;
}

int SeqStackIsEmpty(SeqStack *pst)
{
	assert(pst != NULL);
	if (pst->top == 0)
	{
		return -1;
	}
	return 0;
}

void SeqStackPush(SeqStack *pst, ElementType x)
{
	assert(pst != NULL);
	if (SeqStackIsFull(pst) && !SeqStackExpansion(pst))
		return;
	pst->base[pst->top++] = x;
}

void SeqStackPop(SeqStack *pst)
{
	if (SeqStackIsEmpty(pst))
		return;
	pst->top--;
}

ElementType SeqStackTop(SeqStack *pst)
{
	if (!SeqStackIsEmpty(pst))
		return -1;
	return pst->base[pst->top - 1];
}

void SeqStackShow(SeqStack *pst)
{
	assert(pst != NULL);
	if (!SeqStackIsEmpty(pst))
		return;
	for (int i = 0; i < pst->top; i++)
	{
		printf("  %d  \n", pst->base[i]);
	}
	printf("\n");
}

int  SeqStackSize(SeqStack *pst)
{
	assert(pst != NULL);
	if (!SeqStackIsEmpty(pst))
		return 0;
	return pst->top;
}

void SeqStackDestroy(SeqStack *pst)
{
	assert(pst != NULL);
	free(pst->base);
	pst->base = NULL;
	pst->capacity = pst->top = 0;
}


///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////


void LinkStackInit(LinkStack *pst)
{
	assert(pst != NULL);
	*pst = NULL;
}

bool LinkStackIsEmpty(LinkStack *pst)
{
	assert(pst != NULL);
	if ( *pst == NULL)
	{
		return true;
	}
	return false;
}

void LinkStackPush(LinkStack *pst, ElementType x)
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

ElementType LinkStackTop(LinkStack *pst)
{
	assert(pst != NULL && *pst !=NULL);
	return (*pst)->data;
}

void LinkStackShow(LinkStack *pst)
{
	assert(pst != NULL);
	if (LinkStackIsEmpty(pst))
		return;
	LinkStackNode *s = *pst;
	while (s != NULL)
	{
		printf("  %d  \n", s->data);
		s = s->next;
	}
	printf("\n");
}

int  LinkStackSize(LinkStack *pst)
{
	assert(pst != NULL);
	LinkStackNode *s = *pst;
	int size = 0;
	while (s != NULL)
	{
		size++;
		s = s->next;
	}
	return size;
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


#endif // #ifndef _STACK_H_
