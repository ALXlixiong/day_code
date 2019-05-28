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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return _sortedArrayToBST(nums,0,nums.size()-1);
    }
    TreeNode *_sortedArrayToBST(vector<int> &nums,int left,int right)
    {
        if(right<left)
            return nullptr;
        int mid = left + ((right-left)>>1);
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = _sortedArrayToBST(nums,left,mid-1);
        root->right = _sortedArrayToBST(nums,mid+1,right);
        return root;
    }
};
