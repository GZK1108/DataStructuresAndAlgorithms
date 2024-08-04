/*
荷兰国旗问题
给定一个数组arr，和一个数num，请把小于num的数放在数组的左边，等于num的数放在数组的中间，大于num的数放在数组的右边。
*/

#include <iostream>
using namespace std;

void DutchFlag(int arr[], int L, int R, int num)
{
	//小于区域右边界
	int less = L - 1;
	//大于区域左边界
	int more = R + 1;
	//当前指针
	int cur = L;
	//当前指针没到大于区域
	while (cur < more)
	{
		//当前数小于num
		if (arr[cur] < num)
		{
			//小于区域右移
			swap(arr[++less], arr[cur++]);
		}
		//当前数大于num
		else if (arr[cur] > num)
		{
			//大于区域左移
			swap(arr[--more], arr[cur]);
		}
		//当前数等于num
		else
		{
			//当前指针右移
			cur++;
		}
	}
}

int main()
{
	int arr[] = { 22,6,5, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int num = 5;
	DutchFlag(arr, 0, 8, num);
	for (int i = 0; i < 9; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}