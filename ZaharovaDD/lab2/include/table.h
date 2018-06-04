#pragma once
#define MIN_DIM 50
#include <iostream>
#include <ostream>
template <class key_T, class data_T>
struct RecordTable																		//������, ������� ������ �������
{
	key_T key;																			//����	 
	data_T data;																		//������,������� �������� � �������-���������

	RecordTable(key_T _k = key_T(), data_T _d = data_T()) { key = _k; data = _d; }		//�.
};

template <class key_T, class data_T>
class Table																				//����� ������ (�����������)
{

protected:
	RecordTable <key_T, data_T> ** A_T;													//������ ���������� �� ������ 
	int Max_Dim;																		//������ �������
	int Index;																			//������� �������
	int _Dim;																			//������ ����������� ������
	virtual void Repack() = 0;															//�������, ������������� ������ �������

public:
	Table(int Dim_Tb = MIN_DIM);														//�.
	virtual ~Table() { for (int i = 0; i < Max_Dim; i++) delete A_T[i]; delete[] A_T; };//����������
	virtual void Insert(const key_T &_k, const data_T &_d) = 0;
	virtual void Dell(const key_T &_k) = 0;
	virtual RecordTable<key_T, data_T> * Search(const key_T &_k) const = 0;				//���������

																						//������ ���������
	void Reset() { _Dim = 0; };															//������� ������� = 0
	//virtual void Move() { _Dim++; if (Index == _Dim) Reset(); };
	bool IsTableEnd() const { if (Index == 0) return true; if (_Dim == Index - 1) return 1; else return 0; }; //��������� �� �����
	void GoNext() { if (!IsTableEnd())_Dim++; };										//��������� ���������� �������
	data_T GetCurr() const { return (*(this->A_T[_Dim])).data; };						//�������� �������� ��������
	template <class key_T, class data_T> friend std::ostream& operator<<(std::ostream& os, const Table<key_T, data_T>& P); //������� � �����

};


template <class key_T, class data_T>
Table<key_T, data_T>::Table(int Dim_Tb)
{
	Max_Dim = Dim_Tb;
	A_T = new RecordTable<key_T, data_T> *[Dim_Tb];
	for (int i = 0; i < Dim_Tb; i++)
		A_T[i] = NULL;
	Index = 0;
	_Dim = 0;
};

template <class key_T, class data_T>
std::ostream& operator << (std::ostream& os, const Table<key_T, data_T>& P)
{
	for (int i = 0; i<P.Max_Dim; i++)
	{
		if (P.A_T[i] != NULL)
			os << i << ":  " << (*(P.A_T[i])).key << " --> " << " " << (*(P.A_T[i])).data << endl;
		else  os << i << ":  " << " NULL" << endl;
	}
	return os;
}