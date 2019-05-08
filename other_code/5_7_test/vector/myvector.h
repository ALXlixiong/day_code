#include<iostream>
#include<string>
#include<string.h>
#include<assert.h>
using namespace std;
namespace bit{
  template<class T>
    class vector{
      typedef T* iterator;
      public:
        vector()
          :_start(nullptr)
           ,_finish(nullptr)
           ,_endOfStorage(nullptr)
      {}

        vector(size_t n,const T& val = T())
          :_start(new T[n])
           ,_finish(_start + n)
           ,_endOfStorage(_finish)
      {
        for(int i = 0;i<n;++i)
          _start[i] = val;
      }
        //[left,right)是一段连续的空间
        vector(T* left,T* right)
        {
          assert(left&&right);
          _start = new T[right-left];
          for(int i = 0;i<(right-left);++i)
          {
            _start[i] = left[i];
          }
          _finish = _start+(right-left);
          _endOfStorage = _finish;
          //memcpy(_start,left,sizeof(T)*(right-left));
        }
        //拷贝构造函数
        vector(const vector& v)
        {
          int size = v._finish-v._start;
          _start = new T[size];
          for(int i = 0;i<size;++i)
            _start[i] = v._start[i];
          _finish = _start+size;
          _endOfStorage = _finish;
        }
      private:
        iterator _start;      //指向数据块的开始
        iterator _finish;     //指向有效数据块的结束
        iterator _endOfStorage;   //指向存储容量的结尾
    };
}
