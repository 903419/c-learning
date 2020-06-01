#include "main.h"

//数组查数
int main()
{
	int arr[][4] = { 1,3,5,7,4,6,8,10,6,9,12,15,8,13,15,17 };
	int number = 0;
	printf("输入查找的数:>");
	scanf("%d", &number);
	printf("%d\n",SearchNumber(arr, number));
	return 0;
}

//字符串旋转
//int main()
//{
//	int i = 1;
//	int judge = 1;//判断
//	char arr[] = "AABCD";
//	char arr1[] = "BCDAE";
//	int num = strlen(arr);
//	for (; i < num; i++)
//	{
//		Intermediate(arr, num, Sinistral);//字符串旋转
//		if (0 == strcmp(arr, arr1))//比较两字符串是否相同
//		{
//			judge = 0;
//			break;
//		}
//	}
//	if (0 == judge)
//	{
//		printf("字符串arr1是字符串arr旋转之后的字符串\n");
//	}
//	else
//	{
//		printf("字符串arr1不是字符串arr旋转之后的字符串\n");
//	}
//	return 0;
//}




//模拟qsort
//int main()
//{
//	int arr[] = { 1,4,5,3,9,7,6,1,4,8,3,5 };
//	int num = sizeof(arr) / sizeof(arr[0]);
//	print(arr, num);
//	myqsort(arr,num,sizeof(int),cmpInt);
//	print(arr, num);
//	return 0;
//}


//实现库qsort
//int main()
//{
//	int arr[] = { 1,4,5,3,9,7,6,1,4,8,3,5 };
//	int num = sizeof(arr) / sizeof(arr[0]);
//	print(arr, num);
//	qsort(arr,num,sizeof(int),cmp);
//	print(arr, num);
//	return 0;
//}