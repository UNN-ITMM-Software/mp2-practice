﻿#include <gtest.h>
#include "ScanTable.h"

using namespace std;


TEST(ScanTable, can_create_unord_table)
{
	ASSERT_NO_THROW(ScanTable<int> Tab);
}
//............................................................
class EmptyScan : public testing::Test
{
protected:
	ScanTable<int> Tab;
public:
	EmptyScan() {};
	~EmptyScan() {};
};
////............................................................
TEST_F(EmptyScan, new_table_is_empty)
{
	EXPECT_EQ(true, Tab.IsEmpty());
}
////............................................................................
TEST_F(EmptyScan, can_copy_empty_table)
{
	ASSERT_NO_THROW(ScanTable<int> T(Tab));
}
////............................................................................
TEST_F(EmptyScan, copied_empty_table_is_correct)
{
	ScanTable<int> T(Tab);
	EXPECT_EQ(Tab.IsEmpty(), T.IsEmpty());
}
TEST_F(EmptyScan, cant_get_current_from_empty_table)
{
	ASSERT_ANY_THROW(Tab.GetCurr());
}
////............................................................................
TEST_F(EmptyScan, can_reset_empty_table)
{
	ASSERT_NO_THROW(Tab.Reset());
}
////............................................................................
TEST_F(EmptyScan, reset_empty_table_is_correct)
{
	Tab.Reset();
	ASSERT_ANY_THROW(Tab.GetCurr());
}
////............................................................................
TEST_F(EmptyScan, is_end_is_correct_for_empty_table)
{
	bool k = Tab.IsTabEnded();
	EXPECT_EQ(true, Tab.IsTabEnded());
}
////............................................................................
TEST_F(EmptyScan, cant_set_next_empty_table)
{
	ASSERT_ANY_THROW(Tab.SetNext());
}
////............................................................................
TEST_F(EmptyScan, cant_delete_from_empty_table)
{
	ASSERT_ANY_THROW(Tab.Delete("one"));
}
////............................................................................
TEST_F(EmptyScan, cant_search_in_empty_table)
{
	ASSERT_ANY_THROW(Tab.Search("one"));
}
////............................................................................
TEST_F(EmptyScan, can_insert_in_empty_table)
{
	ASSERT_NO_THROW(Tab.Insert(1, "one"));
}
////----------------------------------------------------------------------------
TEST_F(EmptyScan, insert_in_empty_table_is_correct)
{
	Tab.Insert(1, "one");
	EXPECT_EQ(1, Tab.GetCurrRecords());
	EXPECT_EQ(1, *(Tab.Search("one")));
}
//----------------------------------------------------------------------------
class FilledScan : public testing::Test
{
protected:
	ScanTable<int> T;
public:
	FilledScan()
	{
		for (int i = 0; i < 3; i++)
			T.Insert(i, std::to_string(i));
	}
	~FilledScan() {};
};
//----------------------------------------------------------------------------
TEST_F(FilledScan, can_get_current_from_filled_table)
{
	T.Reset();
	ASSERT_NO_THROW(*(T.GetCurr()));
}
////----------------------------------------------------------------------------
TEST_F(FilledScan, get_current_from_filled_table_is_corect)
{
	T.Reset();
	EXPECT_EQ(0, *(T.GetCurr()));
}
////----------------------------------------------------------------------------
TEST_F(FilledScan, can_set_next_in_filled_table)
{
	T.Reset();
	ASSERT_NO_THROW(T.SetNext());
}
////----------------------------------------------------------------------------
TEST_F(FilledScan, set_next_in_filled_table_is_correct)
{
	T.Reset();
	T.SetNext();
	EXPECT_EQ(1, *(T.GetCurr()));
}
////----------------------------------------------------------------------------
TEST_F(FilledScan, set_next_in_the_end)
{
	T.Reset();
	T.SetNext();//1
	T.SetNext();//2
	T.SetNext();//
	EXPECT_EQ(0, *(T.GetCurr()));
}
////----------------------------------------------------------------------------
TEST_F(FilledScan, filled_table_was_correctly_filled)
{
	T.Reset();
	EXPECT_EQ(0, *(T.GetCurr()));
	T.SetNext();
	EXPECT_EQ(1, *(T.GetCurr()));
	T.SetNext();
	EXPECT_EQ(2, *(T.GetCurr()));
}
////----------------------------------------------------------------------------
TEST_F(FilledScan, can_copy_filled_table)
{
	ASSERT_NO_THROW(ScanTable<int> A(T));
}
////----------------------------------------------------------------------------
TEST_F(FilledScan, copied_filled_table_is_correct)
{
	ScanTable<int> A(T);
	A.Reset();
	EXPECT_EQ(0, *(A.GetCurr()));
	A.SetNext();
	EXPECT_EQ(1, *(A.GetCurr()));
	A.SetNext();
	EXPECT_EQ(2, *(A.GetCurr()));
}
////----------------------------------------------------------------------------
TEST_F(FilledScan, copied_filled_table_has_its_own_memory)
{
	ScanTable<int> A(T);
	A.Delete("0");
	T.Reset();
	A.Reset();
	EXPECT_EQ(0, *(T.GetCurr()));
	EXPECT_NE(0, *(A.GetCurr()));
}
////----------------------------------------------------------------------------
TEST_F(FilledScan, is_full_is_correct)
{
	for (int i = 3; i<10; i++)
		T.Insert(i, std::to_string(i));
	EXPECT_EQ(true, T.IsFull());
}
////----------------------------------------------------------------------------
TEST_F(FilledScan, isnt_full_after_realloc)
{
	for (int i = 3; i<11; i++)
		T.Insert(i, std::to_string(i));
	EXPECT_EQ(false, T.IsFull());
}
////----------------------------------------------------------------------------
TEST_F(FilledScan, is_empty_after_deletion)
{
	T.Delete("0");
	T.Delete("1");
	T.Delete("2");
	EXPECT_EQ(true, T.IsEmpty());
}
////---------------------------------------------------------------------------
TEST_F(FilledScan, can_insert_after_deletion)
{
	T.Delete("0");
	T.Delete("1");
	T.Delete("2");
	T.Insert(0, "0");
	EXPECT_EQ(0, *(T.GetCurr()));
}
//// ----------------------------------------------------------------------------
TEST_F(FilledScan, can_insert)
{
	T.Insert(3, "3");
	T.Reset();
	T.SetNext();
	T.SetNext();
	T.SetNext();
	EXPECT_EQ(3, *(T.GetCurr()));
}
////----------------------------------------------------------------------------
TEST_F(FilledScan, can_delete)
{
	T.Delete("2");
	T.Reset();
	EXPECT_EQ(0, *(T.GetCurr()));
	T.SetNext();
	EXPECT_EQ(1, *(T.GetCurr()));
	T.SetNext();
	EXPECT_EQ(0, *(T.GetCurr()));

}
////----------------------------------------------------------------------------
TEST_F(FilledScan, can_search)
{
	T.Search("2");
	EXPECT_EQ(2, *(T.Search("2")));
}
//----------------------------------------------------------------------------
TEST_F(FilledScan, cant_insert_record_wich_key_isnt_unique)
{
	ASSERT_ANY_THROW(T.Insert(2, "2"));
}