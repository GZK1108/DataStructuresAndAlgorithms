/*
归并排序
先左右分别排序，然后通过双指针按序拷贝到辅助空间
*/

#include<iostream>
using namespace std;


void Merge(int arr[], int L, int M, int R)
{
	//新建长度为R-L+1的整数数组
	int *temp = new int[R - L + 1];
	//左右指针
	int p1 = L;
	int p2 = M + 1;
	//新数组指针
	int i = 0;
	//左右指针都没到边界
	while (p1 <= M && p2 <= R)
	{
		//左边小
		if (arr[p1] <= arr[p2])
		{
			temp[i++] = arr[p1++];
		}
		//右边小
		else
		{
			temp[i++] = arr[p2++];
		}
	}
	//左边没到边界
	while (p1 <= M)
	{
		temp[i++] = arr[p1++];
	}
	//右边没到边界
	while (p2 <= R)
	{
		temp[i++] = arr[p2++];
	}
	//拷贝回原数组
	for (int i = 0; i < R - L + 1; i++)
	{
		arr[L + i] = temp[i];
	}
	delete[] temp;
}

//归并排序
void Sort(int arr[], int L, int R)
{
	if (L == R) { return; }
	int mid = L + ((R - L) >> 1);
	//递归
	Sort(arr, L, mid);
	Sort(arr, mid + 1, R);
	//合并
	Merge(arr, L, mid, R);
}



int main()
{
	int a[] = { 3, 2, 1, 4, 5, 6, 7, 8, 9, 0 };
	int lenth = sizeof(a) / sizeof(a[0]);
	Sort(a, 0, lenth-1);
	for (int i = 0; i < lenth; i++)
	{
		cout << a[i] << " ";
	}
	return 0;
}