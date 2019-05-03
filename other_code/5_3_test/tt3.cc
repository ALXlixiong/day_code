#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<malloc.h>
#include<cstring>
#include<stdlib.h>
#include <crtdbg.h>


class Test{
public:
	Test(int t = 10)
		:_t(t)
	{}
	Test(const Test& t)
	{
		_t = t._t;
	}
private:
	void *operator new(size_t size);
	void operator delete(void *p);
	int _t;
};


int main()
{
	//屏蔽掉new的功能就可以了，所以屏蔽掉opertor new就可以了，而且把定位new也屏蔽了
	Test t;
	//缺陷：可以在全局创建（既不在堆上，也不再栈上）
	//Test *p = new Test;
	//封装一个静态函数，可以避免在数据段创建。
	return 0;
}

//int main()
//{
//	//只能在栈上创建一个对象
//	//Test *p = new Test;
//	//1.禁掉构造函数,可是栈上又创建不了了，可以封装一个static函数
//	Test t = Test::Createtest(1);
//	//但是缺陷
//	Test t1(Test::Createtest(1));//本来创建一个导致创建了多个。
//	return 0;
//}

//class Date{
//public:
//	static Date* CreateDate()
//	{
//		return new Date;
//	}
//	~Date()
//	{
//		cout << this << endl;
//	}
//	//C++11，禁掉函数方法：可以私有或者共有，表示把该函数删除
//	Date(const Date& d) = delete;
//	//Date(const Date& d) = default;//告诉编译器默认生成该函数
//	friend ostream& operator<<(ostream& _cout, Date& d);
//private:
//	Date(int year = 1900, int month = 1, int day = 1)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{
//		cout << this << endl;
//	}
//	//C++98，把一个函数禁止掉，可以只给声明，不给定义，并且是私有的
//	//Date(const Date& d);
//	int _year;
//	int _month;
//	int _day;
//};
//ostream& operator<<(ostream& _cout, Date& d)
//{
//	_cout << d._year << "-" << d._month << "-" << d._day;
//	return _cout;
//}
//
//int main()
//{
//	//设计一个类，只能在栈上创建对象，那么在堆上创建
//	//1.把构造函数给为私有的，堆和构造函数都不可以创建了，
//	//2.可以在类外调用静态成员函数
//	Date *p = Date::CreateDate();
//	//但是Date d(*p);可以只声明，不给定义
//	//但是不定义，可能用户在外面给你定义，所以要把拷贝构造函数给为私有的，
//	delete p;
//	//Date d(*p);//c++11，已是一个删除的函数
//
//	return 0;
//}


//void *operator new(size_t size,char *filename,char *strfunname,size_t num)
//{
//	void *p = ::operator new(size);
//	cout << filename << strfunname << num << endl;
//	return p;
//}
//
//void operator delete(void *p, char *filename, char *strfunname, size_t num)
//{
//	::operator delete(p);
//	cout << filename << strfunname << num << endl;
//}


//void GetMemory(char *p, int num)
//{
//	p = (char*)malloc(sizeof(char)* num);
//}
//
//int main(int argc, char** argv)
//{
//	char *str = NULL;
//	GetMemory(str, 100);
//	cout << "Memory leak test!" << endl;
//	_CrtDumpMemoryLeaks();
//	return 0;
//}




//class N
//{
//public:
//	N()
//	{
//		++_count;
//	}
//	N(N& a)
//	{
//		++_count;
//	}
//	~N()
//	{
//		--_count;
//	}
//	static int GetCount()
//	{
//		return _count;
//	}
//	void test()
//	{
//		;
//	}
//private:
//	static int _count;
//};
//
//int N::_count = 0;
//class Solution {
//public:
//	Solution()
//	{
//		++_count;
//		_sum += _count;
//	}
//	static void reset()
//	{
//		_count = 0;
//		_sum = 0;
//	}
//	static int GetCount()
//	{
//		return _sum;
//	}
//
//	int Sum_Solution(const int n);
//private:
//	static int _sum;
//	static int _count;
//};
//int Solution::_sum = 0;
//int Solution::_count = 0;
//
//int Solution::Sum_Solution(const int n)
//{
//	Solution::reset();
//	Solution arr[5];
//	return Solution::GetCount();
//}

//class Date
//{
//public:
//	Date(int year = 1990, int month = 1, int day = 1)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{}
//
//	class Time
//	{
//	public:
//		Time(int hour = 0, int minute = 0, int second = 0)
//			:_hour(hour)
//			, _minute(minute)
//			, _second(second)
//		{}
//		void display(Date& d)
//		{
//			cout << d._year << "-" << d._month << "-" << d._day<<" ";
//			cout << _hour << ":" << _minute << ":" << _second << endl;
//		}
//	private:
//		int _hour;
//		int _minute;
//		int _second;
//	};
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	int a = -1;
//	printf("%d\n", -5 % 4);
//	return 0;
//}


