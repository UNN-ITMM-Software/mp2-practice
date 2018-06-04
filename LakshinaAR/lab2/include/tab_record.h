#pragma once
#include <string>

using namespace std;


template <class type>
struct record 
{
	type* data;
	string key;
	record() {key = ""; data = nullptr;}                                            //����������� ��� ����������
	
	record(string k) { key = k; data = nullptr; }
	
	record(string s, type t)  {key = s; data = new type(t);}                        //����������� � ����������
	record(const record<type>& r) { key = r.key; data = new type(*(r.data)); }      //����������� �����������
	record<type>& operator=(const record<type>& r);                                 //������������
	~record() { delete data; };
	bool operator==(const record<type>& r) const { return key == r.key; }
	bool operator!=(const record<type>& r) const { return !(*this == r); }

};


template <class type> record<type>& record<type>::operator=(const record<type>& r)
{
	key = r.key;
	delete data;
	data = new type(*(r.data));
	return *this;
}