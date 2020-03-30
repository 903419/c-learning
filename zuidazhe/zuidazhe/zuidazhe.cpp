

#include "pch.h"
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char st[3][20], string[20];
	int i;
	cout << "输入三个字符：\n";
	for (i = 0; i < 3; i++)
		cin.getline(st[i], 20);
	if (strcmp(st[0], st[1]) > 0)
		strcpy_s(string, st[0]);
	else
		strcpy_s(string, st[1]);

	if (strcmp(st[2],string) > 0)
		strcpy_s(string, st[2]);
	else
		strcpy_s(st[2],string);
	cout << string << endl;
	return 0;

}
