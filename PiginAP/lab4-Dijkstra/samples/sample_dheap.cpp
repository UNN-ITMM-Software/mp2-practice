#include "dijkstra.h"
#include <cfloat>
#include <iostream>

using namespace std;

int main() {
	Graph* graph;
	int n;			// �������
	int m;			// ������
	int s;			// Start vertices


	int typeGenerate;
		cout << "Write number vertices" << endl;
		cin >> n;
		cout << "Write number edges" << endl;
		cin >> m;
	
	
		if ((m < 0) || (m > n*(n - 1) / 2) || (m < n - 1))
		{
			cout<<"Graph isn't svyazny"<<endl;
			return -1;
		}
		else{
			graph = new Graph(n, m);}
	
	
		
		
			
		

	cout << "Write type of generate graph:" << endl;
	cout << "1. Random" << endl;
	cout << "2. Manual" << endl;
	
	
	cin >> typeGenerate;
	switch (typeGenerate)
	{
	// ��������� ��������� �����
	case 1: {
		try
		{
			int minRange;								// ����������� �������� ���� �����
			int maxRange;								// ������������ �������� ���� �����
			cout << "Write min Range" << endl;
			cin >> minRange;
			cout << "Write max Range" << endl;
			cin >> maxRange;
			graph->generateGraph(minRange, maxRange);
		}
		catch (const char ex) 
		{
			cout<<ex;
			return -1;
		}
		break;
	}
	// ������ ��������� �����
	case 2: {
		int nac_ver, kon_ver;
		float weight;
	
		try
		{
			for (int i = 0; i < m; i++) {
				cout << "Write start vertices" << endl;
				cin >> nac_ver;
				cout << "Write finish vertices" << endl;
				cin >> kon_ver;
				cout << "Write weight" << endl;
				cin >> weight;
				graph->addEdge(nac_ver, kon_ver, weight);
			}
		}
		catch (const char ex) 
		{
			cout<<ex;
			return -1;
		}
		break;
	}
	}
	cout << "Write start vertices for Dijkstra" << endl;
	cin >> s;
	
	graph->printList();
	cout << endl;

	float *dist;										// ������ ���������� ����� S � i-��� ��������
	int *up;											// ������ ������, �������������� � ���������� ����
	try {
		Dijkstra::dijkstra(graph, s, dist, up);
	}
	catch (const char ex) 
		{
			cout<<ex;
			return -2;
		}

	cout << n << ' ' << m << endl;										// ������ ���������� ������
	cout << "start vertices = " << s << endl;							 // ������ ��������� �������

	m = graph->getRealSize();
	WeightedEdge* edge;
	cout << "// Matrix edges //" << endl;								// ������ ������� ���������� ������
	for (int j = 0; j < m; j++) {
		edge = graph->getEdge(j);
		cout << edge->nac_ver<< ' ' << edge->kon_ver << ' ' << edge->weight << endl;
	}

	cout << "// Distances //" << endl;			 // ������ ���������� �� �������� ������� S �� i-��� �������
	for (int i = 0; i < n; i++)
		if (dist[i] != FLT_MAX)
			cout << dist[i] << ' ';
		else
			cout << "inf" << ' ';
	
	cout << endl << "// Ways //" << endl;			// ������ ����� ���� ������  
	for (int i = 0; i < n; i++) {
		cout << endl;
		cout << i;									// - i-� �������
		cout << ' ' << dist[i];						// - ���������� �� S �� ���� �������
		cout << ' ' << up[i];						// - �������������� ������� i-��
	}

	
	delete graph;				// ������������ ������
	delete[]dist;
	delete[]up;



	cout << endl;
	return 0;
}