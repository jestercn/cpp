#include<bits/stdc++.h>
using namespace std;
bool isPrime(int n)
{
	for(int i = 2; i <= sqrt(n); ++i)
	{
		if(n % i == 0)
			return false;
	}
	return true;
}
//������n��ֳ���������������� 
void sep(int n)
{
	for(int i = 2; i <= n/2; ++i)
	{
		if(isPrime(i) && isPrime(n - i))
		{
			cout<<n<<'='<<i<<'+'<<n - i<<endl;
			break;
		}
	}	
} 

int main()
{
    for(int i = 6; i <= 100; i += 2)
    {
    	sep(i);
	}
    return 0;
}

