#include <iostream>
#include <vector>

template<class T>
class Heap
{
  private:
    std::vector<T> _arr;
  public:
    Heap(std::vector<T> arr)
    {
      _arr.resize(arr.size());
      for(int i = 0;i<_arr.size();++i)
        _arr[i] = arr[i];
    }
    Heap(const Heap<T> &hp)
    {
      _arr.resize(hp._arr.size());
      for(int i = 0;i<_arr.size();++i)
        _arr[i] = hp._arr[i];
    }
    Heap& operator=(const Heap& hp)
    {
      if(this != &hp)
      {
        _arr.resize(hp._arr.size());
        for(int i = 0;i<_arr.size();++i)
          _arr[i] = hp._arr[i];
      }
      return *this;
    }
    void swap(int &left,int &right)
    {
      int tmp = left;
      left = right;
      right = tmp;
    }
    void AdjustDown(size_t parent)
    {
      int left = (parent<<1) +1;
      int right = (parent<<1)+2;
      if(left>=_arr.size())
        return;
      int maxChild = left;
      if(right<_arr.size() && _arr[right]>_arr[left])
        maxChild = right;
      if(_arr[parent]<_arr[maxChild])
        swap(_arr[parent],_arr[maxChild]);
      else 
        return;
      parent = maxChild;
      AdjustDown(parent);
    }
    void AdjustDownNor(int parent)
    {
      int left = (parent<<1) +1;
      while(left<_arr.size())
      {
        int right = (parent<<1)+2;
        int maxChild = left;
        if(right<_arr.size() && _arr[left]<_arr[right])
          maxChild = right;

        if(_arr[parent]<_arr[maxChild])
          swap(_arr[parent],_arr[maxChild]);
        else 
          break;
        parent = maxChild;
        left = (parent<<1)+1;
      }
    }
    void CreateHeap()
    {
      for(int i = (_arr.size()-2)/2;i>=0;--i)
        AdjustDownNor(i);
        //AdjustDown(i);
    }
    void AdjustUp(int child)
    {
      while(child>0)
      {
        int parent = (child-1)/2;
        if(_arr[parent]<_arr[child])
          swap(_arr[parent],_arr[child]);
        else 
          break;
        child = parent;
      }
    }
    void InsertHeap(T val)
    {
      _arr.resize(_arr.size()+1);
      _arr[_arr.size()-1] = val;
      AdjustUp(_arr.size()-1); 
    }

    void DeleteHeap()
    {
      swap(_arr[0],_arr[_arr.size()-1]);
      _arr.resize(_arr.size()-1);
      AdjustDownNor(0);
    }
    void PrintHeap()
    {
      for(int i = 0;i<_arr.size();++i)
        std::cout<<_arr[i]<<" ";
      std::cout<<std::endl;
    }
    void AdjustDown_sort(int parent,int size)
    {
      int left = (parent<<1) + 1;
      if(left>size)
        return;
      int maxChild = left;
      int right = left+1;
      if(right<=size && _arr[right]>_arr[left])
        maxChild = right;

      if(_arr[parent]<_arr[maxChild])
        swap(_arr[parent],_arr[maxChild]);

      parent = maxChild;
      AdjustDown_sort(parent,size);
    }
    void HeapSort()
    {
      CreateHeap();
      PrintHeap();
      for(int i = (_arr.size()-1);i>0;)
      {
        swap(_arr[0],_arr[i]);
        --i;
        AdjustDown_sort(0,i);
      }
    }
    ~Heap()
    {
      _arr.resize(0);
    }
};
int main()
{
  std::vector<int> arr{33,12,54,23,70,5,88,57,45,89,23};
  Heap<int> hp1(arr);
  hp1.PrintHeap();
  //hp1.CreateHeap();
  //hp1.PrintHeap();
  //hp1.InsertHeap(100);
  //hp1.PrintHeap();
  //hp1.DeleteHeap();
  //hp1.PrintHeap();
  hp1.HeapSort();
  hp1.PrintHeap();
  //Heap<int> hp2 = hp1;
  //hp2 = hp1;
  //hp2.PrintHeap();
  //Heap<int> hp3(hp1);
  return 0;
}
