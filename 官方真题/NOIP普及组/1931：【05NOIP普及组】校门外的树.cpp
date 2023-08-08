#include <iostream>
#include<cstdio>
#include<iomanip>
#include<cmath>
#include<set>
using namespace std;
bool visit[10005]={0};
int main(){
    int l,m,x,y,cnt=0;
    cin>>l>>m;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        for(int j=x;j<=y;j++){
            visit[j]=true;
        }
    }
   for(int k=0;k<=l;k++){
      if(visit[k]==0)
         cnt++;
   }
   cout<<cnt;
   return 0;
}