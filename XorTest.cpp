/*
�����ϰ�⣬���������г��������ε�����
1��һ�������н���һ�����ֳ��������Σ��������ֳ���ż���Σ����������
2��һ�����������������ֳ��������Σ��������ֳ���ż���Σ��������������
*/
/*
#include<iostream>
using namespace std;

// ȫ��ȡ���
int Eor(int aa[],int len)
{
	int eor = 0;
	for (int i = 0; i < len; i++)
	{
		eor = eor ^ aa[i];
	}
	return eor;
}

//ȡ�����Ҳ��1
int RightOne(int e)
{
	//ȡ����
	int e1 = ~e + 1;
	//ԭ���벹��ȡ����õ����Ҳ��1
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
	cout << numb1 << "��" << numb2 << endl;
	return 0;
}*/