#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
int main(){
    long long x,y,cnt=0;
    cin>>x>>y;
    long long s=x*y;
    for(int i=x;i<=y;i++){
        if(gcd(i,s/i)==x && s==i*(s/i)){
            cnt++;
        }
    }
  	cout<<cnt;
	return 0;
}