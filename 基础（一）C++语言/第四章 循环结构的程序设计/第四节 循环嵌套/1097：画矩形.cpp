#include<bits/stdc++.h>
using namespace std;
int main()
{
    int h, w, x;//h�� w�� xΪ1ʵ�� 0����
    char c;
    cin>>h>>w>>c>>x;
    char c_i = x == 1 ? c : ' ';//�ڲ��ַ�
    for(int i = 0; i < w; ++i)
        cout<<c;
    cout<<endl;
    for(int i = 0; i < h-2; ++i)
    {
        cout<<c;
        for(int j = 0; j < w-2; ++j)
            cout<<c_i;
        cout<<c<<endl;
    }
    for(int i = 0; i < w; ++i)
        cout<<c;
    cout<<endl;
}
