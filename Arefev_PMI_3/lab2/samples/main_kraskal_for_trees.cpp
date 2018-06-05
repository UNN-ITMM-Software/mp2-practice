#include "binary_search_tree.h"
#include "priority_queue.h"
#include "graph.h"
#include "binary_search_tree_based_priority_queue.h"
#include "kraskal.h"
#include <iostream>

using namespace std;

int main(void)
{
	setlocale(LC_ALL, "Russian");

	int n, m;

	cout << "������� ����� ������ ������ �����" << endl;
	cin >> n;
	cout << "������� ����� ����� ������ �����" << endl;
	cin >> m;
	Edge* E = new Edge[m];
	int l = 0;//������� �� ������� �����
	for (int i = 0; i < n; i++)
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
	PriorityQueue<Edge>* Q = new BinarySearchTreeBasedPriorityQueue<Edge>;
	Edge* WE = new Edge[n - 1];
	AlgoritmKraskala AK;
	WE = AK.Kraskal(&G, Q);
	return 0;
}

	