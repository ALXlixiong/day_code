#include <iostream>

//class Data
//{
//	friend std::ostream& operator<<(std::ostream& _cout, Data &d);
//	friend std::istream& operator>>(std::istream& _cin, Data &d);
//public:
//	explicit Data(int year = 1990,int month= 1,int day = 1)
//		:year_(year)
//		, month_(month)
//		, day_(day)
//	{}
//private:
//	int year_;
//	int month_;
//	int day_;
//};

//std::ostream& operator<<(std::ostream& _cout, Data &d)
//{
//	_cout << d.year_ << "-" << d.month_ << "-" << d.day_;
//	return _cout;
//}
//std::istream& operator>>(std::istream& _cin, Data &d)
//{
//	_cin >> d.year_;
//	_cin >> d.month_;
//	_cin >> d.day_;
//	return _cin;
//}

#if 0
template<class T,class K>
K Add(const T& left, const K& right)
{
	return left + right;
}
int main()
{
	std::cout << Add<int, double>(1, 2.0) << std::endl;
	std::cout << Add(1, 2.2) << std::endl;
	return 0;
}
#endif

#if 0
int main()
{
	Data d;
	Data d1(1, 1, 1);
	std::cout << d <<d1<< std::endl;
	std::cin >> d;
	std::cout << d << std::endl;

	return 0;
}
#endif

#if 0
template<class T>
struct ListNode
{
	T val_;
	ListNode<T> *next_;
	explicit ListNode(T val)
		:val_(val)
		, next_(nullptr)
	{}
};

template<class T>
class List
{
	typedef ListNode<T> Node;
	typedef Node* PNode;
public:
	List()
		:pHead_(nullptr)
	{}
	void InsertNode(T val)
	{
		if (pHead_ == nullptr)
		{
			pHead_ = new Node(val);
			pHead_->next_ = nullptr;
		}
		else
		{
			PNode cur = pHead_;
			while (cur->next_)
				cur = cur->next_;
			cur->next_ = new Node(val);
		}
	}
	void PrintList()
	{
		PNode cur = pHead_;
		while (cur)
		{
			std::cout << cur->val_ << " ";
			cur = cur->next_;
		}
		std::cout << std::endl;
	}
private:
	PNode pHead_;
};

int main()
{
	List<int> l;
	l.InsertNode(1);
	l.InsertNode(2);
	l.InsertNode(3);
	l.InsertNode(4);
	l.InsertNode(5);
	l.PrintList();
	return 0;
}
#endif
#if 0
#include <vector>
#define MAX 100000000
std::vector<bool> prime(MAX + 1, true);
int main()
{
	prime[0] = prime[1] = false;
	for (int i = 2; i*i <= MAX; ++i)
	{
		if (prime[i])
		{
			for (int j = i + i; j <= MAX; j += i)
				prime[j] = false;
		}
	}
	int count = 0;
	for (int i = 0; i <= MAX; ++i)
	{
		if (prime[i])
			++count;
	}
	std::cout << count << std::endl;
	return 0;
}
#endif
#if 0
#include <cstring>
#pragma warning(disable:4996)
#include <cassert>
class String
{
public:
	String(const char* str = "")
	{
		if (str == nullptr)
		{
			assert(nullptr);
			return;
		}
		str_ = new char[strlen(str) + 1];
		strcpy(str_, str);
	}
	String(const String& s)
	{
		str_ = new char[strlen(s.str_) + 1];
		strcpy(str_, s.str_);
	}
	String& operator=(const String& s)
	{
		if (this != &s)
		{
			char *tmp = new char[strlen(s.str_)+1];
			strcpy(tmp, s.str_);
			delete[] str_;
			str_ = tmp;
		}
		return *this;
	}
	~String()
	{
		if (str_)
		{
			delete[] str_;
			str_ = nullptr;
		}
	}
private:
	char *str_;
};


int main()
{
	String s1;
	String s2("hello");
	String s3(s2);
	s1 = s2;
	return 0;
}
#endif

#include <vector>
#if 0
int main()
{
	std::vector<int> v{ 1, 2, 3, 4 };
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	for (auto &e : v)
		std::cout << e << " ";
	std::cout << std::endl;
	for (auto it = v.rbegin(); it != v.rend(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	auto pos = find(v.begin(), v.end(), 3);
	std::cout << *(pos - 1) << std::endl;

	v.insert(pos, 10);
	for (auto it = v.rbegin(); it != v.rend(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	pos = find(v.begin(), v.end(), 3);
	v.erase(pos);
	for (auto it = v.rbegin(); it != v.rend(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	return 0;
}
#endif
#include <list>
#include <functional>
#include <queue>
#include <algorithm>
#if 0
struct cmp
{
	bool operator()(const int& left, const int& right)
	{
		return left > right;
	}
};

int main()
{
	std::vector<int> v{ 4, 2, 1, 5, 7, 8 };
	sort(v.begin(), v.end());
	for (auto &e : v)
		std::cout << e << " ";
	std::cout << "\n";
	sort(v.begin(), v.end(), cmp());
	std::priority_queue<int> q;
	for (auto &e : v)
		q.push(e);
	std::cout << q.top() << std::endl;
	std::priority_queue<int, std::vector<int>,cmp > q1;
	for (auto &e : v)
		q1.push(e);
	std::cout << q1.top() << std::endl;
	return 0;
} 
#endif
#if 0
//#define num 10
#include <array>
#include <algorithm>
class Solution
{
private:
	//constexpr int num;
	//std::array<int, num> v_;
};


int main()
{
	std::vector<int> v{ 1, 2, 3, 4 };
	
	return 0;
}
#endif
#if 0
class Solution
{
public:
	static int GetResult(int n,int& ret)
	{
		n&&GetResult(n - 1, ret);
		ret += n;
		return ret;
	}
};
int main()
{
	int ret = 0;
	std::cout << Solution::GetResult(3, ret) << std::endl;
	return 0;
}
#endif
#if 0

template<class T1,class T2>
class Data
{
public:
	Data()
	{
		std::cout << "Data<T1,T2>" << "\n";
	}
private:
	T1 a_;
	T2 b_;
};

template<>
class Data<int, int>
{
public:
	Data()
	{
		std::cout << "Data<int,int>\n";
	}
private:
	int a_;
	int b_;
};

template<class T1>
class Data<T1, char*>
{
public:
	Data()
	{
		std::cout << "Data<T1,char*>\n";
	}
private:
	T1 a_;
	char *b_;
};

int main()
{
	Data<int, int> d1;
	Data<int, char *> d2;
	Data<double, int> d3;
	return 0;
}

#endif
#include <assert.h>
#pragma warning(disable:4996)
#if 0
class String
{
public:
	String(char *str = "")
	{
		if (str == nullptr)
		{
			assert(nullptr);
			return;
		}
		str_ = new char[strlen(str) + 1];
		strcpy(str_, str);
	}
	String(const String& s)
	{
		str_ = s.str_;
	}
	~String()
	{
		if (str_)
		{
			delete[] str_;
			str_ = nullptr;
		}
	}
private:
	char *str_;
};

int main()
{
	String s1("haha");
	String s2(s1);
	return 0;
}
#endif


