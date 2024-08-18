/*
N皇后问题
在一个N*N棋盘中放置N个皇后，使得它们互不攻击，即任意两个皇后都不能处于同一行、同一列或同一斜线上。
返回有多少种放置方法
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class NQueen{
	public:
	int totalNQueens(int n){
		if(n < 1){
			return 0;
		}
		vector<int> record(n, -1);
		return process(0, record, n);
	}
	int process(int i, vector<int>& record, int n){
		if(i == n){
			return 1;
		}
		int res = 0;
		for(int j = 0; j < n; j++){
			if (isValid(record, i, j)) {
				record[i] = j;
				res += process(i + 1, record, n);
			}
		}
		return res;
	}
	//判断第i行第j列是否可以放置皇后
	bool isValid(vector<int>& record, int i, int j){
		for (int k = 0; k < i; k++) {
			if (record[k] == j || abs(record[k] - j) == abs(k - i)) {
				return false;
			}
		}
		return true;
	}
	//利用位运算优化，可以极大提高速度
};




int main(){
	NQueen nq;
	cout << nq.totalNQueens(8) << endl;
	return 0;
}