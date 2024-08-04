/*
������������
����һ������arr����һ����num�����С��num���������������ߣ�����num��������������м䣬����num��������������ұߡ�
*/

#include <iostream>
using namespace std;

void DutchFlag(int arr[], int L, int R, int num)
{
	//С�������ұ߽�
	int less = L - 1;
	//����������߽�
	int more = R + 1;
	//��ǰָ��
	int cur = L;
	//��ǰָ��û����������
	while (cur < more)
	{
		//��ǰ��С��num
		if (arr[cur] < num)
		{
			//С����������
			swap(arr[++less], arr[cur++]);
		}
		//��ǰ������num
		else if (arr[cur] > num)
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