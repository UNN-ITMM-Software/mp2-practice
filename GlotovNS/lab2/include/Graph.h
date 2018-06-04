#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>

#define maxSizeVertices 1000


class WeightedEdge
{
public:
	int nver;			    // ��������� �������
	int kver;			    // �������� �������
	float weight;	        // ��� ����� �� N � K
	WeightedEdge(int nver, int kver, float weight);
};

class Graph
{
private:
	int vershini;			// ���������� ������
	int rebra;				// ���������� �����
	int tek_rebro;			// ������� ���������� �����
	int tek_vershina;		// ������� ���������� ������
	WeightedEdge** edges;   // ������ ���������� �����
	int* vertices;			// ������ ������
public:
	// ������������
	Graph(int n);
	Graph(int n, int m);
	~Graph();
	void GenerateGraph(float minRange, float maxRange);     // ��������� ����� � ��������� ������
	void AddEdge(int N, int K, float weight);				// ���������� �����
	void RemoveEdge(int N, int K);							// �������� �����
	int GetVerticesNum();					// ����� ������
	int GetEdgeSize();						// ������������ ����� �����
	int GetRealSize();						// �������� ����� �����
	bool IsConnectivity();					// �������� �� ��������� �����
	WeightedEdge** GetEdgeSet();			// ������ ���������� �����
	WeightedEdge*  GetEdge(int j);			// ���������� �������� �����
	float GetWeight(int N, int K);			// ��� ����� � ��������� ���������
	void PrintList();                       // ���������

											
private:
	void GenerateVertices(int &N, int &K);					// ��������� ������
	float GenerateWeight(float minRange, float maxRange);	// ��������� ��������� �����
	void Cleaner();											// �������� ���� ���������� ����� � �����
	int SearchEdge(int nver, int kver);				        // ����� ����� �� �������� ��������
	bool SearchVershinu(int ver);							// ����� �������� ������� (���������� �� ��� � ������� ���������� �����)
	void AddVershini(int nver, int kver);			        // ���������� ������ � ������ ������
};


