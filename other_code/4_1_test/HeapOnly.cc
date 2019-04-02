#include<iostream>
using namespace std;

class HeapOnly
{
  //构造函数给为私有的
  HeapOnly(){}
  //防止拷贝
  //HeapOnly(const HeapOnly& ht){}
  //不需要防止赋值运算符重载，因为构造函数已经给为私有的
  //C++11
  HeapOnly(const HeapOnly& ht) = delete;
  public:
    static HeapOnly* GetHeapOnly()
    {
      return new HeapOnly;
    }
};

class StackOnly{
  void* operator new(size_t size);//因为new底层调用operator new全局函数，所以给为私有的即可
  void operator delete(void *p);
  public:
    
};

void TestHeapOnly()
{
  StackOnly sp;
  HeapOnly* hp = HeapOnly::GetHeapOnly();
}
