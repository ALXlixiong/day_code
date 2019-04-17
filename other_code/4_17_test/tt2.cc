#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>

#include <queue>
struct ListNode {
    int val;
    ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

struct cmp
{
	bool operator()(ListNode *&left, ListNode* &right)
	{
		return left->val>right->val;
	}
};
class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		//两两合并效率太慢
		//可以把所以值放入multiset中，然后创建新的链表返回节点
		/*multiset<int> s;
		for(size_t i = 0;i<lists.size();++i)
		{
		auto begin = lists[i];
		while(begin != nullptr)
		s.insert(begin->val);
		}
		ListNode *head = new ListNode(-1);
		auto begin = s.begin();
		auto end = s.end();
		ListNode *cur = head->next;
		while(begin != end)
		{
		cur = new ListNode(*begin);
		cur = cur->next;
		}
		return head->next;*/

		//使用最小堆完成
		if (lists.empty())
			return nullptr;
		priority_queue<ListNode*, vector<ListNode*>, cmp> q;
		for (size_t i = 0; i<lists.size(); ++i)
		{
			if (lists[i] != nullptr)
				q.push(lists[i]);
		}
		ListNode *head = new ListNode(-1);
		ListNode *pre = head;
		while (!q.empty())
		{
			ListNode *top = q.top();
			pre->next = top;
			pre = pre->next;
			q.pop();
			if (top->next != nullptr)
				q.push(top->next);
		}
		return head->next;
	}
};
int main()
{
	string s1 = "eat";
	string s2 = "sea";
	vector<int> v{ 1,1,1,1 };
	string s = "25525511135";
	//int ret = Solution::threeSumClosest(v,-100);
	
	return 0;
}

