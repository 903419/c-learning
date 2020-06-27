#include "main.h"

int main()
{
	int arr[] = { 1,1,2,3,2,3,5,9,9,6 };
	int num = sizeof(arr) / sizeof(arr[0]);
	int x = 0;
	int y = 0;
	TwoSingleAf(arr, num, &x, &y);
	printf("两个单身狗：%d  和  %d\n", x, y);
	return 0;
}
//atoi
//int main()
//{
//	char arr[] = "-785k9857lk";
//	printf("%d\n", atoi(arr));
//	printf("%s\n", strerror(errno));
//	printf("my_atoi：%d\n",my_atoi(arr));
//	return 0;
//}