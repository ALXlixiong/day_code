#include<iostream>
using namespace std;
#include<vector>
int row = 0;
int col = 0;
vector<vector<int>> maze;
vector<vector<int>> temp_path;
vector<vector<int>> best_path;

void GetBestPath(int i,int j)
{
    maze[i][j] = 1;
    temp_path.push_back({i,j});
    if(i == row-1 && j == col-1)
    {
        if(best_path.empty() || best_path.size()>temp_path.size())
            best_path = temp_path;
    }
    //上
    if(i-1>=0 && maze[i-1][j] == 0)
    {
        GetBestPath(i-1,j);
    }
    
    //下
    if(i+1<=row-1 && maze[i+1][j] == 0)
    {
        GetBestPath(i+1,j);
    }
    
    //左
    if(j-1>=0 && maze[i][j-1] == 0)
    {
        GetBestPath(i,j-1);
    }
    
    //右
    if(j+1<=col-1 && maze[i][j+1] == 0)
    {
        GetBestPath(i,j+1);
    }
    maze[i][j] = 0;
    temp_path.pop_back();
}
int main()
{
    while(cin>>row>>col)
    {
        maze.resize(row);
        for(size_t i = 0;i<maze.size();++i)
            maze[i].resize(col);
        for(size_t i = 0;i<maze.size();++i)
        {
            for(size_t j = 0;j<maze[0].size();++j)
            {
                cin>>maze[i][j];
            }
        }
        best_path.clear();
        temp_path.clear();
        GetBestPath(0,0);
        for(auto& e:best_path)
            cout<<"("<<e[0]<<","<<e[1]<<")"<<endl;
    }
    return 0;
}
