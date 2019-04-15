#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <assert.h>
#include <stdio.h>
using namespace std;

typedef struct BTNode
{
  struct BTNode *pLeft;
  struct BTNode *pRight;
  int data;
}BTNode;

void CreateBTree(BTNode **pRoot,vector<char> &arr,char invalid,size_t *index)
{
  assert(pRoot);
  if((*index)<arr.size() && arr[*index] != invalid)
  {
    *pRoot = new BTNode;
    (*pRoot)->data = arr[*index];
    ++*index;
    CreateBTree(&(*pRoot)->pLeft,arr,invalid,index);
    ++*index;
    CreateBTree(&(*pRoot)->pRight,arr,invalid,index);
  }
}

void PreOrder(BTNode *pRoot)
{
  if(pRoot)
  {
    printf("%c ",pRoot->data);
    PreOrder(pRoot->pLeft);
    PreOrder(pRoot->pRight);
  }
}
void MidOrder(BTNode *pRoot)
{
  if(pRoot)
  {
    MidOrder(pRoot->pLeft);
    printf("%c ",pRoot->data);
    MidOrder(pRoot->pRight);
  }
}
void PostOrder(BTNode *pRoot)
{
  if(pRoot)
  {
    PostOrder(pRoot->pLeft);
    PostOrder(pRoot->pRight);
    printf("%c ",pRoot->data);
  }
}

BTNode* BTNodeCopy(BTNode *pRoot)
{
  BTNode *NewNode = nullptr;
  if(pRoot)
  {
    NewNode = new BTNode;
    NewNode->data = pRoot->data;

    if(pRoot->pLeft)
      NewNode->pLeft = BTNodeCopy(pRoot->pLeft);
    if(pRoot->pRight)
      NewNode->pRight = BTNodeCopy(pRoot->pRight);
  }
  return NewNode;
}

void BTNodeDestroy(BTNode **pRoot)
{
  assert(pRoot);
  if(*pRoot)
  {
    BTNodeDestroy(&(*pRoot)->pLeft);
    BTNodeDestroy(&(*pRoot)->pRight);
    delete *pRoot;
    *pRoot = nullptr;
  }
}
void LevelOrder(BTNode *pRoot)
{
  queue<BTNode *> q;
  q.push(pRoot);
  while(!q.empty())
  {
    BTNode *p = q.front();
    q.pop();
    printf("%c ",p->data);
    if(p->pLeft != nullptr)
      q.push(p->pLeft);
    if(p->pRight != nullptr)
      q.push(p->pRight);
  }
  cout<<endl;
}
bool IsComBinTree(BTNode *pRoot)
{
  queue<BTNode *> q;
  q.push(pRoot);
  while(!q.empty())
  {
    BTNode *front = q.front();
    q.pop();
    if(front == nullptr)
      break;
    q.push(front->pLeft);
    q.push(front->pRight);
  }
  while(!q.empty())
  {
    BTNode *front = q.front();
    q.pop();
    if(front != nullptr)
      return false;
  }
  return true;
}
//一个节点返回1
//空节点返回0
//取左右最高在加根节点
int BTreeHeight(BTNode *pRoot)
{
  if(pRoot == nullptr)
    return 0;
  if(pRoot->pLeft == nullptr && pRoot->pRight == nullptr)
    return 1;
  int LeftHeight = BTreeHeight(pRoot->pLeft);
  int RightHeight = BTreeHeight(pRoot->pRight);
  return LeftHeight>RightHeight ? LeftHeight+1 : RightHeight + 1;
}
//左叶子节点+右子树叶子节点
int BTreeLeafNode(BTNode *pRoot)
{
  if(pRoot == nullptr)
    return 0;
  if(pRoot->pLeft == nullptr && pRoot->pRight == nullptr)
    return 1;
  int LeftLeaf = BTreeLeafNode(pRoot->pLeft);
  int RightLeaf = BTreeLeafNode(pRoot->pRight);
  return LeftLeaf+RightLeaf;
}
int BTreeNodeCount(BTNode *pRoot)
{
  if(pRoot == nullptr)
    return 0;
  if(pRoot->pLeft == nullptr && pRoot->pRight == nullptr)
    return 1;
  return BTreeNodeCount(pRoot->pLeft) + BTreeNodeCount(pRoot->pRight) + 1;
}
//第K层节点个数
//左子树第K层+右子树第K层
//递归K-1，相当于K=1得到一个节点
int BTreeKCount(BTNode *pRoot,int k)
{
  if(pRoot == nullptr || k<=0)
    return 0;
  if(k == 1)
    return 1;
  return BTreeKCount(pRoot->pLeft,k-1) + BTreeKCount(pRoot->pRight,k-1);
}
BTNode* IsNodeInBTree(BTNode *pRoot,char data)
{
  if(pRoot == nullptr)
    return nullptr;
  if(pRoot->data == data)
    return pRoot;
  BTNode *tmp = IsNodeInBTree(pRoot->pLeft,data);
  if(tmp == nullptr)
  {
    return IsNodeInBTree(pRoot->pRight,data);
  }
  return tmp;
}

BTNode *FindParentNode(BTNode *pRoot,BTNode *child)
{
  if(pRoot == nullptr || child == nullptr)
    return nullptr;
  if(pRoot == child)
    return nullptr;
  if(pRoot->pLeft == child || pRoot->pRight == child)
    return pRoot;
  BTNode *res = FindParentNode(pRoot->pLeft,child);
  if(res == nullptr)
    return FindParentNode(pRoot->pRight,child);
  return res;
}
void swap(BTNode **left,BTNode **right)
{
  BTNode *tmp = *left;
  *left = *right;
  *right = tmp;
}
void MirrorBTree(BTNode **pRoot)
{
  if(*pRoot)
  {
    swap(&((*pRoot)->pRight),&((*pRoot)->pLeft));
    MirrorBTree(&(*pRoot)->pLeft);
    MirrorBTree(&(*pRoot)->pRight);
  }
}
void PreOrderNor(BTNode *pRoot)
{
  stack<BTNode *> s;
  BTNode *top = pRoot;
  while(top != nullptr || !s.empty())
  {
    while(top)
    {
      printf("%c ",top->data);
      s.push(top);
      top = top->pLeft;
    }
    top = s.top();
    s.pop();
    top = top->pRight;
  }
}
void MidOrderNor(BTNode *pRoot)
{
  stack<BTNode *> s;
  BTNode *top = pRoot;
  while(top != nullptr || !s.empty())
  {
    while(top)
    {
      s.push(top);
      top = top->pLeft;
    }
    top = s.top();
    printf("%c ",top->data);
    s.pop();
    top = top->pRight;
  }
}
void PostOrderNor(BTNode *pRoot)
{
  stack<BTNode *> s;
  BTNode *cur = pRoot;
  BTNode *top = nullptr;
  BTNode *last = nullptr;//标记上一次打印遍历节点
  while(cur != nullptr || !s.empty())
  {
    while(cur)
    {
      s.push(cur);
      cur = cur->pLeft;
    }
    top = s.top();
    //当右子树为空，或者右子树遍历完成，打印根节点
    if(top->pRight == nullptr || top->pRight == last)
    {
      printf("%c ",top->data);
      last = top;
      s.pop();
    }
    else 
      cur = top->pRight;
  }
}

void MirrorBTreeNor(BTNode **pRoot)
{
  assert(pRoot);
  stack<BTNode *> s;
  s.push(*pRoot);
  while(!s.empty())
  {
    BTNode *top = s.top();
    s.pop();
    BTNode *tmp = top->pRight;
    top->pRight = top->pLeft;
    top->pLeft = tmp;

    if(top->pLeft)
      s.push(top->pLeft);
    if(top->pRight)
      s.push(top->pRight);
  }
}
//二叉树最近祖先
//假设节点都在二叉树
BTNode *NearestAncestor(BTNode *root,BTNode *p,BTNode *q)
{
  if(root == nullptr || p == root || q == root)
    return root;
  BTNode *leftp = FindParentNode(root->pLeft,p);
  BTNode *leftq = FindParentNode(root->pLeft,q);

  if(leftp == nullptr && leftq != nullptr)
    return root;
  if(leftp != nullptr && leftq == nullptr)
    return root;

  if(leftq)
    return NearestAncestor(root->pLeft,p,q);
  else 
    return NearestAncestor(root->pRight,p,q);
}
//判断二叉树是否为平衡二叉树
bool IsBalanceTree(BTNode *root)
{
  if(root == nullptr)
    return true;
  int leftHeight = BTreeHeight(root->pLeft);
  int rightHeight = BTreeHeight(root->pRight);
  int diff = leftHeight-rightHeight;
  if(diff<-1 || diff>1)
    return false;

  if(IsBalanceTree(root->pLeft) == false)
    return false;
  else 
    return true;
  if(IsBalanceTree(root->pRight) == false)
    return false;
  else 
    return true;
}

//判断最远两个节点之间距离
int MAX(int a,int b,int c)
{
  int max = a;
  if(b>max)
    max = b;
  if(c>max)
    max = c;
  return max;
}
int GetFarestDistance(BTNode *root)
{
  if(root == nullptr)
    return 0;
  int leftHeight = BTreeHeight(root->pLeft);
  int rightHeight = BTreeHeight(root->pRight);
  int rootDistance = leftHeight+rightHeight;

  int leftFarDistance = GetFarestDistance(root->pLeft);
  int rightFarDistance = GetFarestDistance(root->pRight);

  return MAX(rootDistance,leftFarDistance,rightFarDistance);
}

BTNode *CreateBTree2(vector<char>::iterator v1,vector<char>::iterator v2,size_t size)
{
  if(size<=0)
    return nullptr;
  size_t index = 0;
  for(size_t i = 0;i<size;++i)
  {
    if(v1[0] == v2[i])
    {
      index = i;
      break;
    }
  }

  BTNode *root = new BTNode;
  root->data = v2[index];

  root->pLeft = CreateBTree2(v1+1,v2,index);
  root->pRight = CreateBTree2(v1+1+index,v2+1+index,size-1-index);
  return root;
}

void Test1()
{
  vector<char> arr{'A','B','D','G','#','#','#','#','C','E','#','#','F'};
  BTNode *root = nullptr;
  size_t index = 0;
  CreateBTree(&root,arr,'#',&index);
  PreOrder(root);
  cout<<endl;
  PreOrderNor(root);
  cout<<endl;
  MidOrder(root);
  cout<<endl;
  MidOrderNor(root);
  cout<<endl;
  LevelOrder(root);
  PostOrderNor(root);
  cout<<endl;
  PostOrder(root);
  cout<<endl;
  cout<<"farest distance:"<<GetFarestDistance(root)<<endl;
  vector<char> v1{'A','B','D','C','E','F'};
  vector<char> v2{'D','B','A','E','C','F'};
  root = CreateBTree2(v1.begin(),v2.begin(),v1.size());
  PostOrder(root);
  //if(IsComBinTree(root))
  //  cout<<"is complete bin tree"<<endl;
  //else 
  //  cout<<"is not complete bin tree"<<endl;
  //cout<<"Height:"<<BTreeHeight(root)<<endl;
  //cout<<"Leaf:"<<BTreeLeafNode(root)<<endl;
  //cout<<"NodeCount:"<<BTreeNodeCount(root)<<endl;
  //cout<<"K = 4:"<<BTreeKCount(root,4)<<endl;
  //printf("find 'G':%c\n",IsNodeInBTree(root,'G')->data);
  //printf("find 'G' parent:%c\n",FindParentNode(root,IsNodeInBTree(root,'G'))->data);
  //cout<<"MirrorBTree:"<<endl;
  //MirrorBTree(&root);
  //LevelOrder(root);
  //MidOrder(root);
  //cout<<endl;
  //PostOrder(root);
  //cout<<endl;
  //BTNode *p = BTNodeCopy(root);
  //PostOrder(p);
  BTNodeDestroy(&root);
  PreOrder(root);
}

int main()
{
  Test1();
  return 0;
}
