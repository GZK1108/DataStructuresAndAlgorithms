/*
堆学习，桶排序
*/

#include<iostream>
using namespace std;


// 调整堆
void HeapInsert(int arr[], int index)
{
	while (arr[index] > arr[(index - 1) / 2])
	{
		swap(arr[index], arr[(index - 1) / 2]);
		index = (index - 1) / 2;
	}
}
 
//某个数在index位置，能否向下移动
void Heapify(int arr[], int index, int size)
{
	int left = index * 2 + 1; //左孩子
	while (left < size) //下方有左孩子
	{
		//左右孩子中最大的孩子
		int largest = left + 1 < size && arr[left + 1] > arr[left] ? left + 1 : left;
		//孩子和父亲中最大的数
		largest = arr[largest] > arr[index] ? largest : index;
		//如果父亲是最大的，不用交换
		if (largest == index)
		{
			break;
		}
		//父亲和孩子交换
		swap(arr[largest], arr[index]);
		//index来到孩子的位置
		index = largest;
		//左孩子
		left = index * 2 + 1;
	}
}

//堆排序
void HeapSort(int arr[], int size)
{
	if (arr == NULL || size < 2)
	{
		return;
	}
	//生成堆
	for (int i = 0; i < size; i++)
	{
		HeapInsert(arr, i); //从0到i生成堆
	}

	//堆的大小
	int heapSize = size;
	//调整堆
	swap(arr[0], arr[--heapSize]);
	while (heapSize > 0)
	{
		Heapify(arr, 0, heapSize);
		swap(arr[0], arr[--heapSize]);
	}

}


int main()
{
	int arr[] = { 3, 5, 2, 8, 1, 4, 7, 6 };
	HeapSort(arr, sizeof(arr) / sizeof(arr[0]));
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}