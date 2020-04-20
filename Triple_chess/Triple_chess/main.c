#include "test.h"

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
			printf("\n要不要再来一局！\n");
			break;
		case 2:
			break;
		default:
			break;
		}
	}
	return 0;
}