#include<bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;
bool isPrime(int num)
{
    if(num < 2)
        return false;
    for(int i = 2; i <= sqrt(num); ++i)
    {
        if(num % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int n;
    cin>>n;
    bool isEmpty = true;
    for(int i = 4; i <= n; ++i)
    {
        if(isPrime(i) && isPrime(i-2))
        {
            isEmpty = false;
            cout<<i-2<<' '<<i<<endl;
        }
    }
    if(isEmpty)
        cout<<"empty";
    return 0;
}
