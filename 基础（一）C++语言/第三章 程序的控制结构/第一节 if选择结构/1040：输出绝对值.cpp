#include<bits/stdc++.h>
using namespace std;
//��if�����������ϰif��䣬����fabs() 
int main()
{
	double a;
	cin>>a;
	if(a < 0)
		a = -a;
	cout<<fixed<<setprecision(2)<<a;
	return 0;
}
