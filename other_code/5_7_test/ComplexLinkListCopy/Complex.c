#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int DataType;

typedef struct ComplexLinkList
{
  struct ComplexLinkList *pNext;
  struct ComplexLinkList *random;
  DataType data;
}ComplexLinkList;



ComplexLinkList *BuyNode(DataType data)
{
  ComplexLinkList *NewNode = (ComplexLinkList *)malloc(sizeof(ComplexLinkList));
  assert(NewNode);
  NewNode->pNext = NULL;
  NewNode->random = NULL;
  NewNode->data = data;
  return NewNode;
}

ComplexLinkList *ComplexLinkListCopy(ComplexLinkList *pHead)
{
  if(pHead == NULL)
    return NULL;
  ComplexLinkList *pre = pHead;
  //复制节点
  while(pre)
  {
    ComplexLinkList *NewList = BuyNode(pre->data);
    NewList->pNext = pre->pNext;
    pre->pNext = NewList;
    pre = NewList->pNext;
  }
  //复制随机指针
  ComplexLinkList *NewList = pHead->pNext;
  ComplexLinkList *p1 = pHead;
  ComplexLinkList *p2 = NULL;
  while(p1)
  {
    p2 = p1->pNext;
    if(p1->random == NULL)
      p2->random = NULL;
    else 
      p2->random = p1->random->pNext;
    p1 = p2->pNext;
  }

  //拆开复杂链表
  p1 = pHead;
  p2 = p1->pNext;
  while(p2)
  {
    p1->pNext = p2->pNext;
    p1 = p2;
    p2 = p1->pNext;
  }
  return NewList;
}




void ComplexTest()
{
  ComplexLinkList *node1 = BuyNode(1);
  ComplexLinkList *node2 = BuyNode(2);
  ComplexLinkList *node3 = BuyNode(3);
  ComplexLinkList *node4 = BuyNode(4);

  node1->pNext = node2;
  node2->pNext = node3;
  node3->pNext = node4;

  node1->random = node3;
  node2->random = node2;
  node3->random = node4;
  node2->random = NULL;
  ComplexLinkList *NewList = ComplexLinkListCopy(node1);
}

int main()
{
  ComplexTest();
  return 0;
}
