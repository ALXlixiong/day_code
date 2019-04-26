#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//链式栈

typedef char DataType;
typedef struct Stack
{
  struct Stack *next;
  DataType data;
}stack;

void StackPush(stack **s,DataType data);
void StackPop(stack **s);
void StackPrint(stack *s);
void StackTest();

////////////////////////////////////

stack *BuyNode(DataType data)
{
  stack *NewNode = (stack *)malloc(sizeof(stack));
  NewNode->data = data;
  NewNode->next = NULL;
  return NewNode;
}


void StackPush(stack **s,DataType data)
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

void  StackPop(stack **s)
{
  assert(s);
  if(*s == NULL)
    return;
  stack *cur = (*s)->next;
  free(*s);
  *s = cur;
}

DataType StackTop(stack *s)
{
  if(s == NULL)
    return -1;
  else 
    return s->data;
}

void StackPrint(stack *s)
{
  stack *cur = s;
  while(cur)
  {
    printf("%d ",cur->data);
    cur = cur->next;
  }
  printf("\n");
}

/////////////////////////////////////////// 
//栈的应用
/////////////////////////////////////////// 
//(1)括号匹配


void StackTest()
{
  //stack *s = NULL;

//  StackPush(&s,5);
//  StackPush(&s,4);
//  StackPush(&s,3);
//  StackPush(&s,2);
//  StackPrint(s);
//  StackPop(&s);
//  StackPrint(s);
}

#include<string.h>

void test(char *arr)
{
  stack *s = NULL;
  char *cur = arr;
  while(*cur != '\0')
  {
    switch(*cur)
    {
      case '(':
          StackPush(&s,*cur);
          break;
      case '[':
          StackPush(&s,*cur);
          break;
      case '{':
          StackPush(&s,*cur);
          break;
      case ')':
          {
            if(StackTop(s) == '(')
            {
              StackPop(&s);
              break;
            }
            else if(StackTop(s) == -1)
            {
              printf("右括号多于左括号\n");
              return;
            }
            else 
            {
              printf("左右括号不匹配\n");
              return;
            }
          }
      case ']':
          {
            if(StackTop(s) == '[')
            {
              StackPop(&s);
              break;
            }
            else if(StackTop(s) == -1)
            {
              printf("右括号多于左括号\n");
              return;
            }
            else 
            {
              printf("左右括号不匹配\n");
              return;
            }
          }
      case '}':
          {
            if(StackTop(s) == '{')
            {
              StackPop(&s);
              break;
            }
            else if(StackTop(s) == -1)
            {
              printf("右括号多于左括号\n");
            }
            else 
            {
              printf("左右括号不匹配\n");
              return;
            }
          }
    }
    cur++;
  }
  if(s == NULL)
  {
    printf("匹配正确\n");
  }
  else if(StackTop(s) == '(')
  {
    printf("左括号多于右括号\n");
  }
}




int main()
{
 // char *a = "(())abc{[(])}";//左右括号次序匹配不正确
 // 
 // char *b = "(()))abc{[]}";//右括号多于左括号
 // char *c = "(()()abc{[]}";//左括号多于右括号
 // char *d = "(())abc{[]()}";//左右括号匹配正确
 // test(a);
 // test(b);
 // test(c);
 // test(d);
  return 0;
}
