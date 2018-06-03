#include <iostream>
#include <string>
#include <locale.h>
#include "Postfix.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "������� ����������� ��������������� ��������� �� ��������� ����� � �����������" << endl;
	cout << "������� ������������� ����� ���������: " << endl;
	string expression;
	cin >> expression;
	string notation;
	float result;
	try {
		notation = Postfix::postfix_notation(expression);
		result = Postfix::postfix_calculation(notation);
	}
	catch (...)
	{
		cout << "������! ������� ��������� ��������!" << endl;
		return 1;
	}
	cout << endl;
	cout << "����������� �����: " << notation << endl;
	cout << "���������: " << result << endl;
	system("pause");
}
