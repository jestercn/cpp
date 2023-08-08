#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int r[4] = {};
    for(int i = 0; i < n; ++i)
    {
        int age;
        cin>>age;
        if(age >= 0 && age <= 18)
            r[0]++;
        else if (age >= 19 && age <= 35)
            r[1]++;
        else if (age >= 36 && age <= 60)
            r[2]++;
        else
            r[3]++;
    }
    float sum = n;
    for(int i = 0; i < 4; ++i)
        cout<<fixed<<setprecision(2)<<(float)r[i] / sum * 100<<'%'<<endl;
    return 0;
}
