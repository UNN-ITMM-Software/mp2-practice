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
