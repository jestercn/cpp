#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, k;
    cin>>m>>k;
    int c = 0;//����������m������3�ĸ���
    if (m % 19 == 0)
    {
        while(m > 0)
        {
            if (m % 10 == 3)
                c++;
            m /= 10;
        }
        if (c == k)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    else
        cout<<"NO"<<endl;
    return 0;
}
