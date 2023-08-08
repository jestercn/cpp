#include <iostream>
using namespace std;
int main(){
   int pay,res=0,sum=0;
   bool flag=true;
   for(int i=1;i<=12;i++){
      cin>>pay;
      if(pay>300+res){
        cout<<-1*i<<endl;
        flag=false;
        break;
      }else{
        res=300+res-pay;
        if(res>=100){
            sum +=res-res%100;
            res %=100;   
        }
      }          
   }
   if(flag)
   cout<<sum*1.2+res; 
   return 0;
}