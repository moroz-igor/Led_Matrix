#include "pch.h"
#include <iostream>
#include <typeinfo>
#include "windows.h"
#include <string>
using namespace std;
		char comparator(char leter, char library[], int num);
		const int maxlen = 40;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char library[] = " абвггдежзиіїйклмнопрстуфхцчшщьюя";
	unsigned int modules = 0;
	string start = "0,";
do {
		cout << "\n\tВведите кол-во матричных модулей: ";
		cin >> modules;
		for (unsigned int i = 0; i < modules * 2 - 1; i++)
		{
			start += "0,";
		}
		while (modules > 8) {
			cout << "\n\tКол-во не должно превышать \' 8 \'"; break;
		}
} while (modules > 8);
	     cout << "\n\tВведите текст бегущей строки: ";
do {
	    int *resDigit = (int *)calloc(maxlen, sizeof(int));
		char user[maxlen];
		string result, temp, usercin;
		cout << "\n\t";
		std::getline(std::cin, usercin);
		if(usercin.length() <= maxlen){
			cout << "\n\t";
			cout << "Массив верификации - \' user_string[] \' : " ;
				for (unsigned int  i = 0; i < usercin.length(); i++)
				{
					user[i] = usercin[i];
				}
				cout << "\n\t";
				for (unsigned int i = 0; i < usercin.length(); i++)
				{
					resDigit[i] = comparator(user[i], library, sizeof(library) - 1);
					//cout << resDigit[i] << " ";
					if (resDigit[i] < 10)
					{
						temp = resDigit[i] + '0';
						(i != usercin.length() -1) ? temp += "," : temp;
					}
					else {
						string rank_1, rank_2;
						rank_1 = resDigit[i] / 10 + '0';
						rank_2 = resDigit[i] % 10 + '0';
						temp = rank_1 + rank_2;
						(i != usercin.length() -1) ? temp +=  "," : temp ;
					}
					result = result + temp;
				}
					result = start + result;
						cout << "\n\n\t";
						cout << result << endl;
						cout << "\n\n\t";
					free(resDigit);

		}
		else {	cout << "ERROR!\tNUMBER OVERFLOW" << endl; };
				cout << "Для выхода из программы закройте окно "<< endl;
				cout << "\tДля продолжения введите новую строку"<< endl;
} while (1);
}
char comparator(char leter, char library[], int num) {
	int i = 0;
	for (i = 0; i < num; i++)
	{
		if (library[i] == leter)break;
	}
	return i;
}
