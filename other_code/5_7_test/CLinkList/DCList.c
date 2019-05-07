#include "DCList.h"


void CLinkListInit(CLinkList **ppHead)
{
  assert(ppHead);
  *ppHead = (CLinkList *)malloc(sizeof(CLinkList));
  assert(*ppHead);
  (*ppHead)->pFront = *ppHead;
  (*ppHead)->pNext = *ppHead;
}

CLinkList *BuyNode(DataType data)
{
  CLinkList *NewNode = (CLinkList *)malloc(sizeof(data));
  assert(NewNode);

  NewNode->data = data;
  NewNode->pNext = NULL;
  NewNode->pFront = NULL;
  return NewNode;
}

void CLinkListPushBack(CLinkList *pHead,DataType data)
{
  assert(pHead);
   
  CLinkList *NewNode = BuyNode(data);
  
  NewNode->pFront = pHead->pFront;
  pHead->pFront->pNext = NewNode;
  pHead->pFront = NewNode;
  NewNode->pNext = pHead;
}

void CLinkListPushFront(CLinkList *pHead,DataType data)
{
  assert(pHead);
  CLinkList *NewNode = BuyNode(data);
  NewNode->pNext = pHead->pNext;
  pHead->pNext->pFront = NewNode;
  pHead->pNext = NewNode;
  NewNode->pFront = pHead;
}

void CLinkListPrint(CLinkList *pHead)
{
  if(pHead == NULL)
    return;
  if(pHead->pNext == pHead)
  {
    printf("没有元素\n");
    return;
  }
  CLinkList *cur = pHead->pNext;
  while(cur != pHead)
  {
    printf("%d ",cur->data);
    cur = cur->pNext;
  }
  printf("\n");
}


void CLinkListPopBack(CLinkList *pHead)
{
  assert(pHead);
  CLinkList *cur = pHead->pFront;
  pHead->pFront = pHead->pFront->pFront;
  cur->pFront->pNext = pHead;
  free(cur);
  cur = NULL;
}

void CLinkListPopFront(CLinkList *pHead)
{
  assert(pHead);
  CLinkList *cur = pHead->pNext;
  pHead->pNext = cur->pNext;
  cur->pNext->pFront = pHead;
  free(cur);
  cur = NULL;
}

int CLinkListFind(CLinkList *pHead,DataType data)
{
  assert(pHead);
  if(pHead->pNext == pHead)
    return -1;
  CLinkList *cur = pHead->pNext;

  while(cur != pHead)
  {
    if(cur->data == data)
      return 0;
    cur = cur->pNext;
  }
  return -1;
}

void CLinkListDestory(CLinkList **ppHead)
{
  assert(ppHead);
  if(*ppHead == NULL)
    return;
  CLinkList *cur = (*ppHead)->pNext;
  while(cur != *ppHead)
  {
    cur = cur->pNext;
    free(cur->pFront);
    cur->pFront = NULL;
  }
  free(cur->pFront);
  free(*ppHead);
  *ppHead = NULL;
}


void CLinkListInsert(CLinkList *pHead, DataType data_1,DataType data_2)
{
  assert(pHead);
  if(CLinkListFind(pHead,data_2) == -1)
    return;
  CLinkList *cur = pHead->pNext;

  while(cur != pHead)
  {
    if(cur->data == data_2)
    {
      CLinkList *NewNode = BuyNode(data_1);
      NewNode->pNext = cur->pNext;
      cur->pNext->pFront = NewNode;
      cur->pNext = NewNode;
      NewNode->pFront = cur;
      return;
    }
    cur = cur->pNext;
  }
}

void CLinkListEnrase(CLinkList *pHead,DataType data)
{
  assert(pHead);
  if(-1 == CLinkListFind(pHead,data))
    return;
  CLinkList *cur = pHead->pNext;
  while(cur != pHead)
  {
    if(cur->data == data)
    {
      cur->pFront->pNext = cur->pNext;
      cur->pNext->pFront = cur->pFront;
      free(cur);
      cur = NULL;
      return;
    }
    cur = cur->pNext;
  }
}




void Test()
{
  CLinkList *head = NULL;
  CLinkListInit(&head);
  CLinkListPrint(head);
  CLinkListPushFront(head,5);
  CLinkListPushFront(head,4);
  CLinkListPushFront(head,3);
  CLinkListPushFront(head,2);
  CLinkListPushFront(head,1);
  CLinkListPrint(head);
  CLinkListPushBack(head,6);
  CLinkListPushBack(head,7);
  CLinkListPrint(head);
  CLinkListPopBack(head);
  CLinkListPrint(head);
  CLinkListPopFront(head);
  CLinkListPrint(head);
  CLinkListInsert(head,1,2);
  CLinkListPrint(head);
  CLinkListEnrase(head,1);
  CLinkListPrint(head);

  printf("find = %d\n",CLinkListFind(head,1));
  CLinkListDestory(&head);
  CLinkListPrint(head);
}
