#include <bits/stdc++.h>
using namespace std;
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

//将字符数组转化为数字数组 数字数组从第1位置到第len位置，从低位到高位保存各位数字，第0位置保存数字位数
void toNumArr(char s[], int a[])
{
    int len = strlen(s);
    a[0] = len;
    for(int i = 0; i < len; ++i)
    {
        a[i + 1] = s[len - 1 - i] - '0';
    }
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
	for(int i = 0; i <= b[0]; ++i)
		a[i] = b[i];
}

int main()
{
    int a[1000]={}, b[1000]={}, r[1000]={}, n;
    cin>>n;
    //构造数字2 
    a[0] = 1;
    a[1] = 2;
    //构造数字1
	r[0] = 1;
	r[1] = 1; 
    for(int i = 1; i <= n; ++i)//直接乘n次 
    {
    	numcpy(b, r);//把上一次乘法的结果存入b 
    	memset(r, 0, sizeof(r));//每次乘法运算前要将保存结果的数组r清空 
    	Multiply(a, b, r);
	}
    showNum(r);
}
