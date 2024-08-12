/*前缀树*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class TrieNode{
public:
	int path;//有多少个单词共用这个节点
	int end;//有多少个单词以这个节点结尾
	TrieNode* nexts[26];//26个字母，可以用哈希表代替，如unordered_map<char, TrieNode*> next;
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
		for(int i = 0; i < word.size(); i++){//从左到右遍历单词
			index = word[i] - 'a'; //a:0, b:1, c:2, ...z:25
			if(node->nexts[index] == NULL){
				node->nexts[index] = new TrieNode();
			}
			node = node->nexts[index]; //node指向下一个节点
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
					//这里会导致内存泄漏，需要遍历到底去析构？后面测试
					node->nexts[index] = NULL;
					return;
				}
				node = node->nexts[index];
			}
			node->end--;
		}
	}

	//查找单词word在字典树中出现的次数
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

	//查找以pre为前缀的单词数量
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