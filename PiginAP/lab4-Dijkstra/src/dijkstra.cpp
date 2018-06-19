#include "Dijkstra.h"

DataFloat::DataFloat(int v, float dist)
{
	this->v = v;
	priorities = dist;
}
//============================================================||============================================================
void Dijkstra::dijkstra(Graph *&graph, int s, float *&distance, int *&up)
{
	int n = graph->getVerticesNum();	// ���������� ������
	int m = graph->getRealSize();		// �������� ���������� �����
	if ((s < 0) || (s >= n))
		throw "Not Right start vertices";

	Data** dist = new Data*[n];
	up = new int[n];

	DHeapBasedPriorityQueue *queue = new DHeapBasedPriorityQueue();

	for (int i = 0; i < n; i++) {
		up[i] = i;
		dist[i] = new DataFloat(i, FLT_MAX);
		if (i == s)
			dist[s]->priorities = 0;
		queue->push(dist[i]);
	}

	WeightedEdge** edges = graph->getEdgeSet();
	while (!queue->isEmpty())
	{
		int vConsidered = ((DataFloat*)queue->pop())->v;    // ��������������� �������
		float delta;

		for (int i = 0; i < m; i++)
		{
			int vIncident = -1;						// ����������� ��������
			if (edges[i]->kon_ver == vConsidered)
				vIncident = edges[i]->nac_ver;
			if (edges[i]->nac_ver == vConsidered)
				vIncident = edges[i]->kon_ver;
			if (vIncident == -1) continue;

			float way = dist[vConsidered]->priorities + graph->getWeight(vConsidered, vIncident);
			delta = dist[vIncident]->priorities - way;
			if (delta > 0)
			{
				dist[vIncident]->priorities = way;  
				up[vIncident] = vConsidered;		
				queue->heap->hilling();
			}
		}
	}

	distance = new float[n];
	for (int i = 0; i < n; i++)
		distance[i] = dist[i]->priorities;

	for (int i = 0; i < n; i++)
		delete dist[i];
	delete[]dist;
	delete queue;
}