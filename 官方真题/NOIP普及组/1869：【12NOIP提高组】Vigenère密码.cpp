#include<bits/stdc++.h>
#include<vector>
using namespace std;
vector<int>v;
void lower(string& s,int n){
    for(int i=0;i<n;i++){
        if(s[i]>='A'&& s[i]<='Z')
            s[i]=s[i]-'A'+'a';
    }
}
void upper(string& s,int n){
    for(int i=0;i<n;i++){
        if(v[i]==1)
            s[i]=s[i]-'a'+'A';
    }
}
int main(){
    string k,c;
    getline(cin,k);
    getline(cin,c);
    for(int i=0;i<c.size();i++){
        if(c[i]>='A'&& c[i]<='Z'){
            v.push_back(1);
        }else{
            v.push_back(0);
        }
    }
    lower(c,c.size());
    lower(k,k.size());
    for(int i=0;i<c.size();i++){
        c[i]=((c[i]-k[i%k.size()]+26)%26)+'a';
    }
    upper(c,c.size());
    cout<<c;
    return 0;
}