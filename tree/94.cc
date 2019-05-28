#include <iostream>
#include <stack>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode *> s;
        vector<int> ret;
        TreeNode *head = root;
        while(head != nullptr || !s.empty())
        {
            TreeNode *cur = head;
            while(cur != nullptr)
            {
                s.push(cur);
                cur = cur->left;
            }
            TreeNode *top = s.top();
            ret.push_back(top->val);
            s.pop();
            head = top->right;
        }
        return ret;
    }
};
void test()
{
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(3);
    TreeNode *node4 = new TreeNode(4);
    TreeNode *node5 = new TreeNode(5);
    TreeNode *node6 = new TreeNode(6);
    node1->left = node2;
    node2->left = node3;
    node1->right = node4;
    node4->left = node5;
    node5->right = node6;
    
    Solution s;
    vector<int> ret = s.inorderTraversal(node1);
    for(auto e:ret)
        cout<<e<<" ";
    cout<<endl;
}
int main()
{
    test();
    return 0;
}
