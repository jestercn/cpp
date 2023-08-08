#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	int n, t, e;//t病例总数 e有效病例数  
	cin>>n;
	cin>>t>>e;
	double x = (double)e/t, y;//x:鸡尾酒疗法治愈率 y:其它疗法治愈率 
	for(int i = 1; i < n; ++i)
	{
		cin>>t>>e;
		y = (double)e/t;
		if(y - x > 0.05)
			cout<<"better"<<endl;
		else if(x - y > 0.05)
			cout<<"worse"<<endl;
		else
			cout<<"same"<<endl; 
	}
	return 0;
}
