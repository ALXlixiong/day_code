#include <iostream>

class Data
{
	friend std::ostream& operator<<(std::ostream& _cout, Data &d);
	friend std::istream& operator>>(std::istream& _cin, Data &d);
public:
	explicit Data(int year = 1990,int month= 1,int day = 1)
		:year_(year)
		, month_(month)
		, day_(day)
	{}
private:
	int year_;
	int month_;
	int day_;
};

std::ostream& operator<<(std::ostream& _cout, Data &d)
{
	_cout << d.year_ << "-" << d.month_ << "-" << d.day_;
	return _cout;
}
std::istream& operator>>(std::istream& _cin, Data &d)
{
	_cin >> d.year_;
	_cin >> d.month_;
	_cin >> d.day_;
	return _cin;
}

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

