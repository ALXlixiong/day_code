#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//class Solution {
//public:
//
//	int findSecondMinimumValue(TreeNode* root) {
//		int min = 0;
//		stack<TreeNode *> s;
//		TreeNode *cur = root;
//		bool flag = false;
//		while (cur != nullptr && !s.empty())
//		{
//			while (cur)
//			{
//				s.push(cur);
//				if (!flag)
//					min = cur->val;
//				cur = cur->left;
//			}
//			flag = true;
//			TreeNode *top = s.top();
//			s.pop();
//			if (top->val>min)
//				return top->val;
//			cur = top->right;
//		}
//		return -1;
//	}
//};
//
//class Solution {
//public:
//	TreeNode *head = nullptr;
//	TreeNode* increasingBST(TreeNode* root) {
//		if (!root)
//			return root;
//		head = new TreeNode(-1);
//		TreeNode *ret = head;
//		_increasingBST(root);
//		return ret->right;
//	}
//
//	void _increasingBST(TreeNode *root)
//	{
//		if (root)
//		{
//			_increasingBST(root->left);
//			head->right = root;
//			head = head->right;
//			_increasingBST(root->right);
//		}
//	}
//};
//int main()
//{
//	vector<int> v1{ 1, 2, 3 };
//	vector<int> v2{ 3, 2, 1 };
//	Solution s;
//	TreeNode *node1 = new TreeNode(2);
//	TreeNode *node2 = new TreeNode(2);
//	TreeNode *node3 = new TreeNode(5);
//	TreeNode *node4 = new TreeNode(5);
//	TreeNode *node5 = new TreeNode(7);
//
//	node1->left = node2;
//	node1->right = node3;
//	node3->left = node4;
//	node3->right = node5;
//	TreeNode *ret = s.increasingBST(node1);
//	return 0;
//}

//#include <set>
//
//int main()
//{
//	set<int> s;
//	s.insert(10);
//	s.insert(1);
//	s.insert(7);
//	s.insert(5);
//	for (auto it : s)
//		cout << it << endl;
//	return 0;
//}
class Codec {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		//前序遍历实现序列化
		if (root == nullptr)
			return "";
		string ret = "";
		_serialize(root, ret);
		return ret;
	}
	void _serialize(TreeNode *root, string &ret)
	{
		if (root == nullptr)
			ret += "#";
		else
		{
			ret += root->val + '0';

			_serialize(root->left, ret);
			_serialize(root->right, ret);
		}
	}
	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		//使用前序遍历构建二叉树
		if (data == "")
			return nullptr;
		TreeNode *root = nullptr;
		int index = 0;
		_deserialize(&root, data, index);
		return root;
	}

	void _deserialize(TreeNode **root, string data, int &index)
	{
		if (index<data.size() && data[index] != '#')
		{
			*root = new TreeNode(data[index]-'0');
			++index;
			_deserialize(&((*root)->left), data, index);
			++index;
			_deserialize(&((*root)->right), data, index);
		}
	}
};

int main()
{
		TreeNode *node1 = new TreeNode(2);
		TreeNode *node2 = new TreeNode(2);
		TreeNode *node3 = new TreeNode(5);
		TreeNode *node4 = new TreeNode(5);
		TreeNode *node5 = new TreeNode(7);
	
		node1->left = node2;
		node1->right = node3;
		node3->left = node4;
		node3->right = node5;

		Codec s;
		string ret = s.serialize(node1);
		TreeNode *node = s.deserialize(ret);
		char a = '-1';
		cout << a - '0' << endl;
		
	return 0;
}


//struct ListNode
//{
//	int _val;
//	ListNode *_pre;
//	ListNode *_next;
//	ListNode(int val) :_val(val), _pre(nullptr), _next(nullptr)
//	{}
//};
//
//class List
//{
//	typedef ListNode Node;
//	typedef Node* PNode;
//
//private:
//	PNode _head;
//public:
//	List()
//		:_head(nullptr)
//	{}
//
//	void InsertNode(int val)
//	{
//		if (_head == nullptr)
//		{
//			_head = new Node(val);
//		}
//		else
//		{
//			PNode cur = _head;
//			while (cur->_next)
//			{
//				cur = cur->_next;
//			}
//			cur->_next = new Node(val);
//			cur->_next->_pre = cur;
//		}
//	}
//	PNode GetHead()
//	{
//		return _head;
//	}
//};
//
//int main()
//{
//	List l;
//	l.InsertNode(1);
//	l.InsertNode(3);
//	l.InsertNode(5);
//	l.InsertNode(6);
//
//	return 0;
//}



