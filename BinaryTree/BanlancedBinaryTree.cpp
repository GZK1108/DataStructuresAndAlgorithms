#include<iostream>
#include <stack>
#include <queue>
using namespace std;


struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};//结构体





/*
//判断搜索二叉树，中序遍历不减
bool isValidBST(TreeNode* root)
{
	if(root == NULL)
		return true;
	//利用栈
	stack<TreeNode*> s;
	TreeNode* p = root;
	TreeNode* pre = NULL;
	//若栈不为空或者p不为空
	while(!s.empty() || p)
	{
		//若p不为空
		if(p)
		{
			//p入栈
			s.push(p);
			//p指向左孩子
			p = p->left;
		}
		else
		{
			//栈顶元素出栈
			p = s.top();
			s.pop();
			//若pre不为空且pre大于等于p
			if(pre && pre->val >= p->val)
				return false;
			//pre指向p
			pre = p;
			//p指向右孩子
			p = p->right;
		}
	}
	return true;
}
*/


struct returnData {
	bool isBST;  //>0是，<0否，=0空
	int min;
	int max;
	returnData(bool xisBST, int xmin,int xmax) : isBST(xisBST), min(xmin), max(xmax) {}
};


//搜索二叉树，递归法
returnData* isValidBST2(TreeNode* root)
{
	//若根节点为空
	if(root == NULL)
		return NULL;

	returnData* left = isValidBST2(root->left);
	returnData* right = isValidBST2(root->right);
	int min = root->val;
	int max = root->val;
	bool isBST = true;
	//若左子树不为空
	if (left != NULL) {
		min = min < left->min ? min : left->min;
		max = max > left->max ? max : left->max;
	}
	//若右子树不为空
	if (right!= NULL) {
		min = min < right->min ? min : right->min;
		max = max > right->max ? max : right->max;
	}
	//判断左子树是否是搜索二叉树
	if (left != NULL && (!left->isBST || left->max >= root->val))
		isBST = false;
	//判断右子树是否是搜索二叉树
	if (right != NULL && (!right->isBST || right->min <= root->val))
		isBST = false;
	//返回
	return new returnData(isBST, min, max);
}





//完全二叉树判断
/*
1.若一个节点有右孩子，没有左孩子，返回false
2.若一个节点不是左右孩子都全，那么之后的节点都是叶子节点
*/
bool isCompleteTree(TreeNode* root)
{
	if(root == NULL)
		return true;
	//利用队列
	queue<TreeNode*> q;
	TreeNode* p = root;
	//根节点入队
	q.push(p);
	//标记是否遇到过叶子节点
	bool leaf = false;
	//若队列不为空
	while(!q.empty())
	{
		//队头元素出队
		p = q.front();
		q.pop();
		//若遇到过叶子节点，且当前节点不是叶子节点
		if(leaf && (p->left || p->right))
			return false;
		//若左孩子为空，右孩子不为空，返回false
		if(p->left == NULL && p->right)
			return false;
		//若左孩子不为空，右孩子为空，之后的节点都是叶子节点
		if(p->left)
			q.push(p->left);
		//若右孩子不为空，入队
		if(p->right)
			q.push(p->right);
		if(p->left == NULL || p->right == NULL)
			leaf = true;
	}
	return true;
}


//满二叉树：除了叶子节点，每个节点都有两个孩子
bool isFullTree(TreeNode* root)
{
	if(root == NULL)
		return true;
	//利用队列
	queue<TreeNode*> q;
	TreeNode* p = root;
	//根节点入队
	q.push(p);
	//若队列不为空
	while(!q.empty())
	{
		//队头元素出队
		p = q.front();
		q.pop();
		//若左孩子为空，右孩子不为空，返回false
		if(p->left == NULL && p->right)
			return false;
		//若左孩子不为空，右孩子为空，返回false
		if(p->left && p->right == NULL)
			return false;
		//若左孩子不为空，入队
		if(p->left)
			q.push(p->left);
		//若右孩子不为空，入队
		if(p->right)
			q.push(p->right);
	}
	return true;
}


//平衡二叉树：左右子树高度差不超过1
int getHeight(TreeNode* root)
{
	if(root == NULL)
		return 0;
	int left = getHeight(root->left);
	int right = getHeight(root->right);
	return left > right ? left + 1 : right + 1;
}

bool isBalanced(TreeNode* root)
{
	if(root == NULL)
		return true;
	int left = getHeight(root->left);
	int right = getHeight(root->right);
	if(abs(left - right) > 1)
		return false;
	return isBalanced(root->left) && isBalanced(root->right);
}

/*
int main() {
	//新建一课树
	TreeNode* root = new TreeNode(6);
	root->left = new TreeNode(4);
	root->right = new TreeNode(7);
	root->left->left = new TreeNode(3);
	root->left->right = new TreeNode(5);
	//判断是否是搜索二叉树，使用递归法
	//cout << isValidBST(root) << endl;
	//判断是否是搜索二叉树，使用递归法
	cout << isValidBST2(root)->isBST << endl;

}
*/