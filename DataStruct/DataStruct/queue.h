#ifndef _QUEUE_H_
#define _QUEUE_H_
#include "shared.h"

#define QUEUE_DEFAULT_SIZE 8

typedef struct SeqQueue
{
	ElementType *base;
	int capacity;
	int front;
	int rear;
}SeqQueue;//顺序队列

typedef struct LinkQueueNode
{
	ElementType data;
	struct LinkQueueNode *link;
}LinkQueueNode;//链式队列

typedef struct LinkQueue
{
	LinkQueueNode *head;
	LinkQueueNode *tail;
}LinkQueue;

typedef struct CycleQueue
{
	int capacity;
	ElementType *base;
	int front;
	int rear;
}CycleQueue;//循环队列



/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////



void SeqQueueInit(SeqQueue *psq);
bool SeqQueueIsFull(SeqQueue *psq);
bool SeqQueueIsEmpty(SeqQueue *psq);
void SeqQueueEn(SeqQueue *psq,ElementType x);
void SeqQueueDe(SeqQueue *psq);
ElementType SeqQueueFront(SeqQueue *psq);
int SeqQueueSize(SeqQueue *psq);
void SeqQueueShow(SeqQueue *psq);
void SeqQueueDestroy(SeqQueue *psq);


/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////

void LinkQueueInit(LinkQueue *plq);
int LinkQueueIsEmpty(LinkQueue *plq);
void LinkQueueEn(LinkQueue *plq, ElementType x);
void LinkQueueDe(LinkQueue *plq);
ElementType LinkQueueFront(LinkQueue *plq);
int LinkQueueSize(LinkQueue *plq);
void LinkQueueShow(LinkQueue *plq);
void LinkQueueDestroy(LinkQueue *plq);


/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////


void CycleQueueInit(CycleQueue *pcq);
bool CycleQueueIsEmpty(CycleQueue *pcq);
void CycleQueueEn(CycleQueue *pcq, ElementType x);
void CycleQueueDe(CycleQueue *pcq);
ElementType CycleQueueFront(CycleQueue *pcq);
int CycleQueueSize(CycleQueue *pcq);
void CycleQueueShow(CycleQueue *pcq);
void CycleQueueDestroy(CycleQueue *pcq);


/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////



void SeqQueueInit(SeqQueue *psq)
{
	psq->base = (ElementType *)malloc(sizeof(ElementType) * QUEUE_DEFAULT_SIZE);
	psq->capacity = QUEUE_DEFAULT_SIZE;
	psq->front = psq->rear = 0;
}

bool SeqQueueIsFull(SeqQueue *psq)
{
	return psq->rear == psq->capacity;
}

bool SeqQueueIsEmpty(SeqQueue *psq)
{
	return psq->front == psq->rear;
}

void SeqQueueEn(SeqQueue *psq ,ElementType x)
{
	assert(psq != NULL);
	if (SeqQueueIsFull(psq))
	{
		printf("不能入队！\n");
		return;
	}
	psq->base[psq->rear++] = x;
}

void SeqQueueDe(SeqQueue *psq)
{
	assert(psq != NULL);
	if (SeqQueueIsEmpty(psq))
	{
		printf("空队列，不能出队!\n");
		return;
	}
	psq->front++;
}

ElementType SeqQueueFront(SeqQueue *psq)
{
	assert(psq != NULL);
	assert(!SeqQueueIsEmpty(psq));
	return psq->base[psq->front];
}

int SeqQueueSize(SeqQueue *psq)
{
	assert(psq != NULL);
	return psq->rear - psq->front;
}

void SeqQueueShow(SeqQueue *psq)
{
	assert(psq != NULL);
	if (!SeqQueueIsEmpty(psq))
	{
		for (int i = psq->front; i < psq->rear; i++)
		{
			printf("%d  ", psq->base[i]);
		}
		printf("\n");
	}
}

void SeqQueueDestroy(SeqQueue *psq)
{
	assert(psq != NULL);
	free(psq->base);
	psq->capacity = psq->front = psq->rear = 0;
}


//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

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

void LinkQueueEn(LinkQueue *plq, ElementType x)
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

ElementType LinkQueueFront(LinkQueue *plq)
{
	assert(plq != NULL);
	assert(!LinkQueueIsEmpty(plq));
	return plq->head->data;
}

ElementType LinkQueueBack(LinkQueue *plq)
{
	assert(plq != NULL);
	assert(!LinkQueueIsEmpty(plq));
	return plq->tail->data;
}

int LinkQueueSize(LinkQueue *plq)
{
	assert(plq != NULL);
	if (LinkQueueIsEmpty(plq))
	{
		printf("空队！\n");
		return 0;
	}
	LinkQueueNode *p = plq->head;
	int size = 0;
	while (p != NULL)
	{
		size++;
		p = p->link;
	}
	return size;
}

void LinkQueueShow(LinkQueue *plq)
{
	assert(plq != NULL);
	if (!LinkQueueIsEmpty(plq))
	{
		LinkQueueNode *p = plq->head;
		while (p != NULL)
		{
			printf("%d   ", p->data);
			p = p->link;
		}
		printf("\n");
	}
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


////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////


void CycleQueueInit(CycleQueue *pcq)
{
	pcq->base = (ElementType *)malloc(sizeof(ElementType) * (QUEUE_DEFAULT_SIZE +1));
	pcq->capacity = QUEUE_DEFAULT_SIZE;
	pcq->front = pcq->rear = 0;
}

bool CycleQueueIsEmpty(CycleQueue *pcq)
{
	assert(pcq != NULL);
	return pcq->front == pcq->rear;
}

bool CycleQueueIsFull(CycleQueue *pcq)
{
	assert(pcq != NULL);
	return ((pcq->rear + 1) % (pcq->capacity + 1)) == pcq->front;
}

void CycleQueueEn(CycleQueue *pcq, ElementType x)
{
	assert(pcq!=NULL);
	if (CycleQueueIsFull(pcq))
	{
		printf("队满！\n");
		return;
	}
	pcq->base[pcq->rear] = x;
	pcq->rear = (pcq->rear + 1) % (pcq->capacity + 1);
}

void CycleQueueDe(CycleQueue *pcq)
{
	assert(pcq != NULL);
	if (CycleQueueIsEmpty(pcq))
	{
		printf("空队,不能出队！\n");
		return;
	}
	pcq->front = (pcq->front + 1) % (pcq->capacity + 1);
}

ElementType CycleQueueFront(CycleQueue *pcq)
{
	assert(pcq != NULL);
	if (!CycleQueueIsEmpty(pcq))
	{
		return pcq->base[pcq->front];
	}
	return -1;
}

int CycleQueueSize(CycleQueue *pcq)
{
	assert(pcq);
	if (CycleQueueIsEmpty(pcq))
	{
		return 0;
	}
	return (pcq->rear - pcq->front + pcq->capacity + 1 ) % (pcq->capacity + 1);
}

void CycleQueueShow(CycleQueue *pcq)
{
	if (CycleQueueIsEmpty(pcq))
	{
		return;
	}
	for (int i = pcq->front; i != pcq->rear;)
	{
		printf("%d  ", pcq->base[i]);
		i = (i + 1) % (pcq->capacity + 1);
	}
	printf("\n");
}

void CycleQueueDestroy(CycleQueue *pcq)
{
	free(pcq->base);
}


////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////


#endif // _QUEUE_H_
