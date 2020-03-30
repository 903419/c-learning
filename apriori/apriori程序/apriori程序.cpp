// apriori程序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <fstream>


//typedef struct
//{
//	int item[100]; //数据项
//} D_Node; //数据库D

typedef struct
{
	int item[100]; //数据项,用item[0]保存支持度
} C_Node; //候选集

typedef struct
{
	int item[100]; //数据项,用item[0]保存支持度
} L_Node;//频繁集

C_Node C[100][100];
L_Node L[100][100];
//D_Node D[100][100];
int D[100][100];
int min_supp=30,sup=15; //最小支持度

void InPut()
{
	int i, j, n, n1;//n是交易集的大小，n1是输入的记录个数，数据输入到D[100]中
//	printf("最小支持度:");
//	scanf("%d", &min_supp);
//	printf("几条交易记录？");
//	scanf("%d", &D[0].item[0]);
//	n = D[0].item[0];
	FILE *fp;
	fp = fopen("DATA.txt", "r");
	n = 100;  //100条交易记录
	for (i = 1; i <= n; i++)
	{
//		printf("第%d条交易中有几个物品？", i);
//		scanf("%d", &n1);
//		D[i][j].item[0] = n1;
		for (j = 1; j <= 100; j++)
		{
			fscanf(fp,"%d", &D[i][j]);
		}

	}

}
//扫描数据集D生成1项候选集C1
void C1()
{


	/* 将D放入C中，D[0]item[0]是交易集个数，D[1]item[0]是第一个交易集的数据项个数，
	D[1]item[1]到D[1]item[个数]是第一个交易集合的数据。
	c不管交易集个数，只看数据项。C[n][k].item[0]是候选集Cn的第k项的支持度，
	c[1][1]item[1]数据项，c[1][1]item[0]此数据项的个数。c[1][0]item[0]中no是不同数据项的个数。
	*/
	int i, j, k;
	int no = 1, temp = 0; //no是不重复的数据项的个数
	C[1][0].item[0] = 0; //1 项集的个数，在本算法中，用C[n][k].item[0]来保存候选集Cn的第k项的支持度
	if (D[0][0] != 0)
	{
		C[1][1].item[1] = D[0][0]; //给第一个数据项赋初值

	}

	for (i = 0; i < 100; i++) //交易集
	{

		for (j = 0; j < 100; j++) // 某个交易集中的记录
		{
			if (D[i][j] != NULL)
			{
				temp = 1;
				for (k = 1; k <= no; k++)   //no：候选集中数据项的个数
				{
					if (C[1][k].item[1] == D[i][j])//一项候选集的第k项的值等于第i条交易中第j项的值
					{
						C[1][k].item[0]++; //一项候选集的第k项的支持度加1
						temp = 0;

					}
				}
				if (temp)//第i条交易中的第j数不在候选集中  添加  生成新的项集
				{

					C[1][++no].item[1] = D[i][j];
					C[1][no].item[0] = 1;
				}
			}

	//		if (temp)//第i条交易中的第j数不在候选集中  添加  生成新的项集
	//		{

	//			C[1][++no].item[1] = D[i][j];
	//			C[1][no].item[0] = 1;
	//		}

		}

	}
	C[1][0].item[0] = no;//数据项的个数
}

void Cn(int n)
{
	//用频繁集Ln-1为基础，通过连接得到n项候选集Cn
	int i, j, k, p, q, s, t, num;
	int no = 0, temp = 0, count;
	C[n][0].item[0] = 0; //初始化
	num = L[n - 1][0].item[0]; //num是Ln-1项集的记录个数
	for (i = 1; i <= num; i++) //扫描频繁项集
	{

		for (j = i + 1; j <= num; j++)
		{

			temp = 1; //测试是否满足联结条件
			if (n > 2)//不是一项集连时，可能有重复项
			{
				for (k = 1; k < n - 1; k++)
				{
					if (L[n - 1][i].item[k] != L[n - 1][j].item[k])//相同位置有相同的项才可以连接
					{
						temp = 0;
						break;
					}
				}
			}
			if (temp == 1)//满足联结条件
			{
				no++;
				for (p = 1; p <= n - 1; p++)
					C[n][no].item[p] = L[n - 1][i].item[p];  //把n-1项频繁项集中的前n-1项赋给候选集

				C[n][no].item[p] = L[n - 1][j].item[p - 1];	//这行p是执行p++之后的，比上行p大1
				C[n][no].item[0] = 0;
				for (q = 0; q < 100; q++) // 测试其支持度
				{
					count = 0; //count用来记数,当所测试的项存在时,count加1,当count=n时，则子集存在
					for (s = 1; C[n][no].item[s] != 0; s++) //第n项候选集的第no条记录的第s项数据的值
					{
						for (t = 0; t < 100; t++) //遍历第q条记录
						{
							if (D[q][t] != NULL)
							{
								if (C[n][no].item[s] == D[q][t]) //候选集中的值在记录中给该记录个数加一
								{
									count += 1;
									break;
								}
							}
						}

					}
					if (count == n) //第n项候选集的第no条记录
						C[n][no].item[0] += 1;//子集存在,第no项的支持度加1

				}

				C[n][0].item[0] += 1;
			}
		}
	}
}

void Ln(int n)
{
	int i, j, k;
	j = 0;
	L[n][0].item[0] = 0; //第n项频繁项集第0个数据项的个数是0
	for (i = 1; i <= C[n][0].item[0]; i++) //扫描候选集个数
	{
		if (C[n][i].item[0] >= min_supp) //第n项候选集中第i条记录的个数  >  最小支持度
		{
			j += 1;
			for (k = 1; k <= n; k++)//第n项候选集中第j条记录中有k个数据项
				L[n][j].item[k] = C[n][i].item[k];  //候选集添加到频繁项集中
			L[n][j].item[0] = C[n][i].item[0];  //添加 第n项候选集中第j条记录 的个数  即支持度
		}

	}

	L[n][0].item[0] = j; //频繁n项集中的记录的个数
}
void Ln2(int n)
{
	int i, j, k;
	j = 0;
	L[n][0].item[0] = 0; //第n项频繁项集第0个数据项的个数是0
	for (i = 1; i <= C[n][0].item[0]; i++) //扫描候选集个数
	{
		if (C[n][i].item[0] >= sup) //第n项候选集中第i条记录的个数  >  最小支持度
		{
			j += 1;
			for (k = 1; k <= n; k++)//第n项候选集中第j条记录中有k个数据项
				L[n][j].item[k] = C[n][i].item[k];  //候选集添加到频繁项集中
			L[n][j].item[0] = C[n][i].item[0];  //添加 第n项候选集中第j条记录 的个数  即支持度
		}

	}

	L[n][0].item[0] = j; //频繁n项集中的记录的个数
}
void OutPut(int n)
{
	int i, j, k;

	k = L[n][0].item[0];//n项频繁集中有k条记录
	if (k != 0)
	{
		printf("\n频繁项集L%d如下:\n", n);
		for (i = 1; i <= k; i++)
		{

			for (j = 1; j <= n; j++) //n项频繁集中每条记录有n个数据项
				printf(" %d ", L[n][i].item[j]);
			printf("  支持度:%d\n", L[n][i].item[0]);

		}

	}
	else
		printf("迭代结束\n");
}

void main()
{
	int i;
	int n = 1;
	InPut();
	C1();//初始化,生成1项候选集C1
	Ln(1);//得到1项频繁集L1
	while (L[n][0].item[0] != 0)
	{
		n += 1;
		Cn(n);
		Ln2(n);
	}
	for (i = 1; i <= n; i++)
		OutPut(i);
}
