#pragma once

#include <iostream>
#include <string>
#include <algorithm>
#include "monom.h"
#include "List.h"

#define X 120//��� x

using namespace std;

class Polinom
{
private:
	List<Monom> list_m;
public:
	Polinom(const string Line = "" ); // ����������� �� ������
	Polinom(const Monom m) { list_m.InsertAfter(list_m.GetCurr(),m); }// �����������  �������������� ���� �� ������
	Polinom(const List<Monom> &p2) { this->list_m = p2; }; // ����������� �������������� ���� �� ������ 
	Polinom(const Polinom& pol) { this->list_m = pol.list_m; };  //����������� �����������

	Polinom operator+ (const Polinom&) const;
	Polinom operator- (const Polinom& pol) const { return (*this + pol *(-1.0)); }
	Polinom operator* (const Polinom& pol) const;
	Polinom operator* (const double c) const; 
	
	bool operator== (const Polinom& pol) const { return list_m == pol.list_m; }
	bool operator!= (const Polinom& pol) const { return list_m != pol.list_m; }

	friend ostream& operator<< (ostream& os, const Polinom&);
};