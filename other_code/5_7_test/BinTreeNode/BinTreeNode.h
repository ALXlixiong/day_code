#include<stdio.h>
#include<assert.h>
#include<malloc.h>
#include<string.h>
typedef char DataType;

typedef struct BinTreeNode
{
  struct BinTreeNode *pLeft;
  struct BinTreeNode *pRight;
  DataType data;
}BinTreeNode;
