#pragma once

#include <iostream>
#include <string>
#include "Monom.h"
#include "list.h"

using std::string;
using std::ostream;
using std::cout;
using std::endl;

class Polinom {

private:
	
	Rlist<Monom> Pol_List;

public:
	
	//������������
	Polinom(const string expr);
	Polinom(const Polinom& POL);
	
	//���������
	Polinom operator+ (const Polinom&) const;
	Polinom operator- (const Polinom& POL) const { return (*this + POL*(-1)); }
	Polinom operator* (const Polinom&) const;// ��������� �������� �� �������
	Polinom operator* (const double) const; // ��������� �������� �� ��������� ������
	

	
	bool operator== (const Polinom& POL) const { return Pol_List == POL.Pol_List; }
	bool operator!= (const Polinom& POL) const { return Pol_List != POL.Pol_List; }

	Rlist <Monom> FindSimilar (Rlist <Monom> POL); // �������� �������� ���������
    Rlist<Monom> Parsing (const string);// �������� ������ �� ������


	friend Polinom operator* (const double CONST , const Polinom& POL) { return POL*CONST; } // ��������� �������� �� ��������� �����
	friend ostream& operator<< (ostream& os, const Polinom&);
};