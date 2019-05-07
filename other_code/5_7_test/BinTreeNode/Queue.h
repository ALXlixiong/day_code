#include "BinTreeNode.h"

typedef struct BinTreeNode *EleType;

typedef struct QueueNode{
  struct QueueNode *next;
  EleType data_1;
}QueueNode;

typedef struct Queue{
  QueueNode *head;
  QueueNode *tail;
}Queue;


void QueueInit(Queue *q)
{
  assert(q);
  q->head = NULL;
  q->tail = NULL;
}

QueueNode *BuyNode_1(EleType data)
{
  QueueNode *NewNode = (QueueNode *)malloc(sizeof(QueueNode));
  assert(NewNode);
  NewNode->data_1 = data;
  NewNode->next = NULL;
  return NewNode;
}

void QueuePushTail(Queue *q,EleType data)
{
  assert(q);
  if(q->head == NULL)
    q->head = q->tail = BuyNode_1(data);
  else 
  {
    q->tail->next = BuyNode_1(data);
    q->tail = q->tail->next;
  }
}


//void QueuePrint(Queue *q)
//{
//  assert(q);
//  if(q->head == NULL)
//    return;
//  QueueNode *cur = q->head;
//  while(cur)
//  {
//    printf("%d ",cur->data);
//    cur = cur->next;
//  }
//  printf("\n");
//}


void QueuePopHead(Queue *q)
{
  assert(q);
  if(q->head == NULL)
    return;
  QueueNode *cur = q->head;
  q->head = cur->next;
  free(cur);
  cur = NULL;
}

EleType QueueTop(Queue *q)
{
  return q->head->data_1;
}

int QueueIsEmpty(Queue *q)
{
  if(q->head == NULL)
    return 0;
  else 
    return 1;
}

//void test()
//{
//  Queue q;
//  QueueInit(&q);
//  QueuePushTail(&q,1);
//  QueuePushTail(&q,2);
//  QueuePushTail(&q,3);
//  QueuePushTail(&q,4);
//  QueuePushTail(&q,5);
//  QueuePrint(&q);
//  QueuePopHead(&q);
//  QueuePrint(&q);
//}
//
//int main()
//{
//  test();
//  return 0;
//}
