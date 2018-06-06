#include "priority_queue.h"

PriorityQueueHeap::PriorityQueueHeap(int d)
{
	heap = new DAryHeap(d);
}

PriorityQueueHeap::PriorityQueueHeap(const PriorityQueueHeap &queue)
{
	this->heap = new DAryHeap(*(queue.heap));
}

PriorityQueueHeap::PriorityQueueHeap(Data **keys, int num, int d)
{
	heap = new DAryHeap(d);
	heap->addSet(keys, num);
}

PriorityQueueHeap::~PriorityQueueHeap()
{
	delete heap;
}

void PriorityQueueHeap::push(Data *&key)
{
	heap->add(key);
}

Data* PriorityQueueHeap::pop()
{
	return heap->erase(0);
}

void PriorityQueueHeap::refresh()
{
	heap->spudding();
}

int PriorityQueueHeap::isFull()
{
	return heap->isFull();
}

int PriorityQueueHeap::isEmpty()
{
	return heap->isEmpty();
}
