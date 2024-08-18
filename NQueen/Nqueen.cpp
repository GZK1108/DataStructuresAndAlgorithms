/*
N�ʺ�����
��һ��N*N�����з���N���ʺ�ʹ�����ǻ��������������������ʺ󶼲��ܴ���ͬһ�С�ͬһ�л�ͬһб���ϡ�
�����ж����ַ��÷���
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
	//�жϵ�i�е�j���Ƿ���Է��ûʺ�
	bool isValid(vector<int>& record, int i, int j){
		for (int k = 0; k < i; k++) {
			if (record[k] == j || abs(record[k] - j) == abs(k - i)) {
				return false;
			}
		}
		return true;
	}
	//����λ�����Ż������Լ�������ٶ�
};




int main(){
	NQueen nq;
	cout << nq.totalNQueens(8) << endl;
	return 0;
}