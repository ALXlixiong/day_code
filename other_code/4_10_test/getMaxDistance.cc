#include <iostream>
using namespace std;
#include <stack>
#include <vector>
#include <algorithm>
struct BTNode
{
	int _val;
	BTNode* _pleft;
	BTNode* _pright;
	BTNode(int val = 0)
		:_val(val)
		, _pleft(nullptr)
		, _pright(nullptr)
	{}
};

class BinTreeNode
{
	typedef BTNode Node;
	typedef Node* PNode;
public:
	BinTreeNode(PNode &root)
		:_root(root)
	{}
	void NorPreOrder()
	{
		_NorPreOrder(GetRoot());
	}
	//获取二叉树中节点之间的最大距离
	int GetMaxDistance()
	{
		PNode root = GetRoot();
		if (root == nullptr)
			return 0;
		int left = _GetMaxDistance(root->_pleft) + 1;
		int right = _GetMaxDistance(root->_pright) + 1;
		return left + right - 1;
	}
	//获取二叉树任意两个节点之间的距离
	//假设二叉树中节点不重复，且存在
	int GetNodeDistance(int val1,int val2)
	{
		//找val，并且保存节点路径
		vector<PNode> path1;
		vector<PNode> path2;
		GetNodePath(GetRoot(),val1, path1);
		GetNodePath(GetRoot(),val2, path2);
		//找到两个路径中最后一次出现的相等节点
		int pos = 0;
		for (size_t i = 0; i < min(path1.size(), path2.size()); ++i)
		{
			if (path1[i] == path2[i])
				pos = i;
		}
		return path1.size() - 1 - pos + path2.size() - 1 - pos;
	}
private:
	//找节点，保存路径
	bool GetNodePath(PNode root, int val, vector<PNode> &path)
	{
		if (root == nullptr)
			return false;
		if (root->_val == val)
		{
			path.push_back(root);
			return true;
		}
		path.push_back(root);
		bool tmp1 = GetNodePath(root->_pleft, val, path);
		if (!tmp1)
		{
			//如果左子树没有找到，还不能直接pop，需要判断当前节点的右子树里面是否有，没有则pop
			bool tmp2 = GetNodePath(root->_pright, val, path);
			if (!tmp2)
				path.pop_back();
			return tmp2;
		}
		return tmp1;
	}
	static void _NorPreOrder(PNode root)
	{
		if (root == nullptr)
			return;
		stack<PNode> s;
		while (root != nullptr || !s.empty())
		{
			while (root != nullptr)
			{
				cout << root->_val << " ";
				s.push(root);
				root = root->_pleft;
			}
			PNode top = s.top();
			s.pop();
			root = top->_pright;
		}
		cout << endl;
	}
	static int _GetMaxDistance(PNode root)
	{
		if (root == nullptr)
			return 0;
		int leftHeight = _GetMaxDistance(root->_pleft);
		int rightHeight = _GetMaxDistance(root->_pright);
		return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
	}
	PNode GetRoot()
	{
		return _root;
	}
private:
	PNode _root;
};
int main()
{
	BTNode *node1 = new BTNode(1);
	BTNode *node2 = new BTNode(2);
	BTNode *node3 = new BTNode(3);
	BTNode *node4 = new BTNode(4);
	BTNode *node5 = new BTNode(5);
	BTNode *node6 = new BTNode(6);
	BTNode *node7 = new BTNode(7);
	BTNode *node8 = new BTNode(8);
	node1->_pleft = node2;
	node1->_pright = node3;
	node2->_pleft = node4;
	node3->_pleft = node5;
	node3->_pright = node6;
	node2->_pright = node7;
	node7->_pleft = node8;

	BinTreeNode b(node1);
	b.NorPreOrder();
	cout << b.GetMaxDistance() << endl;
	cout <<"两个节点之间的距离"<< b.GetNodeDistance(7,8) << endl;
	return 0;
}

