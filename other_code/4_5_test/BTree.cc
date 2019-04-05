#include<iostream>
using namespace std;
#include<cstring>
#include<queue>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

#include<queue>
class Solution {
public:
    static char* Serialize(TreeNode *root) 
    {
        if(root == nullptr)
            return nullptr;
        queue<TreeNode*> q;
        _Serialize(root,q);
        char* ret = new char[q.size()+1];
        int num = q.size();
        for(int i = 0;i<num;++i)
        {
            if(q.front() == nullptr)
            {
                ret[i] = '#';
            }
            else 
                ret[i] = q.front()->val+'0';
            q.pop();
        }
        ret[num] = '\0';
        return ret;
    }
    static void _Serialize(TreeNode* root,queue<TreeNode*>& q)
    {
        if(root)
        {
            q.push(root);
            _Serialize(root->left,q);
            _Serialize(root->right,q);
        }
        else 
            q.push(nullptr);
    }
    static TreeNode* Deserialize(char *str) 
    {
        if(str == nullptr)
            return nullptr;
        TreeNode *root = nullptr;
        int index = 0;
        _Deserialize(root,str,strlen(str),&index);
        return root;
    }
    static void _Deserialize(TreeNode* &root,char* str,int size,int* index)
    {
        if(*index<size && str[*index] != '#')
        {
            root = new TreeNode(str[*index]-'0');
            cout<<root->val<<" "<<endl;
            ++(*index);
            _Deserialize(root->left,str,size,index);
            ++(*index);
            _Deserialize(root->right,str,size,index);
        }
    }
};
int main()
{
  TreeNode *node1 = new TreeNode(100);
  TreeNode *node2 = new TreeNode(50);
  TreeNode *node3 = new TreeNode(150);
  TreeNode *node4 = new TreeNode(4);
  TreeNode *node5 = new TreeNode(5);
  TreeNode *node6 = new TreeNode(6);

  node1->left = node2;
  node1->right = node3;

  char *str = Solution::Serialize(node1);
  cout<<str<<endl;
  TreeNode *root = Solution::Deserialize(str);
  cout<<root->left->val<<endl;
  cout<<root->right->val<<endl;

  return 0;
}
