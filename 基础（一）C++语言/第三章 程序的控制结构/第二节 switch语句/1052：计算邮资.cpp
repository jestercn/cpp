#include<bits/stdc++.h>
using namespace std;
int main()
{
    int weight, res = 0;//weight������ res����� 
    char isHurry;//�Ƿ�Ӽ� 
    cin>>weight>>isHurry;
    if(weight <= 1000)
        res = 8;
    else
        res = 8 + ceil((double)(weight - 1000)/500)*4;
    if(isHurry == 'y')
        res += 5;
    cout<<res;     
}
