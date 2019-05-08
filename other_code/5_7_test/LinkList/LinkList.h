#pragma once 
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<assert.h>


typedef int DataType;

typedef struct LinkList
{
  struct LinkList *next;
  DataType data;
}LinkList;

void LinkListPushBack(LinkList **ppHead,DataType data);
void LinkListPushFront(LinkList **ppHead,DataType data);
void LinkListPopBack(LinkList **ppHead);
void LinkListPopFront(LinkList **ppHead);
LinkList *LinkListFind(LinkList *pHead,DataType data);
void LinkListInsert(LinkList **ppHead,DataType data,LinkList *pos);
void LinkListEnrase(LinkList **ppHead,DataType data);
void LinkListPrint(LinkList *pHead);
void LinkListDestory(LinkList **ppHead);
void LinkListTest();
void LinkListPopSameElement(LinkList **ppHead,DataType data);
