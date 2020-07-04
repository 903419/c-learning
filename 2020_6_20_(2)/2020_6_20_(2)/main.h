#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#pragma warning(disable:4996)
#define N 1000
typedef struct Info
{
	char name[20];
	char sex[10];
	int age;
	char telephone[12];
	char address[20];
}Info;
typedef struct MailList
{
	Info *data;
	int count;
	int capacity;
}MailList;
void InitiBook(MailList *pm);
void AddContact(MailList *pm);
int Check(MailList *pm);
void DeleteContact(MailList *pm);
void SeekContact(MailList *pm);
void ShowOneContact(MailList *pm, int number);
void ModifyContact(MailList *pm);
void ShowContact(MailList *pm);
void ClearContact(MailList *pm);
void SortContact(MailList *pm);
void ReadContact(MailList *pm);
void SaveContact(MailList *pm);


#endif // !_MAIN_H_
