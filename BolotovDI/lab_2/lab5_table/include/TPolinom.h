#pragma once

#include "TRingList.h"

class TPolinom
{
private:
	TRingList<TMonom> monoms; // ������ 
public:
	TPolinom() {}; // ����������� 
	TPolinom(const string s); // ����������� �� ������
	TPolinom(const TPolinom &poli2); // ����������� �����������
	~TPolinom() {}; // ����������

	TPolinom operator + (const TPolinom& poli2); // ����� ���������
	TPolinom operator - (const TPolinom& poli2); // �������� ���������
	TPolinom operator * (const TPolinom& poli2); // ������������ ��������� 
	TPolinom operator * (double cf2); // ������������ �������� � �����
	friend TPolinom operator *(double cf2, const TPolinom& poli2); // ������������ ����� � ��������
	TPolinom& operator = (const TPolinom& tmp); // �������� �����������
	bool operator == (const TPolinom& poli2) const; // �������� ��������� 
	void PrivPod(); // ���������� ��������

	friend ostream& operator <<(ostream& ostr, const TPolinom& poli2); // ������ �������� 
};