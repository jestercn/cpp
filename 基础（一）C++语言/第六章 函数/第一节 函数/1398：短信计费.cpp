#include<bits/stdc++.h>
using namespace std;
float price(int charNum)
{
    int msgNum = charNum%70 == 0 ? charNum/70 : charNum/70+1;
    return msgNum * 0.1;
}

int main()
{
    int n;
    cin>>n;
    float sum = 0;
    for(int i = 0; i < n; ++i)
    {
        int charNum;
        cin>>charNum;
        sum += price(charNum);
    }
    cout<<fixed<<setprecision(1)<<sum;
    return 0;
}
