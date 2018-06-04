#pragma once



//����� ������
template<class type>
class unit
{
public:
	type data;		                                                    //������ � ��������
	unit* next;	                                                        //��������� �� ��������� �������
	unit() { next = nullptr; }										    //����������� �� ���������
	unit(type dz) { data = dz; next = nullptr; }					    //����������� � ����������
	bool operator< (const unit& z) const { return (data < z.data); }	    
	bool operator> (const unit& z) const { return (data > z.data); }	
};