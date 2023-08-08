#include<bits/stdc++.h>
using namespace std;
//字符串在b进制下转为值 
int toVal(char s[], int len, int b)
{
	int val = 0;
	for(int i = 0; i < len; ++i)
	{
		val = val * b + s[i] - '0';
	}
	return val;
}

int main()
{
	char s_p[10], s_q[10], s_r[10];
	cin>>s_p>>s_q>>s_r;
	int p, q, r;
	int len_p = strlen(s_p), len_q = strlen(s_q), len_r = strlen(s_r);
	for(int b = 2; b <= 40; ++b)
	{
		p = toVal(s_p, len_p, b);
		q = toVal(s_q, len_q, b);
		r = toVal(s_r, len_r, b);
		if(p * q == r)
		{
			cout<<b;
			return 0;
		}
	}
	cout<<0;
	return 0;
}
