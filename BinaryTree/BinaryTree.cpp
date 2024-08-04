/*
������
*/

#include <iostream>
#include <stack>
#include <queue>
using namespace std;


struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


//�������
//�ݹ鷨
void preOrder(TreeNode* root)
{
	if(root == NULL)
		return;
	cout << root->val << " ";
	preOrder(root->left);
	preOrder(root->right);
}

//�ǵݹ鷨
void preOrderStack(TreeNode* root)
{
	if(root == NULL)
		return;
	//����ջ
	stack<TreeNode*> s;
	TreeNode* p = root;
	//�Ѹ��ڵ���ջ
	s.push(p);
	//��ջ��Ϊ��
	while(!s.empty())
	{
		//ջ��Ԫ�س�ջ
		p = s.top();
		s.pop();
		cout << p->val << " ";
		//����ջ�Һ��ӣ�����ջ����
		if(p->right)
			s.push(p->right);
		if(p->left)
			s.push(p->left);
	}
}


//��������
//�ݹ�
void postOrder(TreeNode* root)
{
	if(root == NULL)
		return;
	postOrder(root->left);
	postOrder(root->right);
	cout << root->val << " ";
}

//�ǵݹ�
void postOrderStack(TreeNode* root)
{
	if (root == NULL)
		return;
	stack<TreeNode*> s; //����ջ
	stack<TreeNode*> output; //��ź���������
	//���ڵ���ջ
	s.push(root);
	while (!s.empty())
	{
		TreeNode* p = s.top();
		s.pop();
		output.push(p);
		if (p->left)
			s.push(p->left);
		if (p->right)
			s.push(p->right);
	}
	//���
	while (!output.empty())
	{
		cout << output.top()->val << " ";
		output.pop();
	}
	
}


//�������
//�ݹ�
void inOrder(TreeNode* root)
{
	if(root == NULL)
		return;
	inOrder(root->left);
	cout << root->val << " ";
	inOrder(root->right);
}

//�ǵݹ�
void inOrderStack(TreeNode* root)
{
	if (root == NULL)
		return;
	stack<TreeNode*> s;
	TreeNode* p = root;
	while (p || !s.empty())
	{
		while (p) //һֱ������
		{
			s.push(p);
			p = p->left;
		}
		if (!s.empty())
		{
			p = s.top();
			s.pop();
			cout << p->val << " ";
			p = p->right;
		}
	}
}


//������ȱ���
void levelOrder(TreeNode* root)
{
	if (root == NULL)
		return;
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty())
	{
		TreeNode* p = q.front();
		q.pop();
		cout << p->val << " ";
		if (p->left)
			q.push(p->left);
		if (p->right)
			q.push(p->right);
	}
}



int main()
{
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(7);
	preOrder(root);
	cout << endl;
	preOrderStack(root);
	cout << endl;
	postOrder(root);
	cout << endl;
	postOrderStack(root);
	cout << endl;
	inOrder(root);
	cout << endl;
	inOrderStack(root);
	return 0;
}