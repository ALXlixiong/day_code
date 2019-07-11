#include <iostream>
#include <vector>

template<class K, class V>
struct AVLTreeNode
{
    AVLTreeNode<K, V> *right_;
    AVLTreeNode<K, V> *left_;
    AVLTreeNode<K, V> *parent_;
    std::pair<K, V> val_;
    int bf_;

    AVLTreeNode(K first, V second) :val_(first, second), bf_(0), right_(nullptr), left_(nullptr), parent_(nullptr)
    {}
};

template<class K, class V>
class AVLTree
{
    typedef AVLTreeNode<K, V> Node;
    typedef Node* PNode;
    private:
    PNode Root_;
    public:
    AVLTree() :Root_(nullptr)
    {}

    bool insert(K first, V second)
    {
        if (Root_ == nullptr)
        {
            Root_ = new Node(first, second);
            return true;
        }

        PNode pCur = Root_;
        PNode pParent = nullptr;
        while (pCur)
        {
            pParent = pCur;
            if (pCur->val_.first == first)
                return false;
            else if (first > pCur->val_.first)
                pCur = pCur->right_;
            else
                pCur = pCur->left_;
        }
        pCur = new Node(first, second);
        if (pParent->val_.first > first)
        {
            pParent->left_ = pCur;
            pCur->parent_ = pParent;
        }
        else
        {
            pParent->right_ = pCur;
            pCur->parent_ = pParent;
        }

        while (pParent)
        {
            if (pParent->left_ == pCur)
                pParent->bf_--;
            else
                pParent->bf_++;

            if (pParent->bf_ == 0)
                break;
            else if (pParent->bf_ == -1 || pParent->bf_ == 1)
            {
                pCur = pParent;
                pParent = pParent->parent_;
            }
            else if (pParent->bf_ == -2 || pParent->bf_ == 2)
            {
                if (pParent->bf_ == 2)
                {
                    if (pParent->right_->bf_ == 1)
                        RotateLeft(pParent);
                    else
                        RightRotateLeft(pParent);
                }
                else
                {
                    if (pParent->left_->bf_ == -1)
                        RotateRight(pParent);
                    else
                        LeftRotateRight(pParent);
                }
            }
        }
        return true;
    }
    void InOrder()
    {
        _InOrder(Root_);
        std::cout << std::endl;
    }
    private:
    void _InOrder(PNode root)
    {
        if (root)
        {
            _InOrder(root->left_);
            std::cout << root->val_.first<< " ";
            _InOrder(root->right_);
        }
    }
    void RotateRight(PNode &pParent)
    {
        PNode pSubL = pParent->left_;
        PNode pSubLR = pSubL->right_;

        PNode ppParent = pParent->parent_;

        pSubL->right_ = pParent;
        pParent->left_ = pSubLR;
        pSubL->parent_ = ppParent;
        if (pSubLR)
            pSubLR->parent_ = pParent;
        pParent->parent_ = pSubL;

        if (ppParent == nullptr)
        {
            Root_ = pSubL;
            pSubL->parent_ = nullptr;///
        }
        else
        {
            if (ppParent->left_ == pParent)
                ppParent->left_ = pSubL;
            else
                ppParent->right_ = pSubL;
        }
        pParent->bf_ = pSubL->bf_ = 0;
    }
    void RotateLeft(PNode &pParent)
    {
        PNode pSubR = pParent->right_;
        PNode pSubRL = pSubR->left_;

        PNode ppParent = pParent->parent_;

        if (pSubRL != nullptr)
            pSubRL->parent_ = pParent;
        pParent->right_ = pSubRL;
        pParent->parent_ = pSubR;
        pSubR->left_ = pParent;
        pSubR->parent_ = ppParent;

        if (ppParent == nullptr)
        {
            Root_ = pSubR;
            pSubR->parent_ = nullptr;
        }
        else
        {
            if (ppParent->left_ == pParent)
                ppParent->left_ = pSubR;
            else
                ppParent->right_ = pSubR;
        }
        pParent->bf_ = pSubR->bf_ = 0;
    }
    void LeftRotateRight(PNode &pParent)
    {
        RotateLeft(pParent->left_);
        RotateRight(pParent);
    }
    void RightRotateLeft(PNode &pParent)
    {
        RotateRight(pParent->right_);
        RotateLeft(pParent);
    }
};

void TestAvl()
{
    AVLTree<int, int> t;
    std::vector<int> v{ 1,2,3,4,5,6,7,8 };
    for (int i = 0; i < v.size(); ++i)
    {
        t.insert(v[i], v[i]);
    }
    t.InOrder();
}

int main()
{
    TestAvl();
    return 0;
}

