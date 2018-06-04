#include "..//include/Deijkstra.h"
#include <cfloat>
#include <iostream>
#include "locale.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	Graph* graph;
	int n, m, s, nmenu;
	try
	{
		cout << "������� ���������� ������:" << endl;
		cin >> n;
		cout << "������� ���������� �����:" << endl;
		cin >> m;
		graph = new Graph(n, m);
	}
	catch (...)
	{
		return -1;
	}
	cout << "1. ��������� ���������" << endl;
	cout << "2. ������ ����" << endl;
	cin >> nmenu;
	switch (nmenu)
	{
	case 1: {
		try
		{
			int minRange;
			int maxRange;
			cout << "������� ����������� �������� ���� �����:" << endl;
			cin >> minRange;
			cout << "������� ������������ �������� ���� �����:" << endl;
			cin >> maxRange;
			graph->GenerateGraph(minRange, maxRange);
		}
		catch (...) {
			return -1;
		}
		break;
	}
	case 2: {
		int nac_ver, kon_ver;
		float weight;
		try
		{
			for (int i = 0; i < m; i++)
			{
				cout << "������� ��������� �������:" << endl;
				cin >> nac_ver;
				cout << "������� �������� �������:" << endl;
				cin >> kon_ver;
				cout << "������� ���:" << endl;
				cin >> weight;
				graph->AddEdge(nac_ver, kon_ver, weight);
			}
		}
		catch (...)
		{
			return -1;
		}
		break;
	}
	}
	if (!graph->IsConnectivity())
	{
		return -3;
	}
	cout << "������� ��������� ������� ��� ��������� ��������:" << endl;
	cin >> s;
	graph->PrintList();
	cout << endl;
	float *dist;    
	int *up;	
	try {
		Dijkstra::dijkstra(graph, s, dist, up);
	}
	catch (...) {
		return -2;
	}
	cout << n << ' ' << m << endl;	      
	cout << s << endl;					 
	m = graph->GetRealSize();
	WeightedEdge* edge;
	cout << "Matrix edges" << endl; 
	for (int j = 0; j < m; j++)
	{
		edge = graph->GetEdge(j);
		cout << edge->n << ' ' << edge->k << ' ' << edge->weight << endl;
	}
	cout << "���������� �� �������� ������� �� i-�� �������:" << endl;	   
	for (int i = 0; i < n; i++)
	{
		if (dist[i] == FLT_MAX)
		{
			return -4;
		}
		cout << s << " -> " << i << " ��������� = " << dist[i] << endl;
	}
	cout << endl << "���� ���� ������:" << endl;    
	for (int i = 0; i < n; i++)
	{
		int temp = i;
		cout << temp << " <- ";
		while (up[temp] != s)
		{
			cout << up[temp] << " <- ";
			temp = up[temp];
		}
		cout << s << endl;
	}
	delete graph;
	delete[]dist;
	delete[]up;
	cout << endl;
	system("pause");
	return 0;
}