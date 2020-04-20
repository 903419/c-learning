#include "test.h"

void Menu()
{
	printf("\n#################################\n");
	printf("####  1.Play      2.Quit     ####\n");
	printf("#################################\n");
	printf("Please input your choice:>  ");
}

void InitialArr(char Arr[][COL], int row, int col)
{
	int i = 0;
	for (; i < row; i++)
	{
		int j = 0;
		for (; j < col; j++)
		{
			Arr[i][j] = ' ';
		}
	}
}

void ShowArr(char Arr[][COL], int row, int col)
{
	int i = 0;
	printf("-----------\n");
	printf("   1| 2| 3|\n");
	printf("-----------\n");
	for (; i < row; i++)
	{
		printf("%d| %c| %c| %c|\n", i+1, Arr[i][0], Arr[i][1], Arr[i][2]);
		printf("-----------\n");
	}
}

int PlayerArr(char Arr[][COL], int row, int col)
{
	printf("Please input your row and col:>");
	int i = 0;
	int j = 0;
	scanf("%d %d", &i, &j);
	if (i >= 1 && i <= 3 && j >= 1 && j <= 3)
	{
		if (Arr[i-1][j-1] != ' ')
		{
			return 2;  //该位置已经有点了，不能再输入
		}
		else
		{
			Arr[i - 1][j - 1] = BLACK;
			return 1;  //输入正确
		}
	}
	return -1;  //坐标输入错误
}

int JudgeArr(char Arr[][COL], int row, int col)
{
	int i = 0;
	for (;i<row;i++)
	{
		if (Arr[i][0]!=' '&& Arr[i][0] == Arr[i][1] && Arr[i][1] == Arr[i][2])
		{
			return Arr[i][0];
		}
	}
	for (i=0; i < row; i++)
	{
		if (Arr[0][i] != ' '&&Arr[0][i] == Arr[1][i] && Arr[1][i] == Arr[2][i])
		{
			return Arr[0][i];
		}
	}
	if (Arr[0][0] != ' '&&Arr[0][0] == Arr[1][1] && Arr[1][1] == Arr[2][2])
	{
		return Arr[0][0];
	}
	if (Arr[0][2] != ' '&&Arr[0][2] == Arr[1][1] && Arr[1][1] == Arr[2][0])
	{
		return Arr[0][2];
	}
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (; j < col; j++)
		{
			if (Arr[i][j] == ' ')
			{
				return 'E'; //Empty,棋盘还有空，继续下棋
			}
		}
	}
	return 'D';//Draw,棋盘满了，未有输赢，平局
}

void ComputerArr(char Arr[][COL], int row, int col)
{
	while (1)
	{
		int i = rand() % row;
		int j = rand() % col;
		if (Arr[i][j] == ' ')
		{
			Arr[i][j] = WHITE;
			break;
		}
	}
	Sleep(500);
	printf("Computer done!\n");

}

void Game()
{
	printf("\n游戏开始！\n");
	char Arr[ROW][COL];
	InitialArr(Arr, ROW, COL);
	char ret = 'E'; //Empty,棋盘最开始全为空，返回值可为D，WHITE和BLACK
	int ProRet = 0;
	while (1)
	{
		ShowArr(Arr, ROW, COL);
		again:
	    ProRet=PlayerArr(Arr, ROW, COL);
		if (2 == ProRet)
		{
			printf("该位置已经有点了，请重新输入\n");
			goto again;
		}
		else if (-1 == ProRet)
		{
			printf("坐标输入有误，请重新输入\n");
			goto again;
		}
		else
		{
			printf("Player done!\n");
			Sleep(500);
		}
	    ret=JudgeArr(Arr, ROW, COL);
		if (ret != 'E')//不等于空，就说明，棋盘还没满，继续玩游戏
		{
			break;
		}
		ComputerArr(Arr, ROW, COL);
		ret = JudgeArr(Arr, ROW, COL);
		if (ret != 'E')//不等于空，就说明，棋盘还没满，继续玩游戏
		{
			break;
		}
	}
	ShowArr(Arr, ROW, COL);
	switch (ret)//进行判定，谁输谁赢
	{
	case BLACK:
		printf("\n恭喜你，你赢了！\n");
		break;
	case WHITE:
		printf("\n很遗憾，你输了！\n");
		break;
	case 'D':
		printf("\n平局，再接再厉！\n");
		break;
	default:
		break;
	}
	printf("\n游戏结束！\n");
}