#include <iostream>
#include <string.h>
class Data
{
public:
	Data(int a = 0)
	:a_(a)
	{}
private:
	int a_;
};





class HeapOnly
{
public:
	static HeapOnly* GetHeapOnly()
	{
		return new HeapOnly;
	}
	HeapOnly(const HeapOnly &) = delete;
	HeapOnly& operator=(const HeapOnly&) = delete;
private:
	HeapOnly(){}
};

class StackOnly
{
public:
	StackOnly(){}
	void *operator new(size_t) = delete;
};

//class Singleton
//{
//public:
//	static Singleton *GetInstance()
//	{
//		return &m_instance;
//	}
//	Singleton(const Singleton&) = delete;
//	Singleton& operator=(const Singleton&) = delete;
//private:
//	Singleton(){}
//	static Singleton m_instance;
//};
//Singleton Singleton::m_instance;
#include <mutex>
class Singleton
{
public:
	static Singleton* GetInstance()
	{
		if (m_instance == nullptr)
		{
			m_.lock();
			if (m_instance == nullptr)
			{
				m_instance = new Singleton;
			}
			m_.unlock();
		}
		return m_instance;
	}

	class Cycle
	{
	public:
		~Cycle()
		{
			if (m_instance)
			{
				delete m_instance;
				m_instance = nullptr;
			}
		}
	};
	
private:
	static Singleton* m_instance;
	static std::mutex m_;
	static Cycle cycle_;
};
Singleton* Singleton::m_instance = nullptr;
std::mutex Singleton::m_;
Singleton::Cycle Singleton::cycle_;

int main()
{
	HeapOnly *p = HeapOnly::GetHeapOnly();
	HeapOnly *h;
	//StackOnly *p = new StackOnly;
	return 0;
}
