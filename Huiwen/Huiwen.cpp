/*
������[12321]
*/

#include <iostream>
using namespace std;

//�ṹ��
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

//�ж��Ƿ��ǻ�����
bool isHuiwen(Node* head)
{
	if (head == NULL || head->next == NULL)
	{
		return true;
	}
	//����ָ��
	Node* slow = head;
	Node* fast = head;
	//��ָ���ߵ���ͷ����ָ���ߵ��м�
	while (fast->next != NULL && fast->next->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	//�Ұ벿�ֵĵ�һ���ڵ�
	Node* right = slow->next;
	//�Ұ벿�ֵĵ�һ���ڵ����һ���ڵ�
	slow->next = NULL;
	//�Ұ벿�ֵĵ�һ���ڵ�
	Node* next = NULL;
	//�Ұ벿�ַ�ת������right����������
	while (right != NULL)
	{
		next = right->next;
		right->next = slow;
		slow = right;
		right = next;
	}
	//�Ұ벿�ֵĵ�һ���ڵ�
	next = slow;
	//��벿�ֵĵ�һ���ڵ�
	Node* left = head;
	bool res = true;
	//����left��right
	cout<< "���" << endl;
	for(Node* cur = left; cur != NULL; cur = cur->next)
	{
		cout <<cur->value << " ";
	}
	cout << endl;
	cout << "�Ҳ�" << endl;
	for (Node* cur = next; cur != NULL; cur = cur->next)
	{
		cout <<  cur->value << " ";
	}

	//�ж��Ƿ��ǻ�����������right���������⣩
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
	//��ԭ����
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
	//����
	Node* head = new Node(2);
	head->next = new Node(2);
	head->next->next = new Node(3);
	head->next->next->next = new Node(5);
	head->next->next->next->next = new Node(1);
	head->next->next->next->next->next = new Node(2);
	//����
	for (Node* cur = head; cur != NULL; cur = cur->next)
	{
		cout<<cur->value << " ";
	}
	cout << endl;
	cout << isHuiwen(head) << endl;
	return 0;
}