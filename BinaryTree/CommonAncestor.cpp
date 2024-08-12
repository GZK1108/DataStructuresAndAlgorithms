/*
���ö������������������
*/

#include<iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;


struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};//�ṹ��


//����һ����ϣ����ÿ���ڵ�ĸ��ڵ�
void dfs(TreeNode* root, TreeNode* parent, unordered_map<TreeNode*, TreeNode*>& parentMap) {
	if (root == NULL) {
		return;
	}
	parentMap[root] = parent;
	dfs(root->left, root, parentMap);
	dfs(root->right, root, parentMap);
}


//�ҵ�p�����и��ڵ㣬������set��
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	unordered_map<TreeNode*, TreeNode*> parentMap;//��ϣ����ÿ���ڵ�ĸ��ڵ�
	dfs(root, NULL, parentMap);
	unordered_set<TreeNode*> pParents;//���游�ڵ���
	TreeNode* cur = p;
	while (parentMap[cur] != NULL) {
		pParents.insert(cur);
		cur = parentMap[cur];
	}
	pParents.insert(root);
	//��������qʱ������q
	cur = q;
	while(parentMap[cur] != NULL) {
		if (pParents.find(cur) != pParents.end()) {
			return cur;
		}
		cur = parentMap[cur];
	}
	return root;
}


//�ݹ鷨
TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
	if(root== NULL|| root==p || root==q) {
		return root;
	}
	TreeNode* left = lowestCommonAncestor2(root->left, p, q);
	TreeNode* right = lowestCommonAncestor2(root->right, p, q);
	if(left && right) {
		return root;
	}
	return left ? left : right;
}



/*
int main() {
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(5);
	root->right = new TreeNode(1);
	root->left->left = new TreeNode(6);
	root->left->right = new TreeNode(2);
	root->right->left = new TreeNode(0);
	root->right->right = new TreeNode(8);
	TreeNode* p = root->left;
	TreeNode* q = root->right;
	TreeNode* res = lowestCommonAncestor(root, p, q);
	cout << res->val << endl;
	TreeNode* res2 = lowestCommonAncestor2(root, p, q);
	cout << res2->val << endl;
	return 0;
}
*/