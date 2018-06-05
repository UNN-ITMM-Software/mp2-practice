#include <iostream>
#include "graph.h"
#include "priority_queue.h"
#include "priority_queue_based_dheap.h"
#include "dejkstra.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int n, m;

	cout << "������� ����� ������ ������ �����" << endl;
	cin >> n;
	cout << "������� ����� ����� ������ �����" << endl;
	cin >> m;
	Edge* E = new Edge[m];
	int l = 0;//������� �� ������� �����
	for (int i = 0; i < n-1; i++)
	{
		cout << "������� ���� ���� �����, ����������� ������� " << i << endl;
		for (int j = i + 1; j < n; j++)
		{
			float w;
			cout << " � �������� " << j << ": ";
			cin >> w;
			cout << endl;
			if (w != 0) {
				Edge tmp(i, j, w);
				E[l] = tmp;
				l++;
			}
			if (l > m) cout << "Error!" << endl;
		}
	}

	Graph G(n, m, E);
	PriorityQueue<Vertex>* Q = new PriorityQueueBasedDHeap<Vertex>(n);
	AlgoritmDejkstri AD;
	AD.Dejkstra(&G, Q);
	return 0;
}