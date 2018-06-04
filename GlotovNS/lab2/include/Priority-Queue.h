#pragma once

#include "D-Heap.h"

class PriorityQueue
{
public:
	PriorityQueue() {};
	virtual void Push(Data *&key) = 0;
	virtual Data* Pop() = 0;
	//virtual void Refresh() = 0;
    const int IsFull() = 0;
	const int IsEmpty() = 0;
};


/*           ������������ ������� �� D-����           */
class DHeapBasedPriorityQueue : public PriorityQueue {
protected:
	DHeap * heap;
public:
	DHeapBasedPriorityQueue(int d = 4);
	DHeapBasedPriorityQueue(const DHeapBasedPriorityQueue &queue);
	DHeapBasedPriorityQueue(Data **keys, int num, int d = 4);
	~DHeapBasedPriorityQueue();
	virtual void Push(Data *&key);	// ���������� ����� � �������
	virtual Data* Pop();			// �������� ������������
//	virtual void Refresh();			// ���������� �������
	virtual int IsFull();
	virtual int IsEmpty();
};
