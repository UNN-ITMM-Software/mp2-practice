#pragma once

#include <iostream>
#include <string>
#include <algorithm>
#include "Monom.h"
#include "list.h"


using std::string;
using std::ostream;
using std::cout;
using std::cin;
using std::endl;

class Polinom {

protected:
	
	Rlist<Monom> Monoms;
	string name;
	//��������������� ������
	Rlist <Monom> Simplify(Rlist <Monom> POL); // �������� �������� ���������
	Rlist<Monom> Parsing(const string Line);// �������� ������ �� ������

public:
	
	//������������
	Polinom(const string Line = "" ); // ����������� �� ������
	Polinom(const int A) { Monoms.InsertAfter(Monoms.GetCurr(), A); };
	Polinom(const Monom m) { Monoms.InsertAfter(Monoms.GetCurr(),m); }// �����������  �������������� ����: �� ������
	Polinom(const Rlist<Monom> &P2) : Monoms(P2) {}; // ����������� �������������� ����: �� ������ 
	Polinom(const Polinom& POL) : Monoms(POL.Monoms) {};  //����������� �����������
	
	//���������
	Polinom operator+ (const Polinom&) const;
	Polinom operator- (const Polinom& POL) const { return (*this + POL*(-1.0)); }
	Polinom operator* (const Polinom& POL) const;// ��������� �������� �� �������
	Polinom operator* (const double c) const; // ��������� �������� �� ��������� ������
	
	bool operator== (const Polinom& POL) const { return Monoms == POL.Monoms; }
	bool operator!= (const Polinom& POL) const { return Monoms != POL.Monoms; }

	friend Polinom operator* (const double C , const Polinom& POL) { return POL*C; } // ��������� �������� �� ��������� �����
	friend ostream& operator<< (ostream& os, const Polinom&);
};