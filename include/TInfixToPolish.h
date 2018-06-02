#ifndef TINFIXTOPOLISH
#define TINFIXTOPOLISH
#include <iostream>
#include "TStack.h"
#include "TList.h"
#include <string>
#include  <map>
using namespace std;


class TInfixToPolish{
	private:
		static int GetOperation(char); //�������� ��������� ��������
		static map<char, float> ReadValue(string); //������������ ���������� ���� map,��� ����-������ ��������,a ��������-�������� ��������
	public:
		static void Calk(string); // ���������� ��������������� ���������
		static string InfixToPolish(string); //������� ��������������� ��������� � ����������� �����
		static bool Brace(string); //��������� �� ���������� ������������� � ������������� ������?!
		static bool Protect(string); // ��������� �� ������� ������?!
};

#endif