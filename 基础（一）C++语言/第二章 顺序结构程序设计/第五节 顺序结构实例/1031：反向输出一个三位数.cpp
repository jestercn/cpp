#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	cout<<n%10<<n/10%10<<n/100;//n%10求个位，n/10整除运算，去掉个位（如123/10=12），再%10，得到十位。n/100得到百位 
	return 0;
}

