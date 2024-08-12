/*
�����������л��ͷ����л�
*/

#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};//�ṹ��

//ǰ��������л�
string serialize(TreeNode* root) {
	if (root == NULL) {
		return "#!";
	}
	string res = to_string(root->val) + "!";
	res += serialize(root->left);
	res += serialize(root->right);
	return res;
}

//ǰ����������л�
TreeNode* deserialize(string data) {
	queue<string> q;
	string str;
	for (int i = 0; i < data.size(); i++) {
		if (data[i] == '!') {
			q.push(str);
			str = "";
		}
		else {
			str += data[i];
		}
	}
	return deserialize(q);
}