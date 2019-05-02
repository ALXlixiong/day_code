#include<iostream>
#include<string>
#include<string.h>
#include<assert.h>
using namespace std;
namespace bit{
	template<class T>
	class vector{
		typedef T* iterator;
		typedef T* reverse_iterator;
		typedef T& reference;
		typedef T& const_reference;
	public:
		//构造函数
		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{}
		//创建初始值为n个val
		vector(size_t n, const T& val = T())
			:_start(new T[n])
			, _finish(_start + n)
			, _endOfStorage(_finish)
		{
			for (size_t i = 0; i<n; ++i)
				_start[i] = val;
		}
		//[left,right)是一段连续的空间
		vector(T* left, T* right)
		{
			assert(left&&right);
			_start = new T[right - left];
			for (int i = 0; i<(right - left); ++i)
			{
				_start[i] = left[i];
			}
			_finish = _start + (right - left);
			_endOfStorage = _finish;
			//浅拷贝
			//memcpy(_start,left,sizeof(T)*(right-left));
		}
		//拷贝构造函数
		vector(const vector& v)
		{
			int size = v._finish - v._start;
			_start = new T[size];
			for (int i = 0; i<size; ++i)
				_start[i] = v._start[i];
			_finish = _start + size;
			_endOfStorage = _finish;
		}
		//赋值用算符重载
		vector<T>& operator=(const vector<T>& v)
		{
			int size = v._finish - v._start;
			iterator tmp = new T[size];
			for (int i = 0; i < size; ++i)
				tmp[i] = v._start[i];
			delete[] _start;
			_start = tmp;
			_finish = tmp + size;
			_endOfStorage = _finish;
			return *this;
		}

		~vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _endOfStorage =  nullptr;
			}
		}
		//迭代器
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		reverse_iterator rbegin()
		{
			return _finish;
		}
		reverse_iterator rend()
		{
			return _start;
		}

		size_t size()
		{
			return _finish - _start;
		}
		size_t capacity()
		{
			return _endOfStorage - _start;
		}
		bool empty()
		{
			return _start == nullptr;
		}
		void resize(size_t newSize, const T& val = T())
		{
			size_t oldSize = size();
			if (newSize <= oldSize)
				_start = _start + newSize;
			else
			{
				if (newSize <= capacity())
				{
					for (size_t i = oldSize; i < newSize; ++i)
						_start[i] = val;
				}
				else
				{
					T* tmp = new T[newSize];
					for (size_t i = 0; i < oldSize; ++i)
						tmp[i] = _start[i];
					for (size_t i = oldSize; i < newSize; ++i)
						tmp[i] = val;
					delete[] _start;
					_start = tmp;
					_finish = tmp + newSize;
					_endOfStorage = _finish;
				}
			}
		}
		void reserve(size_t newCapacity)
		{
			if (newCapacity > capacity())
			{
				T* tmp = new T[newCapacity];
				for (size_t i = 0; i < size(); ++i)
					tmp[i] = _start[i];
				for (size_t i = size(); i < newCapacity; ++i)
					tmp[i] = 0;
				delete[] _start;
				_start = tmp;
				_finish = tmp + newCapacity;
				_endOfStorage = _finish;
			}
		}

		//元素访问
		T& operator[](size_t index)
		{
			assert(index < size());
			return _start[index];
		}
		//因为可能是const对象，而且const对象不可以调用非const函数，所以需要给出const函数
		//[]访问越界调用assert函数，但是at函数访问越界，直接抛异常
		const T& operator[](size_t index)const 
		{
			assert(index < size());
			return _start[index];
		}
		T& at(size_t index)
		{
			return _start[index];
		}
		const T& at(size_t index)const
		{
			return _start[index];
		}

		reference front()
		{
			return *_start;
		}
		const_reference front()const
		{
			return *_start;
		}
		reference back()
		{
			return *(_finish - 1);
		}
		const_reference back()const
		{
			return *(_finish - 1);
		}
		void push_back(const T& val)
		{
			if (size() == capacity())
				reserve(capacity() * 2);
			*_finish++ = val;
		}
		void clear()
		{
			//情况容量不变
			_start = _finish;
		}
		void swap(vector<T> v)
		{
			swap(_start, v._start);
			swap(_finish, v._finish);
			swap(_endOfStorage, v._endOfStorage);
		}
		////将val插入到pos的位置并且返回该位置
		//iterator insert(iterator position, const T& val)
		//{
		//	if (size() == capacity())
		//		reserve(capacity() * 2);
		//	//重新分配空间之后已经找不到postion
		//	//迭代器失效
		//	for (iterator cur = _finish; cur > position; --cur)
		//		cur = cur - 1;
		//	*position = val;
		//	_finish += 1;
		//	return position;
		//}
		////删除pos位置元素，然后返回pos下一个元素搬移之后的位置
		//iterator erase(iterator pos)
		//{
		//	if (pos == _finish - 1)
		//	{
		//		_finish -= 1;
		//		return _finish;
		//	}
		//	for (iterator cur = pos; cur < _finish; ++cur)
		//		*cur = *(cur + 1);
		//	_finish -= 1;
		//	return pos;
		//}
	private:
		iterator _start;      //指向数据块的开始
		iterator _finish;     //指向有效数据块的结束
		iterator _endOfStorage;   //指向存储容量的结尾
	};
}

