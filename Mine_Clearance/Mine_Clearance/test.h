#ifndef _TEST_H_
#define _TEST_H_


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#pragma warning(disable:4996)

#define ROW 6   //棋盘数
#define COL 6
#define NUM 4   //雷数
#define ZERO '0'  //没有雷
#define ONE '1'   //雷

void Game();
void Initial(char board[][COL], int row, int col,char p);//初始化
void Show(char board[][COL], int row, int col);//显示棋盘
void SetMine(char mine[][COL], int row, int col,int n);//布雷
char GetNum(char mine[][COL],int x,int y);//获得附近的雷数
void Boom(char mine[][COL], char board[][COL], int x, int y);//递归展开
void Boom2(char mine[][COL], char board[][COL], int x, int y);//展开附近几个点的雷数


#endif // !_TEST_H_
