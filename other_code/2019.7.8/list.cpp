#include <iostream>

struct ListNode
{
    int val_;
    ListNode *next_;
    ListNode *pre_;
    ListNode(int val):val_(val),next_(nullptr),pre_(nullptr)
    {}
};

class List
{
    private:
        typedef ListNode* PNode;
    private:
        PNode head_;
    public:
        List(PNode head = nullptr):head_(head)
    {}

        void insert(int val)
        {
            if(head_ == nullptr)
            {
                head_ = new ListNode(val);
                head_->next_ = head_;
                head_->pre_ = head_;
            }
            else
            {
                PNode tmpNode = new ListNode(val);
                tmpNode->next_ = head_->next_;
                tmpNode->pre_ = head_;

                head_->next_ = tmpNode;
                head_->next_->next_->pre_ = tmpNode;
            }
        }
        void Print()
        {
            PNode cur = head_;
            if(cur == nullptr)
                return;
            std::cout<<cur->val_<<" ";
            cur = cur->next_;
            while(cur != head_)
            {
                std::cout<<cur->val_<<" ";
                cur = cur->next_;
            }
            std::cout<<std::endl;
        }
};

int main()
{
    List s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    s.Print();
    return 0;
}


