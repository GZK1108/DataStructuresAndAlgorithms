/*
异或练习题，查找数组中出现奇数次的数字
1：一个数组中仅有一个数字出现奇数次，其他数字出现偶数次，输出该数据
2：一个数组中有两个数字出现奇数次，其他数字出现偶数次，输出这两个数据
*/
/*
#include<iostream>
using namespace std;

// 全部取异或
int Eor(int aa[],int len)
{
	int eor = 0;
	for (int i = 0; i < len; i++)
	{
		eor = eor ^ aa[i];
	}
	return eor;
}

//取出最右侧的1
int RightOne(int e)
{
	//取补码
	int e1 = ~e + 1;
	//原码与补码取与则得到最右侧的1
	return e & e1;

}


int main()
{
	int a[] = { 1,1,1,3,3,5,5,6,7,5,5,6,7,9,9,9,1,5};
	int len = sizeof(a) / sizeof(a[0]);
	int res = Eor(a,len);
	int onlyOne = RightOne(res);
	int numb1 = 0, numb2 = 0;
	for (int i = 0; i < len; i++)
	{
		if ((a[i] & onlyOne) == 0)
		{
			numb1 = numb1 ^ a[i];
		}
	}
	numb2 = numb1 ^ res;
	cout << numb1 << "和" << numb2 << endl;
	return 0;
}*/