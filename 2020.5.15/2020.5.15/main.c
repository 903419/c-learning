#include "main.h"

int Max(int a, int b)
{
	int num = a * b;
	int i = 0;
	for (i = 2; i < 10; i++)
	{
		if ((0 == a % i) && (0 == b % i))
		{
			num /= i;
			break;
		}
	}
	return num;
}

//µ¥´ÊÄæĞòÊä³ö
void Reverse(char *p, int start,int end)
{
	while (start < end)
	{
		char temp = p[start];
		p[start] = p[end];
		p[end] = temp;
		start++, end--;
	}
}

void Reverse1(char *p,int n)
{
	int begin = 0;
	char i = 0;
	for (; begin < n; begin++)
	{
		if (p[begin] == ' '&&p[begin] != '\0')
		{
			Reverse(p, i, begin - 1);
			i = begin + 1;
		}
	}
}

int main()
{
	char arr[] = "I am student I am boy.";
	int end = strlen(arr) - 1;
	int start = 0;
	Reverse(arr,start,end);
	Reverse1(arr,end);
	printf("%s", arr);
	return 0;
}

//0000 0000 0000 0000 0000 0000 0110 0011   99
//0000 0000 0000 0000 0000 0000 0110 0010   99-1

//0000 0000 0000 0000 0000 0000 0110 0010  
//0000 0000 0000 0000 0000 0000 0110 0001


//0000 0000 0000 0000 0000 0000 0110 0000
//0000 0000 0000 0000 0000 0000 0101 1111

//0000 0000 0000 0000 0000 0000 0100 0000
//0000 0000 0000 0000 0000 0000 0011 1111






//int main()
//{
//	char arr1[] = "abcdefghijk";
//	char arr2[20] = {0};
//	my_strcpy(arr2,arr1);//½«1¿½±´µ½2
//	printf("%s\n", arr1);
//	printf("%s\n", arr2);
//}


//int main()
//{
//	char arr[] = "abcdefghijk";
//	printf("%d\n", strlen(arr));
//	printf("%d\n",my_strlen(arr));
//	return 0;
//}



//int main()
//{
//	int i = 0;
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	for (i = 0; i <= 12; i++)
//	{
//		arr[i] = 0;
//		printf("hello bit\n");
//	}
//	return 0;
//}






//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int num = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	for (; i < num; i++)
//	{
//		printf("%d ",arr[i]);
//	}
//	printf("\n");
//	Swap(arr, num);
//	for (i=0; i < num; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}