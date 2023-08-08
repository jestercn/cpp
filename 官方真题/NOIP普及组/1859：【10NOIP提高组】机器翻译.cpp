#include<bits/stdc++.h>
#include<deque>
#include<iterator>
using namespace std;
deque<int>v;
int cnt=0;
void solution(int val,int n){
    if(!v.empty()){
        for(auto cmp : v){
            if(cmp ==val)
            return ;
        }
    }
    if(v.empty()){
       v.push_back(val);
        cnt++; 
    }else if(v.size()<n){
        v.push_back(val);
        cnt++;
    }else if(v.size()==n){
        v.pop_front();
        v.push_back(val);
        cnt++;
    }
    return ;
}
int main(){   
    int n,total,val;
    cin>>n>>total;
    for(int i=0;i<total;i++){
        cin>>val;
        solution(val,n);
    }
    cout<<cnt;
    return 0;
}