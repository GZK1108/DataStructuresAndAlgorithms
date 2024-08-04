/*
回文数[12321]
*/

#include <iostream>
using namespace std;

//结构体
class Node
{
public:
	int value;
	Node* next;
	Node(int value)
	{
		this->value = value;
	}
};

//判断是否是回文数
bool isHuiwen(Node* head)
{
	if (head == NULL || head->next == NULL)
	{
		return true;
	}
	//快慢指针
	Node* slow = head;
	Node* fast = head;
	//快指针走到尽头，慢指针走到中间
	while (fast->next != NULL && fast->next->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	//右半部分的第一个节点
	Node* right = slow->next;
	//右半部分的第一个节点的下一个节点
	slow->next = NULL;
	//右半部分的第一个节点
	Node* next = NULL;
	//右半部分反转，这里right可能有问题
	while (right != NULL)
	{
		next = right->next;
		right->next = slow;
		slow = right;
		right = next;
	}
	//右半部分的第一个节点
	next = slow;
	//左半部分的第一个节点
	Node* left = head;
	bool res = true;
	//遍历left和right
	cout<< "左侧" << endl;
	for(Node* cur = left; cur != NULL; cur = cur->next)
	{
		cout <<cur->value << " ";
	}
	cout << endl;
	cout << "右侧" << endl;
	for (Node* cur = next; cur != NULL; cur = cur->next)
	{
		cout <<  cur->value << " ";
	}

	//判断是否是回文数（这里right可能有问题）
	while (left != NULL && right != NULL)
	{
		if (left->value != right->value)
		{
			res = false;
			break;
		}
		left = left->next;
		right = right->next;
	}
	//还原链表
	right = next->next;
	next->next = NULL;
	while (right != NULL)
	{
		slow = right->next;
		right->next = next;
		next = right;
		right = slow;
	}
	return res;
}


int main()
{
	//链表
	Node* head = new Node(2);
	head->next = new Node(2);
	head->next->next = new Node(3);
	head->next->next->next = new Node(5);
	head->next->next->next->next = new Node(1);
	head->next->next->next->next->next = new Node(2);
	//遍历
	for (Node* cur = head; cur != NULL; cur = cur->next)
	{
		cout<<cur->value << " ";
	}
	cout << endl;
	cout << isHuiwen(head) << endl;
	return 0;
}