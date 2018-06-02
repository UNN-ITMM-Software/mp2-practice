#ifndef TLIST_H
#define TLIST_H                                                                                       
#include <locale.h>
#include "TLink.h"


template <typename Type>
class TList {
	private:
	   TLink<Type> *begin;
	public:
	   TList(); //�����������
	   TList(const TList<Type>&L); //����������� �����������
	   ~TList(); //����������
	   void Insert_Begin(Type key); //���������� �������� � ������
	   void Insert_End(Type key); //���������� �������� � �����
	   void Insert_Before(Type key, Type nextkey); // ���������� ��-�� �� ������� ��-��
	   void Insert_After(Type key, Type prevkey); // ���������� ��-�� ����� ������� ��-��
	   TLink<Type>* Search(Type key); // ����� �������� � �������� ������
	   void Delete(Type key); //��������
	   TLink<Type>* Getroot() const; // �������� ������� ������
	   int Size() const; //������� ���������� ���������
	   void Print(); //����� ��������� ������ �� �����
       };  

template <typename Type>
TList<Type>::TList(){
	begin = NULL;
}
template <typename Type>
TList<Type>::TList(const TList<Type>&L){
	if (L.begin == 0) return 0;
	TLink<Type>*second = L.begin;
	begin->Key = second->key;
	begin->pNext = 0;
	second = second->pNext;
	TLink<Type>*tmp = begin;
	while (begin != 0)
	{
		tmp->pNext = new TLink<Type>;
		tmp->pNext->pNext = 0;
		tmp = tmp->pNext;
		second = second->pNext;
	}

}

template <typename Type>
TList<Type>::~TList(){
	delete begin;

}
template <typename Type>
void TList<Type>::Insert_Begin(Type key) //���������� ��-��  � ������ ������
{
	TLink<Type> *n = new TLink<Type>();
	n->key = key;
	n->pNext = begin;
	begin = n;
}

template <typename Type>
void TList<Type>::Insert_End(Type key) //���������� ��-�� � ����� ������
{
	if (begin == 0)
	{
		begin = new TLink<Type>();
		begin->key = key;
		begin->pNext = NULL;
		return;
	}

	while (begin->pNext != 0)
	{
		begin = begin->pNext;
	}
	begin->pNext = new TLink<Type>();
	begin->pNext->key = key;
	begin->pNext->pNext = 0;
}

template <typename Type>
void TList<Type>::Insert_Before(Type key, Type nextkey)  //���������� ��-�� �� ������� ��-�� � �������� ������
{
	setlocale(LC_CTYPE, "russian");
	if (begin == 0)
	{
		throw "������ ����";
	}
	if (begin->key == nextkey)
	{
		TLink<TYPE>* ptr = new TLink<Type>();
		ptr->key = key;
		ptr->pNext = begin;
		begin = ptr;
		return;
	}
	TLink<Type> *tmp = begin;
	while ((tmp->pNext != 0) && (tmp->pNext->key != nextkey))
	{
		tmp = tmp->pNext;
	}
	if (tmp->pNext == 0)
	{
		throw "������� � ��������� ������ �� ������";
	}
	TLink<Type> *n = new TLink<Type>();
	n->key = key;
	n->pNext = tmp->pNext;
	tmp->pNext = n;
}
template <typename Type> //���������� �� - �� ����� ������� �� - �� � �������� ������
void TList<Type>::Insert_After(Type key, Type prevkey)  
{
	setlocale(LC_CTYPE, "russian");
	if (begin == 0)
	{
		throw "������ ����";
	}
	TLink<Type> *tmp = begin;
	while ((tmp->pNext != 0) && (tmp->key != prevkey))
	{
		tmp = tmp->pNext;
	}

	if ((tmp->pNext == 0) && (tmp->key != prevkey))
	{
		throw "������� � ��������� ������ �� ������";
	}
	TLink<Type> *n = new TLink<Type>();
	n->key = key;
	n->pNext = tmp->pNext;
	tmp->pNext = n;
}

 template <typename Type>
 TLink<Type>* TList<Type>::Getroot() const{
	 return begin;

}
 template <typename Type>
 int TList<Type>::Size() const{
	 int amount = 0;
	 TLink<Type>*ptr = begin;
	 while (ptr != 0){
		 amount++;
		 ptr = ptr->pNext;
	 
	 }
	 return amount;
 }
 template <typename Type>
 TLink<Type>* TList<Type>::Search(Type key){
	 setlocale(LC_CTYPE, "russian");
	 TLink<Type>*tmp = begin;
	 while (tmp != 0)
	 {
		 if (tmp->key == key)
		 {
			 return tmp;
		 }
		 tmp = tmp->pNext;
	 }
	 throw " ������� � ��������� ������ �� ������";
 }

 template <typename Type>
 void TList<Type>::Delete(Type key){
	 setlocale(LC_CTYPE, "russian");
	 if (begin == 0) return;
	 TLink<Type>*tmp = begin;
	 if (begin->key = key)
	 {
		 begin = begin->pNext;
		 delete tmp;
		 return;
	 }
	 while ((tmp->pNext != 0) && (tmp->pNext->key != key))
		 tmp = tmp->pNext;
	 if (tmp->pNext == 0)
	 {
		 throw " ������!";
	 }
	 TLink<Type>*ptr = tmp->pNext;
	 tmp->pNext = ptr->pNext;
	 delete ptr;
 }
 template <typename Type>
 void TList<Type>:: Print(){
		 TLink<Type> *tmp = begin;
	 while (tmp != 0){
		 cout << tmp->key << "->";
		 tmp = tmp->pNext;

	 }

 }
#endif