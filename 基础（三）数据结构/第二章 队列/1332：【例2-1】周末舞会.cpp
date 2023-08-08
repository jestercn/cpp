#include <bits/stdc++.h>
using namespace std;
//声明两个队列
int que_m[1000], que_f[1000];
int h_m, t_m, h_f, t_f;//两个队列的头尾指针

int main()
{
    int m, f, temp_m, temp_f, n;//m,f:男女人数 temp_m, temp_f:临时出队的男女编号 n:舞曲数
    cin>>m>>f>>n;
    for(int i = 1; i <= m; ++i)//男士入队
        que_m[++t_m] = i;
    for(int i = 1; i <= f; ++i)//女士入队
        que_f[++t_f] = i;
    for(int i = 0; i < n; ++i)
    {
        temp_m = que_m[++h_m];//男队，女队各出队1人
        temp_f = que_f[++h_f];
        cout<<temp_m<<' '<<temp_f<<endl;
        que_m[++t_m] = temp_m;//把两个出队的人再入队
        que_f[++t_f] = temp_f;
    }
	return 0;
}
