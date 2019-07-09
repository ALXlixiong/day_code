#include <iostream>

template<class K,class V>
struct AVLTreeNode
{
    AVLTreeNode<K,V> *right_;
    AVLTreeNode<K,V> *left_;
    AVLTreeNode<K,V> *parent_;
    std::pair<K,V> val_;
    int bf_;

    AVLTreeNode(K first,V second):val_(first,second),bf_(0),right_(nullptr),left_(nullptr),parent_(nullptr)
    {}
};

template<class K,class V>
class AVLTree
{
        typedef AVLTreeNode<K,V> Node;
        typedef Node* PNode;
    private:
        PNode Root_;
    public:
        AVLTree():Root_(nullptr)
    {}

        bool insert(K first,V second)
        {
            if(Root_ == nullptr)
            {
                Root_ = new Node(first,second);
                return true;
            }

            PNode pCur = Root_;
            pNode pParent = nullptr;
            while(pCur)
            {
                pParent = pCur;
                if(pCur->val_.first == first)
                    return false;
                else if(first>pCur->val_.first)
                    pCur = pCur->right_;
                else
                    pCur = pCur->left_;
            }
            pCur  = new Node(first,second);
            if(pParent->val_.first > first)
            {
               pParent->left_ = pCur;
               pCur->parent_ = pParent;
            }
            else
            {
                pParent->right_ = pCur;
                pCur->parent_ = pParent;
            }

            while(pParent)
            {
               if(pParent->left_ == pCur)
                   pParent->bf_--;
               else
                   pParent->bf_++;

               if(pParent->bf_ == 0)
                   break;
               else if(pParent->bf_ == -1 || pParent->bf_ == 1)
               {
                   pCur = pParent;
                   pParent = pParent->parent_;
               }
               else if(pParent->bf_ == -2 || pParent->bf_ == 2)
               {

               }
            }
        }
    private:
        
};
