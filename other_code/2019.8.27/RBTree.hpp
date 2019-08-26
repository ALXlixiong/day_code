#include <algorithm>
enum Color
{
    RED,
    BLACK
};
template<class T>
struct RBTreeNode
{
    RBTreeNode<T> *right_;
    RBTreeNode<T> *left_;
    RBTreeNode<T> *parent_;
    Color color_;
    T data_;

    RBTreeNode(T data, Color color = RED)
        :right_(nullptr)
         , left_(nullptr)
         , parent_(nullptr)
         , color_(color)
         , data_(data)
    {}
};

template<class T>
class RBTree
{
    typedef RBTreeNode<T> Node;
    typedef Node* PNode;
    private:
    PNode pRoot_;
    public:
    RBTree()
        :pRoot_(nullptr)
    {}
    void Insert(T data, Color color = RED)
    {
        if (pRoot_ == nullptr)
        {
            pRoot_ = new Node(data, color);
        }
        else
        {
            PNode cur = pRoot_;
            PNode pParent = nullptr;
            while (cur)
            {
                pParent = cur;
                if (data > cur->data_)
                    cur = cur->right_;
                else if (data < cur->data_)
                    cur = cur->left_;
                else
                    return;
            }
            cur = new Node(data, color);
            if (data>pParent->data_)
            {
                pParent->right_ = cur;
                cur->parent_ = pParent;
            }
            else
            {
                pParent->left_ = cur;
                cur->parent_ = pParent;
            }

            //如果插入节点的颜色和父节点颜色相同，都是红色，违背条件
            //需要向上调整
            while(pParent && pParent->color_ == RED)
            {
                PNode grandFather = pParent->parent_;
                if (pParent == grandFather->left_)
                {
                    PNode uncle = grandFather->right_;
                    //情况一
                    if (uncle && uncle->color_ == RED)
                    {
                        grandFather->color_ = RED;
                        pParent->color_ = BLACK;
                        uncle->color_ = BLACK;
                        cur = grandFather;
                        pParent = cur->parent_;
                    }
                    else
                    {
                        //情况二 和 情况三
                        if (cur == pParent->right_)
                        {
                            RotateLeft(pParent);
                            std::swap(cur, pParent);
                        }

                        RotateRight(grandFather);
                        pParent->color_ = BLACK;
                        grandFather->color_ = RED;
                        cur->color_ = RED;
                    }
                }
                else
                {
                    PNode uncle = grandFather->left_;
                    if (uncle && uncle->color_ == RED)
                    {
                        grandFather->color_ = RED;
                        uncle->color_ = BLACK;
                        pParent->color_ = BLACK;
                        cur = grandFather;
                        pParent = cur->parent_;
                    }
                    else
                    {
                        if (cur == pParent->left_)
                        {
                            RotateRight(pParent);
                            std::swap(pParent, cur);
                        }

                        RotateLeft(grandFather);
                        pParent->color_ = BLACK;
                        grandFather->color_ = cur->color_ = RED;
                    }
                }
            }
        }
        //最终修改根节点为黑色
        pRoot_->color_ = BLACK;
    }
    private:
    void RotateLeft(PNode pParent)
    {
        PNode pSubR = pParent->right_;
        PNode pSubRL = pSubR->left_;

        if (pSubRL)
            pSubRL->parent_ = pParent;
        pParent->right_ = pSubRL;

        PNode ppParent = pParent->parent_;
        if (ppParent == nullptr)
        {
            pRoot_ = pSubR;
            pSubR->parent_ = nullptr;
        }
        else
        {
            if (pParent == ppParent->left_)
                ppParent->left_ = pSubR;
            else
                ppParent->right_ = pSubR;
        }
        pSubR->parent_ = ppParent;
        pParent->parent_ = pSubR;
        pSubR->left_ = pParent;
    }
    void RotateRight(PNode pParent)
    {
        PNode pSubL = pParent->left_;
        PNode pSubLR = pSubL->right_;
        if (pSubLR != nullptr)
            pSubLR->parent_ = pParent;
        pParent->left_ = pSubLR;
        PNode ppParent = pParent->parent_;
        if (ppParent == nullptr)
        {
            pRoot_ = pSubL;
            pSubL->parent_ = nullptr;
        }
        else
        {
            if (pParent == ppParent->left_)
                ppParent->left_ = pSubL;
            else
                ppParent->right_ = pSubL;
        }
        pSubL->parent_ = ppParent;
        pParent->parent_ = pSubL;
        pSubL->right_ = pParent;
    }
};
