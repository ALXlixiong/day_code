#include "LinkList.h"

LinkList *BuyNode(DataType data)
{
  LinkList *NewNode = (LinkList *)malloc(sizeof(LinkList));
  if(NULL == NewNode)
  {
    assert(-1);
    return NULL;
  }
  NewNode->next = NULL;
  NewNode->data = data;
  return NewNode;
}

//尾插
void LinkListPushBack(LinkList **ppHead,DataType data)
{
  assert(ppHead);
  if(*ppHead == NULL)
  {
    *ppHead = BuyNode(data);
    return;
  }
  LinkList *cur = *ppHead;
  while(cur->next != NULL)
  {
    cur = cur->next;
  }
  cur->next = BuyNode(data);
}

//头插
void LinkListPushFront(LinkList **ppHead,DataType data)
{
  assert(ppHead);
  if(*ppHead == NULL)
  {
    *ppHead = BuyNode(data);
    return;
  }
  LinkList *pre = BuyNode(data);
  pre->next = *ppHead;
  *ppHead = pre;
}


//尾删
void LinkListPopBack(LinkList **ppHead)
{
  assert(ppHead);
  //空
  if(*ppHead == NULL)
    return;
  
  LinkList *cur = *ppHead;
  //一个节点
  if(cur->next == NULL)
  {
    free(cur);
    cur = NULL;
    return;
  }
  //多个节点
  while(cur->next->next != NULL)
  {
    cur = cur->next;
  }
  free(cur->next);
  cur->next = NULL;
}


//头删
void LinkListPopFront(LinkList **ppHead)
{
  assert(ppHead);
  LinkList *pre = *ppHead;
  if(pre == NULL)
    return;
  pre = pre->next;
  free(*ppHead);
  *ppHead = NULL;
  *ppHead = pre;
}

//查找
LinkList *LinkListFind(LinkList *pHead,DataType data)
{
  assert(pHead);
  LinkList *cur = pHead;
  if(cur == NULL)
    return NULL;
  while(cur)
  {
    if(cur->data == data)
      return cur;
    cur = cur->next;
  }
  return NULL;
}



//随机插
void LinkListInsert(LinkList **ppHead,DataType data,LinkList *pos)
{
  assert(ppHead);
  assert(pos);
  LinkList *cur = *ppHead;
  if(NULL == cur)
  {
    *ppHead = BuyNode(data);
    return;
  }
  while(cur)
  {
    if(cur == pos)
    {
      LinkList *p = BuyNode(data);
      p->next = cur->next;
      cur->next = p;
      return;
    }
    cur = cur->next;
  }
}

//随机删
void LinkListEnrase(LinkList **ppHead,DataType data)
{
  assert(ppHead);
  if(*ppHead == NULL)
    return;
  LinkList *cur = *ppHead;
  //第一个节点
  if(cur->data == data)
  {
    *ppHead = cur->next;
    free(cur);
    cur = NULL;
    return;
  }
  //其他节点
  while(cur->next)
  {
    if(cur->next->data == data)
    {
      LinkList *p = cur->next;
      cur->next = p->next;
      free(p);
      p = NULL;
      return;
    }
    cur = cur->next;
  }
}


//删除链表内所有相同的元素
void LinkListPopSameElement(LinkList **ppHead,DataType data)
{
  assert(ppHead);
  LinkList *cur = *ppHead;
  //考虑首元素是不是要删除元素
  while(cur->data == data)
  {
    *ppHead = cur->next;
    free(cur);
    cur = *ppHead;
  }
  
  LinkList *p1 = *ppHead;
  LinkList *p2 = NULL;
  while(p1 != NULL)
  {
    if(p1->data  != data)
    {
      p2 = p1;
      p1 = p1->next;
    }
    else 
    {
      p2->next = p1->next;
      free(p1);
      p1 = p2->next;
    }
  }
}

//销毁
void LinkListDestory(LinkList **ppHead)
{
  assert(ppHead);
  LinkList *cur = *ppHead;
  while(cur)
  {
    LinkList *p = cur->next;
    free(cur);
    cur = p;
  }
  *ppHead = NULL;
}

//打印
void LinkListPrint(LinkList *pHead)
{
  LinkList *cur = pHead;
  while(cur)
  {
    printf("%d ",cur->data);
    cur = cur->next;
  }
  printf("\n");
}

void LinkListTest()
{
  LinkList *head= NULL;
  
 // printf("头插\n");
 // LinkListPushFront(&head,1);
 // LinkListPushFront(&head,2);
 // LinkListPushFront(&head,3);
 // LinkListPushFront(&head,4);
 // LinkListPushFront(&head,5);
 // LinkListPrint(head);
 // printf("尾插\n");
 // LinkListPushBack(&head,0);
 // LinkListPrint(head);

 // printf("头删\n");
 // LinkListPopFront(&head);
 // LinkListPrint(head);
 // printf("尾删\n");
 // LinkListPopBack(&head);
 // LinkListPrint(head);
 // printf("在4后面插入0\n");
 // LinkList *pos = LinkListFind(head,4);
 // LinkListInsert(&head,0,pos);
 // LinkListPrint(head);
 // printf("随机删\n");
 // LinkListEnrase(&head,3);
 // LinkListPrint(head);
  LinkListPushBack(&head,3); 
  LinkListPushBack(&head,3); 
  LinkListPushBack(&head,6); 
  LinkListPushBack(&head,5); 
  LinkListPushBack(&head,3); 
  LinkListPushBack(&head,3); 
  LinkListPushBack(&head,7); 
  LinkListPushBack(&head,3); 
  LinkListPushBack(&head,1); 
  LinkListPushBack(&head,2); 
  LinkListPushBack(&head,3); 
  LinkListPrint(head);
  LinkListPopSameElement(&head,3);
  LinkListPrint(head);
  LinkListDestory(&head);

}
