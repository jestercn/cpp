#include <bits/stdc++.h>
using namespace std;

int main()
{
    char charr[260];
    cin.get(charr, 260);
    int sum = 0;
    for(int i = 0; i < strlen(charr); ++i)
    {
        if(charr[i] >= '0' && charr[i] <= '9')
            sum++;
    }
    cout<<sum;
    return 0;
}
