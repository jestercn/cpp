#include<bits/stdc++.h>
using namespace std;
//���측���ͱ����ж���� 
int main()
{
    float s, walkT, rideT;
    cin>>s;
    walkT = s / 1.2;
    rideT = 27 + 23 + s / 3;
    if (fabs(walkT - rideT)<= 0.0001)
        cout<<"All"<<endl;
    else if (walkT > rideT)
        cout<<"Bike"<<endl;
    else if (walkT < rideT)
        cout<<"Walk"<<endl;
    return 0;
}
