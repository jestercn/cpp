#include<iostream>
#include<cmath>
using namespace std;
bool prime(int n,int& m){
    int i=2;
    while((i<=m) &&(n%i!=0))
        i++;
    if(i>m)
        return true;
    return false;
}
int main(){
    int n;
    cin>>n;
    int end =floor(sqrt(n));
    for(int i=1;i<=end;i++){
        if((n%i==0)&& prime(n/i,end)){
            cout<<n/i;
        }    
    }
    return 0;
}