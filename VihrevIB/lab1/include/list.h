#pragma once
#include "Node.h"
// ����������� ������ � ������� //

template<typename T>
class Rlist
{
protected:
	Node<T>* head;
	Node<T>* current;
public:
	//������������ � ����������
	Rlist();
	Rlist(const Rlist<T>& ListToCopy);
	~Rlist();

	//������
    Rlist<T>& operator=(const Rlist<T>& ListToCopy);
	//void InsertToTail(); // ������� � �����
	void InsertAfter(Node<T>* N, T Data);
	void OrderedInsert(T Data);       // ������� � ������������� ������
	void Clean(); // ������� ������
	
	// ������ ���������
	Node<T>* GetHead() const { return head; } // �������� ��������� �� ������
	Node<T>* GetCurr() const{ return current; } // �������� ��������� �� �������
	void GetNext() { current = current->next; }// �������� ��������� �� ���������
	void Reset() { current = head->next;  } // ����������� ��������� � ������
	bool IsEnded() { return current == head; } // �������� �� �����
	
	bool operator==(const Rlist<T>& RLst) const;								//���������
	bool operator!=(const Rlist<T>& RLst) const { return !(*this == RLst); }	//���������

	
};

template <typename T>
Rlist<T>::Rlist()
{
	head = new Node<T>;
   	head->data = NULL;
	head->next = head;
	current = head;
}

template <typename T>
Rlist<T>::Rlist(const Rlist<T>& ListToCopy) 
{
	Node<T>* TempCurr = ListToCopy.head;
	head = new Node<T>(TempCurr->data);
	head->next = head;
	current = head;
	while (TempCurr->next != ListToCopy.head)
	{
		TempCurr= TempCurr->next;
		current->next = new Node<T>(TempCurr->data);
		GetNext();
	}
	current->next = head;
}

template <class T>
Rlist<T>::~Rlist()
{
	Clean();
	delete head;
}

template <class T>
Rlist<T>& Rlist<T>::operator=(const Rlist<T>& ListToCopy)
{
	Clean();
	Node<T>* TempCurr1 = ListToCopy.head;
	Node<T>* TempCurr2 = head;
	while (TempCurr1->next != ListToCopy.head)
	{
		TempCurr1 = TempCurr1->next;
		TempCurr2->next = new Node<T>(TempCurr1->data);
		TempCurr2 = TempCurr2->next;
	}
	TempCurr2->next = head;
	current = head;
	return *this;
}

template <class T>
void Rlist<T>::InsertAfter(Node<T>* N, T Data)
{
	Node<T>* temp = N->next;
	N->next = new Node<T>(Data);
	N->next->next = temp;
}

template <class T>
void Rlist<T>::OrderedInsert(T Data)
{
	Node<T>* Temp;
	current = head;

	while ( (current->next->data > Data) && current->next != head)
		GetNext();

	Temp = current->next;
	current->next = new Node<T>(Data);
	current->next->next = Temp;
}

template <class T>
void Rlist<T>::Clean()
{
	Node<T>* TempCurr = head->next;
	Node<T>* Temp;
	while (TempCurr != head)
	{
	    Temp = TempCurr->next;
		delete TempCurr;
		TempCurr = Temp;
	}
	head->next = head;
}

template<class T>
bool Rlist<T>::operator==(const Rlist<T>& RLst) const
{
	bool flag = true;
	if (this != &RLst)
	{
		Node<T>* temp1 = head->next;
		Node<T>*  temp2 = RLst.head->next;
		
		while (temp1 != head && temp2 != RLst.head && temp1->data == temp2->data)
		{
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		if (temp1->data != temp2->data)
			flag = false;
	}
	return flag;
}