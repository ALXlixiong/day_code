#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <assert.h>
using namespace std;
#include <string.h>



#if 0
namespace bit
{
	class string
	{
	public:
		string(const char *str = "")
		{
			if (str == nullptr)
			{
				assert(str);
				return;
			}
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
		}
		string(const string& s)
		{
			_str = new char[strlen(s._str) + 1];
			strcpy(_str, s._str);
		}

		string& operator=(const string& s)
		{
			if (this != &s)
			{
				char *tmp = new char[strlen(s._str) + 1];
				strcpy(tmp, s._str);
				delete[] _str;
				_str = tmp;
			}
			return *this;
		}

		~string()
		{
			if (_str != nullptr)
			{
				delete[] _str;
				_str = nullptr;
			}
		}
	private:
		char *_str;
	};
}
using namespace bit;
#endif

class String
{
public:
	String(const char* str = "")
		:_Pcount(new int(1))
	{
		if (nullptr == str)
			str = "";
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	String(const String& s)
	{
		_str = s._str;
		_Pcount = s._Pcount;
		++(*_Pcount);
	}

	String& operator=(const String& s)
	{
		if (*_Pcount == 1)
		{
			delete[] _str;
			_str = s._str;
			delete _Pcount;
			_Pcount = s._Pcount;
			++(*_Pcount);
		}
		else
		{
			--(*_Pcount);
			_str = s._str;
			_Pcount = s._Pcount;
			++(*_Pcount);
		}
		return *this;
	}

	char& operator[](size_t index)
	{
		if ((*_Pcount) > 1)
		{
			String tmp(_str);
			swap(tmp, *this);
		}
		return _str[index];
	}

	~String()
	{
		if (--(*_Pcount) == 0 && _str)
		{
			delete[] _str;
			_str = nullptr;
			delete _Pcount;
			_Pcount = nullptr;
		}
	}
private:
	char *_str;
	int *_Pcount;
};
int main()
{
	string s1("hello world");
	string s2(s1);
	return 0;
}
