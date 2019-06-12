#include <iostream>
using namespace std;
#include <vector>
#include <string>
class Solution
{
    private:
        string _str1;
        string _str2;
    public:
        Solution(string str1,string str2):_str1(str1),_str2(str2)
    {}
        void GetMaxLengthChildString()
        {
            int MaxLen = 0;
            int Pos = 0;
            vector<vector<int> > dp(_str1.size(),vector<int>(_str2.size(),0));
            for(int i = 0;i<_str1.size();++i){
                for(int j = 0;j<_str2.size();++j){
                    if(_str1[i] == _str2[j])
                    {
                        if(i == 0 || j == 0){
                            dp[i][j] = 1;
                        }
                        else{
                            dp[i][j] = dp[i-1][j-1]+1;
                        }
                    }
                    if(dp[i][j]>MaxLen){
                        MaxLen = dp[i][j];
                        Pos = i;
                    }
                }
            }
            cout<<_str1.substr(Pos-MaxLen+1,MaxLen)<<endl;
        }
};

int main()
{
    string str1 = "";
    string str2 = "";
    while(cin>>str1>>str2)
    {
        Solution s(str1,str2);
        s.GetMaxLengthChildString();
    }
}
