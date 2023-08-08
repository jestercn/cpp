#include <bits/stdc++.h>
using namespace std;

bool tree[1050000];//顺序存储结构二叉树 初始值为false
int main()
{
    int par_d, par_i, p = 1;//par_d,par_i为输入的参数D与I, p为此时指向的结点在数组中的下标 第1位置是树的根
    cin>>par_d>>par_i;
    for(int i = 0; i < par_i; ++i)
    {
        p = 1;
        for(int d = 1; d < par_d; ++d)//叶子结点那一层不用计算
        {
            if(tree[p])
            {
                tree[p] = false;
                p = 2 * p + 1;//走右子树
            }
            else
            {
                tree[p] = true;
                p = 2 * p;//走左子树
            }
        }
    }
    cout<<p;
    return 0;
}
