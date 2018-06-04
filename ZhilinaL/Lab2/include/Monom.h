#pragma once

class monom
{
public:
	double coeff;//����������� ������				                                   
	unsigned int abc;//������� ������, x^a,y^b,z^c
	monom(double c = 0, unsigned int a = 0);//����������� � �����������                  
	monom& operator=(const monom& m);//���������� ��������� ������������                     
	bool operator< (const monom& m) const;//���������� ��������� ������, ���������� ����� ������� � �����.
	bool operator> (const monom& m) const;//���������� ��������� ������, ���������� ����� ������� � �����.
	//���������� ���������� ���������
	bool operator==(const monom& m) const;
	bool operator!=(const monom& m) const;
};
monom::monom(double c, unsigned int a)
{
	coeff = c;
	abc = a;
}

monom& monom:: operator=(const monom& m)
{
	coeff = m.coeff;
	abc = m.abc;
	return *this;
}

bool monom:: operator< (const monom& m) const
{
	bool res = true;
	if (abc >= m.abc)
		res = false;
	return res;
}

bool monom:: operator> (const monom& m) const
{
	bool res = true;
	if (abc <= m.abc)
		res = false;
	return res;
}

bool monom:: operator==(const monom& m) const
{
	bool res = true;
	if (abc != m.abc || coeff != m.coeff)
		res = false;
	return res;
}

bool monom:: operator!=(const monom& m) const
{
	return !(*this == m);
}
