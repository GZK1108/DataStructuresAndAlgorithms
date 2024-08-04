/*
哈希表学习与使用
Unordered_map: 无序的键值对集合KEY->VALUE
Unordered_set: 无序的键集合KEY
*/

#include<iostream>
#include <unordered_map>
using namespace std;

int main()
{
	//哈希表
	unordered_map<int, int> map;
	map[1] = 2;
	map[3] = 4;
	map[5] = 6;
	map[7] = 8;
	map[9] = 10;
	map[11] = 12;
	map[13] = 14; 
	//遍历
	for (auto it = map.begin(); it != map.end(); it++)
	{
		cout << it->first << " " << it->second << endl;
	}
	return 0;
} 