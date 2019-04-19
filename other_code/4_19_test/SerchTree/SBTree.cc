#include <iostream>
#include <vector>
#include <assert.h>

typedef struct BSTree
{
  int data;
  struct BSTree *pLeft;
  struct BSTree *pRight;
}BSTree;

int BSTreeFind(BSTree *root,int data)
{
  if(root == nullptr)
    return -1;
  if(root->data == data)
    return 0;
  else if(root->data<data)
    return BSTreeFind(root->pRight,data);
  else 
    return BSTreeFind(root->pLeft,data);
}

int BSTreeFindNor(BSTree *root,int data)
{
  BSTree *cur = root;
  while(cur != nullptr)
  {
    if(cur->data == data)
      return 0;
    else if(cur->data > data)
      cur = cur->pLeft;
    else 
      cur = cur->pRight;
  }
  return -1;
}
//1、空树直接插入
//2、先查找该元素是否存在，如果存在插入失败
//3、当查找到最后为nullptr进行插入，当然需要记录插入节点的父节点
int BSTreeInsert(BSTree**root,int data)
{
  BSTree *newNode = new BSTree;
  newNode->data = data;
  if(*root == nullptr)
  {
    *root = newNode;
    return 0;
  }
  BSTree *cur = *root;
  if(cur->data == data)
    return -1;
  else if(data>cur->data)
    return BSTreeInsert(&((*root)->pRight),data);
  else 
    return BSTreeInsert(&((*root)->pLeft),data);
}

int BSTreeInsertNor(BSTree**root,int data)
{
  assert(root);
  BSTree *cur = *root;
  BSTree *parent = nullptr;
  //查找，如果有重复插入失败
  while(cur != nullptr)
  {
    if(cur->data == data)
      return -1;
    parent = cur;
    if(cur->data>data)
      cur = cur->pLeft;
    else if(cur->data < data)
      cur = cur->pRight;
  }
  BSTree *newNode = new BSTree;
  newNode->data = data;
  //空树
  if(parent == nullptr)
  {
    *root = newNode;
    return 0;
  }
  // 
  if(data>parent->data)
    parent->pRight = newNode;
  else 
    parent->pLeft = newNode;
  return 0;
}
#include <queue>
void LevelPrint(BSTree *root)
{
  if(root == nullptr)
    return;
  std::queue<BSTree *> s;
  s.push(root);
  while(!s.empty())
  {
    BSTree *cur = s.front();
    s.pop();
    std::cout<<cur->data<<" ";
    if(cur->pLeft != nullptr)
      s.push(cur->pLeft);
    if(cur->pRight != nullptr)
      s.push(cur->pRight);
  }
  std::cout<<std::endl;
}

int BSTreeDelete(BSTree **root,int data)
{
  assert(root);
  BSTree *cur = *root;
  BSTree *parent = nullptr;
  while(cur != nullptr)
  {
    if(cur->data == data)
    {
      if(cur->pLeft == nullptr)
      {
        if(parent == nullptr)
          *root = cur->pRight;
        else{
          if(data > parent->data){
            parent->pRight = cur->pRight;
          }
          else if(data < parent->data){
            parent->pLeft = cur->pRight;
          }
        }
        delete cur;
        cur = nullptr;
        return 0;
      }
      else if(cur->pRight == nullptr)
      {
        if(parent == nullptr)
          *root = cur->pLeft;
        else{
          if(data>parent->data){
            parent->pRight = cur->pLeft;
          }
          else if(data<parent->data){
            parent->pLeft = cur->pLeft;
          }
        }
        delete cur;
        cur = nullptr;
        return 0;
      }
      else{
        //替换删除
        parent = cur;
        cur = cur->pRight;
        while(cur ->pLeft != nullptr)
          cur = cur->pLeft;
        parent->data = cur->data;
        if(cur == parent->pRight)
          parent->pRight = cur->pRight;
        delete cur;
        cur = nullptr;
        return 0;
      }
    }
    parent = cur;
    if(data < cur->data)
      cur = cur->pLeft;
    else 
      cur = cur->pRight;
  }
  return -1;
}

void Test()
{
  BSTree *root = nullptr;
  BSTreeInsert(&root,5);
  BSTreeInsert(&root,6);
  BSTreeInsert(&root,4);
  BSTreeInsert(&root,2);
  BSTreeInsert(&root,1);
  BSTreeInsert(&root,0);
  BSTreeInsert(&root,7);
  BSTreeInsert(&root,9);
  BSTreeInsert(&root,8);
  BSTreeInsert(&root,10);
  LevelPrint(root);
  std::cout<<BSTreeFind(root,8)<<std::endl;
  std::cout<<BSTreeFind(root,30)<<std::endl;
  BSTreeDelete(&root,1);
  BSTreeDelete(&root,5);
  BSTreeDelete(&root,10);
  BSTreeDelete(&root,8);
  BSTreeDelete(&root,9);
  BSTreeDelete(&root,0);
  LevelPrint(root);
}

int main()
{
  Test();
  return 0;
}
