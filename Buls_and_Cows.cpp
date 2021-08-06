/*
* 
Игра «Быки и коровы». Правила:

   программа генерирует случайным образом 4-значное число;

   пользователю предлагают угадать сгенерированное программой число;

   за каждую угаданную пользователем цифру, стоящую на правильной позиции, он получает «корову»;

   за каждую угаданную пользователем цифру, стоящую на неправильной позиции, он получает «быка»;

   после каждого предположения пользователю должно выводиться количество «коров» и «быков», которые он заработал;
*
*/


#include <iostream>
#include <iomanip>
#include <vector>
#include <time.h>
#include <windows.h>

using namespace std;

int verify(const vector<int> value, const int contain);
void Print_at_Monitor(const vector<int> bulls, const vector<int> cows);

int main()
{
    srand(unsigned(time(NULL)));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    vector<int> value{  };
    int contain = 0,
        game_over = 0,
        finish = 0,
        check = 0;
    char ch; // continue
    do
    {
        cout << "\n   Комп'ютер генерує число, яке складає чотири числа і ти повинен їх відгадати\n "
           " Бик означає що число розташоване на правильній позиці, корова - означає наявність\n "
           " числа в цьому числі, але не розташоване в правильній позиції. " << endl;
        cout << "\n   You have three attempts!" << endl;
        game_over = 0;
        for (int i = 0; i < 4; i++)   // заповнює рандомними числами
        {
            check = 0;
            do
            {
                contain = 1 + rand() % 9;
                check = verify(value, contain);
  
            } while (check == -1);
            value.push_back(contain);
        }
        vector<int> input { };
        vector<int> bulls{ };
        vector<int> cows{ };
        int zahl;      // поміщається число яке вводить гравець
         
        do {
            finish = 0;
            for (int i = 0; i < 4; i++)
            {
                check = 0;
                cout << endl;
                do
                {
                    cout << "Character input :"; cin >> zahl;
                    check = verify(input, zahl);    // якщо значення повторюється, повернути -1
                    if (check == -1)
                    {
                        cout << "Repeatedly!" << endl << "\nPlease, input another value!" << endl;
                    }
                } while (check == -1);
                input.push_back(zahl);
            }

            for (int j = 0; j < 4; j++)
            {
                if (value[j] == input[j])      // шукаємо бика... 
                {
                    finish++;
                    bulls.push_back(input[j]);
                }
                else {                                 // шукаємо корову...
                    for (int i = 0; i < 4; i++)     //  перевіряємо на наявність корівки
                    {
                        if (value[j] == input[i])
                        {
                            cows.push_back(input[i]);
                            break;
                        }
                    }
                }
            }
            if (finish == value.size())    // при наявності максимальної кількості биків, завершити гру
            {
                cout << "\nFinish!!!!!\n" << "You win!!!!!!" << endl;
                return 0;
            }
            game_over++;    // рахує кількість проб вгадати число
            if (game_over == 3)
            {
                cout << "\nGAME OVER!!!\n YOU LOST!!!" << endl;
                cout << " It is :";
                for (int i = 0; i < value.size(); i++)
                {
                    cout << value[i];
                }
                cout << endl;
                return 0;
            }
            Print_at_Monitor(bulls, cows);  // виводим на екран
           // cout << "Bull is " << bull << ", and cow is " << cow << endl << endl;
            input.clear();
            bulls.clear();
            cows.clear();
        } while (finish < 4);
            cout << "To plaing else(y/n)?"; cin >> ch;
    } while (ch == 'Y' || ch == 'y');

    return 0;
}
int verify(const vector<int> bedeuted, const int data)
{
    for (int i = 0; i < bedeuted.size(); i++)
    {
        if (data == bedeuted[i])
        {
            return -1;
        }
    }
    return 0;
}
void Print_at_Monitor(const vector<int> bulls, const vector<int> cows)
{
    cout << endl;
    int size_bulls = bulls.size();
    int size_cows = cows.size();
    if (1 < size_bulls)
    {
        cout << "Bulls are ";
        for (int i = 0; i < size_bulls; i++)
        {
            cout << bulls[i] << " ";
        }
        cout << "." << endl;
    }
    else  if (1 == size_bulls)
    {
        cout << "Bull is " << bulls[0] << "." << endl;
    }
    else
        cout << "Bull is not!" << endl;
    if (1 < size_cows)
    {
        cout << "Cows are ";
        for (int i = 0; i < size_cows; i++)
        {
            cout << cows[i] << " ";
        }
        cout << "." << endl;
    }
     else if (1 == size_cows)
        {
            cout << "Cow is " << cows[0] << "." << endl;
        }
     else 
         cout << "Cow is not!" << endl;
}