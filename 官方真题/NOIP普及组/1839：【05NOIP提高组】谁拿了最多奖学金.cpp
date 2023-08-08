#include<bits/stdc++.h>
#include<map>
#include<queue>
using namespace std;
map<int,string>v;
 typedef struct student{
        string name;
        int score;
        int judge;
        char better,west;
        int cnt;
    }student;
    
int main(){
    int n,total=0,sum=0,max=0;
    student stu;
    cin>>n;
    for(int i=0;i<n;i++){
       cin>>stu.name>>stu.score>>stu.judge>>stu.better>>stu.west>>stu.cnt;
       if(stu.score>80&&stu.cnt>=1){
        total +=8000;
       }
       if(stu.score>85&&stu.judge>80){
        total +=4000;
       }
       if(stu.score>90){
        total +=2000;
       }
       if(stu.score>85&&stu.west=='Y'){
        total +=1000;
       }
       if(stu.judge>80&&stu.better=='Y'){
        total +=850;
       }
        if(max!=total) {v[total]=stu.name;}
        if(max<total)  { max=total;}
        sum +=total;
        total=0;
    }
      
      cout<<v[max]<<endl<<max<<endl<<sum<<endl;
    return 0;
}