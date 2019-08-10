#include <iostream>
#include <memory>
#if 0
class Data
{
public:
	Data(int year, int month, int day)
		:year_(year)
		, month_(month)
		, day_(day)
	{}
	friend std::ostream& operator<<(std::ostream& cout_, Data& d);
	friend std::istream& operator>>(std::istream & cin_, Data& d);
public:
	int year_;
	int month_;
	int day_;
};

std::ostream& operator<<(std::ostream& cout_, Data& d)
{
	cout_ << d.day_ << d.month_ << d.year_;
	return cout_;
}


std::istream& operator>>(std::istream & cin_, Data& d)
{
	cin_ >> d.day_ >> d.month_ >> d.year_;
	return cin_;
}


int main()
{
	std::auto_ptr<Data> p1(new Data(1,2,3));

	std::cin >> *p1.get();

	std::cout << *p1.get() << std::endl;
	Data*p3 = p1.get();
	std::cout << *p3 << std::endl;

	Data* p2 = p1.release();
	std::cout << *p2 << std::endl;
	
	return 0;
}
#endif
#if 0
template<class T>
class AutoPtr
{
public:
	explicit AutoPtr(T *ptr)
		:ptr_(ptr)
	{}

	virtual ~AutoPtr()
	{
		if (ptr_)
		{
			delete ptr_;
			ptr_ = nullptr;
		}
	}

	AutoPtr(const AutoPtr& a)
		:ptr_(a.ptr_)
	{
		a.ptr_ = nullptr;
	}

	AutoPtr& operator=(const AutoPtr& a)
	{
		if (this != &a)
		{
			if (ptr_)
				delete ptr_;
			ptr_ = a.ptr_;
			a.ptr_ = nullptr;
		}
		return *this;
	}

	T& operator*()
	{
		return *ptr_;
	}

	T* operator->()
	{
		return ptr_;
	}
private:
	T *ptr_;
};

class Data
{
public:
	Data(int year, int month, int day)
		:year_(year)
		, month_(month)
		, day_(day)
	{}
	friend std::ostream& operator<<(std::ostream& cout_, Data& d);
	friend std::istream& operator>>(std::istream & cin_, Data& d);
public:
	int year_;
	int month_;
	int day_;
};

std::ostream& operator<<(std::ostream& cout_, Data& d)
{
	cout_ << d.day_ << d.month_ << d.year_;
	return cout_;
}


std::istream& operator>>(std::istream & cin_, Data& d)
{
	cin_ >> d.day_ >> d.month_ >> d.year_;
	return cin_;
}

template<class T>
class UniquePtr
{
public:
	explicit UniquePtr(const T* ptr = nullptr)
		:ptr_(ptr)
	{}

	T* operator->()
	{
		return ptr_;
	}

	T& operator*()
	{
		return *ptr_;
	}

private:
	UniquePtr(const UniquePtr&) = delete;
	UniquePtr& operator=(const UniquePtr&) = delete;
	T* ptr_;
};
#include <atomic>
int main()
{
	std::atomic<int* > count(0);
	(*count)++;
	std::cout << count << std:: endl;
	return 0;
}
#endif

//循环引用问题
struct ListNode
{
	int val_;
	std::weak_ptr<ListNode> next_;
	std::weak_ptr<ListNode> pre_;

	virtual ~ListNode()
	{
		std::cout << "~ListNode()" << std::endl;
	}
};

template<class T>
struct deleteArray
{
	void opeator()(T* ptr)
	{
		delete[] ptr;
	}
};

int main()
{
	deleteArray<ListNode> deleteArray;
	std::shared_ptr<ListNode> p1(new ListNode[10], deleteArray);
	//std::shared_ptr<int> p1((int *)malloc(4), deleteArray);
	return 0;
}
