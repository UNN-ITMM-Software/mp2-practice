
#include <iomanip>
#include "Queue.h"
#include "Stack.h"
#include <stack>
#include <queue>
#include <cstdlib>

int main() // ������������ ������ �����
{
	setlocale(LC_ALL, "Russian");

	int A = rand() % 1000 + 1;
	int B = rand() % 1000 + 1;
	int C = rand() % 1000 + 1;
	Stack<int> a(3);
	a.push(A);
	a.push(B);
	a.push(C);

	cout << "������������ ������ �����" << endl;
	cout << "����� ������ �:" << &(a.pop()) << endl; 
	cout << "B=" << a.pop() << endl; 

	int D = rand() % 1000 + 1;
	int E= rand() % 1000 + 1;
	int F= rand() % 1000 + 1;
	
	int* mas = new int[3];
	mas[0] = D;
	mas[1] = E;
	mas[2] = F;
	void* t = mas;
	Stack<int>d;
	d.SetMemory(t, 3);

	cout << "����� SetMemory" << endl;
	cout << d.pop() << endl;
	cout << d.pop() << endl;
	cout << d.pop() << endl;
//---------------------------------------------------------------------------------------------//
// ������������ ������ �������

	Queue<int> b(3);
	b.push(A);
	b.push(B);
	b.push(C);
	
	cout << "������������ ������ �������" << endl;
	cout << "A=" << b.pop() << endl; 	
}
