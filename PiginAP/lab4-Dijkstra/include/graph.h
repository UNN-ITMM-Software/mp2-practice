#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <cstdlib>
#include <ctime>

#define maxVerticesSize 1000


class WeightedEdge {
public:
	int nac_ver;			// ��������� �������
	int kon_ver;			// �������� �������
	float weight;	// ��� ����� �� N � K

	WeightedEdge(int _nac_ver, int _kon_ver, float _weight);
};
//============================================================||============================================================
class Graph {
private:
	int vershini;			// ���������� ������
	int rebra;				// ���������� �����
	int tek_rebro;			// ������� ���������� �����
	WeightedEdge** edges;   // ������ ���������� �����
	int* vertices;			// ������ ������
public:
	// ������������
	Graph(int vershini);
	Graph(int vershini, int rebra);
	~Graph();

	void generateGraph(float minRange, float maxRange);					// ��������� ����� � ��������� �������
	void addEdge(int nac_ver, int kon_ver, float weight);				// ���������� �����
	void removeEdge(int nac_ver, int kon_ver);							// �������� �����

	int getVerticesNum();								// ����� ������
	int getEdgeSize();									// ������������ ����� �����
	int getRealSize();									// �������� ����� �����
	WeightedEdge** getEdgeSet();						// ������ ���������� �����
	WeightedEdge*  getEdge(int j);						// ���������� �������� �����
	float getWeight(int nac_ver, int kon_ver);			// ��� ����� � ��������� ���������

	void printList();



private:
	void generateVertices(int &nac_ver, int &kon_ver);					// ��������� ������
	float generateWeight(float minRange, float maxRange);				// ��������� ��������� �����
	void cleaner();														// �������� ���� ���������� ����� � �����
	int searchEdge(int _nac_ver, int _kon_ver);							// ����� ����� �� �������� ��������

};
#endif;