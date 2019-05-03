#include<iostream>
using namespace std;
#include<string>
class HeapOnly
{
public:
	//静态成员（静态区）都是在程序结束释放
	static HeapOnly* Create(int data = 0)
	{
		HeapOnly *p = new HeapOnly;
		p->_data = data;
		return p;
		//不可以直接 return new HeapOnly(data);因为调用构造函数之后data值为随机值。
	}
	//C++11新的屏蔽一个函数
	//1、如果是delete表示这个函数被取消
	//2、如果是default表示这个函数按照编译器默认生成
	//3、可以给为私有的或者共有的，都可以实现相应的功能
	//HeapOnly(const HeapOnly& h) = default;
	HeapOnly(const HeapOnly& h) = delete;

private:
	HeapOnly(int data = 0){}
	//C++98屏蔽一个函数：
	//1、只声明，不给定义，说不定实现特别麻烦
	//2、给为私有的
	//HeapOnly(const HeapOnly& h);
	int _data;
};


//缺点可以在全局创建对象，既不在栈也不再堆。
class StackOnly
{
public:
	StackOnly(int data = 0)
		:_data(data)
	{}
	//屏蔽operator new相当于屏蔽了定位new和new。
	void *operator new(size_t size) = delete;
private:
	int _data;
};


int main()
{
	//HeapOnly *p1 = HeapOnly::Create(1);
	//HeapOnly *p2 = HeapOnly::Create();
	StackOnly d;
	StackOnly *p = (StackOnly *)malloc(sizeof(StackOnly));

	return 0;
}


//class Date
//{
//public:
//	static Date* CreateDate(int year = 2010, int month = 1, int day = 1)
//	{
//		Date *p = new Date;
//		p->_year = year;
//		p->_month = month;
//		p->_day = day;
//		return p;
//	}
//	~Date()//不是必须的，因为拷贝构造函数被屏蔽了，浅拷贝不可能发生了，
//	{
//		delete this;
//	}
//private:
//	Date(int year = 2010, int month = 1, int day = 1){}
//	Date(const Date& d);
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date *p1 = Date::CreateDate();
//	Date *p2 = Date::CreateDate(1996, 10, 1);
//	return 0;
//}
