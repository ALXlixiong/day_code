#include <iostream>
#include <stack>
#include <string>
#include <stdlib.h>
#include <vector>
using namespace std;

void Func(int count,vector<string> v)
{
    stack<string> s;
    for(int i = 0;i<count;++i)
    {
        string op = v[i];
        if(op == "+")
        {
            string f1 = s.top();
            s.pop();
            string f2 = s.top();
            s.pop();

            string tmp = to_string(atoi(f1.c_str()) + atoi(f2.c_str()));
            s.push(tmp);
        }
        else if(op == "-")
        {
            string f1 = s.top();
            s.pop();
            string f2 = s.top();
            s.pop();

            string tmp = to_string(atoi(f2.c_str()) - atoi(f1.c_str()));
            s.push(tmp);
        }
        else if(op == "*")
        {
            string f1 = s.top();
            s.pop();
            string f2 = s.top();
            s.pop();

            string tmp = to_string(atoi(f1.c_str()) * atoi(f2.c_str()));
            s.push(tmp);
        }
        else if(op == "/")
        {
            string f1 = s.top();
            s.pop();
            string f2 = s.top();
            s.pop();

            string tmp = to_string(atoi(f2.c_str()) / atoi(f1.c_str()));
            s.push(tmp);
        }
        else
            s.push(op);
    }
    cout<<s.top()<<endl;
}

int main()
{
    int count = 0;
    while(cin>>count)
    {
        vector<string> tmp;
        string ch = "";
        for(int i = 0;i<count;++i)
        {
            cin>>ch;
            tmp.push_back(ch);
        }
        Func(count,tmp);
    }
    return 0;
}
