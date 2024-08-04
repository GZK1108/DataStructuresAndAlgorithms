/*
快速排序
*/

#include <iostream>
using namespace std;


//荷兰国旗过程，返回等于区域的左右边界
int* process(int arr[], int L, int R)
{
	//小于区域右边界
	int less = L - 1;
	//大于区域左边界
	int more = R;
	//当前指针
	int cur = L;
	//当前指针没到大于区域
	while (cur < more)
	{
		//当前数小于num
		if (arr[cur] < arr[R])
		{
			//小于区域右移
			swap(arr[++less], arr[cur++]);
		}
		//当前数大于num
		else if (arr[cur] > arr[R])
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
	//最后一个数和大于区域第一个数交换
	swap(arr[more], arr[R]);
	//返回等于区域的左右边界
	int* p = new int[2];
	p[0] = less + 1;
	p[1] = more;
	return p;
}


//快速排序
void Sort(int arr[], int L, int R)
{
	if (L >= R) { return; }
	//随机快排，随机选一个数和最后一个数交换
	swap(arr[L + rand() % (R - L + 1)], arr[R]);
	int* p = process(arr, L, R);
	Sort(arr, L, p[0]-1);
	Sort(arr, p[1]+1, R);
}



int main()
{
	int arr[] = { 22,6,5, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	Sort(arr, 0, sizeof(arr)/sizeof(arr[0])-1);
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}