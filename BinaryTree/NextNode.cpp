/*
后继结点：中序遍历的下一个结点
提供父节点的情况下，找到后继结点
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
	TreeNode* parent;
	TreeNode(int x) : val(x), left(NULL), right(NULL), parent(NULL) {}
};//结构体



TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
	if (root == NULL) {
		return NULL;
	}
	//如果p有右孩子，后继结点是右子树的最左结点
	if (p->right != NULL) {
		TreeNode* cur = p->right;
		while (cur->left != NULL) {
			cur = cur->left;
		}
		return cur;
	}
	//当没有右孩子，查找父亲左孩子
	else {
				TreeNode* parent = p->parent;
		while (parent != NULL && parent->left != p) {
			p = parent;
			parent = p->parent;
		}
		return parent;
}