#include "pch.h"
#include "SomeClass.h"
#include <iostream>
#include<stack>
#include<string>
#include "stringExtend.h"

using namespace CppExtend;

class StringExtendTest : public ::testing::Test
{
protected:
	void SetUp()
	{
		st = new stringExtend;
	}
	void TearDown()
	{
		delete st;
	}

	stringExtend *st;
};

template <class T>
bool compareStack(stack<T> arg1, T* arg2, int n)
{
	bool flag = n == arg1.size();
	if (flag)
	{
		for (int i = 0; i < n; i++)
		{
			flag = arg1.top() == arg2[i];
			if (!flag)
				break;
			arg1.pop();
		}
	}
	return flag;
}


TEST_F(StringExtendTest, addBeforeChar)
{
	st->set("abd");
	string res = st->addBefore('c')->get();
	ASSERT_EQ(res, "cabd");
}


TEST_F(StringExtendTest, addBeforeString)
{
	st->set("abc");
	string res = st->addBefore("d")->get();
	ASSERT_EQ("dabc", res);
}

TEST_F(StringExtendTest, addAfterChar)
{
	st->set("abc");
	string res = st->addAfter('d')->get();
	ASSERT_EQ(res, "abcd");
}

TEST_F(StringExtendTest, addAfterString)
{
	st->set("abc");
	string res = st->addAfter("d")->get();
	ASSERT_EQ(res, "abcd");
}

TEST_F(StringExtendTest, remove1arg)
{
	st->set("abc");
	string res = st->remove(2)->get();
	ASSERT_EQ(res, "ab");
}

TEST_F(StringExtendTest, remove2arg)
{
	st->set("abcd");
	string res = st->remove(3, 1)->get();
	ASSERT_EQ(res, "abc");
}


TEST_F(StringExtendTest, removeBetween)
{
	st->set("abcdefgh");
	string res = st->removeBetween(3, 5)->get();
	ASSERT_EQ("abcgh", res);
}

TEST_F(StringExtendTest, replace)
{
	st->set("abcdef");
	string res = st->replace("ab", "ss")->get();
	ASSERT_EQ(res, "sscdef");
}

TEST_F(StringExtendTest, indexOfChar)
{
	st->set("abcd");
	int index = st->indexOf('c');
	ASSERT_TRUE(index == 2);
}

TEST_F(StringExtendTest, indexOfString)
{
	st->set("abcc");
	int index = st->indexOf("c");
	ASSERT_TRUE(index == 2);
}

TEST_F(StringExtendTest, lastIndexOfChar)
{
	st->set("abcc");
	int index = st->lastIndexOf('c');
	ASSERT_TRUE(index == 3);
}

TEST_F(StringExtendTest, latIndexOfString)
{
	st->set("acbd");
	int index = st->indexOf("c");
	ASSERT_TRUE(index == 1);
}

TEST_F(StringExtendTest, indexOfAnyChar)
{
	st->set("abcc");
	stack<int> indexes = st->indexOfAny('c');

	ASSERT_TRUE(compareStack(indexes, new int[2] {3, 2}, 2));
}

TEST_F(StringExtendTest, indexOfAnyString)
{
	st->set("abcc");
	stack<int> indexes = st->indexOfAny("cc");
	ASSERT_TRUE(compareStack(indexes, new int[1] {2}, 1));
}

TEST_F(StringExtendTest, lastIndexOfAnyChar)
{
	st->set("abcc");
	stack<int> indexes = st->lastIndexOfAny('c');
	ASSERT_TRUE(compareStack(indexes, new int[2] {2, 3}, 2));
}

TEST_F(StringExtendTest, lastIndexOfString)
{
	st->set("abcc");
	stack<int> indexes = st->lastIndexOfAny("cc");
	ASSERT_TRUE(compareStack(indexes, new int[1] {3}, 1));
}

TEST_F(StringExtendTest, compare1)
{
	st->set("abcd");
	ASSERT_TRUE(!st->compare("abcD", false));
}

TEST_F(StringExtendTest, compare2)
{
	st->set("abcd");
	ASSERT_TRUE(st->compare("abcd", true));
}

TEST_F(StringExtendTest, join1)
{
	st->set("");
	stack<char> temp;
	temp.push('a');
	temp.push('b');
	temp.push('c');
	string res = st->join('=',temp)->get();
	ASSERT_EQ(res, "c=b=a");
}


TEST_F(StringExtendTest, join2)
{
	st->set("");
	stack<int> temp;
	temp.push(1); temp.push(2); temp.push(3);
	string res = st->join('=', temp)->get();
	ASSERT_EQ(res, "3=2=1");
}

TEST_F(StringExtendTest, sort1)
{
	st->set("dacbEhgf");
	string res = st->sort(true, false)->get();
	ASSERT_EQ("abcdEfgh", res);
}

TEST_F(StringExtendTest, sort2)
{
	st->set("dacbEhgf");
	string res = st->sort(true, true)->get();
	ASSERT_EQ(res, "Eabcdfgh");
}

TEST_F(StringExtendTest, sort3)
{
	st->set("dacbEhgf");
	string res = st->sort(false, false)->get();
	ASSERT_EQ("hgfEdcba", res);
}

TEST_F(StringExtendTest, sort4)
{
	st->set("dacbEhgf");
	string res = st->sort(false, true)->get();
	ASSERT_EQ(res, "hgfdcbaE");
}

TEST_F(StringExtendTest, substring)
{
	st->set("123456");
	string res = st->substring(2, 3)->get();
	ASSERT_TRUE("345", res);
}

TEST_F(StringExtendTest, substringBetween)
{
	st->set("123456");
	string res = st->substringBetween(2, 5)->get();
	ASSERT_EQ(res, "345");
}

TEST_F(StringExtendTest, toUpper)
{
	st->set("AbCdef");
	string res = st->toUpper()->get();
	ASSERT_EQ(res, "ABCDEF");
}

TEST_F(StringExtendTest, toLowUpCase)
{
	st->set("abCDEf");
	string res = st->toLowUpCase()->get();
	ASSERT_EQ(res, "aBcDeF");
}

TEST_F(StringExtendTest, toUpLowCase)
{
	st->set("AbcdEF");
	string res = st->toUpLowCase()->get();
	ASSERT_EQ(res, "AbCdEf");
}

TEST_F(StringExtendTest, reverce)
{
	st->set("abcdef");
	string res = st->reverse()->get();
	ASSERT_EQ(res, "fedcba");
}

TEST_F(StringExtendTest, fillBefore)
{
	st->set("abcd");
	string res = st->fillBefore(2, '_')->get();
	ASSERT_EQ(res, "__abcd");
}

TEST_F(StringExtendTest, fillAfter)
{
	st->set("abcd");
	string res = st->fillAfter(2, '_')->get();
	ASSERT_EQ(res, "abcd__");
}

TEST_F(StringExtendTest, supplimentBefore)
{
	st->set("abcd");
	string res = st->supplementBefore(6, '_')->get();
	ASSERT_EQ(res, "__abcd");
}

TEST_F(StringExtendTest, supplimentAfter)
{
	st->set("abcd");
	string res = st->supplimentAfter(6, '_')->get();
	ASSERT_EQ(res, "abcd__");
}

TEST_F(StringExtendTest, trim)
{
	st->set(" ab c d  ");
	string res = st->trim()->get();
	ASSERT_EQ(res, "abcd");
}

TEST_F(StringExtendTest, firsti)
{
	st->set("1234");
	char c = st->first();
	ASSERT_TRUE(c == '1');
}

TEST_F(StringExtendTest, lasti)
{
	st->set("1234");
	char c = st->last();
	ASSERT_TRUE(c == '4');
}

TEST_F(StringExtendTest, mostPopularSymbol)
{
	st->set("112343442344");
	char c = st->getMostPopularSymbol();
	ASSERT_TRUE(c == '4');
}

TEST_F(StringExtendTest, splitChar)
{
	st->set("aa.bb.cc");
	stack<string> data = st->split('.');
	ASSERT_TRUE(compareStack(data, new string[3]{ "cc","bb","aa" }, 3));
}

TEST_F(StringExtendTest, splitString)
{
	st->set("aa##bb##cc");
	stack<string> data = st->split("##");
	ASSERT_TRUE(compareStack(data, new string[3]{ "cc","bb","aa" }, 3));
}

TEST_F(StringExtendTest, startWithChar)
{
	st->set("abcdef");
	ASSERT_TRUE(st->startWith('a'));
}

TEST_F(StringExtendTest, startWithString)
{
	st->set("abcdef");
	ASSERT_TRUE(st->startWith("abc"));
}

TEST_F(StringExtendTest, endWithChar)
{
	st->set("abcdef");
	ASSERT_TRUE(st->endWith('f'));
}

TEST_F(StringExtendTest, endWithString)
{
	st->set("abcdef");
	ASSERT_TRUE(st->endWith("def"));
}

TEST_F(StringExtendTest, set)
{
	st->set("c");
	ASSERT_EQ(st->get(), "c");
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}