#ifndef _TEST_H_
#define _TEST_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#pragma warning(disable:4996)

#define ROW 3
#define COL 3
#define BLACK 'X'
#define WHITE 'O'

void InitialArr(char Arr[][COL],int row,int col);
void ShowArr(char Arr[][COL], int row, int col);
int PlayerArr(char Arr[][COL], int row, int col);
int JudgeArr(char Arr[][COL], int row, int col);
void ComputerArr(char Arr[][COL], int row, int col);
void Menu();
void Game();


#endif // !_TEST_H_