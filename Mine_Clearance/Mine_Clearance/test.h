#ifndef _TEST_H_
#define _TEST_H_


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#pragma warning(disable:4996)

#define ROW 6   //������
#define COL 6
#define NUM 4   //����
#define ZERO '0'  //û����
#define ONE '1'   //��

void Game();
void Initial(char board[][COL], int row, int col,char p);//��ʼ��
void Show(char board[][COL], int row, int col);//��ʾ����
void SetMine(char mine[][COL], int row, int col,int n);//����
char GetNum(char mine[][COL],int x,int y);//��ø���������
void Boom(char mine[][COL], char board[][COL], int x, int y);//�ݹ�չ��
void Boom2(char mine[][COL], char board[][COL], int x, int y);//չ�����������������


#endif // !_TEST_H_
