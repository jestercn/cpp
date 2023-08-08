#include <iostream>
using namespace std;
int a[200001],b[200001];
void Merge(int a[],int l,int mid,int r,int t[]){
   int i=l,j=mid+1,k=l;
   while(i<=mid && j<=r)
      if(a[i]<a[j]) t[k++]=a[i++];
      else t[k++]=a[j++];
   while(i<=mid) t[k++]=a[i++];
   while(j<=r) t[k++]=a[j++];
   for(i=l;i<=r;i++) a[i]=t[i];
}
void Merge_sort(int a[],int l,int r,int t[]){
   if(l==r) return ;
   int mid=l+(r-l)/2;
   Merge_sort(a,l,mid,t);
   Merge_sort(a,mid+1,r,t);
   Merge(a,l,mid,r,t);
}
int main(){
   int n,s,cnt=0,cmp;
   ios::sync_with_stdio(false);
   cin>>n;
   for(int i=1;i<=n;i++){
      cin>>a[i];
   }
   Merge_sort(a,1,n,b);
   cmp=a[1];
   for(s=1;s<=n;s++)
        if(a[s]==cmp) cnt++;
        else{
            cout<<a[s-1]<<" "<<cnt<<'\n';
            cmp=a[s];
            cnt=1;
        }
    cout<<a[s-1]<<" "<<cnt<<'\n';
 }