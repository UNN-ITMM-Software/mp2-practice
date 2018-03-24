#include "gtest.h"
#include "polinom.h"
#include "monom.h"
#include "list.h"
// ����� ������� � ���������
TEST(ListRing, Insert_to_end) // ������� � �����
{
	monom A(12, 14);
	monom B(14, 43);
	ListRing<monom> L;
	L.InsertoTail(A);
	L.InsertoTail(B);
	monom res(L.GetCurrent()->GetData());
	EXPECT_EQ(res,B);

}

TEST(ListRing, Can_create_list) // ����� ������� ����
{
	EXPECT_NO_THROW(ListRing<monom> L);
}

TEST(ListRing, Delete_last_node) // ������� �������� �������
{
	monom A(12, 14);
	monom B(14, 43);
	ListRing<monom> L;
	L.InsertoTail(A);
	L.InsertoTail(B);
	Node<monom>* ptr = L.GetCurrent();
	L.Delete(ptr);
	monom res(L.GetCurrent()->GetData());
	EXPECT_EQ(res, A);

}

TEST(ListRing, Can_check_is_empty) // �������� �� ������� �� ������� �����
{
	monom A(12, 14);
	monom B(14, 43);
	ListRing<monom> L;
	L.InsertoTail(A);
	L.InsertoTail(B);
	EXPECT_EQ(0, L.IsEmpty());

}

TEST(ListRing, Can_check_is_empty_if_empty) // �������� �� ������� ������� �����
{
	ListRing<monom> L;
	EXPECT_EQ(1, L.IsEmpty());

}

TEST(ListRing, Can_check_is_empty_if_wasnot_empty) // �������� �� ������� ���������� �����
{
	monom A(12, 14);
	monom B(14, 43);
	ListRing<monom> L;
	L.InsertoTail(A);
	L.InsertoTail(B);
	L.clear();
	EXPECT_EQ(1, L.IsEmpty());
}

TEST(ListRing, OPERATOR_Ravno) // �������� ���������  = 
{
	monom A(12, 14);
	monom B(14, 43);
	ListRing<monom> L;
	L.InsertoTail(A);
	L.InsertoTail(B);
	ListRing<monom> Z = L;
	EXPECT_EQ(Z.GetCurrent()->GetData(), L.GetCurrent()->GetData());
}


// ����� ��� ��������, �������������������

struct T //��������� ��� �������� �������� �������� (���������� ������)
{
	string s;
	monom LastMonom;

	T(string mys = "", monom f = monom(0,0))
	{
		s = mys;
		LastMonom = f;
	}
};

class ParameterizedStringForPolinom : public ::testing::TestWithParam<T>
{
protected:
	struct T testcase;

public:
	ParameterizedStringForPolinom() : testcase(GetParam())
	{
	}

	~ParameterizedStringForPolinom() {}
};

TEST_P(ParameterizedStringForPolinom, can_create_polinom)
{
	Polinom A(GetParam().s);
	EXPECT_EQ(GetParam().LastMonom, A.GetList().GetCurrent()->GetData());
}

T myarray[] = { T("3+z+y+x", monom(100,1)) , T("3+z+y",monom(10,1)), T("1+z+12.3x^3", monom(300,12.3)),  T("1+z+12.3x^3y^3z^1", monom(331,12.3)) };

INSTANTIATE_TEST_CASE_P(Instantiation1,
	ParameterizedStringForPolinom,
	::testing::ValuesIn(myarray));

