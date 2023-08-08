#include <bits/stdc++.h>
using namespace std;
//N进制高精度加法
void Add(int a[], int b[], int r[], int n)
{
    int c = 0, i;
    for(i = 1; i <= a[0] || i <= b[0]; ++i)
    {
        r[i] = a[i] + b[i] + c;
        c = r[i] / n;
        r[i] %= n;
    }
    r[i] = c;
    while(r[i] == 0 && i > 1)//去除多余的0
        i--;
    r[0] = i;
}

//将字符数组转化为数字数组 数字数组从第1位置到第len位置，从低位到高位保存各位数字，第0位置保存数字位数
void toNumArr(char s[], int a[])
{
    int len = strlen(s);
    a[0] = len;
    for(int i = 0; i < len; ++i)
    {
    	char c = s[len - 1 - i];
    	if(c >= '0' && c <= '9')
        	a[i + 1] = c - '0';
        else
        	a[i + 1] = c - 'A' + 10;
    }
}

//判断一个数字数组是否是回文数 
bool isPalin(int a[])
{
	int len = a[0];
	for(int i = 1; i <= len/2; ++i)
	{
		if(a[i] != a[len + 1 - i])
			return false;
	}
	return true;
}

//获取反向数字 
void getRevNum(int a[], int r[])
{
	r[0] = a[0];
	for(int i = 1; i <= a[0]; ++i)
	{
		r[a[0] + 1 - i] = a[i];
	}
}

//数字b复制给数字a 
void numcpy(int a[], int b[])
{
	for(int i = 0; i <= b[0]; ++i)
		a[i] = b[i];
}

int main()
{
    int a[1000]={}, b[1000]={}, r[1000]={}, n;
    char s[1000];
    cin>>n>>s;
    toNumArr(s, a);//输入的数字存入数字数组a 
    for(int i = 1; i <= 30; ++i)
    {
    	getRevNum(a, b);//数字a翻转形成数字b 
    	Add(a, b, r, n);
    	if(isPalin(r))//如果相加的结果是回文数 
    	{
    		cout<<i;
    		return 0;
		}
		else
			numcpy(a, r);//否则，把结果拷贝给a 
	}
	cout<<"Impossible";
	return 0;
}
