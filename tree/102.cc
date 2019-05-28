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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode *> q1;
        queue<TreeNode *> q2;
        vector<vector<int>> ret;
        if(root == nullptr)
            return ret;
        q1.push(root);
        while(!q1.empty() || !q2.empty())
        {
            vector<int> tmp;
            while(!q1.empty())
            {
                TreeNode *top = q1.front();
                q1.pop();
                tmp.push_back(top->val);
                if(top->left)
                    q2.push(top->left);
                if(top->right)
                    q2.push(top->right);
            }
            ret.push_back(tmp);
            q1.swap(q2);
        }
        return ret;
    }
};
