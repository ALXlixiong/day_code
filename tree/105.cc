#include <iostream>
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
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

		return _buildTree(preorder.begin(), inorder.begin(), preorder.size());
	}
	TreeNode *_buildTree(vector<int>::iterator pre, vector<int>::iterator in, int size)
	{
		if (size == 0)
			return nullptr;
		int pos = 0;
		for (int i = 0; i<size; ++i)
		{
			if (in[i] == pre[0])
			{
				pos = i;
				break;
			}
		}

		TreeNode *root = new TreeNode(pre[0]);
		root->left = _buildTree(pre + 1, in, pos);
		root->right = _buildTree(pre + pos + 1, in + pos + 1, size - pos - 1);
		return root;
	}
};

int main()
{
	vector<int> v1{ 1, 2, 3 };
	vector<int> v2{ 3, 2, 1 };
  Solution s;
	TreeNode *ret = s.buildTree(v1, v2);
	return 0;
}
