#pragma once

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<assert.h>


//struct Pos;

//typedef struct Pos DataType;

#define N 6

//��ڵ�
typedef struct Pos
{
	int _row;//��
	int _col;//��
}Pos;

//�Թ�
typedef struct Maze
{
	int arr[N][N];
	Pos enter;//���
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
//�Թ�
void MazePrint(Maze *m);
void MazeInit(Maze *m, int a[][N]);
void MazeGetShortPath(Maze *m, Pos cur, Stack *path, Stack *shortpath);
void StackCopy(Stack *s1, Stack *s2);

