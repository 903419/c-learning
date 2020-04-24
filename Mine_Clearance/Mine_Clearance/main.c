#include "test.h"

void Menu()
{
	printf("###############################\n");
	printf("##     1.Play      2.Quit    ##\n");
	printf("###############################\n");
	printf("Please input your choice:>");
}
int main()
{
	int select = 1;
	while (select == 1)
	{
		Menu();
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			Game();
			printf("\n要不要再玩一局？\n");
			break;
		case 2:
			break;
		default:
			break;
		}
	}
	return 0;
}