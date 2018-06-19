#include "d-heap.h"

class PriorityQueue {
public:
	PriorityQueue() {};

	virtual void push(Data *&key) = 0;
	virtual Data* pop() = 0;


	virtual int isFull()const = 0;
	virtual int isEmpty()const = 0;
};


/*           ������������ ������� �� D-����           */
class DHeapBasedPriorityQueue : public PriorityQueue {
	
public:
	DHeapBasedPriorityQueue(int d = 4);
	DHeapBasedPriorityQueue(const DHeapBasedPriorityQueue &queue);
	DHeapBasedPriorityQueue(Data **keys, int num, int d = 4);
	~DHeapBasedPriorityQueue();

	virtual void push(Data *&key);	// ���������� ����� � �������
	virtual Data* pop();			// �������� ������������
	DHeap * heap;

	virtual int isFull()const;
	virtual int isEmpty()const;
};