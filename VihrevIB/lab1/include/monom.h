#pragma once
// �����
class Monom
{
public:
	double coeff; //�����������
	unsigned int abc; // �������
	
	//�����������
	Monom(double COEFF = 0 , unsigned int ABC = 0) { coeff = COEFF; abc = ABC;}
	
	//���������
	bool operator< (const Monom& m) const { return (abc<m.abc); }
	bool operator> (const Monom& m) const  { return (abc>m.abc); }
	bool operator==(const Monom& m) const { return (abc == m.abc && coeff == m.coeff); }	//
	bool operator!=(const Monom& m) const { return !(*this == m); }
	
	Monom& operator=(const Monom& m) { coeff = m.coeff; abc = m.abc; return *this; }
};