#include <bits/stdc++.h>
using namespace std;
#define N 10000
//高精度乘法 
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
    int r_i = a[0] + b[0];//去除多余的0
    while(r[r_i] == 0 && r_i > 1)
        r_i--;
    r[0] = r_i;
}
//高精度加法
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
    while(r[i] == 0 && i > 1)//去除多余的0
        i--;
    r[0] = i;
}
//数字数组a增加1 
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

//数字b复制给数字a
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
	int a[N]={}, b[N]={}, r[N]={}, s[N]={};//a用来保存阶乘结果，b用来保存不断变大的要乘的数字，s保存和，r用作临时数字 
    int n;
    cin>>n;
    //把a构造成1 
    a[0] = 1;
    a[1] = 1;
    for(int i = 1; i <= n; ++i)
    {    	
    	AddOne(b);
    	Multiply(a, b, r);
		numcpy(a, r);//把上一次乘法的结果存入a
		memset(r, 0, sizeof(r));//将r清空 
		
		Add(a, s, r);//把新算出的阶乘值加入和中 
		numcpy(s, r);
		memset(r, 0, sizeof(r));//将r清空
	}
    showNum(s);
}
