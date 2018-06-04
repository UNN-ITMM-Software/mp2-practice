#include "TPolinom.h"

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>

using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");

	TPolinom A;
	TPolinom B;
	TPolinom C;
	string s;
	string c;

	int i = 1;
	int j = 0;
	int k;
	while (i == 1)
	{
		cout << "��� ������ ������� � ���������� ?" << endl;
		cout << "1. ����� ���������." << endl;
		cout << "2. �������� ���������." << endl;
		cout << "3. ������������ ���������." << endl;
		cout << "4. ������������ �������� � ����a." << endl;
		cout << "5. ������������ ����� � ��������." << endl;
		cout << "��� �����: ";
		cin >> j;
		cout << endl;

		if (j == 1)
		{
			cout << "������� ������ �������: ";
			cin.ignore();
			getline(cin, s);
			cout << endl;
			cout << "������� ������ �������: ";
			getline(cin, c);
			cout << endl;

			TPolinom A(s);
			TPolinom B(c);
			C = A + B;
			cout << C;
			cout << endl;
		}

		if (j == 2)
		{
			cout << "������� ������ �������: ";
			cin.ignore();
			getline(cin, s);
			cout << endl;
			cout << "������� ������ �������: ";
			getline(cin, c);
			cout << endl;

			TPolinom A(s);
			TPolinom B(c);
			C = A - B;
			cout << C;
			cout << endl;
		}

		if (j == 3)
		{
			cout << "������� ������ �������: ";
			cin.ignore();
			getline(cin, s);
			cout << endl;
			cout << "������� ������ �������: ";
			getline(cin, c);
			cout << endl;

			TPolinom A(s);
			TPolinom B(c);
			C = A * B;
			cout << C;
			cout << endl;
		}

		if (j == 4)
		{
			cout << "������� �������: ";
			cin.ignore();
			getline(cin, s);
			cout << endl;
			cout << "������� �����: ";
			cin >> k;
			TPolinom A(s);
			C = A * k;
			cout << C;
			cout << endl;
		}
		
		if (j == 5)
		{
			cout << "������� �����: ";
			cin >> k;
			cout << endl;
			cout << "������� �������: ";
			cin.ignore();
			getline(cin, s);
			cout << endl;
			TPolinom A(s);
			C = k * A;
			cout << C;
			cout << endl;
		}

		cout << endl;
		cout << "��������� ������ � ��������� ? " << endl;
		cout << "1. ��" << endl;
		cout << "2. ���" << endl;
		cout << "��� �����: ";
		cin >> i;
		cout << endl;
	}

	cin.get();
}