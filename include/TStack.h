#ifndef TSTACK_H
#define TSTACK_H
#include "TList.h"
#include <locale.h>

template <typename Type>
class TStack{
	private:
		TList<Type> *pFirst; //��������� �� ������ �����
	public:
		TStack(); //�����������
		TStack(const TStack<Type>& St); //����������� �����������
		~TStack(); //����������
		Type Getroot(); //�������� ������� ������
		bool Is_Full() const; //�������� �� �������
		bool Is_Empty() const; //�������� �� �������
		void Push(Type key); //���������� �������� � ����
		Type Pop(); //������� �������� �� �����
		void Print(); // ����� �� �����

};

template <typename Type> //����������� ��� �����
TStack <Type> ::TStack() {
	pFirst = new TList<Type>;
}

template <typename Type>   //�������� ������� ������
Type TStack<Type>::Getroot() {
	return pFirst;
}
template <typename Type >   //����������� �����������
TStack <Type> ::TStack(const TStack & St ) {
	pFirst = new TList<Type>(*(St.pFirst));
}

template <typename Type>  //����������
TStack<Type>::~TStack(){
	pFirst->~TList();
}


template <typename Type>
bool TStack<Type>::Is_Empty() const{   //�������� �������
	return (pFirst->Getroot() == 0);
}

template <typename Type>
bool TStack<Type>::Is_Full() const {  //�������� �������
	TLink<Type> *ptr;
	try{
		ptr = new TLink<Type>;
	}
	catch (...){
		return true;
	}
	   delete ptr;
		return false;
}

 template <typename Type>  //���������� �������� � ����
 void TStack<Type>::Push(Type key){   
 setlocale(LC_CTYPE, "russian");
 if (Is_Full()) throw " ���� �����";
 pFirst->Insert_Begin(key);
 }

 template <typename TYPE>
 void TStack<TYPE>::Print()
 {
	 TStack<TYPE>* tmp = new TStack<TYPE>(*this);
	 while (!tmp->Is_Empty())
		 cout << tmp->Pop() << endl;

 }

 template <typename Type>
 Type TStack <Type>::Pop(){ //������� �������� �� �����
 setlocale(LC_CTYPE, "russian");
 if (Is_Empty()) throw " ���� ����";
 Type ptr = pFirst->Getroot()->key;
 pFirst->Delete(ptr);
 return ptr;
 }
#endif