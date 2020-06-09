#include "main.h"

int main()
{
	char str[] = "ABCD";
	printf("%d\n", my_strlen(str));
	return 0;
}

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