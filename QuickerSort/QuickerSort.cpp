/*
��������
*/

#include <iostream>
using namespace std;


//����������̣����ص�����������ұ߽�
int* process(int arr[], int L, int R)
{
	//С�������ұ߽�
	int less = L - 1;
	//����������߽�
	int more = R;
	//��ǰָ��
	int cur = L;
	//��ǰָ��û����������
	while (cur < more)
	{
		//��ǰ��С��num
		if (arr[cur] < arr[R])
		{
			//С����������
			swap(arr[++less], arr[cur++]);
		}
		//��ǰ������num
		else if (arr[cur] > arr[R])
		{
			//������������
			swap(arr[--more], arr[cur]);
		}
		//��ǰ������num
		else
		{
			//��ǰָ������
			cur++;
		}
	}
	//���һ�����ʹ��������һ��������
	swap(arr[more], arr[R]);
	//���ص�����������ұ߽�
	int* p = new int[2];
	p[0] = less + 1;
	p[1] = more;
	return p;
}


//��������
void Sort(int arr[], int L, int R)
{
	if (L >= R) { return; }
	//������ţ����ѡһ���������һ��������
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