#include "test.h"

void Initial(char board[][COL], int row, int col,char p)//棋盘初始化函数，在这里，需要对全部棋盘进行初始化
{
	int i = 0;
	for (; i < row; i++)
	{
		int j = 0;
		for (; j < row; j++)
		{
			board[i][j] = p;
		}
	}
}

void Show(char board[][COL], int row, int col)//棋盘显示，这里只显示1~10行列的棋盘
{
	int i = 0;
	for (i = 1; i < row - 1; i++)
	{
		printf("%s", "---");
	}
	printf("---\n");
	printf("   ");
	for (i=1; i < row - 1; i++)
	{
		printf("%2d|", i);
	}
	printf("\n");
	for (i = 1; i < row - 1; i++)
	{
		printf("%s", "---");
	}
	printf("---\n");
	for (i = 1; i < row - 1; i++)
	{
		printf("%2d|", i);
		int j = 1;
		for (; j < col - 1; j++)
		{
			printf("%2c|", board[i][j]);
		}
		printf("\n");
		for (j = 1; j < row - 1; j++)
		{
			printf("%s", "---");
		}
		printf("---\n");
	}
}

void SetMine(char mine[][COL], int row, int col,int n)//布雷，使用随机数进行布雷，同样，只对1~10行列进行布雷
{
	while (n)
	{
		int i = rand() % (row - 2) + 1;
		int j = rand() % (col - 2) + 1;
		if (mine[i][j] == ONE)
		{
			continue;
		}
		mine[i][j] = ONE;
		n--;
	}
}

char GetNum(char mine[][COL], int x, int y)//获得输入坐标附近的雷数
{
	return mine[x - 1][y - 1] + mine[x - 1][y] + mine[x - 1][y + 1] +\
		mine[x][y - 1] + mine[x][y + 1] + \
		mine[x + 1][y - 1] + mine[x + 1][y] + mine[x + 1][y + 1] - 7 * ZERO;
}

void Boom(char mine[][COL], char board[][COL], int x, int y)//递归展开，这样展开就展开了全部棋盘
{
	char num = mine[x][y];
	if (num == ZERO)
	{
		board[x][y] = GetNum(mine, x, y);
		if (board[x - 1][y - 1] == '*')
		{
			Boom(mine, board, x - 1, y - 1);
		}
		if (board[x - 1][y ] == '*')
		{
			Boom(mine, board, x - 1, y );
		}
		if (board[x - 1][y + 1] == '*')
		{
			Boom(mine, board, x - 1, y + 1);
		}
		if (board[x ][y - 1] == '*')
		{
			Boom(mine, board, x , y - 1);
		}
		if (board[x][y + 1] == '*')
		{
			Boom(mine, board, x, y + 1);
		}
		if (board[x+1][y - 1] == '*')
		{
			Boom(mine, board, x+1, y - 1);
		}
		if (board[x + 1][y ] == '*')
		{
			Boom(mine, board, x + 1, y );
		}
		if (board[x + 1][y+1] == '*')
		{
			Boom(mine, board, x + 1, y+1);
		}
	}
}

void Boom2(char mine[][COL], char board[][COL], int x, int y)//炸开输入坐标附近的几个坐标的雷数
{
	board[x][y] = GetNum(mine, x, y);
	if (mine[x - 1][y - 1] == ZERO)
	{
		board[x - 1][y - 1] = GetNum(mine, x - 1, y - 1);
	}
	if (mine[x - 1][y] == ZERO)
	{
		board[x - 1][y] = GetNum(mine, x - 1, y);
	}
	if (mine[x - 1][y + 1] == ZERO)
	{
		board[x - 1][y + 1] = GetNum(mine, x - 1, y + 1);
	}
	if (mine[x][y - 1] == ZERO)
	{
		board[x][y - 1] = GetNum(mine, x, y - 1);
	}
	if (mine[x][y + 1] == ZERO)
	{
		board[x][y + 1] = GetNum(mine, x, y + 1);
	}
	if (mine[x + 1][y - 1] == ZERO)
	{
		board[x + 1][y - 1] = GetNum(mine, x + 1, y - 1);
	}
	if (mine[x + 1][y] == ZERO)
	{
		board[x + 1][y] = GetNum(mine, x + 1, y);
	}
	if (mine[x + 1][y + 1] == ZERO)
	{
		board[x + 1][y + 1] = GetNum(mine, x + 1, y + 1);
	}
}


void Game()
{
	srand((int)time(0));
	char board[ROW][COL];
	char mine[ROW][COL];

	Initial(board, ROW, COL, '*');//显示棋盘初始化，初始化为‘*’
	Initial(mine, ROW, COL, ZERO);//初始化布雷棋盘，初始化为‘0’
	SetMine(mine, ROW, COL,NUM);//布雷，布雷个数为NUM个，布雷为‘1’
	//Show(board, ROW, COL);
	//Show(mine, ROW, COL);

	int number = 0;//这里是为了判定，显示棋盘上的‘*’和NUM数相等，就表示扫雷成功
	while (1)
	{
		system("cls");
		Show(board, ROW, COL);
		int x = 0;
		int y = 0;
		int i = 0;
		number = 0;
		printf("请输入要扫的坐标:>");
		scanf("%d %d", &x, &y);
		printf("正在显示....\n");
		if (x<1 || x>(ROW - 2) || y<1 || y>(ROW - 2))//对输入进行判定，输入坐标大了
		{
			printf("输入坐标错误，请重新输入...\n");
			Sleep(1000);
			continue;
		}
		if (board[x][y] != '*')//输入坐标被扫过了
		{
			printf("输入坐标已被扫过，请重新输入...\n");
			Sleep(1000);
			continue;
		}
		if (mine[x][y] == ZERO)//输入坐标无雷
		{
			//Boom(mine, board, x, y);//递归展开，这样展开就展开了全部
			Boom2(mine, board, x, y);//炸开输入坐标附近的坐标
			//char num = GetNum(mine, x, y);
			//board[x][y] = num;
			Sleep(1000);
		}
		else//输入坐标有雷
		{
			printf("\n游戏结束，(%d,%d)坐标有雷\n",x,y);
			break;
		}
		for (i = 1; i < ROW - 1; i++)//计算board上面，‘*’的数为多少
		{
			int j = 0;
			for (j = 1; j < ROW - 1; j++)
			{
				if (board[i][j] == '*')
				{
					number++;
				}
			}
		}
		if (number == NUM)//若‘*’数和NUM相等，结束循环
		{
			break;
		}
	}
	if (number == NUM)//结果判定
	{
		Sleep(2000);
		system("cls");
		printf("\n恭喜你，完美通关！\n");
	}
	else
	{
		Sleep(2000);
		system("cls");
		printf("\n很遗憾，游戏失败，再接再厉!\n");
	}
	Show(mine, ROW, COL);//再显示一下mine棋盘
	Sleep(2000);
}