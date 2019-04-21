#pragma once

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<assert.h>


//struct Pos;

//typedef struct Pos DataType;

#define N 6

//入口点
typedef struct Pos
{
	int _row;//行
	int _col;//列
}Pos;

//迷宫
typedef struct Maze
{
	int arr[N][N];
	Pos enter;//入口
}Maze;

typedef struct Pos DataType;

typedef struct Stack{
	DataType *array;
	int top;
	int capacity;
}Stack;

void StackInit(Stack *s, int capacity);
void StacjCheckMem(Stack *s);
void StackPush(Stack *s, DataType data);
void StackPop(Stack *s);
DataType StackTop(Stack *s);
int StackSize(Stack *s);
int StackEmpty(Stack *s);
//迷宫
void MazePrint(Maze *m);
void MazeInit(Maze *m, int a[][N]);
void MazeGetShortPath(Maze *m, Pos cur, Stack *path, Stack *shortpath);
void StackCopy(Stack *s1, Stack *s2);

