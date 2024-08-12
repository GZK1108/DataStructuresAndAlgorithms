/*
��̽�㣺�����������һ�����
�ṩ���ڵ������£��ҵ���̽��
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
};//�ṹ��



TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
	if (root == NULL) {
		return NULL;
	}
	//���p���Һ��ӣ���̽������������������
	if (p->right != NULL) {
		TreeNode* cur = p->right;
		while (cur->left != NULL) {
			cur = cur->left;
		}
		return cur;
	}
	//��û���Һ��ӣ����Ҹ�������
	else {
				TreeNode* parent = p->parent;
		while (parent != NULL && parent->left != p) {
			p = parent;
			parent = p->parent;
		}
		return parent;
}