#pragma once

#include <iostream> 
#include <algorithm>

#define maxSize 1000
typedef int dataType;

class Data
{
public:
	float priorities;
};

class DHeap
{
protected:
	Data** keys;	// ����� (����������)
	int d;			// �-������� ����
	int lastIdx;	// ������� ������ ����
public:
	/* ������������ */
	DHeap(int d);
	DHeap(const DHeap &heap);
	~DHeap();
	int IsFull();
	int IsEmpty();
	void Add(Data *&key);				// ������� �������� � ����
	void AddSet(Data **key, int num);	// ������� ������ ��������� � ����
	Data* Erase();						// �������� ���������� ��������
	Data* Erase(int i);					// ... i-�� ��������
	void Transposition(int i, int j);	// ����� ���������� �������� 
	void Surfacing(int i);				// ��������
	void Immersion(int i);				// ����������
	void Hilling();						// ����������
private:
	int MinChild(int i);				// ����� ������������ �������
};


