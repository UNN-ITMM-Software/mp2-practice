#include <iostream>
#include <locale.h>
#include <conio.h>
#include "TList.h"

using namespace std;

void main(){
	setlocale(LC_CTYPE, "russian");
	TList<int> *begin = new TList<int>;
	cout << " ������� �������� � ����� " << endl;
	begin->Insert_End(1);
	begin->Print();
	cout << endl << endl;

	cout << " ������� �������� � ������ " << endl;
	begin->Insert_Begin(2);
	begin->Print();
	cout << endl << endl;

	cout << " ������� ��������  ����� ������� ��-�� � �������� ������ ( ��-� -> ���� ��������� ) " << endl;
	try{
		begin->Insert_After(5, 2);
		begin->Print();
	}
	catch (const char *exeption){
		cerr << exeption << endl;
	}
	cout << endl << endl;

	cout << " ������� ��������  �� ������� ��-�� � �������� ������ ( ��-� -> ���� ��������� ) " << endl;
	try{
		begin->Insert_Before(3, 5);
		begin->Print();
	}
	catch (const char *exeption){
		cerr << exeption << endl;
	}
	cout << endl << endl;

	cout << " ��������  ��-�� � �������� ������ " << endl;
	try{
		begin->Delete(2);
		begin->Print();
	}
	catch (const char *exeption){
		cerr << exeption << endl;
	}
	cout << endl << endl;
	std::system("pause");
}
