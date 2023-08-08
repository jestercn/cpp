#include<bits/stdc++.h>
using namespace std;
#define N 100005
//考察：模拟，桶
//k[i]表示国家数，现在世界上国家就200多个，所以假设x的第二维最大长度为300
int t[N], k[N], x[N][300], na[N];//na[i]表示国籍为i的人有多少人
int main()
{
    int n, st = 1, g, ct = 0;//st:下标大于等于st的船都在考虑范围内 ct:计数
    cin>>n;
    for(int i = 1; i <= n; ++i)
    {
        scanf("%d %d", &t[i], &k[i]);
        for(int j = 0; j < k[i]; ++j)
        {
            scanf("%d", &x[i][j]);//x[i][j]为国籍号
            if(na[x[i][j]] == 0)//如果新增某国籍的人
                ct++;//国籍种类增加
            na[x[i][j]]++;//x[i][j]国籍的人增加1
        }
        while(t[i] - t[st] >= 86400)//若st不在t[i]时考虑的范围内
        {
            //不再统计第st条船的信息
            for(int i = 0; i < k[st]; ++i)
            {
                na[x[st][i]]--;
                if(na[x[st][i]] == 0)//如果某个国籍的人减少到0
                    ct--;//国籍种类减少
            }
            st++;//查看下一条船的记录
        }
        printf("%d\n", ct);
    }
    return 0;
}
