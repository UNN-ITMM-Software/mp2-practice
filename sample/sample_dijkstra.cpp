#include "dijkstra.h"
#include <cfloat>
#include <iostream>

using namespace std;

int main() {
	Graph* graph;
	int n; // ���������� ������
	int m; // ���������� �����
	int s; // ��������� �������


	int typeGenerate;
	try
	{
		cout << "Write number vertices" << endl;
		cin >> n;
		cout << "Write number edges" << endl;
		cin >> m;
		graph = new Graph(n, m);
	}
	catch (...)
	{
		return -1;
	}

	cout << "Write type generate graph:" << endl;
	cout << "1. Random" << endl;
	cout << "2. Manual" << endl;


	cin >> typeGenerate;
	switch (typeGenerate)
	{
		/* ��������� ��������� �����*/
	case 1: {
		try
		{
			int minRange; // ����������� �������� ���� �����
			int maxRange; // ������������ �������� ���� �����
			cout << "Write minRange" << endl;
			cin >> minRange;
			cout << "Write maxRange" << endl;
			cin >> maxRange;
			graph->generateGraph(minRange, maxRange);
		}
		catch (...) {
			return -1;
		}
		break;
	}
			/* ������ ��������� �����*/
	case 2: {
		int _nac_ver, _kon_ver;
		float _weight;

		try
		{
			for (int i = 0; i < m; i++) {
				cout << "Write start vershinu" << endl;
				cin >> _nac_ver;
				cout << "Write finish vershinu" << endl;
				cin >> _kon_ver;
				cout << "Write weight" << endl;
				cin >> _weight;
				graph->addEdge(_nac_ver, _kon_ver, _weight);
			}
		}
		catch (...)
		{
			return -1;
		}
		break;
	}
	}
	if (!graph->isConnectivity()) // �������� �� ���������
		return -3;
	graph->printVertices();
	cout << "Write start vertices for Dijkstra" << endl;
	cin >> s;

	graph->printList();
	cout << endl;

	float *dist;    // ������ ���������� ����� S � i-��� ��������
	int *up;		// ������ ������, �������������� � ���������� ����
	try {
		Dijkstra::dijkstra(graph, s, dist, up);
	}
	catch (...) {
		return -2;
	}

	cout << n << ' ' << m << endl;	      // ������ ���������� ������
	cout << s << endl;					  // ������ ��������� �������

	m = graph->getRealSize();
	WeightedEdge* edge;
	cout << "// Matrix edges //" << endl; // ������ ������� ���������� ������
	for (int j = 0; j < m; j++) {
		edge = graph->getEdge(j);
		cout << edge->nac_ver << ' ' << edge->kon_ver << ' ' << edge->weight << endl;
	}

	cout << endl << "// Distances //" << endl;	   // ������ ���������� �� �������� ������� S �� i-��� �������
	for (int i = 0; i < n; i++) {
		if (dist[i] == FLT_MAX) return -4;
		cout << s << " -> " << i << " distance = " << dist[i] << endl;
	}


	cout << endl << "// Ways //" << endl;   // ������ ����� ���� ������  
	for (int i = 0; i < n; i++) {
		int j = i;
		cout << j << " <- ";
		while (up[j] != s) {
			cout << up[j] << " <- ";
			j = up[j];
		}
		cout << s << endl;
	}

	// ������������ ������
	delete graph;
	delete[]dist;
	delete[]up;


	// �������� �������
	cout << endl;
	system("pause");
	return 0;
}