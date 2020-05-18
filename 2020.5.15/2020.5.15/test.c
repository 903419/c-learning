#include "main.h"

void my_strcpy(char *m, char *n)
{
	if (n == NULL)
	{
		return;
	}
	while (1)
	{
		if (*n != NULL)
		{
			*m++ = *n++;
		}
		else
		{
			*++m = *n;
			break;
		}
	}
}



int my_strlen(char *p)
{
	if (p == NULL)
	{
		return 0;
	}
	int count = 0;
	while (*p)
	{
		p++;
		count++;
	}
	return count;
}


void Swap(int *p, int n)
{
	int i = 0;
	for (; i < n; i++)//ц╟ещ
	{
		int j = 0;
		for (; j < n - i - 1; j++)
		{
			if ((p[j] % 2 == 0) && (p[j + 1] % 2 != 0))
			{
				int temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
		}
	}
}