#pragma once
#include <iostream>
#include <ostream>
template <class typeK, class typeD>
struct dataTable  //������, ������� ����� ������� �������
{
	typeK key;			//����	 
	typeD data;			//������, ���������� � �������-���������
	dataTable(typeK key_k = typeK(), typeD data_d = typeD()) //����������� 
	{
		key = key_k; data = data_d;
	}  
};

template <class typeK, class typeD>
class Table //����������� ����� ������
{
public:
	Table(int SizeTable = 30);
	virtual ~Table();
	virtual void insert(const typeK &k, const typeD &d) = 0; //�������
	virtual void delet(const typeK &k) = 0; //��������
	virtual dataTable<typeK, typeD> * search(const typeK &k) const = 0; //�����
																				 
	void reset() // ��������� ��������
	{
		curind = 0;
	}; 
	bool isended() const // �������� �� �����
	{
		if (top == 0) // ����� ������� ������� � �������
			return true;
		if (curind == top - 1) return 1;
		else return 0;
	};
	void getnext() 
	{ 
		if (!isended())curind++; 
	};
	typeD getcurdata() const // �������� ������ �������� ��������
	{ 
		return (*(this->dt[curind])).data;
	};
	template <class typeK, class typeD>
	friend std::ostream& operator<<(std::ostream& os, const Table<typeK, typeD>&P);

protected:
	dataTable <typeK, typeD> ** dt; //������ ���������� �� ������
	int maxsize; //������ �������
	virtual void realocate() = 0;//����������������� ������
	int curind; // ������� �������
	int top; // ������� �������
};


template <class typeK, class typeD>
Table<typeK, typeD>::Table(int SizeTable)
{
	maxsize = SizeTable;
	dt = new dataTable<typeK, typeD> *[SizeTable];
	for (int i = 0; i < SizeTable; i++)
		dt[i] = NULL;
	top = 0;
	curind = 0;
};


template <class typeK, class typeD>
Table<typeK, typeD>::~Table()
{
	for (int i = 0; i < maxsize; i++)
		delete dt[i];
	delete[] dt;
};


template <class typeK, class typeD>
std::ostream& operator << (std::ostream& os, const Table<typeK, typeD>& P)
{
	for (int i = 0; i<P.maxsize; i++)
	{
		if (P.dt[i] != NULL)
			os << i << ":  " << (*(P.dt[i])).key << " --> " << " " << (*(P.dt[i])).data<<endl;
		else  os << i << ":  " << " NULL" << endl;
	}
	return os;
}

