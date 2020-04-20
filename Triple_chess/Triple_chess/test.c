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
			return 2;  //��λ���Ѿ��е��ˣ�����������
		}
		else
		{
			Arr[i - 1][j - 1] = BLACK;
			return 1;  //������ȷ
		}
	}
	return -1;  //�����������
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
				return 'E'; //Empty,���̻��пգ���������
			}
		}
	}
	return 'D';//Draw,�������ˣ�δ����Ӯ��ƽ��
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
	printf("\n��Ϸ��ʼ��\n");
	char Arr[ROW][COL];
	InitialArr(Arr, ROW, COL);
	char ret = 'E'; //Empty,�����ʼȫΪ�գ�����ֵ��ΪD��WHITE��BLACK
	int ProRet = 0;
	while (1)
	{
		ShowArr(Arr, ROW, COL);
		again:
	    ProRet=PlayerArr(Arr, ROW, COL);
		if (2 == ProRet)
		{
			printf("��λ���Ѿ��е��ˣ�����������\n");
			goto again;
		}
		else if (-1 == ProRet)
		{
			printf("����������������������\n");
			goto again;
		}
		else
		{
			printf("Player done!\n");
			Sleep(500);
		}
	    ret=JudgeArr(Arr, ROW, COL);
		if (ret != 'E')//�����ڿգ���˵�������̻�û������������Ϸ
		{
			break;
		}
		ComputerArr(Arr, ROW, COL);
		ret = JudgeArr(Arr, ROW, COL);
		if (ret != 'E')//�����ڿգ���˵�������̻�û������������Ϸ
		{
			break;
		}
	}
	ShowArr(Arr, ROW, COL);
	switch (ret)//�����ж���˭��˭Ӯ
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
	default:
		break;
	}
	printf("\n��Ϸ������\n");
}