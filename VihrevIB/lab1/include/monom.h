#pragma once
// �����
class Monom
{
public:
	double coeff; //�����������
	unsigned int abc; // �������
	Monom() { coeff = 0; abc = 0; } //����������� �� ���������
	Monom(double COEFF, unsigned int ABC) { coeff = COEFF; abc = ABC; }

};