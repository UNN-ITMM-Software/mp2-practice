#pragma once
#include <math.h>


class monom
{
public:
	double cff;																									//�����. ����� �������
	int svr;																									//�������� �������

	monom(const monom& a) { cff = a.cff; svr = a.svr; }
	monom(const double index_cff = 0.0, const unsigned int index_svr = 0) { cff = index_cff; svr = index_svr; }	//�.
	const monom& operator=(const monom& a) { cff = a.cff; svr = a.svr; return *this; }							//�. ������������
	bool operator< (const monom& a) const { return (svr<a.svr); }												//�. ���������
	bool operator> (const monom& a) const { return (svr>a.svr); }												//�. ���������
	bool operator==(const monom& a) const { return ((svr == a.svr) && (cff == a.cff)); }						//����������� ==
	bool operator!=(const monom& a) const { return !(*this == a); }												//����������� !=


};
