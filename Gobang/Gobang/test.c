#include "test.h"

void Menu()
{
	printf("\n#######################################\n");
	printf("###       1.Play        2.Quit      ###\n");
	printf("#######################################\n");
	printf("Please input your choice:>");
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
	printf("---------------------------------\n");
	printf("   1 | 2| 3| 4| 5| 6| 7| 8| 9|10|\n");
	printf("---------------------------------\n");
	for (; i < row; i++)
	{
		if (i < 9)
		{
			printf("%d | %c| %c| %c| %c| %c| %c| %c| %c| %c| %c|\n", i + 1, Arr[i][0], Arr[i][1], Arr[i][2], Arr[i][3], Arr[i][4], Arr[i][5], Arr[i][6], Arr[i][7], Arr[i][8], Arr[i][9]);
		}
		if (9 == i)
		{
			printf("%d| %c| %c| %c| %c| %c| %c| %c| %c| %c| %c|\n", i + 1, Arr[i][0], Arr[i][1], Arr[i][2], Arr[i][3], Arr[i][4], Arr[i][5], Arr[i][6], Arr[i][7], Arr[i][8], Arr[i][9]);
		}
		printf("---------------------------------\n");
	}
}

void PlayerArr(char Arr[][COL], int row, int col)
{
	printf("Please input your row and col:>");
	int i = 0;
	int j = 0;
	while (1)
	{
		scanf("%d %d", &i, &j);
		if (i > 10 || i < 1 || j > 10 || j < 1)
		{
			printf("�������겻�ԣ����������룡\n");
		}
		//if (Arr[i-1][j-1] == ' ')
		//{
		//	Arr[i-1][j-1] = BLACK;
		//	printf("Player done!\n");
		//	break;
		//}
		else if (Arr[i-1][j-1] != ' ')
		{
			printf("�õ��������ӣ����������ӣ�\n");
		}
		else
		{
			Arr[i-1][j-1] = BLACK;
			printf("Player done!\n");
			Sleep(500);
			break;
		}
	}
}

int JudgeArr(char Arr[][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (; i < row; i++)//ÿ���ж�
	{
	    j = 0;
		for (; j < row - 4; j++)
		{
			if (Arr[i][j] != ' '&&Arr[i][j] == Arr[i][j + 1] && Arr[i][j + 1] == Arr[i][j + 2] && Arr[i][j + 2] == Arr[i][j + 3] && Arr[i][j + 3] == Arr[i][j + 4])
			{
				return Arr[i][j];
			}
		}
	}
	for (j=0; j < col; j++)//ÿ���ж�
	{
		i = 0;
		for (; i < col - 4; i++)
		{
			if (Arr[i][j] != ' '&&Arr[i][j] == Arr[i+1][j] && Arr[i+1][j] == Arr[i+2][j] && Arr[i+2][j] == Arr[i+3][j] && Arr[i+3][j] == Arr[i+4][j])
			{
				return Arr[i][j];
			}
		}
	}
	for (i = 0; i < row - 1; i++)//���Խ���
	{
		if (Arr[i][i] != ' '&&Arr[i][i] == Arr[i + 1][i + 1] && Arr[i + 1][i + 1] == Arr[i + 2][i + 2] && Arr[i + 2][i + 2] == Arr[i + 3][i + 3] && Arr[i+3][i + 3] == Arr[i + 4][i + 4])
		{
			return Arr[i][i];
		}
	}
	for (i = 0, j = 9; i < row - 4, j >= 4; i++, j--)//���Խ���
	{
		if (Arr[i][j] != ' '&&Arr[i][j] == Arr[i + 1][j - 1] && Arr[i + 1][j - 1] == Arr[i + 2][j - 2] && Arr[i + 2][j - 2] == Arr[i + 3][j - 3] && Arr[i + 3][j - 3] == Arr[i + 4][j - 4])
		{
			return Arr[i][j];
		}
	}
	for (i = 0; i < row; i++)
	{
		j = 0;
		for (; j < col; j++)
		{
			if (Arr[i][j] == ' ')
			{
				return 'E'; //���̻��п�λ��
			}
		}
	}
	return 'D'; //�������ˣ�δ����Ӯ
}

void ComputerArr(char Arr[][COL], int row, int col)
{
	while (1)
	{
		int i = rand() % row;
		int j = rand() % row;
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
	char Arr[ROW][COL];
	InitialArr(Arr, ROW, COL);
	char ret = 'E';
	while (1)
	{
		ShowArr(Arr, ROW, COL);
		PlayerArr(Arr, ROW, COL);
		ret = JudgeArr(Arr, ROW, COL);
		if (ret != 'E')
		{
			break;
		}
		ComputerArr(Arr, ROW, COL);
		ret = JudgeArr(Arr, ROW, COL);
		if (ret != 'E')
		{
			break;
		}
	}
	ShowArr(Arr, ROW, COL);
	switch (ret)
	{
	case BLACK:
		printf("\n��ϲ�㣬��Ӯ�ˣ�\n");
		break;
	case WHITE:
		printf("\n���ź��������ˣ�\n");
		break;
	case 'D':
		printf("\nƽ�֣��ٽ�������\n");
		break;
	}
}