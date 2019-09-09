//#include <iostream>
//#include <vector>
//#include <stack>
//#include <math.h>
//template<class T>
//struct BTreeNode
//{
//	BTreeNode<T> *right_;
//	BTreeNode<T> *left_;
//	T val_;
//	BTreeNode(T val)
//		:val_(val)
//		, right_(nullptr)
//		, left_(nullptr)
//	{}
//};
//
//template<class T>
//class BTree
//{
//	typedef BTreeNode<T> Node;
//	typedef Node* PNode;
//private:
//	PNode pRoot_;
//public:
//	BTree()
//		:pRoot_(nullptr)
//	{}
//
//	void CreateBTree(std::vector<T> &v)
//	{
//		int index = 0;
//		_CreateBTree(v, index);
//	}
//	void MidOrder()
//	{
//		_MidOrder(pRoot_);
//	}
//private:
//	void _MidOrder(PNode root)
//	{
//		if (root)
//		{
//			_MidOrder(root->left_);
//			std::cout << root->val_ << std::endl;
//			_MidOrder(root->right_);
//		}
//	}
//	void _CreateBTree(std::vector<T> &v, int &index)
//	{
//		std::stack<PNode> s;
//		if (pRoot_ == nullptr)
//		{
//			pRoot_ = new Node(v[index++]);
//			s.push(pRoot_);
//		}
//		while (!s.empty() && index<v.size())
//		{
//			PNode top = s.top();
//			s.pop();
//			top->left_ = new Node(v[index++]);
//			s.push(top->left_);
//			top->right_ = new Node(v[index++]);
//			s.push(top->right_);
//		}
//	}
//};
//
//int main()
//{
//	int size = 0;
//	while (std::cin >> size)
//	{
//		int tmp = pow(2,size) - 1;
//		std::vector<int> v(tmp, 0);
//		for (int i = 0; i < tmp; ++i)
//			std::cin >> v[i];
//		BTree<int> b;
//		b.CreateBTree(v);
//		b.MidOrder();
//	}
//	return 0;
//}

#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
	int memory = 0;
	int count = 0;
	while (std::cin >> memory >> count)
	{
		int tmp = memory;
		std::vector<int> file_size(count, 0);
		std::vector<int> file_like(count, 0);
		for (int i = 0; i < count; ++i)
			std::cin >> file_size[i];
		for (int i = 0; i < count; ++i)
			std::cin >> file_like[i];
		std::vector<std::vector<int>> dp(count, std::vector<int>(memory, 0));

		for (int i = 1; i < count; ++i)
		{
			for (int j = 0; j < memory; ++j)
			{
				if (file_size[i]>j)
					dp[i][j] = dp[i - 1][j];
				else
				{
					dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - file_size[i]] + file_like[i]);
				}
			}
		}
		std::cout << dp[count - 1][tmp - 1] << std::endl;
	}
	return 0;
}
