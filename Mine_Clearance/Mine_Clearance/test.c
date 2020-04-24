#include "test.h"

void Initial(char board[][COL], int row, int col,char p)//���̳�ʼ���������������Ҫ��ȫ�����̽��г�ʼ��
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

void Show(char board[][COL], int row, int col)//������ʾ������ֻ��ʾ1~10���е�����
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

void SetMine(char mine[][COL], int row, int col,int n)//���ף�ʹ����������в��ף�ͬ����ֻ��1~10���н��в���
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

char GetNum(char mine[][COL], int x, int y)//����������긽��������
{
	return mine[x - 1][y - 1] + mine[x - 1][y] + mine[x - 1][y + 1] +\
		mine[x][y - 1] + mine[x][y + 1] + \
		mine[x + 1][y - 1] + mine[x + 1][y] + mine[x + 1][y + 1] - 7 * ZERO;
}

void Boom(char mine[][COL], char board[][COL], int x, int y)//�ݹ�չ��������չ����չ����ȫ������
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

void Boom2(char mine[][COL], char board[][COL], int x, int y)//ը���������긽���ļ������������
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

	Initial(board, ROW, COL, '*');//��ʾ���̳�ʼ������ʼ��Ϊ��*��
	Initial(mine, ROW, COL, ZERO);//��ʼ���������̣���ʼ��Ϊ��0��
	SetMine(mine, ROW, COL,NUM);//���ף����׸���ΪNUM��������Ϊ��1��
	//Show(board, ROW, COL);
	//Show(mine, ROW, COL);

	int number = 0;//������Ϊ���ж�����ʾ�����ϵġ�*����NUM����ȣ��ͱ�ʾɨ�׳ɹ�
	while (1)
	{
		system("cls");
		Show(board, ROW, COL);
		int x = 0;
		int y = 0;
		int i = 0;
		number = 0;
		printf("������Ҫɨ������:>");
		scanf("%d %d", &x, &y);
		printf("������ʾ....\n");
		if (x<1 || x>(ROW - 2) || y<1 || y>(ROW - 2))//����������ж��������������
		{
			printf("���������������������...\n");
			Sleep(1000);
			continue;
		}
		if (board[x][y] != '*')//�������걻ɨ����
		{
			printf("���������ѱ�ɨ��������������...\n");
			Sleep(1000);
			continue;
		}
		if (mine[x][y] == ZERO)//������������
		{
			//Boom(mine, board, x, y);//�ݹ�չ��������չ����չ����ȫ��
			Boom2(mine, board, x, y);//ը���������긽��������
			//char num = GetNum(mine, x, y);
			//board[x][y] = num;
			Sleep(1000);
		}
		else//������������
		{
			printf("\n��Ϸ������(%d,%d)��������\n",x,y);
			break;
		}
		for (i = 1; i < ROW - 1; i++)//����board���棬��*������Ϊ����
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
		if (number == NUM)//����*������NUM��ȣ�����ѭ��
		{
			break;
		}
	}
	if (number == NUM)//����ж�
	{
		Sleep(2000);
		system("cls");
		printf("\n��ϲ�㣬����ͨ�أ�\n");
	}
	else
	{
		Sleep(2000);
		system("cls");
		printf("\n���ź�����Ϸʧ�ܣ��ٽ�����!\n");
	}
	Show(mine, ROW, COL);//����ʾһ��mine����
	Sleep(2000);
}