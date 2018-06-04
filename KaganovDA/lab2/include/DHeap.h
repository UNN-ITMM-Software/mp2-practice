#pragma once
#include <iostream> 
#include <algorithm>
#include "Graph.h"

#define maxSize 1000
typedef int dataType;

class Data {
public:
	float priorities;
};

class DHeap {
protected:
	Data **keys;
	int d;
	int idx;
public:
	DHeap(int d);
	DHeap(const DHeap &heap);
	~DHeap();

	void Add(Data *&key);
	void AddSet(Data **key, int num);
	Data* Delete();
	Data* Remove(int i);					//������� ���� i

	void Transpose(int i, int j);			//�����������
	void Surfacing(int i);					//��������
	void Sinking(int i);					//����������
	void Hilling();							//����������
	int IsFull()const;
	int IsEmpty()const;

private:
	int MinChild(int i);					//���������� ���� i
};
