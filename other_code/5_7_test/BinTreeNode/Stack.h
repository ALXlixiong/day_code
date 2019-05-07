
#include "BinTreeNode.h"
typedef struct BinTreeNode* ElementType;
//typedef int ElementType;
typedef struct Stack{
  struct Stack *next;
  ElementType data;
}Stack;


Stack * BuyNode_2(ElementType data)
{
  Stack *NewNode = (Stack *)malloc(sizeof(Stack));
  assert(NewNode);
  NewNode->next = NULL;
  NewNode->data = data;
  return NewNode;
}


void StackPush(Stack **s,ElementType data)
{
  assert(s);
  if(*s == NULL)
    *s = BuyNode_2(data);
  else{
    Stack *NewNode = BuyNode_2(data);
    NewNode->next = *s;
    *s = NewNode;
  }
}

void StackPop(Stack **s)
{
  assert(s);
  if(*s == NULL)
    return;
  else{
    Stack *head = *s;
    *s = head->next;
    free(head);
    head = NULL;
  }
}


//void StackPrint(Stack *s)
//{
//  if(s == NULL)
//    return;
//  Stack *cur = s;
//  while(cur)
//  {
//    printf("%d ",cur->data);
//    cur = cur->next;
//  }
//  printf("\n");
//}

ElementType StackTop(Stack *s)
{
  return s->data;
}

int StackIsEmpty(Stack *s)
{
  if(s == NULL)
    return 0;
  else 
    return 1;
}

//void test()
//{
//  Stack *s = NULL;
//  StackPush(&s,1);
//  StackPush(&s,2);
//  StackPush(&s,3);
//  StackPush(&s,4);
//  StackPrint(s);
//  StackPop(&s);
//  StackPrint(s);
//}
//
//int main()
//{
//  test();
//  return 0;
//}
