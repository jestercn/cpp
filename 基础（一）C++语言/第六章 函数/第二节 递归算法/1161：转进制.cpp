#include<bits/stdc++.h>
using namespace std;
//将n转换为b进制 
//由于每次n%b取到最低位，那么先调用toBase()，再输出最低位。 
void toBase(int n, int b)
{
	if(n == 0)
		return;
	toBase(n / b, b);
	if(n % b >= 10)
		cout<<char('A' + n % b - 10);
	else
		cout<<n % b;
}

int main()
{
	int n, b;
	cin>>n>>b;
	toBase(n, b);
	return 0;
}
