#include <bits/stdc++.h>
using namespace std;
//�������01��������
int m, n, sumVal, maxVal, sumWei;//sumWei:��ѡ����Ʒ�������� sumVal:�Ѿ�ѡ�����Ʒ�ļ�ֵ�ܺ� maxVal�����ܴﵽ������ֵ 
int wei[35], val[35], ct;//wei[i]:��i����Ʒ������  val[i]:��i����Ʒ�ļ�ֵ 

//Ҫ��Ҫѡȡ��i����Ʒ 
void Search(int i)
{
	ct++;
	if(i > n)
	{
		if(sumVal > maxVal)
			maxVal = sumVal;
	}
	else
	{
		Search(i + 1);//���ӵ�i����Ʒ
		if(sumWei + wei[i] <= m) //����ӵ�i����Ʒ��û�г��� 
		{	
			sumWei += wei[i];
			sumVal += val[i];
			Search(i + 1);//�ӵ�i����Ʒ
			sumWei -= wei[i];
			sumVal -= val[i]; 
		}
	}
}
int main()
{
	cin>>m>>n;
	int w, v, j;
//	for(int i = 1; i <= n; ++i)
//		cin>>wei[i]>>val[i];
	for(int i = 1; i <= n; ++i)
	{
		cin>>w>>v;//�������� 
		for(j = i; j > 1; --j)
		{
			if(wei[j - 1] < w)
				wei[j] = wei[j - 1];
			else
				break;
		}
		wei[j] = w;
		val[j] = v;
	}
	Search(1);
	cout<<maxVal<<endl; 
	cout<<"Search Times:"<<ct;
    return 0;
}
/*
300 10
95 89
75 59
23 19
73 43
50 100
22 72
6 44
57 16
89 7
98 64

out:
388

һ��˳��1377��
�Ӵ�С˳��1138�� 
��С����˳��1391�� 
*/ 
