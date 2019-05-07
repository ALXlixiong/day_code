
//#include "Queue.h"
#include "Stack.h"
#include<stdlib.h>
BinTreeNode *BuyNode(DataType data)
{
  BinTreeNode *NewNode = (BinTreeNode *)malloc(sizeof(BinTreeNode));
  assert(NewNode);
  NewNode->data = data;
  NewNode->pLeft = NULL;
  NewNode->pRight = NULL;
  return NewNode;
}

void _CreatBinTreeNode(BinTreeNode **root,char *buf,char invalid,int *index,int size)
{
  //index用来防止下标越界
  //invalid是无效字符
  //注意if语句条件先后顺序
  if(*index<size && buf[*index] != invalid)
  {
    *root = BuyNode(buf[*index]);
    (*index)++;
    _CreatBinTreeNode(&(*root)->pLeft,buf,invalid,index,size);
    (*index)++;
    _CreatBinTreeNode(&(*root)->pRight,buf,invalid,index,size);
  }
}

void CreatBinTreeNode(BinTreeNode **root,char *buf,char invalid)
{
  int index = 0;
  int size = strlen(buf);
  _CreatBinTreeNode(root,buf,invalid,&index,size);
}

//前序遍历
void PreOrder(BinTreeNode *root)
{
  if(root)
  {
    printf("%c ",root->data);
    PreOrder(root->pLeft);
    PreOrder(root->pRight);
  }
}
//中序遍历
void MidOrder(BinTreeNode *root)
{
  if(root)
  {
    MidOrder(root->pLeft);
    printf("%c ",root->data);
    MidOrder(root->pRight);
  }
}

//后序遍历、
void PostOrder(BinTreeNode *root)
{
  if(root)
  {
    PostOrder(root->pLeft);
    PostOrder(root->pRight);
    printf("%c ",root->data);
  }
}
//二叉树拷贝
//先考根节点，其次左子树，在右子树
void BinTreeNodeCopy(BinTreeNode *root,BinTreeNode **NewTree)
{
  assert(NewTree);
  if(root)
  {
    *NewTree = BuyNode(root->data);
    if(root->pLeft != NULL)
      BinTreeNodeCopy(root->pLeft,&(*NewTree)->pLeft);
    if(root->pRight != NULL)
      BinTreeNodeCopy(root->pRight,&(*NewTree)->pRight);
  }
}

//二叉树销毁
//使用后序遍历思想才可以销毁

void BinTreeNodeDestory(BinTreeNode **root)
{
  assert(root);
  if(*root)
  {
    BinTreeNodeDestory(&(*root)->pLeft);
    BinTreeNodeDestory(&(*root)->pRight);
    free(*root);
    *root = NULL;
  }
}
//二叉树节点个数
int GetBinTreeNodeCount(BinTreeNode *root)
{
  if(root == NULL)
    return 0;
  int leftCount = GetBinTreeNodeCount(root->pLeft);
  int rightCount = GetBinTreeNodeCount(root->pRight);
  return leftCount + rightCount +1;
}
//树的高度，左右子树高度比较
int HeightBinTreeNode(BinTreeNode *root)
{
  if(root == NULL)
    return 0;

  int leftHeight = HeightBinTreeNode(root->pLeft);
  int rightHeight = HeightBinTreeNode(root->pRight);
  return leftHeight > rightHeight ? leftHeight+1 : rightHeight+1;
}
//树的叶子节点个数
int GetLeafBinTreeNode(BinTreeNode *root)
{
  if(root == NULL)
    return 0;
  if(root->pLeft == NULL && root->pRight == NULL)
    return 1;

  return GetLeafBinTreeNode(root->pLeft) + GetLeafBinTreeNode(root->pRight);
}

//二叉树K层节点个数
int GetKBinTreeNodeCount(BinTreeNode *root,int k)
{
  if(root == NULL||k<=0)
    return 0;
  if(1 == k)
    return 1;
  return GetKBinTreeNodeCount(root->pLeft,k-1)+GetKBinTreeNodeCount(root->pRight,k-1);
}
//查找节点
BinTreeNode *FindBinTreeNode(BinTreeNode *root,DataType data)
{
  if(root == NULL)
    return NULL;
  if(root->data == data)
    return root;

  BinTreeNode *leftRet = FindBinTreeNode(root->pLeft,data);
  if(leftRet != NULL)
    return leftRet;
  return FindBinTreeNode(root->pRight,data);
}

//获取一个节点的双亲节点

BinTreeNode *FindParent(BinTreeNode *root,DataType data)
{
  if(root == NULL)
    return NULL;
  if(root->data == data)
    return NULL;
  if((root->pLeft != NULL && root->pLeft->data == data) || (root->pRight!= NULL &&  root->pRight->data == data))
    return root;
  BinTreeNode *retLeft = FindParent(root->pLeft,data);
  if(retLeft!= NULL)
    return retLeft;
  return FindParent(root->pRight,data);
}
//获取一个节点的左孩子
BinTreeNode *FindLeftChildNode(BinTreeNode *root,DataType data)
{
  BinTreeNode *retNode = FindBinTreeNode(root,data);
  if(retNode == NULL)
    return NULL;
  else 
    return retNode->pLeft;
}
//获取一个节点的右孩子
BinTreeNode *FindRightChildNode(BinTreeNode *root,DataType data)
{
  BinTreeNode *retNode = FindBinTreeNode(root,data);
  if(retNode == NULL)
    return NULL;
  else 
    return retNode->pRight;
}

//层序遍历(广度优先)  (队列实现)
//void LevelOrder(BinTreeNode *root)
//{
//  if(root == NULL)
//    return;
//  Queue q;
//  QueueInit(&q);
//  QueuePushTail(&q,root);
//  
//  while(QueueIsEmpty(&q)!= 0)
//  {
//    BinTreeNode *head = QueueTop(&q);
//    QueuePopHead(&q);
//    printf("%c ",head->data);
//    if(head->pLeft != NULL)
//      QueuePushTail(&q,head->pLeft);
//    if(head->pRight != NULL)
//      QueuePushTail(&q,head->pRight);
//  }
//  printf("\n");
//}
//

//判断一棵树是不是完全二叉树
//利用层序遍历思想

//void IsGlobleBinTree(BinTreeNode *root)
//{
//  if(root == NULL)
//  {
//    printf("空树\n");
//    return;
//  }
//  Queue q;
//  QueueInit(&q);
//  QueuePushTail(&q,root);//先入头结点
//  while(QueueIsEmpty(&q) != 0)
//  {
//    BinTreeNode *head = QueueTop(&q);
//    QueuePopHead(&q);//边进边出
//    if(head == NULL)
//      break;//当遇到空的时候跳出循环
//    QueuePushTail(&q,head->pLeft);//不管该节点的左右子树是否为空都入队列
//    QueuePushTail(&q,head->pRight);
//  }
//
//  while(QueueIsEmpty(&q) != 0)
//  {
//    BinTreeNode *head = QueueTop(&q);
//    QueuePopHead(&q);
//    if(head != NULL)//说明在空指针后面还有非空节点，则不是完全二叉树
//    {
//      printf("不是完全二叉树\n");
//      return;
//    }
//  }
//  printf("是完全二叉树\n");
//}
///////////////////////////////////////////////////////////////////////////////// 
//二叉树难点（非递归）
//非递归前序遍历
void PreOrderLoop(BinTreeNode *root)
{
  if(root == NULL)
    return;
  Stack *s = NULL;
  BinTreeNode *cur = root;
  while(cur != NULL || StackIsEmpty(s) != 0)
  {
    while(cur != NULL)
    {
      StackPush(&s,cur);
      printf("%c ",cur->data);
      cur = cur->pLeft;
    }
    BinTreeNode *TopNode = StackTop(s);
    StackPop(&s);
    cur = TopNode->pRight;
  }
  printf("\n");
}
//中序非递归遍历
void MidOrderLoop(BinTreeNode *root)
{
  if(root == NULL)
    return;
  Stack *s = NULL;
  BinTreeNode *cur = root;
  while(cur != NULL || StackIsEmpty(s) != 0)
  {
    while(cur != NULL)
    {
      StackPush(&s,cur);
      cur = cur->pLeft;
    }
    BinTreeNode *TopNode = StackTop(s);
    printf("%c ",TopNode->data);//只是和前序打印的位置不同
    StackPop(&s);
    cur = TopNode->pRight;
  }
  printf("\n");
}

//后序遍历非递归
void PostOrderLoop(BinTreeNode *root)
{
  if(root == NULL)
    return;
  Stack *s = NULL;
  BinTreeNode *cur = root;
  BinTreeNode *flag = NULL;//用来记录右子树遍历完了，不然会出现死循环
  while(cur != NULL || StackIsEmpty(s) !=0)
  {
    while(cur != NULL)
    {
      StackPush(&s,cur);
      cur = cur->pLeft;
    }

    BinTreeNode *TopNode = StackTop(s);
    if(TopNode->pRight == NULL || flag == TopNode->pRight) //打印根节点1.右子树为空2.右子树遍历完了（标记）
    {
      printf("%c ",TopNode->data);
      flag = TopNode;//跟新标记
      StackPop(&s);
    }
    else 
      cur = TopNode->pRight;
  }
}
//二叉树镜像
void Swap(BinTreeNode **p1,BinTreeNode **p2)
{
  BinTreeNode *tmp = *p1;
  *p1 = *p2;
  *p2 = tmp;
}

void MirrorBinTree_1(BinTreeNode *root)
{
  if(root)
  {
    Swap(&root->pLeft,&root->pRight);
    MirrorBinTree_1(root->pLeft);
    MirrorBinTree_1(root->pRight);
  }
}
//非递归,利用层序遍历思想（队列）

//void LevelOrder(BinTreeNode *root)
//{
//  if(root == NULL)
//    return;
//  Queue q;
//  QueueInit(&q);
//  QueuePushTail(&q,root);
//  
//  while(QueueIsEmpty(&q)!= 0)
//  {
//    BinTreeNode *head = QueueTop(&q);
//    QueuePopHead(&q);
//    Swap(&head->pLeft,&head->pRight);
//    if(head->pLeft != NULL)
//      QueuePushTail(&q,head->pLeft);
//    if(head->pRight != NULL)
//      QueuePushTail(&q,head->pRight);
//  }
//  printf("\n");
//}


//公共祖先节点()
BinTreeNode *GetAncetorNode(BinTreeNode *root,BinTreeNode *node1,BinTreeNode *node2)
{
  if(root == NULL)
    return 0;
  BinTreeNode *node1_is_left = FindBinTreeNode(root->pLeft,node1->data);
  BinTreeNode *node2_is_left = FindBinTreeNode(root->pLeft,node2->data);
  if(node1_is_left != NULL && node2_is_left == NULL)
    return root;
  if(node1_is_left == NULL && node2_is_left != NULL)
    return root;
  
  if(node1_is_left)//两者都不为空
  {
    return GetAncetorNode(root->pLeft,node1,node2);
  }
  else //两者都为空，则都在右子树
  {
    return GetAncetorNode(root->pRight,node1,node2);
  }
}

//判断是否是平衡二叉树
int isBalanceBinTree(BinTreeNode *root)
{
  if(root == NULL)
    return 1;
  int leftHeight = HeightBinTreeNode(root->pLeft);
  int rightHeight = HeightBinTreeNode(root->pRight);
  if(abs(leftHeight-rightHeight)>1)
    return 0;
  return isBalanceBinTree(root->pRight) && isBalanceBinTree(root->pLeft);
}


void Test1()
{
  BinTreeNode *root = NULL;
  char *buf = "ABD###CE##F";
  char invalid = '#';
  CreatBinTreeNode(&root,buf,invalid);
  PreOrder(root);
  printf("\n");
  MirrorBinTree_1(root);
  PreOrder(root);
  //PreOrder(root);
  //printf("\n");
  //MidOrder(root);
  //printf("\n");
  //PostOrder(root);
  //printf("\n");
  //BinTreeNode *NewTree = NULL;
  //BinTreeNodeCopy(root,&NewTree);
  //PreOrder(NewTree);
  //printf("\n");
  //MidOrder(NewTree);
  //printf("\n");
  //PostOrder(NewTree);
  //printf("\n");
  //BinTreeNodeDestory(&root);
  //PreOrder(root);
  //printf("节点个数:%d\n",GetBinTreeNodeCount(NewTree));
  //printf("二叉树的高度:%d\n",HeightBinTreeNode(NewTree));
  //printf("二叉树叶子节点个数:%d\n",GetLeafBinTreeNode(NewTree));
  //printf("二叉树第3层节点个数:%d\n",GetKBinTreeNodeCount(NewTree,3));
  //BinTreeNode *findRet = FindBinTreeNode(NewTree,'C');
  //if(findRet == NULL)
  //  printf("没有\n");
  //else 
  //  printf("C找到了:%c\n",findRet->data);
  //findRet = FindParent(NewTree,'F');
  //if(findRet == NULL)
  //  printf("没有或者是头结点\n");
  //else 
  //{
  //  printf("F的父节点:%c\n",findRet->data);
  //  //printf("%c\n",findRet->pLeft->data);
  //  //printf("%c\n",findRet->pRight->data);
  //}
  //findRet = FindLeftChildNode(NewTree,'C');
  //if(findRet == NULL)
  //  printf("没有左孩子\n");
  //else 
  //  printf("c左孩子：%c\n",findRet->data);
  ////printf("层序遍历:");
  ////LevelOrder(NewTree);
  ////IsGlobleBinTree(NewTree);
  //PreOrderLoop(NewTree);
  //MidOrderLoop(NewTree);
  //PostOrderLoop(NewTree);
}

int main()
{
  Test1();
  return 0;
}

