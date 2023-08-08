#include <bits/stdc++.h>
using namespace std;
#define N 10000
//�߾��ȳ˷� 
void Multiply(int a[], int b[], int r[])
{
    for(int i = 1; i <= a[0]; ++i)
    {
        int c = 0;
        for(int j = 1; j <= b[0]; ++j)
        {
            r[i+j-1] = a[i]*b[j] + c + r[i+j-1];
            c = r[i+j-1] / 10;
            r[i+j-1] %= 10;
        }
        r[i+b[0]] += c;
    }
    int r_i = a[0] + b[0];//ȥ�������0
    while(r[r_i] == 0 && r_i > 1)
        r_i--;
    r[0] = r_i;
}
//�߾��ȼӷ�
void Add(int a[], int b[], int r[])
{
    int c = 0, i;
    for(i = 1; i <= a[0] || i <= b[0]; ++i)
    {
        r[i] = a[i] + b[i] + c;
        c = r[i] / 10;
        r[i] %= 10;
    }
    r[i] = c;
    while(r[i] == 0 && i > 1)//ȥ�������0
        i--;
    r[0] = i;
}
//��������a����1 
void AddOne(int a[])
{
	int i = 1, c = 1;
	while(c > 0)
	{
		a[i]++;
		c = a[i] / 10;
		a[i] %= 10;
		i++;
	}
	if(i-1 > a[0])
		a[0] = i - 1;
}

void showNum(int a[])
{
    for(int i = a[0]; i >= 1; --i)
        cout<<a[i];
    cout<<endl;
}

//����b���Ƹ�����a
void numcpy(int a[], int b[])
{
	int len = b[0];
	for(int i = 0; i <= len; ++i)
	{
		a[i] = b[i];
	}
}


int main()
{
	int a[N]={}, b[N]={}, r[N]={}, s[N]={};//a��������׳˽����b�������治�ϱ���Ҫ�˵����֣�s����ͣ�r������ʱ���� 
    int n;
    cin>>n;
    //��a�����1 
    a[0] = 1;
    a[1] = 1;
    for(int i = 1; i <= n; ++i)
    {    	
    	AddOne(b);
    	Multiply(a, b, r);
		numcpy(a, r);//����һ�γ˷��Ľ������a
		memset(r, 0, sizeof(r));//��r��� 
		
		Add(a, s, r);//��������Ľ׳�ֵ������� 
		numcpy(s, r);
		memset(r, 0, sizeof(r));//��r���
	}
    showNum(s);
}
