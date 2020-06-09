#include "main.h"


int main()
{
	int arr[3][5] = { 1,2,3,4,5,2,4,6,8,10,3,5,7,9,11 };
	int number = 0;
	printf("输入你要找的数:>");
	scanf("%d", &number);
	printf("%d\n",Find(arr, 3, 5, number));
	return 0;
}

//int main()
//{
//	char arr[] = "AABBCCDD";
//	int len = strlen(arr);
//	int count = 4;//右旋次数
//	char *double_string = (char *)malloc(2 * len + 1);
//	if (double_string == NULL)
//	{
//		return -1;
//	}
//	strcpy(double_string, arr);
//	strcat(double_string, arr);
//	Assign(arr, double_string, len, count);
//	printf("%s", arr);
//	return 0;
//}

//字符串右旋，第二种方法
//int main()
//{
//	char arr[] = "aabbccdd";
//	int len = strlen(arr);
//	int count = 3;//右旋次数
//	rightrotate(arr, len, count);
//	printf("%s\n", arr);
//	return 0;
//}



//字符串右旋问题,第一种方法
//int main()
//{
//	char arr[] = "AABBCCDD";
//	int len = strlen(arr);
//	int count = 3;//右旋次数
//	Rightrotate(arr, len, count);
//	printf("%s\n", arr);
//	return 0;
//}