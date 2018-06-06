#include "monom.h"
#include "polinom.h"
#include <iostream>
#include <ostream>
#include "TablesUnordered.h"
#include "TablesOrdered.h"
#include "TablesHash.h"
using namespace std;

int main()
{

	polinom aff("1+x");
	setlocale(LC_ALL, "Russian");
	int c = 0;
	int k;
	int size;

	cout << "������� ������ �������" << endl;
	cin >> size;
	unordtable<string, polinom> A(size);
	string a;
	ordertable<string, polinom> B(size);
	hashtable<string, polinom> C(size);

	while (c != 1)
	{
		system("cls");
		cout << "�������� ��������" << endl;
		cout << "1 - �������" << endl;
		cout << "2 - ��������" << endl;
		cout << "3 - �����" << endl;
		cout << "4 - ������� �������" << endl;
		cin >> k;
		switch (k)
		{
		case 1:
		{
			string str;
			cout << "������� �������" << endl;
			cin >> str;
			polinom a(str);
			try { A.insert(str, a); }
			catch (...) { cout << "������������� ����" << endl; }
			try { B.insert(str, a); }
			catch (...) { cout << "������������� ����" << endl; }
			try { C.insert(str, a); }
			catch (...) { cout << "������������� ����" << endl; }
			cout << "��������������� :" << endl;
			cout << A << endl;
			cout << "������������� :" << endl;
			cout << B << endl;
			cout << "Hash :" << endl;
			cout << C << endl;
			break;
		}
		case 2:
		{
			string str;
			cout << "������� �������" << endl;
			cin >> str;
			polinom a(str);
			try { A.delet(str); }
			catch (...) { cout << "������� �� ����������" << endl; }
			try { B.delet(str); }
			catch (...) { cout << "������� �� ����������" << endl; }
			try { C.delet(str); }
			catch (...) { cout << "������� �� ����������" << endl; }
			cout << "��������������� :" << endl;
			cout << A << endl;
			cout << "������������� :" << endl;
			cout << B << endl;
			cout << "Hash :" << endl;
			cout << C << endl;
			break;
		}
		case 3:
		{
			string str;
			cout << "������� �������" << endl;
			cin >> str;
			polinom a(str);
			try { cout << "�������: " << A.search(str)->data; }
			catch (...) { cout << "������� �� ����������" << endl; }
			try { cout << "�������: " << B.search(str)->data; }
			catch (...) { cout << "������� �� ����������" << endl; }
			try { cout << "�������: " << C.search(str)->data; }
			catch (...) { cout << "������� �� ����������" << endl; }
			break;
		}
		case 4:
		{
			cout << "��������������� :" << endl;
			cout << A << endl;
			cout << "������������� :" << endl;
			cout << B << endl;
			cout << "Hash :" << endl;
			cout << C << endl;
			break;
		}
		default:
		{
			cout << "������" << endl;
			break;
		}
		}

		cout << "���� ������ �����, ������� 1" << endl;
		cin >> c;
	}
	return 0;
}


