/*
��ѧϰ��Ͱ����
*/

#include<iostream>
using namespace std;


// ������
void HeapInsert(int arr[], int index)
{
	while (arr[index] > arr[(index - 1) / 2])
	{
		swap(arr[index], arr[(index - 1) / 2]);
		index = (index - 1) / 2;
	}
}
 
//ĳ������indexλ�ã��ܷ������ƶ�
void Heapify(int arr[], int index, int size)
{
	int left = index * 2 + 1; //����
	while (left < size) //�·�������
	{
		//���Һ��������ĺ���
		int largest = left + 1 < size && arr[left + 1] > arr[left] ? left + 1 : left;
		//���Ӻ͸�����������
		largest = arr[largest] > arr[index] ? largest : index;
		//������������ģ����ý���
		if (largest == index)
		{
			break;
		}
		//���׺ͺ��ӽ���
		swap(arr[largest], arr[index]);
		//index�������ӵ�λ��
		index = largest;
		//����
		left = index * 2 + 1;
	}
}

//������
void HeapSort(int arr[], int size)
{
	if (arr == NULL || size < 2)
	{
		return;
	}
	//���ɶ�
	for (int i = 0; i < size; i++)
	{
		HeapInsert(arr, i); //��0��i���ɶ�
	}

	//�ѵĴ�С
	int heapSize = size;
	//������
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