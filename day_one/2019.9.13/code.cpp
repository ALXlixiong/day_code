#include <iostream>
#include <string>

template<class T>
struct BTreeNode
{
	T val_;
	BTreeNode<T> *right_;
	BTreeNode<T> *left_;
	BTreeNode(T val)
		:val_(val)
		, right_(nullptr)
		, left_(nullptr)
	{}
};
template<class T>
class BTree
{
	typedef BTreeNode<T> Node;
	typedef Node* PNode;
public:
	BTree()
		:pRoot_(nullptr)
	{}
	void ConstructBTree(std::string mid, std::string post)
	{
		T *tmp_mid = new T[mid.size()];
		for (int i = 0; i < mid.size(); ++i)
			tmp_mid[i] = mid[i];
		T *tmp_post = new T[post.size()];
		for (int i = 0; i < post.size(); ++i)
			tmp_post[i] = post[i];
		pRoot_ = _ConstructBTree(tmp_mid, tmp_post, mid.size());
	}
	void PreOrder()
	{
		_PreOrder(pRoot_);
	}
private:
	void _PreOrder(PNode root)
	{
		if (root)
		{
			std::cout << root->val_;
			_PreOrder(root->left_);
			_PreOrder(root->right_);
		}
	}
	PNode  _ConstructBTree(T *mid, T* post, int size)
	{
		if (size <= 0)
			return nullptr;
		int pos = 0;
		for (int i = 0; i < size; ++i)
		{
			if (mid[i] == post[size - 1])
			{
				pos = i;
				break;
			}
		}
		PNode node = new Node(post[size-1]);
		node->left_ = _ConstructBTree(mid, post, pos);
		node->right_ = _ConstructBTree(mid + pos + 1, post + pos, size - pos - 1);
		return node;
	}
private:
	PNode pRoot_;
};

int main()
{
	std::string mid = "";
	std::string post = "";
	while (std::cin >> mid >> post)
	{
		BTree<char> b;
		b.ConstructBTree(mid, post);
		b.PreOrder();
	}
	return 0;
}
