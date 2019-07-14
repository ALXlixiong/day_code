/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       if(l1 == nullptr || l2 == nullptr)
           return nullptr;
        ListNode *cur1 = l1;
        ListNode *cur2 = l2;
        int flag = 0;
        ListNode *ret = new ListNode(-1);
        ListNode *cur = ret;
        while(cur1 != nullptr && cur2 != nullptr)
        {
            int tmp = cur1->val + cur2->val + flag;
            int num = tmp%10;
            ListNode *node = new ListNode(num);
            cur->next = node;
            cur = cur->next;
            flag = tmp/10;
            
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        
        while(cur1 != nullptr)
        {
            int tmp = cur1->val + flag;
            int num = tmp%10;
            ListNode *node = new ListNode(num);
            cur->next = node;
            cur = cur->next;
            flag = tmp/10;
            cur1 = cur1->next;
        }
        while(cur2 != nullptr)
        {
            int tmp = cur2->val + flag;
            int num = tmp%10;
            ListNode *node = new ListNode(num);
            cur->next = node;
            cur = cur->next;
            flag = tmp/10;
            cur2 = cur2->next;
        }
        if(flag != 0)
        {
            ListNode *cur = ret->next;
            while(cur->next != nullptr)
                cur = cur->next;
            cur->next = new ListNode(flag);
        }
        return ret->next;
    }
};
