#include <iostream>
using namespace std;
#include <string>
#include <algorithm>

class Solution
{
    private:
        string _str;
    public:
        Solution(string str):_str(str)
    {}
        void GetFunc()
        {
            reverse(_str.begin(),_str.end());
            cout<<_str<<endl;
        }
};

int main()
{
    string str;
    while(getline(cin,str))
    {
        Solution s(str);
        s.GetFunc();
    }
}
