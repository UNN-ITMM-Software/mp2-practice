#include <iostream>
#include <dheap_sort.h>

using namespace std;

int main() 
{
	setlocale(LC_ALL, "Russian");

	int n;
	int* mas;
	PiramidSortBasedDHeap D;

	cout << "������� ���������� �����:" << endl;
	cin >> n;
	mas = new int[n];
	cout << "������� ������ ������:" << endl;
	for (int i = 0;i < n;i++)
	{
		cin >> mas[i];
	}

	D.PiramidSort(mas, n);

	return 0;
}