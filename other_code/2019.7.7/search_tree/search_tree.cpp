#include <iostream>

template<class T>
struct BTreeNode
{
    BTreeNode<T>* right_;
    BTreeNode<T>* left_;
    T val_;
    BTreeNode(int val):val_(val),right_(nullptr),left_(nullptr)
    {}
};

template<class T>
class BTree
{
        typedef BTreeNode<T> Node;
        typedef Node* PNode;
    private:
        PNode root_;
    public:
        BTree():root_(nullptr)
    {}
        PNode Find(int val)
        {
            PNode cur = root_;
            while(cur != nullptr)
            {
                if(cur->val_ == val)
                    return cur;
                else if(cur->val_>val)
                    cur = cur->left_;
                else
                    cur = cur->right_;
            }
            return nullptr;
        }

        bool Insert(int val)
        {
            //找到需要插入的位置
            //记录父节点
            PNode cur = root_;
            PNode parent = nullptr;
            while(cur)
            {
                parent = cur;
                if(cur->val_ == val)
                    return false;
                else if(cur->val_>val)
                    cur = cur->left_;
                else
                    cur = cur->right_;
            }
            if(parent == nullptr)
            {
                root_ = new Node(val);
                return true;
            }
            else
            {
                if(val>parent->val_)
                    parent->right_ = new Node(val);
                else
                    parent->left_ = new Node(val);
            }
            return true;
        }
        void InOrder()
        {
            _InOrder(root_);
            std::cout<<std::endl;
        }

        void Delete()
        {
            _Delete(root_);
        }
    private:
        void _InOrder(PNode &root)
        {
            if(root)
            {
                _InOrder(root->left_);
                std::cout<<root->val_<<" ";
                _InOrder(root->right_);
            }
        }
        void _Delete(PNode &root)
        {
            if(root)
            {
                _Delete(root->left_);
                _Delete(root->right_);
                delete root;
                root = nullptr;
            }
        }
};

int main()
{
    BTree<int> b;
    b.Insert(6);
    b.Insert(4);
    b.Insert(5);
    b.Insert(8);
    b.Insert(9);
    b.Insert(7);
    b.Insert(2);
    b.Insert(3);
    b.InOrder();
    return 0;
}
