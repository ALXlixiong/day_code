#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) :
        val(x), next(nullptr) {
    }
};
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    static ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if(pHead == nullptr || pHead->next == nullptr || pHead->next->next == nullptr)
            return nullptr;
        ListNode *slow = pHead;
        ListNode *fast = pHead->next->next;
        while(fast != slow)
        {
            if(fast->next != nullptr && fast->next->next !=nullptr)
            {
                fast = fast->next->next;
                slow = slow->next;
            }
            else 
                return nullptr;
        }
        //包含环
        ListNode *cur = pHead;
        while(cur != slow)
        {
            cur = cur->next;
            slow = slow->next;
        }
        return cur;
    }
};

int main()
{
  ListNode *node1 = new ListNode(1);
  ListNode *node2 = new ListNode(2);
  ListNode *node3 = new ListNode(3);
  ListNode *node4 = new ListNode(4);
  ListNode *node5 = new ListNode(5);
  ListNode *node6 = new ListNode(6);
  ListNode *node7 = new ListNode(7);
  
  node1->next = node2;
  node2->next = node3;
  node3->next = node4;
  node4->next = node5;
  node5->next = node6;
  node6->next = node7;
  node7->next = node3;
  
  ListNode *cur = Solution::EntryNodeOfLoop(node1);
  cout<<"cur "<<cur->val<<endl;
}
