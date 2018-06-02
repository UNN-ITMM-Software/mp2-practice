#include <iostream>
#include <locale.h>
#include <conio.h>
#include "TStack.h"

using namespace std;


void main()
{
	setlocale(LC_CTYPE, "Russian");
	TStack<int>* st = new TStack<int>;
	try{
		cout << " ������� ���������� ��������� � �����" << endl;
		int n;
		cin >> n;
		int k;
		for (int i = 0; i < n; i++)
		{
			cout << "������� ������� ";
			cin >> k;
			st->Push(i);
		}
		cout << "� ���� ��������:" << endl;
		st->Print();

		cout << endl << "����� ����������� ����� " << endl;
		for (int i = 0; i < n; i++)
		{
			st->Pop();
			st->Print();
		}
	}
	catch (const char *exeption){
		cerr << exeption << endl;
	}
}