#include "polinom.h"
#include <conio.h>
#include "table.h"
#include "sorted_table.h"
#include "scan_table.h"
#include "hash_table.h"

void main()
{
	setlocale(LC_ALL, "Russian");
	cout << "�������� ��������:" << endl;
	char c = 0, str;
	Scantable<TPolinom> Tab1;
	SortedTable<TPolinom> Tab2;
	Hashtable<TPolinom> Tab3;
	string key;
	TPolinom P;

	while (c != ' ')
	{
		cout << "1. �������" << endl;
		cout << "2. ��������" << endl;
		cout << "3. �����" << endl;
		cout << "4. �������� �������" << endl;
		cin >> str;
		switch (str)
		{
		case '1':
		{
			cout << "������� �������:" << endl;
			getline(cin, key);
			if (key == "")
				getline(cin, key);
			P = TPolinom(key);
			try
			{
				Tab1.Insert(P, key);
				Tab2.Insert(P, key);
				Tab3.Insert(P, key);
			}
			catch (...)
			{
				cout << "������" << endl;
			}
			break;
		}

		case '2':
		{
			cout << "������� �������:" << endl;
			getline(cin, key);
			if (key == "")
				getline(cin, key);
			try
			{
				Tab1.Delete(key);
				Tab2.Delete(key);
				Tab3.Delete(key);
			}
			catch (...)
			{
				cout << "������" << endl;
			}
			break;
		}
		case '3':
		{
			cout << "������� �������:" << endl;
			getline(cin, key);
			if (key == "")
				getline(cin, key);
			try
			{
				Tab1.Search(key);
				cout << "Scantable: " << endl << Tab1 << endl;
				cout << "-------------------------" << endl;
				cout << "����� � Scantable: " << Tab1.Search(key) << endl;
				cout << "-------------------------" << endl;
				cout << "SortedTable:" << endl << Tab2 << endl;
				cout << "-------------------------" << endl;
				cout << "����� � SortedTable: " << Tab2.Search(key) << endl;
				cout << "-------------------------" << endl;
				cout << "Hashtable:" << endl << Tab3 << endl << endl;
				cout << "-------------------------" << endl;
				cout << "����� � Hashtable: " << Tab3.Search(key) << endl;
				cout << "-------------------------" << endl;
			}
			catch (...)
			{
				cout << "������" << endl;
			}
			break;
		}
		case '4':
		{
			cout << "Scantable: " << endl << Tab1 << endl;
			cout << "-------------------------" << endl;
			cout << "SortedTable:" << endl << Tab2 << endl;
			cout << "-------------------------" << endl;
			cout << "Hashtable:" << endl << Tab3 << endl << endl;
			cout << "-------------------------" << endl;
		}
		default:
			cout << "���������� �����" << endl;
		}
		cout << "������� ������, ����� �����" << endl;
		cout << "������� ����� ������, ����� ����������" << endl;
		c = _getch();
	}
}