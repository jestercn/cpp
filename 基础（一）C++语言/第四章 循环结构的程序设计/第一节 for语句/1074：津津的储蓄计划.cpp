#include<bits/stdc++.h>
using namespace std;

int main()
{
	int m = 0, s = 0, b;//m：津津手中的钱 s：存的钱, b：某个月的预算 
	for(int i = 1; i <= 12; ++i)
	{
		cin>>b;
		if(m + 300 >= b)//如果本月能用的钱大于等于预算 
		{
			int t = m + 300 - b;//t：预计本月末剩余的钱 
			m = t%100; //存钱后，手中剩余的钱 
			s += t - m; //存钱 
		}
		else//如果本月能用的钱小于预算 
		{
			cout<<-i;
			return 0; 
		} 
	}
	cout<<s*1.2 + m;//存款+利息+手里的钱 
}
