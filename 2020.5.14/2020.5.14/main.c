#include "main.h"

int main()
{
	int money = 0;
	printf("输入你的钱数money：->");
	scanf("%d", &money);
	printf("可以喝%d瓶汽水\n",Soda(money));
	return 0;
}