/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//分析：给定一个非空节点，最终路径经过这个节点有4种情况：1.只有该节点本身（左右子树的路径都是负数）；2.该节点+左子树路径；3.该节点+右子树路径；4.该节点+左子树路径+右子树路径。其中1，2，3都可以作为子树路径和向上延伸，而4则不行。
class Solution {
public:
    int ret = INT_MIN;
    int maxPathSum(TreeNode* root) {
        if(root == nullptr)
            return 0;
        _maxPathSum(root);
        return ret;
    }
    
    int _maxPathSum(TreeNode *root)
    {
        if(root == nullptr)
            return 0;
        int left = _maxPathSum(root->left);
        int right = _maxPathSum(root->right);
        int tmp = max(max(left+root->val,right+root->val),root->val);
        ret = max(max(tmp,root->val+left+right),ret);
        return tmp;
    }
};
