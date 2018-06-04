#pragma once

#include "monom.h"
#include "list.h"
#include <iostream>
#include <string>


using namespace std;


class polynom
{
private:
	list<monom> list_pol;		                                                                                     //������� - ������ �� �������
public:
	list<monom> similar_terms(list <monom> sp);                                                                      //�������� ���������
	polynom(const string pol = "" );                                                                                 //������ ������
	polynom(const polynom& pol);                           							                                 //����������� �����������
	polynom& operator=(const polynom &pol);                                                                          //������������
	polynom operator+(const polynom& pol) const;			                                                         //�������� ���������
	polynom operator*(const double a) const;				                                                         //��������� �� ��������� �����
    friend polynom operator*(const double a,const polynom& pol) { return pol*a; }	                                 //��������� �� ��������� ������
	polynom operator-(const polynom& pol) const { return *this + pol*(-1.0); }		                                 //�������� ���������
	polynom operator*(const polynom& pol) const;			                                                         //��������� ��������� 	
    polynom operator-() const { return (-1.0)*(*this); }                                                             //������� �����
    friend ostream& operator<<(ostream &ostr, const polynom &pol);	                                                 //�������� ������
	bool operator==(const polynom& pol) const { return list_pol == pol.list_pol; }		
	bool operator!=(const polynom& pol) const { return list_pol != pol.list_pol; }

	polynom(list<monom> &list) : list_pol(list) {}								                                     //����������� �� ������
};
