#include<iostream>
using namespace std;
int main(){
	int i, n,sum=0,ans=0;
    cin>>n;
    for( i=1;sum<=n;i++){
       sum +=i;
    }
    for(int j=1;j<=i-1;j++){
        ans +=j*j;
    }
    cout<<ans-(sum-n)*(i-1);
	return 0;
}