#include "main.h"


int main()
{
	char dst[20] = "abcdefg";
	char src[] = "ABCDEFG";
	printf("%s", my_strncpy(dst, src, 5));
	return 0;
}


//strncat
//int main()
//{
//	char dst[20] = "abcdefg";
//	char src[] = "abcdefg";
//	printf("%s", my_strncat(dst, src, 9));
//	return 0;
//}


//strtok
//int main()
//
//{
//
//	char s[] = "ab-cd  : ef;gh :i-jkl;mnop;qrs-tu: vwx-y;z";
//	char *delim = "-: ;";
//	char *p;
//	printf("%s\n", strtok(s, delim));
//	while ((p = strtok(NULL, delim)))
//		printf("%s\n", p);
//	printf("\n");
//
//	return 0;
//
//}


//int main()
//{
//	char dst[10];
//	char src[] = "abcdefghijk";
//	memcpy(dst, src, 30);
//	return 0;
//}

//memmove
//int main()
//{
//	int src[15] = { 1,2,3,4,5,6,7,8,9 };
//	int count = sizeof(src);
//	int dst[16] = { 0 };
//	char src2[] = "hello world!";
//	char dst2[16] = "";
//	int num = my_strlen(src2);
//	my_memmove(dst, src, count);
//	my_memmove(src+ 2, src, count);
//	my_memmove(dst2, src2, num);
//	my_memmove(src2 + 2, src2, num);
//	return 0;
//}


//memcpy
//int main()
//{
//	int arr1[] = { 1,2,3,4,5,6,7,8,9 };
//	int arr2[15] = {0};
//	my_memcpy(arr2, arr1, sizeof(arr1));
//	return 0;
//}


//strstr
//int main()
//{
//	const char *str1 = "abcdABCD";
//	const char *str2 = "CDab";
//	printf("%s\n", strstr(str1, str2));
//	printf("%s\n",my_strstr(str1,str2));
//	return 0;
//}


//strlen
//int main()
//{
//	char str[] = "ABCD";
//	printf("%d\n", my_strlen(str));
//	return 0;
//}

//strcpy
//int main()
//{
//	char str1[20] = "";
//	char str2[] = "ABCD";
//	Cpy(str1, str2);
//	printf("%s\n", str1);
//	return 0;
//}

//strcmp
//int main()
//{
//	char str1[] = "abcde";
//	char str2[] = "abcd";
//	//printf("%d\n", strcmp(str1, str2));
//	printf("%d\n", Cmp(str1, str2));
//	return 0;
//}

//strcat
//int main()
//{
//	char str1[80] = "abcd";
//	int num1 = strlen(str1);
//	char str2[] = "ABCD";
//	int num2 = strlen(str2);
//	Link(str1, str2, num1, num2);
//	printf("%s", str1);
//	return 0;
//}