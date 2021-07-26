#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;

int main()
{
	vector<string> names;
	vector<int> years;
	string name_priz;
	int year;
	char ch;
	int i = 0;
	int gesetz = 0;
	int siz_nam = size(names);
	do {
		cout << "Character input name and year :"; cin >> name_priz >> year;
		for (i = 0; i < siz_nam; i++)
		{
			if (name_priz == names[i] && year == years[i])
			{	
				gesetz = 1;
				cout << "Data already is in file" << endl;
				break;
			}
		}
		if (gesetz == 0)
		{
			names.push_back(name_priz);
			years.push_back(year);
		}

		cout << "Continue(Y/N y/n)? :"; cin >> ch;
	} while (ch == 'Y' || ch == 'y');
	int siz_nams = size(names);
	cin.clear(); // очищаем ввод
	cin.good(); // оповещаем что все ок
	for (i = 0; i < siz_nams; i++)
	{
		cout << "names :" << names[i] << endl;
		cout << "years :" << years[i] << endl;
	}
	cout << "\nreturn\n" << endl;
	return 0;
}