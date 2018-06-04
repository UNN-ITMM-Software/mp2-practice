#include "ScanTable.h"
#include "SortedTable.h"
#include "HashTable.h"

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>

using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	
	int c = 0;
	int k;
	int SIZE;

	cout << "����������, ������� ������ �������: ";
	cin >> SIZE;
	cout << endl;
	
	ScanTable A(SIZE);
	SortedTable B(SIZE);
	HashTable C(SIZE);

	while (c != 2)
	{
		system("cls");
		cout << "�������� ��������." << endl;
		cout << "1. �������" << endl;
		cout << "2. ��������" << endl;
		cout << "3. �����" << endl;
		cout << "��� �����: ";
		cin >> k;
		cout << endl;
		switch (k)
		{
			case 1:
			{
				string c;
				cout << "������� ������: ";
				cin.ignore();
				getline(cin, c);
				TPolinom F(c);
				try
				{
					A.Insert(c, &F);
				}
				catch (const char *ex)
				{
					cout << ex << endl;
				}
				try
				{
					B.Insert(c, &F);
				}
				catch (const char *ex)
				{
					cout << ex << endl;
				}
				try
				{
					C.Insert(c, &F);
				}
				catch (const char *ex)
				{
					cout << ex << endl;
				}
				cout << endl << "��������������� �������:" << endl;
				A.PrintTable();
				cout << endl << "������������� �������: " << endl;
				B.PrintTable();
				cout << endl << "���-�������: " << endl;
				C.PrintTable();
				cout << endl;
				break;
			}
			case 2:
			{
				string c;
				cout << "������� ������: ";
				cin.ignore();
				getline(cin, c);
				TPolinom F(c);
				try
				{
					A.Delete(c);
				}
				catch (const char *ex)
				{
					cout << ex << endl;
				}
				try
				{
					B.Delete(c);
				}
				catch (const char *ex)
				{
					cout << ex << endl;
				}
				try
				{
					C.Delete(c);
				}
				catch (const char *ex)
				{
					cout << ex << endl;
				}
				cout << endl << "��������������� �������:" << endl;
				A.PrintTable();
				cout << endl << "������������� �������: " << endl;
				B.PrintTable();
				cout << endl << "���-�������: " << endl;
				C.PrintTable();
				cout << endl;
				break;
			}
			case 3:
			{
				string c;
				cout << "������� ������: ";
				cin.ignore();
				getline(cin, c);
				TPolinom F(c);
				cout << endl;
				A.PrintTable();
				cout << endl;
				B.PrintTable();
				cout << endl;
				C.PrintTable();
				cout << endl;
				if (A.Search(c) != nullptr)
				{
					cout << endl << "������� � ��������������� �������: " << A.GetIndex() << endl;
				}
				else
				{
					cout << "������� �� ������. " << endl;
				}
				if (B.Search(c) != nullptr)
				{
					cout << endl << "������� � ������������� �������: " << B.GetIndex() << endl;
				}
				else
				{
					cout << "������� �� ������. " << endl;
				}
				if (C.Search(c) != nullptr)
				{
					cout << endl << "������� � ���-�������: " << C.GetIndex() << endl;
				}
				else
				{
					cout << "������� �� ������. " << endl;
				}
				break;
			}
		}

		cout << endl << "���������� ������ � ���������? " << endl;
		cout << "1. ��" << endl;
		cout << "2. ���" << endl;
		cout << "��� �����: ";
		cin >> c;
	}

	cin.get();
}