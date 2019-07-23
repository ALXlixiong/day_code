#include <iostream>
#include <vector>
#include <cstdio>
void GetResult(std::vector<std::vector<char> > &v,int x,int y,int &count)
{

    if(x<0 || x>=v.size() || y<0 || y>=v[0].size() ||v[x][y] == '#'|| v[x][y] == '1')
        return;
    ++count;
    v[x][y] = '1';

    GetResult(v,x+1,y,count);
    GetResult(v,x,y+1,count);
    GetResult(v,x-1,y,count);
    GetResult(v,x,y-1,count);
}
int main()
{
    int row = 0;
    int col = 0;
    while(std::cin>>row>>col)
    {
        std::vector<std::vector<char> > v(row,std::vector<char>(col,'.'));
        int x = 0;
        int y = 0;
        for(int i = 0;i<row;++i)
        {
            for(int j = 0;j<col;++j)
            {
                std::cin>>v[i][j];
                if(v[i][j] == '@')
                {
                    x = i;
                    y = j;
                }
            }
        }
        int count = 0;
        GetResult(v,x,y,count);
        std::cout<<count<<std::endl;
    }
    return 0;
}
