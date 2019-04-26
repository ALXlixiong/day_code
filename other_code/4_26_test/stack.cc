#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//链式栈

typedef int EleType;
typedef struct Stack
{
  struct Stack *next;
  EleType data;
}stack;

void StackPush(stack **s,EleType data);
void StackPop(stack **s);
void StackPrint(stack *s);
void StackTest();
EleType StackTop(stack *s);

////////////////////////////////////

stack *BuyNode(EleType data)
{
  stack *NewNode = (stack *)malloc(sizeof(stack));
  NewNode->data = data;
  NewNode->next = NULL;
  return NewNode;
}


void StackPush(stack **s,EleType data)
{
  assert(s);
  if(*s == NULL)
  {
    *s = BuyNode(data);
    return;
  }
  stack *cur = BuyNode(data);
  cur->next = *s;
  *s = cur;
}

void StackPop(stack **s)
{
  assert(s);
  if(*s == NULL)
    return;
  stack *cur = (*s)->next;
  free(*s);
  *s = cur;
}

void StackPrint(stack *s)
{
  stack *cur = s;
  while(cur)
  {
    printf("%d ",cur->data);
    cur = cur->next;
  }
}

EleType StackTop(stack *s)
{
  if(s == NULL)
    return -1;
  return s->data;
}


void StackTest()
{
  stack *s = NULL;
  StackPush(&s,5);
  StackPush(&s,4);
  StackPush(&s,3);
  StackPush(&s,2);
  StackPush(&s,1);
  StackPop(&s);
  StackPrint(s);
  printf("\n%d\n",StackTop(s));
}



int main()
{
  StackTest();
  return 0;
}
