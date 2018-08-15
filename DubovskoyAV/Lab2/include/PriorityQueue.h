#pragma once
#include "DHeap.h"

class PriorityQueue {
public:
	PriorityQueue() {};

	virtual void push(Data *&key) = 0;  // ���������� ����� � �������
	virtual Data* pop() = 0;            // ������� ������������
	

	virtual int  isFull() const = 0;           //�������� �� �������
	virtual int  isEmpty() const = 0;          //�������� �� �������
};


/*������������ ������� �� ���� d-����*/
class DHeapPriorityQueue : public PriorityQueue {
public:
	DHeap * heap;
	DHeapPriorityQueue(int d = 4);
	DHeapPriorityQueue(const DHeapPriorityQueue &queue);
	DHeapPriorityQueue(Data **keys, int num, int d = 4);
	~DHeapPriorityQueue();

	virtual void push(Data *&key);	// ���������� ����� � �������
	virtual Data* pop();			// ������� ������������
	

	virtual int  isFull()const;           //�������� �� �������
	virtual int  isEmpty()const;          //�������� �� �������
};