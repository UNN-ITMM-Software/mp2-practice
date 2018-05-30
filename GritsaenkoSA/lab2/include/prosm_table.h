﻿#pragma once

#include "table.h" 
#include "math.h"
#include <string>

using namespace std;


template <class type_k, class type_d>//неупорядоченная таблица
class ScanTable : public Table <type_k, type_d>
{
private:
	virtual void Realloc();  //переупаковка
public:
	ScanTable(int size = 10) ;//конструктор по умолчанию
	virtual ~ScanTable();//деструктор

	virtual void Insert(const type_k & key, const type_d & Row);	//вставка
	virtual void Delete(const type_k & key);							//удаление
	virtual TableRec<type_k, type_d>* Search(const type_k & key) const;		//поиск
																					

};


template <class type_k, class type_d>//конструктор по умолчанию
ScanTable <type_k, type_d>::ScanTable(int size) : Table<type_k, type_d>(size) 
{
}


template <class type_k, class type_d>//деструктор
ScanTable <type_k, type_d>::~ScanTable() 
{
}

template <class type_k, class type_d>//переупаковка
void ScanTable <type_k, type_d>::Realloc()
{
	int MaxSizeT1 = MaxSizeT*2;
	TableRec<type_k, type_d> ** temp = new TableRec<type_k, type_d>*[MaxSizeT1];
	for (int i = 0; i < this -> MaxSizeT; i++)
		temp[i] = this -> Rows[i];
	for (int i = this->MaxSizeT; i<MaxSizeT1; i++)
		temp[i] = NULL;
	this -> MaxSizeT = MaxSizeT1;
	delete[] this -> Rows;
	this -> Rows = temp;
	
}


template <class type_k, class type_d>//вставка
void ScanTable< type_k, type_d> ::Insert(const type_k & key, const type_d & Row)
{
	if ((double)this->CurSizeT / (double)this->MaxSizeT > 0.7)  //проверка на полноту
	//if (IsFull())
		Realloc();

	for (int i = 0; i < this->CurSizeT; i++)
	{
		if ((*(this->Rows[i])).KEY == key)
		{
			throw "error: the same key";
		}
	}
	this -> Rows[this -> CurSizeT++] = new TableRec<type_k, type_d>(key, Row);
}


template <class type_k, class type_d>//поиск
TableRec<type_k, type_d>* ScanTable< type_k, type_d> ::Search(const type_k & key) const
{
	int i = 0;
	while (i < this->CurSizeT)
	{
		if ((*(this->Rows[i])).KEY == key)
			return this->Rows[i];
		i++;
	}
	throw "error: ne found";
}


template <class type_k, class type_d> 	//удаление
void ScanTable< type_k, type_d> ::Delete(const type_k & key)
{
	int i = 0;
	int flag = 0;
	while ((i < this->CurSizeT) && (flag == 0)) 
	{
		if ((*(this->Rows[i])).KEY == key) 
			flag = 1;
		i++;
	}
	if (flag == 1) 
	{
		i--;
		delete this->Rows[i];
		while (i < this->CurSizeT - 1) 
		{
			this->Rows[i] = this->Rows[i + 1];
			i++;
		}
		this->Rows[i] = NULL;
		this->CurSizeT--;
	}
	else throw "error: ne found";
}

