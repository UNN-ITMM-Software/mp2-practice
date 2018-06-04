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

class Graph {
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

	void generateGraph(float minRange, float maxRange);     // ��������� ����� � ��������� ������
	void addEdge(int N, int K, float weight);				// ���������� �����
	void removeEdge(int N, int K);							// �������� �����

	int getVerticesNum();					// ����� ������
	int getEdgeSize();						// ������������ ����� �����
	int getRealSize();						// �������� ����� �����
	bool isConnectivity();					// �������� �� ��������� �����
	WeightedEdge** getEdgeSet();			// ������ ���������� �����
	WeightedEdge*  getEdge(int j);			// ���������� �������� �����
	float getWeight(int N, int K);			// ��� ����� � ��������� ���������
	void printList();						// ������ �����
	void printVertices();					// ������ ������� ������


	/* ��������������� ������� */
private:
	void generateVertices(int &N, int &K);					// ��������� ������
	float generateWeight(float minRange, float maxRange);	// ��������� ��������� �����
	void cleaner();											// �������� ���� ���������� ����� � �����
	int searchEdge(int _nac_ver, int _kon_ver);				// ����� ����� �� �������� ��������
	bool searchVershinu(int _ver);							// ����� �������� ������� (���������� �� ��� � ������� ���������� �����)
	void addVershini(int _nac_ver, int _kon_ver);			// ���������� ������ � ������ ������


};