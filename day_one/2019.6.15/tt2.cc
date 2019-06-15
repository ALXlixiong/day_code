#include <iostream>
using namespace std;
#include <vector>
#include <stack>
class Pos
{
    public:
        int _row;
        int _col;
        Pos(int row,int col):_row(row),_col(col)
    {}
};
int main()
{
    int col = 0;
    int row = 0;
    cin>>row>>col;
    vevtor<vector<int> > maze(row,vector<int>(col));
    for(int i = 0;i<row;++i)
    {
        for(int j = 0;j<col;++j)
            cin>>maze[i][j];
    }
    stack<Pos> s;
    s.push(Pos(0,0));
    while(!s.empty())
    {
        
    }
    return 0;
}
