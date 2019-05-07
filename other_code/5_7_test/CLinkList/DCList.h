#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<malloc.h>


typedef int DataType;

typedef struct CLinkList
{
  struct CLinkList *pFront;
  struct CLinkList *pNext;
  DataType data;
}CLinkList;


void CLinkListInit(CLinkList **ppHead);

void CLinkListPushBack(CLinkList *pHead,DataType data);

void CLinkListPushFront(CLinkList *pHead,DataType data);

void CLinkListPopBack(CLinkList *pHead);

void CLinkListPopFront(CLinkList *Head);

void CLinkListDestory(CLinkList **ppHead);
void CLinkListInsert(CLinkList *pHead,DataType data_1,DataType data_2);
void CLinkListEnrase(CLinkList *pHead,DataType data);
int CLinkListFind(CLinkList *pHead,DataType data);
void CLinkListPrint(CLinkList *pHead);
void Test();
