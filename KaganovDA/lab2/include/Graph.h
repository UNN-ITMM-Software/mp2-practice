#pragma once
#include <ctime>
#include <cstdlib>
#include <iostream>

#define maxVerticesSize 1000

class Edge {
public:
	int Ne;			//������
	int Ke;			//�����
	float W;		//��� �����

	Edge(int Ne, int Ke, float W);
};

class Graph
{
private:
	int n;				//����� ������
	int m;				//����� ����
	int m_cur;
	Edge** edges;		//������ ���������� �� ����
	int* vertices;
public:
	Graph(int n);
	Graph(int n, int m);
	~Graph();

	void Generate(float minRange, float maxRange);		//������� �����
	void AddEdge(int Ne, int Ke, float weight);
	void DelEdge(int Ne, int Ke);
	int GetVerticesNum();
	int GetEdgeSize();
	int GetRealSize();
	Edge** GetEdgeSet();
	Edge*  GetEdge(int i);
	float GetWeight(int Ne, int Ke);
	void PrintList();
private:
	void GenerateVertices(int &Ne, int &Ke);
	float GenerateWeight(float minRange, float maxRange);
	void Clean();
	int FindEdge(int Ne, int Ke);
};
