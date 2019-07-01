#include <iostream>
using namespace std;
#define PI 3.14
#define EXP 0.00000001
int main()
{
    double n = 0;
    double r = 0;
    while(cin>>n>>r)
    {
        double ret = 2 * PI*r;
        if((ret-n)>=EXP)
        {
            cout<<"Yes"<<endl;
            continue;
        }
        cout<<"No"<<endl;
    }
    return 0;
}
