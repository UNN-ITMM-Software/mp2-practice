#include "kraskal.h"
#include "separated_sets.h"


Edge* AlgoritmKraskala::Kraskal(Graph*g, PriorityQueue<Edge>* queue)
{
	SeparatedSets U(g->GetN());
	int nE = g->GetN() - 1; //����� ����� � ������� ������������ ��������� ������
	int kE = 0; // ����� ����� � �������� ������ ������
	Edge* E = new Edge[nE];
	for (int i = 0;i < g->GetM();i++)
	{
		queue->push(g->GetEdge(i));
	}
	while ((!queue->IsEmpty()) &&(kE < nE))
	{
		Edge Tmp = queue->pop();
		int A = Tmp.GetStart(), B = Tmp.GetFinish();
		int uA = U.DefineSubset(A);
		int uB = U.DefineSubset(B);
		if (uA != uB) 
		{
			U.Unite(uA,uB);
			E[kE] = Tmp;
			kE++;
		}
	}

	return E;
}