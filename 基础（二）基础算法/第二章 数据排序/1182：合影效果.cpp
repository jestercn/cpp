#include<bits/stdc++.h>
using namespace std;

void bubbleSort(double a[], int n, bool isUp)//isUp�Ƿ������� 
{
	bool isChange;
	for(int i = 0; i < n-1; ++i)
		for(int j = 0; j < n-1-i; ++j)
		{
			if(isUp)
				isChange = a[j] > a[j+1];
			else
				isChange = a[j] < a[j+1];
			if(isChange)
				swap(a[j], a[j+1]);
		}
}

int main()
{
	double m[40], f[40], h;//m,f�洢��Ů���
	int n, lm = 0, lf = 0;//lm,lfָm��f��������ĳ��� 
	cin>>n;
	char s[30];
	for(int i = 0; i < n; ++i)
	{
		cin>>s>>h;
		if(strcmp(s, "male") == 0)
			m[lm++] = h;
		else
			f[lf++] = h;
	}
	bubbleSort(m, lm, true);
	bubbleSort(f, lf, false);
	cout<<fixed<<setprecision(2);
	for(int i = 0; i < lm; ++i)
		cout<<m[i]<<' ';
	for(int i = 0; i < lf; ++i)
		cout<<f[i]<<' ';
}
