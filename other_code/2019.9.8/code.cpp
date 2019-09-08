#include <iostream>
#include <vector>
#include <string>
#if 0
class Node
{
public:
	std::string key_;
	unsigned int value_;
	Node(){}
	Node(std::string key, unsigned int value)
		:key_(key)
		, value_(value)
	{}
	Node& operator=(const Node& node)
	{
		if (&node != this)
		{
			key_ = node.key_;
			value_ = node.value_;
		}
		return *this;
	}
};

class Map
{
public:
	Map(int len)
		:cap_(len)
	{
		map_.resize(len);
		size_ = 0;
	}
	bool Insert(Node node)
	{
		//判断是否存在
		for (int i = 0; i < size_; ++i)
		{
			//存在
			if (map_[i].key_ == node.key_)
			{
				//更新值
				if (map_[i].value_ < node.value_)
				{
					Node newnode(map_[i].key_, node.value_);
					//删除跟新的
					for (int j = i; j < cap_; ++j)
					{
						if (j + 1 < cap_)
							map_[j] = map_[j + 1];
					}
					map_[size_ - 1] = newnode;
					return true;
				}
				else//不需要更新
					return false;
			}
		}
		//空间够
		if (size_ < cap_)
		{
			map_[size_++] = node;
		}
		else
		{
			std::cout << map_[0].key_ << " " << map_[0].value_ << std::endl;
			//删除第一个
			for (int i = 0; i < size_; ++i)
			{
				if (i + 1 < size_)
					map_[i] = map_[i + 1];
			}
			map_[size_ - 1] = node;
		}
		return true;
	}
private:
	std::vector<Node> map_;
	int cap_;
	int size_;
};

int main()
{
	int size = 0;
	while (std::cin >> size)
	{
		Map m(size);
		std::string key = "";
		unsigned int value = 0;
		while (std::cin >> key >> value)
		{
			Node node(key, value);
			m.Insert(node);
		}
	}
	return 0;
}
#endif

template<class T>
struct TreeNode
{
	T val_;
	TreeNode<T> *left_;
	TreeNode<T> *right_;
	TreeNode(T val)
		:left_(nullptr)
		, right_(nullptr)
		, val_(val)
	{}
};
template<class T>
class BTNode
{
	typedef TreeNode<T> Node;
	typedef Node* PNode;
private:
	PNode pRoot_;
public:
	BTNode()
		:pRoot_(nullptr)
	{}
	void CreateBTree(std::vector<std::vector<T>> &v)
	{
		;
	}
};

int main()
{
	int k = 0;
	int line = 0;
	while (std::cin >> k >> line)
	{
		std::vector<std::vector<int>> v(line);
		std::cout << line + 1 << std::endl;
	}
	return 0;
}
