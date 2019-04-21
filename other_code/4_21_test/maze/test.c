#include "maze.h"
void MazeTest()
{
	int a[N][N] = {
		{ 0, 0, 0, 0, 0, 0 },
		{ 0, 1, 1, 1, 0, 0 },
		{ 0, 1, 0, 1, 1, 1 },
		{ 0, 1, 0, 1, 0, 0 },
		{ 0, 1, 1, 1, 1, 0 },
		{ 0, 1, 0, 0, 0, 0 }
	};

	Maze m;
	MazeInit(&m, a);
	MazePrint(&m);
	Stack path;
	StackInit(&path,2);
	Stack shortpath;
	StackInit(&shortpath, 10);

	//MazeGetPath(&m);
	MazeGetShortPath(&m,m.enter,&path,&shortpath);
	MazePrint(&m);
	printf("最短路：%d 出口坐标：%d %d\n", StackSize(&shortpath), StackTop(&shortpath)._row, StackTop(&shortpath)._col);
}


int main()
{
	MazeTest();
	system("pause");
	return 0;
}