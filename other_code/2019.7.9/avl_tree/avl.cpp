#include <iostream>

template<class K,class V>
struct AVLTreeNode
{
    AVLTreeNode<K,V> *right_;
    AVLTreeNode<K,V> *left_;
    AVLTreeNode<K,V> *parent_;
    std::pair<K,V> val_;

    AVLTreeNode(K first,V second):val_(first,second),right_(nullptr),left_(nullptr),parent_(nullptr)
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

        }
}
