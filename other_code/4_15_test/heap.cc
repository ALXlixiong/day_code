#include <iostream>
#include <vector>

template<class T>
struct Heap
{
    T* _arr;
    size_t _size;
    size_t _capacity;

    Heap(std::vector<T> &array)
      :_size(array.size())
       ,_capacity(array.size()+3)
  {
    _arr = new T[array.size()];
    for(size_t i = 0;i<_size;++i)
      _arr[i] = array[i];
  }
    Heap<T>& operator=(const Heap<T>& hp)
    {
      if(this != &hp)
      {
        delete[] _arr;
        _arr = new T[hp._size];
        for(size_t i = 0;i<hp._size;++i)
          _arr[i] = hp._arr[i];
        _size = hp._size;
        _capacity = hp._capacity;
      }
      return *this;
    }
    Heap(const Heap<T> &hp)
    {
      _size = hp._size;
      _capacity = hp._capacity;
      delete[] _arr;
      _arr = new T[_size];
      for(size_t i = 0;i<_size;++i)
        _arr[i] = hp._arr[i];
    }
    void swap(int &left,int &right)
    {
      int tmp = left;
      left = right;
      right = tmp;
    }

    void AdjustDown(int parent)
    {
      int left = (parent<<1)+1;
      int right = (parent<<1)+2;
      if(left>=(int)_size)
        return;

      int min_child = left;
      if(right<(int)_size && _arr[left]>_arr[right])
        min_child = right;

      if(_arr[parent]>_arr[min_child])
        swap(_arr[parent],_arr[min_child]);
      else 
        return;

      AdjustDown(min_child);
    }

    void AdjustDownNor(int parent)
    {
      int left = (parent<<1)+1;
      while(left<_size)
      {
        int min_child = left;
        int right = left+1;
        if(right<_size && _arr[right]<_arr[left])
          min_child = right;

        if(_arr[parent]>_arr[min_child])
        {
          swap(_arr[parent],_arr[min_child]);
          parent = min_child;
          left = (parent<<1)+1;
        }
        else 
          return;
      }
    }
    void BigHeapAdjustDown(int parent)
    {
      int left = (parent<<1)+1;
      while(1)
      {
        int right = left+1;
        int max_child = left;
        if(right<_size && _arr[right]>_arr[left])
          max_child = right;

        if(_arr[parent]<_arr[max_child])
        {
          swap(_arr[parent],_arr[max_child]);
          parent = max_child;
          left = (parent<<1)+1;
        }
        else 
          return;
      }
    }
    void BigAdjustUp(int child)
    {
      int parent = (child-1)/2;
      while(child != 0)
      {
        if(_arr[parent]<_arr[child])
        {
          swap(_arr[parent],_arr[child]);
          child = parent;
          parent = (child-1)/2;
        }
        else 
          return;
      }
    }
    void Insert(T data)
    {
      T* tmp = new T[_size+1];
      for(size_t i = 0;i<_size;++i)
        tmp[i] = _arr[i];
      delete[] _arr;
      _arr = tmp;
      ++_size;
      _arr[_size] = data;
      HeapPrint();
      BigAdjustUp(_size);
    }
    void HeapPrint()
    {
      for(size_t i = 0;i<_size;++i)
        std::cout<<_arr[i]<<" ";
      std::cout<<std::endl;
    }
    void Delete()
    {
      swap(_arr[0],_arr[_size-1]);
      --_size;
    }
    ~Heap()
    {
      delete[] _arr;
      _arr = nullptr;
    }
};


void HeapTest2()
{
  std::vector<int> v{4,3,2,5,8,1,0,9,24,12};
  Heap<int> hp1(v);
  hp1.HeapPrint();
  //std::cout<<"hp1:";
  //for(size_t i = 0;i<hp1._size;++i)
  //  std::cout<<hp1._arr[i]<<" ";
  //std::cout<<std::endl;
  //for(int i = (hp1._size-2)/2;i>=0;--i)
  //  hp1.AdjustDownNor(i);
  //hp1.HeapPrint();
  for(int i = (hp1._size-2)/2;i>=0;--i)
    hp1.BigHeapAdjustDown(i);
  hp1.HeapPrint();
  //hp1.Insert(88);
  //hp1.HeapPrint();
  //std::cout<<hp1._arr[hp1._size]<<std::endl;
}
void HeapTest1()
{
  std::vector<int> v{3,2,5,8,1,0,9,24,12};
  Heap<int> hp1(v);
  std::cout<<"hp1:";
  for(size_t i = 0;i<hp1._size;++i)
    std::cout<<hp1._arr[i]<<" ";
  std::cout<<std::endl;
  Heap<int> hp2(hp1);
  std::cout<<"hp2:";
  for(size_t i = 0;i<hp2._size;++i)
    std::cout<<hp2._arr[i]<<" ";
  std::cout<<std::endl;
  Heap<int> hp3 = hp2;
  std::cout<<"hp3:";
  for(size_t i = 0;i<hp3._size;++i)
    std::cout<<hp3._arr[i]<<" ";
  std::cout<<std::endl;
  std::vector<int> v1{1,2,3};
  Heap<int> hp4(v1);
  hp4 = hp3;
  for(size_t i = 0;i<hp4._size;++i)
    std::cout<<hp4._arr[i]<<" ";
  std::cout<<std::endl;
}

int main()
{
  HeapTest2();
  return 0;
}
