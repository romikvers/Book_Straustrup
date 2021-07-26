/*
Перелічити у рядку усі послідовності символіс "cd" і видалити ті з них, після яки йстоїть  літера "b"
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
#include "Windows.h"

using namespace std;

int Calculator(char* satz)
{
	char ch[] = "cd";
	char* pdest;
	int pos = 0,
		p = 0;
	while (pdest = strstr(satz + pos, ch))
	{
		p++;
		pos = (int)(pdest - satz + 1);
	}
	return p;
}
char* Delete(char* satz, const char* ch)
{
	char* t = new char[strlen(satz) + 1];
	char* k;
	int pos = 0,
		pos1 = 0;
	*t = 0;
	while ((k = strstr(satz + pos1, ch)) != NULL)
	{
		pos = (int)(k - satz + 1);
		strncat(t, satz + pos1, pos - pos1);
		cout << " t : " << t << endl;
		if (satz[pos + 1] == 'b') {
			pos += 1;
		}
		pos1 = pos;
	}
	strcat(t, satz + pos1);
	strcpy(satz, t);

	return 0;
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char satz[] = "cdsaj cdb sdcd cd cd cdb";
	char ch[] = "cd";
	//cin.getline(satz, 150);
	cout << "Satz : " << satz << endl;
	int Calc = Calculator(satz);
	cout << "Кількість : " << Calc << endl;
	Delete(satz, ch);
	cout << "Satz Modifikate : " << satz << endl;

	return 0;
}