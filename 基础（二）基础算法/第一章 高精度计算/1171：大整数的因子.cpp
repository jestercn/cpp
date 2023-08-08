#include <bits/stdc++.h>
using namespace std;

//高精度数字对低精度数字取模
int Mod(int a[], int b)
{
    int x = 0;
    for(int i = a[0]; i >= 1; --i)
    {
        x = (x * 10 + a[i]) % b;
    }
    return x;
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

int main()
{
    int a[1000]={};
    char s[1000];
    cin>>s;
    toNumArr(s, a);
    bool hasK = false;
    for(int k = 2; k <= 9; ++k)
    {
    	if(Mod(a, k) == 0)
    	{
    		cout<<k<<' ';
    		hasK = true;
    	}
    }
    if(hasK == false)
    	cout<<"none";
}
