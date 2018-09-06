#include <iostream>
#include "Graph.h"
#include "Priority_Queue.h"
#include "Algorithm.h"


typedef float KeyType;

using namespace std;

int main()
{
	setlocale(LC_CTYPE, "Russian");
	cout << "������� ���������� ������:" << endl;
	int n;
	cin >> n;
	cout << "������� ���������� ����" << endl;
	int m;
	cin >> m;
	Graph<KeyType> *graph = new Graph<KeyType>(n, m);
	KeyType *P = new KeyType[n];

	for (int i = 0; i<m; i++)
	{
		cout << "������� ��������� ������� �����, ����� ��������, � ����� ��� ��� " << endl;
		int f, t;
		KeyType w;
		cin >> f;
		cin >> t;
		cin >> w;
		graph->Push(f - 1, t - 1, w);
	}

	system("cls");
	cout << "����: " << endl << endl;
	graph->Print();
	cout << "������� ��������� �������:" << endl;
	int a;
	cin >> a;
	for (int i = 0; i <= n; i++)
		P[i] = a - 1;
	KeyType *dist = Algorithm<KeyType>::Dijkstra(a - 1, P, graph);
	cout << "����: " << endl << endl;
	for (int i = 1; i<n + 1; i++)
		cout << i << ' ';
	cout << "������� " << endl << endl;
	for (int i = 0; i < n; i++)
		if (dist[i] == max_heap)
			cout << 0 << ' ';
		else
			cout << dist[i] << ' ';
	cout << "���������� ���� " << endl << endl;
	for (int i = 0; i<n; i++)
		cout << P[i] + 1 << ' ';
	cout << "���������� ������� " << endl << endl;
	system("pause");
	return 0;
}