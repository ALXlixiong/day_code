#include <iostream>
typedef struct Node
{
  int data;
  struct Node *left;
  struct Node *right;
}Node;

Node *CreateNode(int data)
{
  Node *newNode = new Node;
  newNode->data = data;
  newNode->left = newNode->right = nullptr;
  return newNode;
}


Node *g_prev = nullptr;

void SBTreeToLink(Node *root)
{
  if(root != nullptr)
  {
    SBTreeToLink(root->left);
    if(g_prev != nullptr)
      g_prev->right = root;
    root->left = g_prev;
    g_prev = root;
    SBTreeToLink(root->right);
  }
}

void Test()
{
  Node *n1 = CreateNode(1);
  Node *n2 = CreateNode(2);
  Node *n3 = CreateNode(3);
  Node *n4 = CreateNode(4);
  Node *n5 = CreateNode(5);
  Node *n6 = CreateNode(6);
  Node *n7 = CreateNode(7);
  n4->left = n2;
  n2->left = n1;
  n2->right = n3;
  n4->right = n5;
  n5->right = n6;
  n6->right = n7;

  SBTreeToLink(n4);
  Node *cur = n1;
  while(cur != nullptr)
  {
    std::cout<<cur->data<<" ";
    cur = cur->right;
  }
  std::cout<<std::endl;
}

int main()
{
  Test();
  return 0;
}
