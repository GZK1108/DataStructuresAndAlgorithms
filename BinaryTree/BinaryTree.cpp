/*
二叉树
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


//先序遍历
//递归法
void preOrder(TreeNode* root)
{
	if(root == NULL)
		return;
	cout << root->val << " ";
	preOrder(root->left);
	preOrder(root->right);
}

//非递归法
void preOrderStack(TreeNode* root)
{
	if(root == NULL)
		return;
	//利用栈
	stack<TreeNode*> s;
	TreeNode* p = root;
	//把根节点入栈
	s.push(p);
	//若栈不为空
	while(!s.empty())
	{
		//栈顶元素出栈
		p = s.top();
		s.pop();
		cout << p->val << " ";
		//先入栈右孩子，再入栈左孩子
		if(p->right)
			s.push(p->right);
		if(p->left)
			s.push(p->left);
	}
}


//后续遍历
//递归
void postOrder(TreeNode* root)
{
	if(root == NULL)
		return;
	postOrder(root->left);
	postOrder(root->right);
	cout << root->val << " ";
}

//非递归
void postOrderStack(TreeNode* root)
{
	if (root == NULL)
		return;
	stack<TreeNode*> s; //辅助栈
	stack<TreeNode*> output; //存放后序遍历结果
	//根节点入栈
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
	//输出
	while (!output.empty())
	{
		cout << output.top()->val << " ";
		output.pop();
	}
	
}


//中序遍历
//递归
void inOrder(TreeNode* root)
{
	if(root == NULL)
		return;
	inOrder(root->left);
	cout << root->val << " ";
	inOrder(root->right);
}

//非递归
void inOrderStack(TreeNode* root)
{
	if (root == NULL)
		return;
	stack<TreeNode*> s;
	TreeNode* p = root;
	while (p || !s.empty())
	{
		while (p) //一直向左走
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


//宽度优先遍历
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