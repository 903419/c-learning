#ifndef _BST_H_
#define _BST_H_

#include "shared.h"

typedef struct BstNode
{
	ElementType data;
	struct BstNode *leftChild;
	struct BstNode *rightChild;
}BstNode;

typedef BstNode* BsTree;

void BstInit(BsTree *bst);
void BstInsert(BsTree *bst, ElementType x);
ElementType BstMin(BsTree bst);
ElementType BstMax(BsTree bst);
void BstSortPrint(BsTree bst);
BstNode* BstFind(BsTree bst, ElementType key);
bool BstErase(BsTree *bst, BstNode *p);
void BstDestroy(BsTree *bst);

//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////

void BstInit(BsTree *bst)
{
	assert(bst != NULL);
	*bst = NULL;
}

void BstInsert(BsTree *bst, ElementType x)
{
	if (*bst == NULL)
	{
		*bst = (BstNode *)malloc(sizeof(BstNode));
		(*bst)->data = x;
		(*bst)->leftChild = (*bst)->rightChild = NULL;
		return;
	}
	if (x < (*bst)->data)
	{
		BstInsert(&(*bst)->leftChild, x);
		return;
	}
	BstInsert(&(*bst)->rightChild, x);
}

ElementType BstMin(BsTree bst)
{
	while (bst->leftChild != NULL)
		bst = bst->leftChild;
	return bst->data;
}

ElementType BstMax(BsTree bst)
{
	while (bst->rightChild != NULL)
		bst = bst->rightChild;
	return bst->data;
}

void BstSortPrint(BsTree bst)
{
	if (bst != NULL)
	{
		BstSortPrint(bst->leftChild);
		printf("%d  ", bst->data);
		BstSortPrint(bst->rightChild);
	}
}

BstNode* BstFind(BsTree bst, ElementType key)
{
	if (bst == NULL)
		return NULL;
	if (bst->data == key)
		return bst;
	if (bst->data > key)
		return BstFind(bst->leftChild, key);
	return BstFind(bst->rightChild, key);
}

bool BstErase(BsTree *bst, BstNode *p)
{
	if (bst != NULL)
	{
		if((*bst)->data > p->data)
			BstErase(&(*bst)->leftChild, p);
		else if((*bst)->data < p->data)
			BstErase(&(*bst)->rightChild, p);
		else
		{
			if (p->leftChild != NULL && p->rightChild != NULL)
			{
				BstNode *s = p->leftChild;
				while (s->rightChild != NULL)
					s = s->rightChild;
				p->data = s->data;
				BstErase(&p->leftChild, s);
			}
			else
			{
				if (p->leftChild != NULL)
				{
					*bst = p->leftChild;
					free(p);
				}
				else 
				{
					*bst = p->rightChild;
					free(p);
				}

			}


			//if (p->leftChild == NULL && p->rightChild == NULL)
			//{
			//	free(p);
			//	*bst = NULL;
			//}
			//else if (p->leftChild != NULL && p->rightChild == NULL)
			//{
			//	*bst = p->leftChild;
			//	free(p);
			//	p = NULL;
			//}
			//else if (p->rightChild != NULL && p->leftChild == NULL)
			//{
			//	*bst = p->rightChild;
			//	free(p);
			//	p = NULL;
			//}
			//else
			//{
			//	BstNode *s = p->leftChild;
			//	while (s->rightChild != NULL)
			//		s = s->rightChild;
			//	p->data = s->data;
			//	BstErase(&p->leftChild, s);
			//}


			return true;
		}
	}
	return false;
}

void BstDestroy(BsTree *bst)
{
	if (*bst != NULL)
	{
		BstDestroy(&(*bst)->leftChild);
		BstDestroy(&(*bst)->rightChild);
		free(*bst);
	}
}

#endif // !_BST_H_
