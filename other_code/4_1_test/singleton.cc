#include<iostream>
#include <mutex>
using namespace std;
//懒汉模式
class Singleton
{
  public:
    static Singleton* GetInstance()
    {
      if(nullptr == _only)//这个判断只要是为了提高效率
      {
        _mutex.lock();
        if(nullptr == _only)//这个怕断是为了保证线程安全
        {
          _only = new Singleton;
        }
        _mutex.unlock();
      }
      return _only;
    }

    class InCycle 
    {
      public:
        ~InCycle()
        {
          if(_only != nullptr)
            delete _only;
        }
    };
    static InCycle _cycle;
  private:
    Singleton(){}
    Singleton(const Singleton&);
    Singleton& operator=(const Singleton& );

    static Singleton* _only;
    static mutex _mutex;
};

Singleton* Singleton::_only = nullptr;
mutex Singleton::_mutex;
//饿汉模式
class singleton 
{
  public:
    static singleton& GetInstance()
    {
      return _only;
    }
  private:
    singleton(){}
    singleton& operator=(const singleton&);
    singleton(const singleton&);
    static singleton _only;
};
