#include <iostream>
#include "windows.h"

using namespace std;

void Gleich1();

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	Gleich1();
	
	return 0;
}
void Gleich1()
{
	int i;
	long long S = 1;
	int P = 0;
	int zahl = 2;
	for (i = 2; i <= 64; i++)
	{
		P = zahl * zahl;
		S += P;
		if (S >= 2000000)
		{
			cout << "reshitok: " << i << " for 1000 zeron" << endl;
			break;
		}
		zahl = P;
	}
	cout << "\nS :" << S << endl;
	cout << "i: " <<  i;
}