#ifndef POLISH_POSTFIX_H
#define POLISH_POSTFIX_H

#include <iostream>
#include <string>
#include <map>

#include "Stack.h"
using namespace std;

class postfix
{
private:
	static int GetOperationPtr(char op);				//�������� ��������� ��������
	static int IsOperation(char op);					//�������� �� ���� ��������
	static bool Operand(const char Exp);
	static float calc_op(float one, float two, char op);
public:
	/* static bool Operand(const char Exp);
	static float calc_op(float one, float two, char op); */
	static char* ConvertToPolish(char *Exp, int len);				//�������������� � �������� �����
	static float ConvertToInfix(char* Exp, int len);				//������� �� ����������� ����� � ������� ���������
};

#endif