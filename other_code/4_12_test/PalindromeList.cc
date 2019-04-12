#include <iostream>
using namespace std;
//Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };
 
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return true;
        //复制临时链表
        ListNode *pHead1 = head;
        ListNode *newNode = new ListNode(-1);
        ListNode *cur = newNode;
        while(pHead1)
        {
            cur->next = new ListNode(pHead1->val);
            cur = cur->next;
            pHead1 = pHead1->next;
        }
        pHead1 = head;
        ListNode *pHead2 = newNode->next;
        //临时链表逆置
        ListNode *p1 = nullptr;
        ListNode *p2 = pHead2;
        ListNode *p3 = pHead2->next;
        while(p2)
        {
            p2->next = p1;
            p1 = p2;
            p2 = p3;
            if(p3 != nullptr)
                p3 = p3->next;
        }
        pHead2 = p1;
        //原链表和临时链表一起走
        while(pHead1 && pHead2)
        {
            if(pHead1->val != pHead2->val)
                return false;
            pHead1 = pHead1->next;
            pHead2 = pHead2->next;
        }
        return true;
    } 
};
