#include "main.h"

//�������
int main()
{
	int arr[][4] = { 1,3,5,7,4,6,8,10,6,9,12,15,8,13,15,17 };
	int number = 0;
	printf("������ҵ���:>");
	scanf("%d", &number);
	printf("%d\n",SearchNumber(arr, number));
	return 0;
}

//�ַ�����ת
//int main()
//{
//	int i = 1;
//	int judge = 1;//�ж�
//	char arr[] = "AABCD";
//	char arr1[] = "BCDAE";
//	int num = strlen(arr);
//	for (; i < num; i++)
//	{
//		Intermediate(arr, num, Sinistral);//�ַ�����ת
//		if (0 == strcmp(arr, arr1))//�Ƚ����ַ����Ƿ���ͬ
//		{
//			judge = 0;
//			break;
//		}
//	}
//	if (0 == judge)
//	{
//		printf("�ַ���arr1���ַ���arr��ת֮����ַ���\n");
//	}
//	else
//	{
//		printf("�ַ���arr1�����ַ���arr��ת֮����ַ���\n");
//	}
//	return 0;
//}




//ģ��qsort
//int main()
//{
//	int arr[] = { 1,4,5,3,9,7,6,1,4,8,3,5 };
//	int num = sizeof(arr) / sizeof(arr[0]);
//	print(arr, num);
//	myqsort(arr,num,sizeof(int),cmpInt);
//	print(arr, num);
//	return 0;
//}


//ʵ�ֿ�qsort
//int main()
//{
//	int arr[] = { 1,4,5,3,9,7,6,1,4,8,3,5 };
//	int num = sizeof(arr) / sizeof(arr[0]);
//	print(arr, num);
//	qsort(arr,num,sizeof(int),cmp);
//	print(arr, num);
//	return 0;
//}