#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
template<class T>
struct BTreeNode
{
	BTreeNode<T> *left_;
	BTreeNode<T> *right_;
	T val_;

	BTreeNode(T val)
		:val_(val)
		, left_(nullptr)
		, right_(nullptr)
	{}
};

template<class T>
struct BTree
{
	typedef BTreeNode<T> Node;
	typedef Node* PNode;
public:
	BTree()
		:pRoot_(nullptr)
	{}
	void CreateBTree(std::vector<T> &v, T invalid)
	{
		size_t index = 0;
		_CreateBTree(v, pRoot_, index, invalid);
	}
	void PreOrder()
	{
		_PreOrder(pRoot_);
		std::cout << "\n";
	}

	void InOrder()
	{
		_InOrder(pRoot_);
		std::cout << "\n";
	}

	void PostOrder()
	{
		_PostOrder(pRoot_);
		std::cout << "\n";
	}
	//非递归前序遍历
	void RPreOrder()
	{
		_RPreOrder(pRoot_);
	}
	//非递归中序遍历
	void RInOrder()
	{
		_RInOrder(pRoot_);
	}
	//非递归后续遍历
	void RPostOrder()
	{
		_RPostOrder(pRoot_);
	}
	//层序遍历
	void CengOrder()
	{
		_CengOrder(pRoot_);
	}
	//二叉树右视图
	std::vector<T> RightView()
	{
		return _RightView(pRoot_);
	}

	//二叉树销毁
	void DestoryTree()
	{
		_DestoryTree(pRoot_);
	}
	//求二叉树高度
	int HeightTree()
	{
		return _HeightTree(pRoot_);
	}

	//求二叉树叶子结点个数
	int LeafNumberTree()
	{
		return _LeafNumberTree(pRoot_);
	}

	//求二叉树节点的个数
	int GetTreeNode()
	{
		return _GetTreeNode(pRoot_);
	}
	//求二叉树第K层节点个数
	int KNodeNumberTree(int k)
	{
		return _KNodeNumberTree(pRoot_,k);
	}

	//判断一个节点是否在二叉树
	PNode FindNodeTree(T val)
	{
		return _FindNodeTree(pRoot_, val);
	}

	//找一个节点的双亲
	PNode FindNodeParentTree(T val)
	{
		return _FindNodeParentTree(pRoot_, val);
	}
	//求二叉树的镜像
	void MirroBTree()
	{
		_MirroBTree(pRoot_);
	}
	//判断二叉树是否为完全二叉树
	bool JudgeIsCompleteBTree()
	{
		return _JudgeIsCompleteBTree(pRoot_);
	}
	//得到二叉树中两个节点之间最远的距离
	int GetMaxDistance()
	{
		return _GetMaxDistance(pRoot_);
	}
	//判断是否为平衡树
	//条件：1. 每个节点的平衡因子绝对值不超1  2. 每个节点的左子树，右子树也是平衡树  3.空树也是平衡树
	bool JudgeIsAVL()
	{
		return _JudgeIsAVL(pRoot_);
	}

	//已知前序和中序创建二叉树
	void CreateBTree(std::vector<T> Pre,std::vector<T> Mid)
	{
		pRoot_ = _CreateBTree(Pre.begin(),Mid.begin(),Pre.size());
	}

private:
	bool _JudgeIsAVL(PNode root)
	{
		if (root == nullptr)
			return true;
		int leftheight = _HeightTree(root->left_);
		int rightheight = _HeightTree(root->right_);
		if (abs(leftheight - rightheight) <= 1)
			return true;
		else
			return false;
		bool tmp = _JudgeIsAVL(root->left_);
		if (tmp == true)
			return _JudgeIsAVL(root->right_);
		return tmp;//false
	}
	PNode _CreateBTree(typename std::vector<T>::iterator pre, typename std::vector<T>::iterator mid, int size)
	{
		if (size <= 0)
			return nullptr;
		PNode root = new Node(pre[0]);
		int pos = 0;
		for (int i = 0; i < size; ++i)
		{
			if (pre[0] == mid[i])
			{
				pos = i;
				break;
			}
		}
		root->left_ = _CreateBTree( pre + 1, mid, pos);
		root->right_ = _CreateBTree( pre + pos + 1, mid + pos + 1, size - pos - 1);
		return root;
	}
	int _GetMaxDistance(PNode root)
	{
		//最远的距离max(left,right,left+right);
		if (root == nullptr)
			return 0;
		int left_distance = _GetMaxDistance(root->left_);
		int right_distance = _GetMaxDistance(root->right_);

		int leftHeight = _HeightTree(root->left_);
		int rightHeight = _HeightTree(root->right_);
		int root_distance = leftHeight + rightHeight;

		return std::max(left_distance, std::max(right_distance, root_distance));
	}
	bool _JudgeIsCompleteBTree(PNode root)
	{
		PNode cur = root;
		std::queue<PNode> q;
		if (cur)
			q.push(cur);
		while (1)
		{
			cur = q.front();
			q.pop();
			if (cur == nullptr)
				break;
			q.push(cur->left_);
			q.push(cur->right_);
		}
		while (!q.empty())
		{
			cur = q.front();
			if (cur != nullptr)
				return false;
			q.pop();
		}
		return true;
	}
	void _MirroBTree(PNode &root)
	{
		if (root == nullptr)
			return;
		if (root->left_ == nullptr && root->right_ == nullptr)
			return;
		PNode tmp = root->left_;
		root->left_ = root->right_;
		root->right_ = tmp;
		if (root->left_)
			_MirroBTree(root->left_);
		if (root->right_)
			_MirroBTree(root->right_);
	}

	PNode _FindNodeParentTree(PNode root, T val)
	{
		if (root == nullptr)
			return nullptr;
		if ((root->left_&& root->left_->val_ == val) ||
			(root->right_ && root->right_->val_ == val))
			return root;

		PNode tmp = _FindNodeParentTree(root->left_, val);
		if (tmp == nullptr)
			return _FindNodeParentTree(root->right_, val);
		return tmp;
	}
	PNode _FindNodeTree(PNode root, T val)
	{
		if (root == nullptr)
			return nullptr;
		if (root->val_ == val)
			return root;
		PNode leftret = _FindNodeTree(root->left_, val);

		if (leftret == nullptr)
			return _FindNodeTree(root->right_, val);

		return leftret;
	}
	int _KNodeNumberTree(PNode root,int k)
	{
		if (root == nullptr)
			return 0;
		if (k == 1)
			return 1;
		return _KNodeNumberTree(root->left_, k - 1) + _KNodeNumberTree(root->right_, k - 1);
	}
	int _GetTreeNode(PNode root)
	{
		if (root == nullptr)
			return 0;
		return _GetTreeNode(root->left_) + _GetTreeNode(root->right_) + 1;
	}
	int _LeafNumberTree(PNode root)
	{
		if (root == nullptr)
			return 0;
		if (root->left_ == nullptr && root->right_ == nullptr)
			return 1;
		return _LeafNumberTree(root->left_) + _LeafNumberTree(root->right_);
	}
	int _HeightTree(PNode root)
	{
		if (root == nullptr)
			return 0;
		int LeftHeight = _HeightTree(root->left_) + 1;
		int RightHeight = _HeightTree(root->right_) + 1;

		return LeftHeight > RightHeight ? LeftHeight : RightHeight;
	}
	void _DestoryTree(PNode root)
	{
		if (root)
		{
			_DestoryTree(root->left_);
			_DestoryTree(root->right_);
			delete root;
			root = nullptr;
		}
	}

	std::vector<T> _RightView(PNode root)
	{
		std::vector<T> ret;
		std::queue<PNode> q1;
		std::queue<PNode> q2;
		PNode cur = root;
		if (cur != nullptr)
			q1.push(cur);
		while (!q1.empty() || !q2.empty())
		{
			while (q1.size() != 1)
			{
				cur = q1.front();
				q1.pop();
				if (cur->left_)
					q2.push(cur->left_);
				if (cur->right_)
					q2.push(cur->right_);
			}
			cur = q1.front();
			q1.pop();
			ret.push_back(cur->val_);
			if (cur->left_)
				q2.push(cur->left_);
			if (cur->right_)
				q2.push(cur->right_);
			q1.swap(q2);
		}
		return ret;
	}
	void _CengOrder(PNode root)
	{
		std::queue<PNode> q;
		PNode cur = root;
		if (cur != nullptr)
			q.push(cur);
		while (!q.empty())
		{
			cur = q.front();
			q.pop();
			std::cout << cur->val_ << " ";
			if (cur->left_)
				q.push(cur->left_);
			if (cur->right_)
				q.push(cur->right_);
		}
	}
	void _RPostOrder(PNode root)
	{
		std::stack<PNode> s;
		PNode flag = nullptr;
		while (root || !s.empty())
		{
			while (root)
			{
				s.push(root);
				root = root->left_;
			}
			PNode top = s.top();
			if (top->right_ == nullptr || flag == top->right_)
			{
				std::cout << top->val_ << " ";
				flag = top;
				s.pop();
			}
			else
				root = top->right_;
		}
	}
	void _RInOrder(PNode root)
	{
		std::stack<PNode> s;
		while (root || !s.empty())
		{
			while (root)
			{
				s.push(root);
				root = root->left_;
			}
			root = s.top();
			std::cout << root->val_ << " ";
			s.pop();
			root = root->right_;
		}
		std::cout << "\n";
	}
	void _RPreOrder(PNode root)
	{
		std::stack<PNode> s;
		while (root || !s.empty())
		{
			while (root)
			{
				std::cout << root->val_ << " ";
				s.push(root);
				root = root->left_;
			}
			root = s.top();
			s.pop();
			root = root->right_;
		}
		std::cout << "\n";
	}
	void _PostOrder(PNode root)
	{
		if (root)
		{
			_PostOrder(root->left_);
			_PostOrder(root->right_);
			std::cout << root->val_ << " ";
		}
	}
	void _InOrder(PNode root)
	{
		if (root)
		{
			_InOrder(root->left_);
			std::cout << root->val_ << " ";
			_InOrder(root->right_);
		}
	}


	void _CreateBTree(std::vector<T> &v, PNode &root, size_t &index, T invalid)
	{
		if (index >= v.size() || v[index] == invalid)
			return;
		if (root == nullptr)
		{
			root = new Node(v[index]);
			++index;
			_CreateBTree(v, root->left_, index, invalid);
			++index;
			_CreateBTree(v, root->right_, index, invalid);
		}
	}

	void _PreOrder(PNode root)
	{
		if (root)
		{
			std::cout << root->val_ << " ";
			_PreOrder(root->left_);
			_PreOrder(root->right_);
		}
	}
private:
	PNode pRoot_;
};
