#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <string.h>
#include <assert.h>
char *strtok(char *str, const char *delim);
char *my_strtok(char *str1, const char *sep);
void my_memmove(const void *dst, const void * src,int count);
void my_memcpy(int *dst,int *src,int count);
char *my_strstr(const char *str1, const char * str2);
int my_strlen(char *str);
void Cpy(char *str1,char *str2);
int Cmp(char *str1, char *str2);
void Link(char *str1, char *str2,int num1,int num2);
#pragma warning(disable:4996)



#endif // !_MAIN_H_
