/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.empty() || postorder.empty())
            return nullptr;
        return _buildTree(inorder.begin(),postorder.end()-1,postorder.size());
    }
    TreeNode *_buildTree(vector<int>::iterator in,vector<int>::iterator post,int size)
    {
        if(size == 0)
            return nullptr;
        int pos = 0;
        for(int i = 0;i<size;++i)
        {
            if(in[i] == *post)
            {
                pos = i;
                break;
            }
        }
        
        TreeNode *root = new TreeNode(*post);
        root->left = _buildTree(in,post-size+pos,pos);
        root->right = _buildTree(in+pos+1,post-1,size-pos-1);
        return root;
    }
};
