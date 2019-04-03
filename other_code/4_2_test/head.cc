#include<iostream>
using namespace std;
#include<queue>
#include<vector>
#include<functional>
class Greater
{
  public:
    bool operator()(const int& left,const int& right)
    {
      return left>right;
    }
};
int main()
{
  vector<int> v{3,2,5,6,1,0,8};
  priority_queue<int,vector<int>,Greater> q(v.begin(),v.end());
  cout<<q.top()<<endl;
  return 0;
}
