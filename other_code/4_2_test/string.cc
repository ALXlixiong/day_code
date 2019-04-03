#include<iostream>
using namespace std;
#include<assert.h>
#include<cstring>
class String
{
  public:
    String(const char* str = "")
    {
      if(str == nullptr)
      {
        assert(str);
        return;
      }
      _str = new char[strlen(str) + 1];
      strcpy(_str,str);
    }
    String(const String& s)
    {
      _str = new char[strlen(s._str) + 1];
      strcpy(_str,s._str);
    }
    String& operator=(const String& s)
    {
      if(this != &s)
      {
        char *tmp = new char[strlen(s._str)+1];
        strcpy(tmp,s._str);
        delete[] _str;
        _str = tmp;
      }
      return *this;
    }
  private:
    char *_str;
};
