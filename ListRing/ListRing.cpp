/*
判断单链表是否有环并返回环的入口点
*/

#include <iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};


ListNode* detectCycle(ListNode* head)
{
	if (head == NULL || head->next == NULL)
		return NULL;
	ListNode* slow = head;
	ListNode* fast = head;
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			ListNode* slow2 = head;
			while (slow2 != slow)
			{
				slow = slow->next;
				slow2 = slow2->next;
			}
			return slow;
		}
	}
	return NULL;
}




int main()
{
	ListNode* head = new ListNode(1);
	ListNode* p = head;
	p->next = new ListNode(2);
	p = p->next;
	p->next = new ListNode(3);
	p = p->next;
	p->next = new ListNode(4);
	p = p->next;
	p->next = new ListNode(5);
	p = p->next;
	p->next = head->next->next;
	ListNode* res = detectCycle(head);
	cout << res->val << endl;

	return 0;
}