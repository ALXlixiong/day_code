#include<queue>
#include<vector>
#include<iostream>
using namespace std;
struct cmp
{
  bool operator()(int &left,int &right)
  {
    return left>right;

  }

};

class Solution {
  public:

    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
      priority_queue<int,vector<int>,cmp()> q(input.begin(),input.end());
      vector<int> ret;
      while(k--)
      {
        ret.push_back(q.top());
        q.pop();

      }
      return ret;
    }

};
