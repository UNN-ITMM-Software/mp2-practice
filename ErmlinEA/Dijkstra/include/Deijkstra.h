#pragma once
#include "Graph.h"
#include "DHeap.h"
#include "priorityqueue.h"
#include <cfloat>

class DataFloat : public Data {
public:
	DataFloat(int v, float dist);
	int v;
};

class Dijkstra {
public:
	static void dijkstra(Graph *&graph, int s, float *&distance, int *&up);
};