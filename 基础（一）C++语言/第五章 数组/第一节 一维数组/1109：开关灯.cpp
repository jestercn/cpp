#include <bits/stdc++.h>
using namespace std;

//解法1：正向思考，用数组表示灯，模拟开关灯的行为 
int main()
{
	bool light[5005];//表示灯状况的数组，true为开灯，false为关灯 
    int n, m;
    cin>>n>>m;
    for(int i = 1; i <= n; ++i)
        light[i] = true;
    for(int i = 1; i <= m; ++i)//i为人编号
    {
        for(int j = 1; j <= n; ++j)//j为灯号
        {
            if (j % i == 0)//如果灯号是人编号的倍数 
            { 
                if(light[j])//改变灯的亮暗状态 
                	light[j] = false;
                else
                	light[j] = true;
            } 
        }
    }
    
    bool firstNum = true;//标志位，是否输出第一个数 
    for(int j = 1; j <= n; ++j)
    {
        if (light[j] == false)
        {
            if(firstNum)
                firstNum = false;
            else
                cout<<',';//不是输出第一个数时，要先输出逗号 
            cout<<j; 
        }
    }
    return 0;
}
/* 
//解法2：不用数组，逆向思考，考察每个灯会被操作的次数
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;//n盏灯 m个人 
    cout<<1;//1号灯只被第一个人操作，一定是关闭的 
    for(int i = 2;i <= n; ++i)//灯i会被序号为i因数的人操作 
    {
    	int c = 0;//计数，计该灯被操作多少次 
        for(int j = 1;j <= m && j <= i; ++j)//那么看从1~m且1~i，有几个数是i的因数，那么该灯就被操作多少次。 
        {
        	if(i % j == 0)
            	c++;
        }
        if(c % 2 == 1)//灯原来是亮着的，进行奇数次操作后，灯会灭 
        	cout<<','<<i;
    }
    return 0;
} 
*/
