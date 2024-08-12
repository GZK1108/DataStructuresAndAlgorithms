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
};//�ṹ��





/*
//�ж������������������������
bool isValidBST(TreeNode* root)
{
	if(root == NULL)
		return true;
	//����ջ
	stack<TreeNode*> s;
	TreeNode* p = root;
	TreeNode* pre = NULL;
	//��ջ��Ϊ�ջ���p��Ϊ��
	while(!s.empty() || p)
	{
		//��p��Ϊ��
		if(p)
		{
			//p��ջ
			s.push(p);
			//pָ������
			p = p->left;
		}
		else
		{
			//ջ��Ԫ�س�ջ
			p = s.top();
			s.pop();
			//��pre��Ϊ����pre���ڵ���p
			if(pre && pre->val >= p->val)
				return false;
			//preָ��p
			pre = p;
			//pָ���Һ���
			p = p->right;
		}
	}
	return true;
}
*/


struct returnData {
	bool isBST;  //>0�ǣ�<0��=0��
	int min;
	int max;
	returnData(bool xisBST, int xmin,int xmax) : isBST(xisBST), min(xmin), max(xmax) {}
};


//�������������ݹ鷨
returnData* isValidBST2(TreeNode* root)
{
	//�����ڵ�Ϊ��
	if(root == NULL)
		return NULL;

	returnData* left = isValidBST2(root->left);
	returnData* right = isValidBST2(root->right);
	int min = root->val;
	int max = root->val;
	bool isBST = true;
	//����������Ϊ��
	if (left != NULL) {
		min = min < left->min ? min : left->min;
		max = max > left->max ? max : left->max;
	}
	//����������Ϊ��
	if (right!= NULL) {
		min = min < right->min ? min : right->min;
		max = max > right->max ? max : right->max;
	}
	//�ж��������Ƿ�������������
	if (left != NULL && (!left->isBST || left->max >= root->val))
		isBST = false;
	//�ж��������Ƿ�������������
	if (right != NULL && (!right->isBST || right->min <= root->val))
		isBST = false;
	//����
	return new returnData(isBST, min, max);
}





//��ȫ�������ж�
/*
1.��һ���ڵ����Һ��ӣ�û�����ӣ�����false
2.��һ���ڵ㲻�����Һ��Ӷ�ȫ����ô֮��Ľڵ㶼��Ҷ�ӽڵ�
*/
bool isCompleteTree(TreeNode* root)
{
	if(root == NULL)
		return true;
	//���ö���
	queue<TreeNode*> q;
	TreeNode* p = root;
	//���ڵ����
	q.push(p);
	//����Ƿ�������Ҷ�ӽڵ�
	bool leaf = false;
	//�����в�Ϊ��
	while(!q.empty())
	{
		//��ͷԪ�س���
		p = q.front();
		q.pop();
		//��������Ҷ�ӽڵ㣬�ҵ�ǰ�ڵ㲻��Ҷ�ӽڵ�
		if(leaf && (p->left || p->right))
			return false;
		//������Ϊ�գ��Һ��Ӳ�Ϊ�գ�����false
		if(p->left == NULL && p->right)
			return false;
		//�����Ӳ�Ϊ�գ��Һ���Ϊ�գ�֮��Ľڵ㶼��Ҷ�ӽڵ�
		if(p->left)
			q.push(p->left);
		//���Һ��Ӳ�Ϊ�գ����
		if(p->right)
			q.push(p->right);
		if(p->left == NULL || p->right == NULL)
			leaf = true;
	}
	return true;
}


//��������������Ҷ�ӽڵ㣬ÿ���ڵ㶼����������
bool isFullTree(TreeNode* root)
{
	if(root == NULL)
		return true;
	//���ö���
	queue<TreeNode*> q;
	TreeNode* p = root;
	//���ڵ����
	q.push(p);
	//�����в�Ϊ��
	while(!q.empty())
	{
		//��ͷԪ�س���
		p = q.front();
		q.pop();
		//������Ϊ�գ��Һ��Ӳ�Ϊ�գ�����false
		if(p->left == NULL && p->right)
			return false;
		//�����Ӳ�Ϊ�գ��Һ���Ϊ�գ�����false
		if(p->left && p->right == NULL)
			return false;
		//�����Ӳ�Ϊ�գ����
		if(p->left)
			q.push(p->left);
		//���Һ��Ӳ�Ϊ�գ����
		if(p->right)
			q.push(p->right);
	}
	return true;
}


//ƽ������������������߶Ȳ����1
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
	//�½�һ����
	TreeNode* root = new TreeNode(6);
	root->left = new TreeNode(4);
	root->right = new TreeNode(7);
	root->left->left = new TreeNode(3);
	root->left->right = new TreeNode(5);
	//�ж��Ƿ���������������ʹ�õݹ鷨
	//cout << isValidBST(root) << endl;
	//�ж��Ƿ���������������ʹ�õݹ鷨
	cout << isValidBST2(root)->isBST << endl;

}
*/