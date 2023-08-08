#include<bits/stdc++.h>
using namespace std;

//判断数字是否是A类数 
bool isClassA(int n)
{
	int sum1 = 0, sum0 = 0;
	for(int a = n; a > 0; a /= 2)
	{
		if(a % 2 == 1)
			sum1++;
		else
			sum0++;
	}	
	return sum1 > sum0;
}

int main()
{
	int ctA = 0, ctB = 0;
   	for(int i = 1; i <= 1000; ++i)
   	{
   		if(isClassA(i))
   			ctA++;
   		else
   			ctB++;
    }
    cout<<ctA<<' '<<ctB;
	return 0;
}
