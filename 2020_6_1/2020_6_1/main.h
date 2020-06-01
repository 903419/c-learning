#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
int SearchNumber(int (*arr)[4],int number);
void Intermediate(void *base,int num,void (*rotate)(void *, int));
void Sinistral(void *a,int num);



int cmpInt(const void *a,const void *b);
void print(int *a, int num);
void myqsort(void *base, int num, int size, int(*cmp)(const void *, const void *));
void swap(void *a,void *b);

#endif
