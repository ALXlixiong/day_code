#include <iostream>
using namespace std;
#include <assert.h>
typedef struct LinkList
{
  int data;
  struct LinkList* pNext;
}LinkList;

void PushBackLinkList(LinkList**pHead,int data)
{
  assert(pHead);
  if(*pHead == nullptr)
  {
    *pHead = new LinkList;
    (*pHead)->data = data;
    (*pHead)->pNext = nullptr;
    return;
  }
  LinkList *cur = *pHead;
  while(cur->pNext != nullptr)
    cur = cur->pNext;
  cur->pNext = new LinkList;
  cur->pNext->data = data;
  cur->pNext->pNext = nullptr;
}

void PrintLinkList(LinkList *pHead)
{
  LinkList *cur = pHead;
  while(cur)
  {
    cout<<cur->data<<" ";
    cur = cur->pNext;
  }
  cout<<endl;
}

void EndToHeadPrintNor(LinkList *pHead)
{
  if(pHead == nullptr)
    return;
  LinkList *end = nullptr;
  while(end != pHead)
  {
    LinkList *cur = pHead;
    while(cur->pNext != end)
      cur = cur->pNext;
    cout<<cur->data<<"->";
    end = cur;
  }
  cout<<"nullptr"<<endl;
}

void EndToHeadR(LinkList *pHead)
{
  if(pHead == nullptr)
    return;
  EndToHeadR(pHead->pNext);
  cout<<pHead->data<<"->";
}

void Circle(LinkList *pHead,int k)
{
  if(pHead == nullptr)
    return;
  LinkList *cur = pHead;
  while(cur->pNext)
    cur = cur->pNext;
  cur->pNext = pHead;
  while(pHead->pNext != pHead)
  {
    cur = pHead->pNext;
    LinkList *pre = pHead;
    int tmp = k-1;
    while(--tmp){
      pre = cur;
      cur = cur->pNext;
    }
    pre->pNext = cur->pNext;
    delete cur;
    pHead = pre->pNext;
  }
  cout<<"lunky:"<<pHead->data<<endl;
}

LinkList* ReverseLinkList_1(LinkList *pHead)
{
   if(pHead == nullptr)
     return nullptr;
   LinkList *NewList = nullptr;
   LinkList *cur = pHead;
   while(cur)
   {
      LinkList *pre = cur;
      cur = cur->pNext;
      pre->pNext = NewList;
      NewList = pre;
   }
   return NewList;
}

void ReverseLinkList_2(LinkList **pHead)
{
  assert(pHead);
  LinkList *p1 = nullptr;
  LinkList *p2 = *pHead;
  LinkList *p3 = (*pHead)->pNext;
  while(p2)
  {
    p2->pNext = p1;
    p1 = p2;
    p2 = p3;
    if(p3 != nullptr)
      p3 = p3->pNext;
  }
  *pHead = p1;
}

LinkList* MergeTwoLink(LinkList *list1,LinkList *list2)
{
  if(list1 == nullptr)
    return list2;
  if(list2 == nullptr)
    return list1;
  LinkList *list = nullptr;
  if(list1->data < list2->data)
  {
    list = list1;
    list1 = list1->pNext;
  }
  else
  {
    list = list2;
    list2 = list2->pNext;
  }
  LinkList *tail = list;
  while(list1 && list2)
  {
    if(list1->data > list2->data)
    {
      tail->pNext = list2;
      list2 = list2->pNext;
    }
    else 
    {
      tail->pNext = list1;
      list1 = list1->pNext;
    }
    tail = tail->pNext;
  }
  if(!list1)
    tail->pNext = list2;
  if(!list2)
    tail->pNext = list1;
  return list;
}

void Test1()
{
  LinkList *list1 = nullptr;
  PushBackLinkList(&list1,1);
  PushBackLinkList(&list1,2);
  PushBackLinkList(&list1,5);
  PushBackLinkList(&list1,7);
  PushBackLinkList(&list1,9);
  LinkList *list2 = nullptr;
  PushBackLinkList(&list2,0);
  PushBackLinkList(&list2,3);
  PushBackLinkList(&list2,4);
  PushBackLinkList(&list2,5);
  PushBackLinkList(&list2,8);
  PushBackLinkList(&list2,12);
  PushBackLinkList(&list2,13);
  PushBackLinkList(&list2,14);
  PushBackLinkList(&list2,15);
  LinkList* NewList = MergeTwoLink(list1,list2);
  PrintLinkList(NewList);
}

void FindMidNode(LinkList *list)
{
  if(list == nullptr)
    return;
  LinkList *slow = list;
  LinkList *fast = list->pNext;
  if(fast == nullptr || fast->pNext == nullptr)
  {
    cout<<slow->data<<endl;
    return;
  }
  fast = fast->pNext;
  while(1)
  {
    slow = slow->pNext;
    fast = fast->pNext;
    if(fast == nullptr || fast->pNext == nullptr)
    {
      cout<<slow->data<<endl;
      return;
    }
    fast = fast->pNext;
  }
}

void Test2()
{
  LinkList *list = nullptr;
  PushBackLinkList(&list,1);
  PushBackLinkList(&list,2);
  PushBackLinkList(&list,5);
  PushBackLinkList(&list,2);
  PushBackLinkList(&list,5);
  PushBackLinkList(&list,7);
  PushBackLinkList(&list,2);
  PushBackLinkList(&list,5);
  PushBackLinkList(&list,9);
  FindMidNode(list);
}

typedef struct ComplexLink 
{
  int data;
  struct ComplexLink *random;
  struct ComplexLink *next;
}ComplexLink;

ComplexLink* ComplexLinkCopy(ComplexLink *list)
{
  if(list == nullptr)
    return nullptr;
  ComplexLink *pre = list;
  ComplexLink *cur = pre->next;
  while(1)
  {
    ComplexLink *NewNode = new ComplexLink;
    NewNode->data = pre->data;
    pre->next = NewNode;
    NewNode->next = cur;
    pre = cur;
    if(cur == nullptr)
      break;
    cur = cur->next;
  }
  ComplexLink *p1 = list;
  ComplexLink *p2 = list;
  while(p1)
  {
    p2 = p1->next;
    if(p1->random == nullptr)
      p2->random = nullptr;
    else 
      p2->random = p1->random->next;
    p1 = p2->next;
  }
  p1 = list;
  p2 = list->next;
  ComplexLink *NewList = p2;
  while(p2)
  {
    p1->next = p2->next;
    p1 = p2;
    p2 = p2->next;
  }
  return NewList;
}

void Test3()
{
  ComplexLink *node1 = new ComplexLink;
  ComplexLink *node2 = new ComplexLink;
  ComplexLink *node3 = new ComplexLink;
  ComplexLink *node4 = new ComplexLink;
  node1->data = 1;node2->data = 2;
  node3->data = 3;node3->data = 4;
  node1->next = node2;
  node2->next = node3;
  node3->next = node4;
  node4->next = nullptr;
  node1->random = node3;
  node2->random = node2;
  node3->random = node4;
  node4->random = nullptr;
  ComplexLink *NewList = ComplexLinkCopy(node1);
}

int main()
{
  Test3();
  return 0;
}
