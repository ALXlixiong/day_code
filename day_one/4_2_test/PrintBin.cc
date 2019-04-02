#include<iostream>
using namespace std;
#include<queue>
struct TreeNode 
{
  struct TreeNode *left;
  struct TreeNode *right;
  int val;
  TreeNode(int x)
    :val(x),left(nullptr),right(nullptr)
  {}
};
class Solution {
  public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
      vector<int> ret;
      if(root == nullptr)
        return ret;
      queue<TreeNode*> q;
      q.push(root);
      while(!q.empty())
      {
        ret.push_back(q.front()->val);
        TreeNode *top = q.front();
        q.pop();
        if(top->left != nullptr)
          q.push(top->left);
        if(top->right != nullptr)
          q.push(top->right);
      }
      return ret;
    }
};
