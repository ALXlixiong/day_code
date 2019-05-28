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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        stack<TreeNode *> s1;
        stack<TreeNode *> s2;
        vector<vector<int>> ret;
        if(root == nullptr)
            return ret;
        s1.push(root);
        while(!s1.empty() || !s2.empty())
        {
            vector<int> tmp;
            while(!s1.empty())
            {
                TreeNode *top = s1.top();
                s1.pop();
                tmp.push_back(top->val);
                
                if(top->left)
                    s2.push(top->left);
                if(top->right)
                    s2.push(top->right);
                
            }
            ret.push_back(tmp);
            if(s2.empty())
                break;
            tmp.clear();
            while(!s2.empty())
            {
                TreeNode *top = s2.top();
                s2.pop();
                tmp.push_back(top->val);
                
                if(top->right)
                    s1.push(top->right);
                if(top->left)
                    s1.push(top->left);
            }
            ret.push_back(tmp);
        }
        return ret;
    }
};
