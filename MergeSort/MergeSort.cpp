/*
�鲢����
�����ҷֱ�����Ȼ��ͨ��˫ָ�밴�򿽱��������ռ�
*/

#include<iostream>
using namespace std;


void Merge(int arr[], int L, int M, int R)
{
	//�½�����ΪR-L+1����������
	int *temp = new int[R - L + 1];
	//����ָ��
	int p1 = L;
	int p2 = M + 1;
	//������ָ��
	int i = 0;
	//����ָ�붼û���߽�
	while (p1 <= M && p2 <= R)
	{
		//���С
		if (arr[p1] <= arr[p2])
		{
			temp[i++] = arr[p1++];
		}
		//�ұ�С
		else
		{
			temp[i++] = arr[p2++];
		}
	}
	//���û���߽�
	while (p1 <= M)
	{
		temp[i++] = arr[p1++];
	}
	//�ұ�û���߽�
	while (p2 <= R)
	{
		temp[i++] = arr[p2++];
	}
	//������ԭ����
	for (int i = 0; i < R - L + 1; i++)
	{
		arr[L + i] = temp[i];
	}
	delete[] temp;
}

//�鲢����
void Sort(int arr[], int L, int R)
{
	if (L == R) { return; }
	int mid = L + ((R - L) >> 1);
	//�ݹ�
	Sort(arr, L, mid);
	Sort(arr, mid + 1, R);
	//�ϲ�
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