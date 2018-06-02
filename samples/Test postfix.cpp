#include <iostream>
#include <algorithm>
#include <locale.h>
#include "TInfixToPolish.h"
#include <string>
#include <conio.h>
using namespace std;


void main(){
	setlocale(LC_CTYPE, "russian");
	string str;
	cout << " ������� �������������� ���������: "<<endl;
	try {
		getline(cin, str);
		transform(str.begin(), str.end(), str.begin(), tolower);
		cout << " ������ �������� ������ � ������ �������� " << endl;
		cout << str << endl;
		while ((!TInfixToPolish::Brace(str))||(!TInfixToPolish::Protect(str)))
		{
			cout << " ��������� ���� ";
			getline(cin, str);
		}
		str = TInfixToPolish::InfixToPolish(str);
		cout << " ����������� �����: " << str << endl;
		TInfixToPolish::Calk(str);
	}
	catch (const char* exeption)
	{
		cerr << exeption << endl;
	}
	std::system("pause");
}