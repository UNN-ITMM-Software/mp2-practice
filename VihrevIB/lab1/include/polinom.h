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
	Polinom(const string Line = "" );
	Polinom(Rlist<Monom> &P2) : Pol_List(P2) {}
	Polinom(const Polinom& POL) : Pol_List(POL.Pol_List) {};  //
	
	//���������
	Polinom operator+ (const Polinom&) const;
	Polinom operator- (const Polinom& POL) const { return (*this + POL*(-1)); }
	Polinom operator* (const Polinom& POL) const;// ��������� �������� �� �������
	Polinom operator* (const double c) const; // ��������� �������� �� ��������� ������
	

	
	bool operator== (const Polinom& POL) const { return Pol_List == POL.Pol_List; }
	bool operator!= (const Polinom& POL) const { return Pol_List != POL.Pol_List; }

	Rlist <Monom> FindSimilar (Rlist <Monom> POL); // �������� �������� ���������
    Rlist<Monom> Parsing (const string Line);// �������� ������ �� ������


	friend Polinom operator* (const double C , const Polinom& POL) { return POL*C; } // ��������� �������� �� ��������� �����
	friend ostream& operator<< (ostream& os, const Polinom&);
};