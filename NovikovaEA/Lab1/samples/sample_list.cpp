#include "polinom.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	{
		int f;
		do
		{
			cout << "�������� �������� � ����������:" << endl;
			cout << "1 - ������� ��������" << endl;
			cout << "2 - �������� ��������" << endl;
			cout << "3 - �������� ������� �� ���������" << endl;
			cin >> f;
			cin.ignore();
			if (f == 1)
			{
				string s;
				cout << "������� ������ �������" << endl;
				getline(cin, s);
				polinom p1(s);
				cout << "������� ������ �������" << endl;
				getline(cin, s);
				polinom p2(s);
				polinom p3 = p1 + p2;
				cout << "���������: " << p3 << endl;
			}
			else
				if (f == 2)
				{
					string s;
					cout << "������� ������ �������" << endl;
					getline(cin, s);
					polinom p1(s);
					cout << "������� ������ �������" << endl;
					getline(cin, s);
					polinom p2(s);
					polinom p3 = p1 * p2;
					cout << "���������: " << p3 << endl;
				}
				else
					if (f == 3)
					{
						string s;
						cout << "������� �������" << endl;
						getline(cin, s);
						polinom p(s);
						cout << "������� �����" << endl;
						double d;
						cin >> d;
						p = p * d;
						cout << "���������: " << p << endl;
					}
					else
						cout << "�������� ��� ���" << endl;
			cout << "������ ����������?" << endl;
			cout << "1 - ��" << endl;
			cout << "2 - ���" << endl;
			cin >> f;
		} while (f == 1);
		return 0;
	}
}




