#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>

#define maxVerticesSize 1000


class WeightedEdge {
public:
	int Ne;			// ��������� �������
	int Ke;			// �������� �������
	float W;	// ��� ����� �� N � K

	WeightedEdge(int Ne, int _Ke, float W);
};

class Graph {
private:
	int n;			// ���������� ������
	int m;				// ���������� �����
	int m_cur;			// ������� ���������� �����
	WeightedEdge** edges;   // ������ ���������� �����
	int* vertices;			// ������ ������


	void generateVertices(int &Ne, int &Ke);					// ��������� ������
	float generateW(float minRange, float maxRange);	// ��������� ��������� �����
	void cleaner();											// �������� ���� ���������� ����� � �����
	int searchEdge(int Ne, int Ke);				// ����� ����� �� �������� ��������

public:
	// ������������
	Graph(int n);
	Graph(int n, int m);
	~Graph();

	void generateGraph(float minRange, float maxRange);     // ��������� ����� � ��������� ������
	void addEdge(int N, int K, float W);				// ���������� �����
	void removeEdge(int N, int K);							// �������� �����

	int getVerticesNum();					// ����� ������
	int getEdgeSize();						// ������ �����
	int getRealSize();						// �������� ����� �����
	WeightedEdge** getEdgeSet();			// ������ ���������� �����
	WeightedEdge*  getEdge(int j);			// ���������� �������� �����
	float getW(int N, int K);			// ��� ����� � ��������� ���������

	void printList();                       //�����
};