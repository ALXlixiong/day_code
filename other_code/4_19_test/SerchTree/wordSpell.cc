#include <iostream>
#include <string>
#include <string.h>
typedef struct Node
{
  std::string word;
  struct Node *pLeft;
  struct Node *pRight;
}Node;

bool Search(Node *root,std::string key)
{
  if(root == nullptr)
    return false;
  int ret = strcmp(key.c_str(),root->word.c_str());
  if(ret == 0)
    return true;
  else if(ret<0)
    return Search(root->pLeft,key);
  else 
    return Search(root->pRight,key);
}

bool Insert(Node **root,std::string key)
{
  if(*root == nullptr)
  {
    Node *newNode = new Node;
    newNode->word = key;
    newNode->pLeft = nullptr;
    newNode->pRight = nullptr;
    *root = newNode;
    return true;
  }
  int ret = strcmp((*root)->word.c_str(),key.c_str());
  if(ret == 0)
    return false;
  else if(ret<0)
    return Insert(&((*root)->pRight),key);
  else 
    return Insert(&((*root)->pLeft),key);
}


void Test()
{
  Node *root = nullptr;
  Insert(&root,"world");
  Insert(&root,"the");
  Insert(&root,"lixiong");
  Insert(&root,"thanks");
  Insert(&root,"word");
  Insert(&root,"apple");
  bool ret = Search(root,"word");
  if(ret == true)
    std::cout<<"find it"<<std::endl;
  else 
    std::cout<<"not exist"<<std::endl;
}

int main()
{
  Test();
  return 0;
}
