#include "Dijkstra.h"
#include <cfloat>
#include <iostream>

using namespace std;

int main() {
	Graph* graph;
	int n; // ���������� ������
	int m; // ���������� �����
	int s; // ��������� �������

	try
	{
		cout << "Enter number vertices" << endl;
		cin >> n;
		cout << "Enter number edges" << endl;
		cin >> m;
		graph = new Graph(n, m);
	}
	catch (...)
	{
		return -1;
	}

	cout << "Enter type generate graph:"<<endl<< "1. Random" << endl << "2. Manual" << endl;

	int typeEnter;
	cin >> typeEnter;
	switch (typeEnter)
	{
	//Random
	case 1: {
		try
		{
			float minRange; // ����������� ��� �����
			float maxRange; // ������������ ��� �����
			cout << "Enter minRange" << endl;
			cin >> minRange;
			cout << "Enter maxRange" << endl;
			cin >> maxRange;
			graph->generateGraph(minRange, maxRange);
		}
		catch (...)
		{
			return -1;
		}
		break;
	}
	//Manual
	case 2: {
		int Ne, Ke;
		float W;

		try
		{
			for (int i = 0; i < m; i++) {
				cout << "Enter start vertex" << endl;
				cin >> Ne;
				cout << "Enter finish vertex" << endl;
				cin >> Ke;
				cout << "Enter Weight " << endl;
				cin >> W;
				graph->addEdge(Ne, Ke, W);
			}
		}
		catch (...)
		{
			return -1;
		}
		break;
	}
	}
	
	graph->printList(); //����� �����
	cout << endl;
	cout <<"N: "<< n << ' ' << " M: " << m << endl;	      // ������ ���������� ������
	

	cout << "Enter start vertex for Dijkstra" << endl;
	cin >> s;
	cout << "Start vertex: " << s << endl;					  // ������ ��������� �������

	float *dist;    // ������ ���������� ����� ��������� �������� � i-��� ��������
	int *up;		// ������ ������, �������������� � ���������� ����
	try {
		Dijkstra::dijkstra(graph, s, dist, up);
	}
	catch (...) {
		return -2;
	}

	cout << endl;
	m = graph->getRealSize();
	WeightedEdge* edge;
	cout << "// Matrix edges //" << endl; // ������ ������� ���������� �����
	for (int j = 0; j < m; j++) {
		edge = graph->getEdge(j);
		cout << edge->Ne << ' ' << edge->Ke << ' ' << edge->W << endl;
	}
	cout << endl;
	cout << "Distances" << endl;	   // ������ ���������� �� �������� ��������� ������� �� i-��� �������
	for (int i = 0; i < n; i++)
		if (dist[i] != FLT_MAX)
			cout << dist[i] << ' ';
		else
			cout << "inf" << ' ';
	cout << endl;

	cout << endl << "// Ways //" << endl;   
	for (int i = 0; i < n; i++) {
		cout << endl;
		cout << i;							
		cout << ' ' << dist[i];				
		cout << ' ' << up[i];				
		cout << endl;
	}


	/* ������������ ������ */
	delete graph;
	delete[]dist;
	delete[]up;
		
	system("pause");// �������� �������
	return 0;
}