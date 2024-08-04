/*
≤Â»Î≈≈–Ú
*/
#include<iostream>
using namespace std;


void Exg(int a[], int i, int j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}


int main()
{
	int a[] = { 3,2,5,4,5,1,2,0,6,3,8,5,4,4,5};
	int lenth = sizeof(a) / sizeof(a[0]);
	for (int i = 1; i < lenth; i++)
	{
		int j = i;
		while ((j>0)&&(a[j] < a[j - 1]))
		{
			Exg(a, j, j-1);
			j--;
		}
		
	}
	for (int k = 0; k < lenth; k++)
	{
		cout << a[k] << " ";
	}

	return 0;
}