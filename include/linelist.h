#pragma once

#include <iostream>
#include "line.h"
using namespace std;


template <class DataType>
struct Node
{
	DataType data;
	Node* next;

	Node(DataType d = DataType(), Node<DataType>* n = NULL)
	{
		data = d;
		next = n;
	}
	Node(const Node<DataType>& node2)
	{
		data = node2.data;
		next = NULL;
	}
	bool operator==(const Node<DataType>& node2) const
	{
		return (data == node2.data && next == node2.next);
	}
	bool operator!=(const Node<DataType>& node2) const
	{
		return !(*this == node2);
	}

};

template <class DataType>
class List
{
	// ����� ����
	Node<DataType>* cur;
	Node<DataType>* head;
public:
	List() { head = NULL; }
	List(const List<DataType>& list2);
	List<DataType>& operator=(const List<DataType>& list2);
	~List();

	void InsertToHead(const DataType& d); // �������� ������� d ������
	void InsertToTail(const DataType& d); // �������� ������� d ���������
	void InsertAfter(Node<DataType>* node, const DataType& d); // �������� ������� d ����� ����� node
	void Delete(const DataType& d); // ������� ����� �� ��������� data = d
	Node<DataType>* Search(const DataType& d); // ����� ��������� �� ����� �� ��������� data = d
	void Clean(); // ������� ��� ������
	int GetSize(); // ������ ����� ������� � ������
	Node<DataType>* GetHead(); // �������� ��������� �� ������ ����� ������
	bool IsEmpty() {return head == NULL; }
	void Reset() { cur = head; }
	void GetNext() { cur = cur->next; }
	Node<DataType>* GetCur() { return cur; }
	void Inverse(); // ������������� ������, �.�. ������ ������ ���� � �������� �������
	List<DataType> Merge(Node<DataType>* node, const List& list2); // ������� ������3, ������� ������2 � ������� ������ ����� ��������� node  
	List<DataType> Merge(const List<DataType>& list2); // ������� ������3, ������� � ����� �������� ������ ������2


	bool operator==(const List& list2) const; // ������ �����, ���� �������� � ��� ���� � ���������� �������
};

template <class DataType>
List<DataType>::List(const List<DataType>& list2)
{
	if (list2.head)
	{
		Node<DataType>* cur = new Node<DataType>(list2.head->data);
		Node<DataType>* temp = list2.head;
		head = cur;
		while (temp->next)
		{
			temp = temp->next;
			cur->next = new Node<DataType>(temp->data);
			cur = cur->next;
		}
	}
	else
		head = NULL;
}

template <class DataType>
List<DataType>& List<DataType>::operator=(const List<DataType>& list2)
{
	if (head != list2.head)
	{
		Clean();
		if (list2.head)
		{
			Node<DataType>* cur = new Node<DataType>(list2.head->data);
			Node<DataType>* temp = list2.head;
			head = cur;
			while (temp->next)
			{
				temp = temp->next;
				cur->next = new Node<DataType>(temp->data);
				cur = cur->next;
			}
		}
		else
			head = NULL;
	}
	return *this;
}

template <class DataType>
List<DataType>::~List()
{
	Clean();
}

template <class DataType>
void List<DataType>::Clean()
{
	Node<DataType>* cur;
	Node<DataType>* temp = head;
	if (head)
		while (temp)
		{
			cur = temp->next;
			delete temp;
			temp = cur;
		}
	head = NULL;
}

template <class DataType>
int List<DataType>::GetSize()
{
	int res = 0;
	Node<DataType>* cur = head;
	while (cur)
	{
		res++;
		cur = cur->next;
	}
	return res;
}

template <class DataType>
Node<DataType>* List<DataType>::GetHead()
{
	return head;
}

template <class DataType>
bool List<DataType>::operator==(const List<DataType>& list2) const
{
	Node<DataType>* cur1 = head;
	Node<DataType>* cur2 = list2.head;
	bool res = true;
	if (cur1 != NULL && cur2 != NULL && cur1 != cur2)
	{
		while (res && cur1->next && cur2->next)
			if (cur1->data == cur2->data)
			{
				cur1 = cur1->next;
				cur2 = cur2->next;
			}
			else
				res = false;
		if (cur1->next || cur2->next)
			res = false;
	}
	else
		if (cur1 != cur2)
			res = false;
	return res;
}

template <class DataType>
void List<DataType>::InsertToHead(const DataType& d)
{
	Node<DataType>*temp = new Node<DataType>(d, head);
	head = temp;
}

template <class DataType>
void List<DataType>::InsertToTail(const DataType& d)
{
	Node<DataType>*cur = head;
	if (cur)
	{
		while (cur->next)
			cur = cur->next;
		cur->next = new Node<DataType>(d);
	}
	else
		head = new Node<DataType>(d);
}

template <class DataType>
void List<DataType>::InsertAfter(Node<DataType>* node, const DataType& d)
{
	if (node && head)
	{
		Node<DataType>*temp = node->next;
		node->next = new Node<DataType>(d, temp);
	}
	else
		if (head == NULL)
			throw "";
}

template <class DataType>
void List<DataType>::Delete(const DataType& d)
{
	Node<DataType>* cur = head;
	Node<DataType>* temp;
	if (head)
	{
		if (head->data == d)
		{
			temp = head->next;
			delete head;
			head = temp;
		}
		else
		{
			while (cur->next)
			{
				if (cur->next->data != d)
					cur = cur->next;
				else
				{
					temp = cur->next;
					cur->next = temp->next;
					delete temp;
				}
			}
		}
	}
}

template <class DataType>
void List<DataType>::Inverse()
{
	if (head)
	{
		Node<DataType>* temp = head->next;
		head->next = NULL;
		Node<DataType>* cur = head;
		Node<DataType>* p;
		while (temp)
		{
			p = temp->next;
			temp->next = cur;
			cur = temp;
			temp = p;
		}
		head = cur;
	}
}

template <class DataType>
Node<DataType>* List<DataType>::Search(const DataType& d)
{
	Node<DataType>*cur = head;
	while (cur)
	{
		if (cur->data == d)
			return cur;
		cur = cur->next;
	}
	return NULL;
}

template <class DataType>
List<DataType> List<DataType>::Merge(Node<DataType>* node, const List<DataType>& list2)
{
	List<DataType> res;
	Node<DataType>* cur1 = head;
	if (head)
	{
		res.head = new Node<DataType>(head->data);
		Node<DataType>* temp = res.head;
		while (cur1->next && cur1 != node)
		{
			temp->next = new Node<DataType>(cur1->next->data);
			temp = temp->next;
			cur1 = cur1->next;
		}
		if (cur1 == node)
		{
			if (list2.head)
			{
				Node<DataType>* cur2 = list2.head;
				while (cur2)
				{
					temp->next = new Node<DataType>(cur2->data);
					cur2 = cur2->next;
					temp = temp->next;
				}
			}
			while (cur1->next)
			{
				temp->next = new Node<DataType>(cur1->next->data);
				cur1 = cur1->next;
				temp = temp->next;
			}
		}
		temp->next = NULL;
	}
	return res;
}

template <class DataType>
List<DataType> List<DataType>::Merge(const List<DataType>& list2)
{
	List res(*this);
	if (res.head && list2.head)
	{
		Node<DataType>* cur = res.head;
		while (cur->next)
			cur = cur->next;


		Node<DataType>* temp = list2.head;
		while (temp)
		{
			cur->next = new Node<DataType>(temp->data);
			cur = cur->next;
			temp = temp->next;
		}
		cur->next = NULL;
	}
	else if (res.head == NULL) res = List(list2);
	return res;
}

