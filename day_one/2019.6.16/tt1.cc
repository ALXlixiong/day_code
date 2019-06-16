#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

void Func(vector<string> &v,unordered_map<char,char> &dic)
{
    vector<string> res;
    for(int i = 0;i<v.size();++i)
    {
        int index = 3;
        string tmp = "";
        for(int j = 0;j<v[i].size();++j)
        {
            if(index > 0 && v[i][j] != '-')
            {
                if(v[i][j] >= '0' && v[i][j]<='9')
                    tmp += v[i][j];
                else
                    tmp += dic[v[i][j]];
                --index;
            }
            else if(v[i][j] != '-')
            {
                if(v[i][j] >= '0' && v[i][j]<='9')
                    tmp += v[i][j];
                else
                    tmp += dic[v[i][j]];
            }

            if(index == 0)
            {
                index = -1;
                tmp += '-';
            }
        }
        res.push_back(tmp);
    }
    set<string> s(res.begin(),res.end());
    for(auto &e:s)
        cout<<e<<endl;
}

int main()
{
		unordered_map<char, char> dic;
		dic.emplace('A', '2');
		dic.emplace('B', '2');
		dic.emplace('C', '2');
		dic.emplace('D', '3');
		dic.emplace('E', '3');
		dic.emplace('F', '3');
		dic.emplace('G', '4');
		dic.emplace('H', '4');
		dic.emplace('I', '4');
		dic.emplace('J', '5');
		dic.emplace('K', '5');
		dic.emplace('L', '5');
		dic.emplace('M', '6');
		dic.emplace('N', '6');
		dic.emplace('O', '6');
		dic.emplace('P', '7');
		dic.emplace('Q', '7');
		dic.emplace('R', '7');
		dic.emplace('S', '7');
		dic.emplace('T', '8');
		dic.emplace('U', '8');
		dic.emplace('V', '8');
		dic.emplace('W', '9');
		dic.emplace('X', '9');
		dic.emplace('Y', '9');
		dic.emplace('Z', '9');    
    int line = 0;
    while(cin>>line)
    {
        vector<string> v(line,"");
        for(int i = 0;i<line;++i)
            cin>>v[i];
        Func(v,dic);
    }
		return 0;
}
