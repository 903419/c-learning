#include "test.h"

int main()
{
	int select = 1;
	srand((int)time(0));
	while (select == 1)
	{
		Menu();
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			Game();
			printf("\nҪ��Ҫ����һ�֣�\n");
			break;
		case 2:
			break;
		default:
			break;
		}
	}
	return 0;
}