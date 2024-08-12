/*ǰ׺��*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class TrieNode{
public:
	int path;//�ж��ٸ����ʹ�������ڵ�
	int end;//�ж��ٸ�����������ڵ��β
	TrieNode* nexts[26];//26����ĸ�������ù�ϣ����棬��unordered_map<char, TrieNode*> next;
	TrieNode(){
		path = 0;
		end = 0;
		for(int i = 0; i < 26; i++){
			nexts[i] = NULL;
		}
	}
};

class Trie{
public:
	TrieNode* root;
	Trie(){
		root = new TrieNode();
	}
	void insert(string word){
		if(word.empty()){
			return;
		}
		TrieNode* node = root;
		node->path++;
		int index = 0;
		for(int i = 0; i < word.size(); i++){//�����ұ�������
			index = word[i] - 'a'; //a:0, b:1, c:2, ...z:25
			if(node->nexts[index] == NULL){
				node->nexts[index] = new TrieNode();
			}
			node = node->nexts[index]; //nodeָ����һ���ڵ�
			node->path++;
		}
		node->end++;
	}
	void del(string word){
		if(search(word)!=0){
			TrieNode* node = root;
			node->path--;
			int index = 0;
			for(int i = 0; i < word.size(); i++){
				index = word[i] - 'a';
				if(--node->nexts[index]->path == 0){
					//����ᵼ���ڴ�й©����Ҫ��������ȥ�������������
					node->nexts[index] = NULL;
					return;
				}
				node = node->nexts[index];
			}
			node->end--;
		}
	}

	//���ҵ���word���ֵ����г��ֵĴ���
	int search(string word){
		if(word.empty()){
			return false;
		}
		TrieNode* node = root;
		int index = 0;
		for(int i = 0; i < word.size(); i++){
			index = word[i] - 'a';
			if(node->nexts[index] == NULL){
				return 0;
			}
			node = node->nexts[index];
		}
		return node->end;
	}

	//������preΪǰ׺�ĵ�������
	int prefixNumber(string pre){
		if(pre.empty()){
			return 0;
		}
		TrieNode* node = root;
		int index = 0;
		for(int i = 0; i < pre.size(); i++){
			index = pre[i] - 'a';
			if(node->nexts[index] == NULL){
				return 0;
			}
			node = node->nexts[index];
		}
		return node->path;
	}
};