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

        bool Erase(int val)
        {
            //找到这个节点
            PNode cur = root_;
            PNode parent = nullptr;
            while(cur)
            {
                if(cur->val_ == val)
                    break;
                else if(val > cur->val_)
                {
                    parent = cur;
                    cur = cur->right_;
                }
                else
                {
                    parent = cur;
                    cur = cur->left_;
                }
            }
            if(cur == nullptr)
            {
                std::cout<<val<<"没找到，删除失败\n";
                return false;
            }
            if(cur->left_ == nullptr)
            {
                //根 || 只有右孩子 || 叶子节点
                if(parent == nullptr)
                {
                    root_ = cur->right_;
                    delete cur;
                    cur = nullptr;
                }
                else if(cur->right_ != nullptr)
                {
                    if(cur == parent->left_)
                    {
                        parent->left_ = cur->right_;
                        delete cur;
                        cur = nullptr;
                    }
                    else
                    {
                        parent->right_ = cur->right_;
                        delete cur;
                        cur = nullptr;
                    }
                }
                else
                {
                    if(cur == parent->left_)
                    {
                        parent->left_ = nullptr;
                        delete cur;
                        cur = nullptr;
                    }
                    else
                    {
                        parent->right_ = nullptr;
                        delete cur;
                        cur = nullptr;
                    }
                }
            }
            else if(cur->right_ == nullptr)
            {
                if(parent == nullptr)
                {
                    root_ = cur->left_;
                    delete cur;
                    cur = nullptr;
                }
                else
                {
                    if(cur == parent->left_)
                    {
                        parent->left_ = cur->left_;
                        delete cur;
                        cur = nullptr;
                    }
                    else
                    {
                        parent->right_ = cur->left_;
                        delete cur;
                        cur = nullptr;
                    }
                }
            }
            else
            {
                PNode deletenode = cur->right_;
                PNode parent = cur;
                while(deletenode->left_)
                {
                    parent = deletenode;
                    deletenode = deletenode->left_;
                }
                //特殊情况
                if(deletenode == cur->right_)
                {
                    cur->val_ = deletenode->val_;
                    cur->right_ = deletenode->right_;
                    delete deletenode;
                    deletenode = nullptr;
                }
                else
                {
                    cur->val_ = deletenode->val_;
                    parent->left_ = deletenode->right_;
                    delete deletenode;
                    deletenode = nullptr;
                }
            }
            return true;
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
    if(!b.Insert(3))
        std::cout<<"insert error\n";
    b.InOrder();



    b.Erase(6);
    b.InOrder();

    b.Erase(2);
    b.InOrder();

    b.Erase(4);
    b.InOrder();

    b.Delete();
    return 0;
}
