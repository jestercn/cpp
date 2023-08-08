#include<iostream>
using namespace std;
int main(){
   int n,l,r,ans,res;
    cin>>n>>l>>r;
    res=l%n;
    ans=r-l+res;
    if(ans<n)
        cout<<ans;
    else 
        cout<<n-1;
   return 0;
}