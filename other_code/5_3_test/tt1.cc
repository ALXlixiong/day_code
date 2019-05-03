#include<iostream>
using namespace std;
#include<thread>
#include<mutex>
//单例模式
//class Singleton
//{
//public:
//	static Singleton* GetInstance()
//	{
//		return &m_instance;
//	}
//	friend ostream& operator<<(ostream& _cout, Singleton& s);
//private:
//	Singleton(int data = 0)//私有化构造函数
//	{
//		_data = data;
//	}
//	Singleton(const Singleton& s);//私有化拷贝构造函数
//	Singleton operator=(const Singleton& s);//私有化赋值运算符重载
//	int _data;
//	static Singleton m_instance;
//};
//Singleton Singleton::m_instance(1);
//
//ostream& operator<<(ostream& _cout, Singleton& s)//重载输出
//{
//	_cout << s._data;
//	return _cout;
//}
//
//void test()
//{
//	cout << *(Singleton::GetInstance())<< endl;
//}

class Singleton
{
public:
	static Singleton* GetInstance()
	{
		//此处两层判断，为了就是提高效率
		//此处使用到了锁，为了就是保证线程安全（同步和互斥）
		if (nullptr == m_pInstance)
		{
			m_pInstance = new Singleton;
		}
		return m_pInstance;
	}
	class cycle{
	public:
		~cycle()
		{
			if (m_pInstance != nullptr)
			{
				delete m_pInstance;
				m_pInstance = nullptr;
			}
		}
	private:
		static cycle endflag;
	};
	
	Singleton(const Singleton& s) = delete;
	Singleton operator=(Singleton& s) = delete;
private:
	Singleton(){}
	static Singleton *m_pInstance;//单例对象指针
	static mutex m_tex;
};
Singleton* Singleton::m_pInstance = nullptr;
mutex Singleton::m_tex;
Singleton::cycle Singleton::cycle::endflag;

void fun(int n)
{
	cout << Singleton::GetInstance() << endl;
}

int main()
{
	thread t1(fun, 1);
	thread t2(fun, 2);
	thread t3(fun, 3);
	t1.join();
	t2.join();
	t3.join();
	return 0;
}
