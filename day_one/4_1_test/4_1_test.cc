#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution {
public:
    static bool IsPopOrder(vector<int> pushV,vector<int> popV) 
    {
        if(pushV.size() != popV.size())
            return false;
        if(pushV.empty())
            return false;
        stack<int> s;
        int begin_1 = 0;
        int begin_2 = 0;
        while(begin_1<pushV.size())
        {
            if(pushV[begin_1] != popV[begin_2])
            {
                if(!s.empty() || popV[begin_2] == s.top())
                {
                    s.pop();
                    ++begin_2;
                }
                else 
                {
                  s.push(pushV[begin_1++]);
                }
            }
            else 
            {
                ++begin_1;++begin_2;
            }
        }
        int len = popV.size();
        for(int i = begin_2;i< (int)len;++i)
        {
            if(popV[i] != s.top())
                return false;
            s.pop();
        }
        if(s.empty())
          return true;
        return false;
    }
};

int main()
{
  vector<int> pushV{1,2,3,4,5};
  vector<int> popV{1,2,3,4,5};
  if(Solution::IsPopOrder(pushV,popV))
  {
    cout<<"ok"<<endl;
  }
  return 0;
}
