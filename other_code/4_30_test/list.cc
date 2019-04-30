using namespace std;
#include<iostream>
#include<vector>
namespace N
{
	//list节点类
	template<class T>
	struct ListNode
	{
		ListNode(const T& data = T())
		:_pPre(nullptr)
		, _pNext(nullptr)
		, _data(data)
		{}

		ListNode<T>* _pPre;
		ListNode<T>* _pNext;
		T _data;
	};


	//迭代器实现
	//1、原生态指针
	//2、封装原生态指针
	template<class T, class Ref, class Ptr>
	class ListIterator
	{
		typedef ListNode<T> Node;
		typedef Node* PNode;
		//Ref:返回值是引用
		//Ptr：返回值是指针
		typedef ListIterator<T, Ref, Ptr> Self;
	public:
		ListIterator(PNode pNode = nullptr)
			:_pNode(pNode)
		{}
		ListIterator(const Self& l)
			:_pNode(l._pNode)
		{}

		Ref operator*()
		{
			return _pNode->_data;
		}

		Ptr operator->()
		{
			return &(operator*());
		}

		Self& operator++()
		{
			_pNode = _pNode->_pNext;
			return *this;
		}
		Self& operator++(int)
		{
			Self temp(*this);
			_pNode = _pNode->_pNext;
			return temp;
		}
		Self& operator--()
		{
			_pNode = _pNode->_pPre;
			return *this;
		}
		Self& operator--(int)
		{
			Self temp(*this);
			_pNode = _pNode->_pPre;
			return temp;
		}

		bool operator!=(const Self& list)
		{
			return _pNode != list._pNode;
		}
		bool operator==(const Self& list)
		{
			return _pNode == list._pNode;
		}

		PNode _pNode;
	};

	template<class T>
	class list
	{
		typedef ListNode<T> Node;
		typedef Node* PNode;
	public:
		//把迭代器和list关联起来，而且对迭代器重命名权限必须是公有的
		typedef ListIterator<T, T&, T*> iterator;
		typedef ListIterator<T, const T&, const T*> const_iterator;

	public:
		list()
		{
			CreateHeadNode();
		}
		list(size_t n, const T& data = T())
		{
			CreateHeadNode();
			for (size_t i = 0; i < n; ++i)
				push_back(data);
		}
		template<class iterator>
		list(iterator first, iterator last)
		{
			CreateHeadNode();
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}


		list(const list& l)
		{
			CreateHeadNode();
			//list<T> tmp(l.cbegin(), l.cend);
			//this->swap(tmp);
		}
		list& operator=(const list& l)
		{
			if (*this != l)
			{
				list<T> tmp(l);
				swap(tmp);
			}
			return *this;
		}
		void swap(list<T>& l)
		{
			swap(_pHead, l._pHead);
		}

		~list()
		{
			clear();
			delete _pHead;
			_pHead = nullptr;
		}

		size_t size() const
		{
			size_t count = 0;
			PNode _pCur = _pHead->_pNext;
			while (_pCur != _pHead)
			{
				++count;
				_pCur = _pCur->_pNext;
			}
			return count;
		}

		void resize(size_t newSize, const T& data = T())
		{
			size_t oldSize = size();
			if (oldSize < newSize)
			{
				for (size_t i = oldSize; i < newSize; ++i)
					push_back(data);
			}
			else if (oldSize>newSize)
			{
				for (size_t i = newSize; i < oldSize; ++i)
					pop_back();
			}
		}

		bool empty() const
		{
			if (_pHead->_pNext = _pHead)
				return true;
			else
				return flase;
		}

		void clear()
		{
			PNode _pCur = _pHead->_pNext;
			while (_pCur != _pHead)
			{
				_pHead->_pNext = _pCur->_pNext;
				delete _pCur;
				_pCur = _pHead->_pNext;
			}
			_pHead->_pPre = _pHead;
		}
		////////////////
		void push_back(const T& data)
		{
			PNode NewNode = new Node(data);
			NewNode->_pNext = _pHead;
			NewNode->_pPre = _pHead->_pPre;

			_pHead->_pPre->_pNext = NewNode;
			_pHead->_pPre = NewNode;
		}
		void pop_back()
		{
			PNode pCur = _pHead->_pPre;
			if (pCur != _pHead)
			{
				_pHead->_pPre = pCur->_pPre;
				pCur->_pPre->_pNext = _pHead;
				delete pCur;
				pCur = nullptr;
			}
		}
		void push_front(const T& data)
		{
			PNode NewNode = new Node(data);

			NewNode->_pNext = _pHead->_pNext;
			NewNode->_pPre = _pHead;

			_pHead->_pNext = NewNode;
			NewNode->_pNext->_pPre = NewNode;
		}
		void pop_front()
		{
			PNode pCur = _pHead->_pNext;
			if (pCur != _pHead)
			{
				_pHead->_pNext = pCur->_pNext;
				pCur->_pNext->_pPre = _pHead;
				delete pCur;
				pCur = nullptr;
			}
		}
		iterator insert(iterator pos, const T& data)
		{
			PNode NewNode = new Node(data);
			//前插
			NewNode->_pNext = pos._pNode;
			NewNode->_pPre = pos._pNode->_pPre;

			NewNode->_pNext->_pPre = NewNode;
			NewNode->_pPre->_pNext = NewNode;

			return iterator(NewNode);

		}
		iterator erase(iterator pos)
		{
			PNode pNext = pos._pNode->_pNext;
			pNext->_pPre = pos._pNode->_pPre;
			pNext->_pPre->_pNext = pNext;
			delete pos._pNode;
			return iterator(pNext);
		}
		iterator begin()
		{
			return iterator(_pHead->_pNext);//调用构造函数创建对象
		}
		iterator end()
		{
			return iterator(_pHead);
		}

		const_iterator cbegin()const
		{
			return const_iterator(_pHead->_pNext);//调用构造函数创建对象
		}
		const_iterator cend()const
		{
			return const_iterator(_pHead);
		}


		///////////
		T& front()
		{
			return _pHead->_pNext->_data;
		}
		const T& front()const
		{
			return _pHead->_pNext->_data;
		}
		T& back()
		{
			return _pHead->_pPre->_data;
		}
		const T& back()const
		{
			return _pHead->_pPre->_data;
		}


	private:
		void CreateHeadNode()
		{
			_pHead = new Node;
			_pHead->_pPre = _pHead;
			_pHead->_pNext = _pHead;
		}
	private:
		PNode _pHead;
	};
}

///////////////////////////////////////////////
//测试

template<class T>
void PrintList(N::list<T>& l)
{
	for (auto it = l.begin(); it != l.end(); ++it)
		cout << *it << ' ';
	cout << endl;

	for (auto& e : l)
		cout << e << ' ';
	cout << endl;

	for (N::list<int>::iterator it = l.begin(); it != l.end(); ++it)
		cout << *it << ' ';
	cout << endl;
}

void TestList1()
{
	N::list<int> l1;
	N::list<int> l2(10, 2);
	PrintList(l2);
	int arr[] = { 1, 2, 3, 4, 5, 6 };
	N::list<int> l4(arr, arr + sizeof(arr) / sizeof(arr[0]));
	PrintList(l4);
	//std::vector<int> v(10, 1);
	//N::list<int> l5(v.begin(), v.end());
	l2.clear();
	PrintList(l2);
}

void TestList2()
{
	int arr[] = { 1, 2, 3, 4, 5, 6 };
	N::list<int> l1(arr, arr + sizeof(arr) / sizeof(arr[0]));
	PrintList(l1);
	l1.push_back(7);
	l1.push_front(0);
	PrintList(l1);
	l1.pop_back();
	PrintList(l1);
	l1.pop_front();
	PrintList(l1);

	l1.resize(10);
	PrintList(l1);
	l1.resize(3);
	PrintList(l1);
	cout << l1.back() << endl;
	cout << l1.front() << endl;
	l1.clear();
	PrintList(l1);
}

class Date{
public:
	Date(int year = 1990, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{}


	int _year;
	int _month;
	int _day;
};

void TestList3()
{
	N::list<Date> l1;
	l1.push_back(Date(1990, 1, 1));
	l1.push_back(Date(1990, 1, 2));
	l1.push_back(Date(1990, 1, 3));
	for (auto it = l1.begin(); it != l1.end(); ++it)
	{
		////////////注it->->year(编译器优化)
		cout << it->_year << ' ' << (*it)._month << ' ' << it->_day << endl;
	}
}


namespace N
{
	template<class iterator,class T>
	iterator find(iterator first, iterator last, const T& data)
	{
		auto it = first;
		while (it != last)
		{
			if (*it == data)
				return it;
			++it;
		}
		return last;
	}
}
void TestList4()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
	N::list<int> l1(arr, arr + sizeof(arr) / sizeof(arr[0]));
	PrintList(l1);
	auto pos = N::find(l1.begin(), l1.end(), 1);
	if (pos != l1.end())
	{
		l1.insert(pos, 8);
	}
	PrintList(l1);
	pos = N::find(l1.begin(), l1.end(), 8);
	if (pos != l1.end())
	{
		l1.erase(pos);
	}
	PrintList(l1);
}
void TestList5()
{
	N::list<int> l1(10, 1);
	N::list<int> l2(l1);
	PrintList(l1);
	PrintList(l2);
}
int main()
{
	TestList5();
	return 0;
}
