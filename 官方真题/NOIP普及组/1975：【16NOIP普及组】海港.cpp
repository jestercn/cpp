#include<bits/stdc++.h>
using namespace std;
#define N 100005
//���죺ģ�⣬Ͱ
//k[i]��ʾ�����������������Ϲ��Ҿ�200��������Լ���x�ĵڶ�ά��󳤶�Ϊ300
int t[N], k[N], x[N][300], na[N];//na[i]��ʾ����Ϊi�����ж�����
int main()
{
    int n, st = 1, g, ct = 0;//st:�±���ڵ���st�Ĵ����ڿ��Ƿ�Χ�� ct:����
    cin>>n;
    for(int i = 1; i <= n; ++i)
    {
        scanf("%d %d", &t[i], &k[i]);
        for(int j = 0; j < k[i]; ++j)
        {
            scanf("%d", &x[i][j]);//x[i][j]Ϊ������
            if(na[x[i][j]] == 0)//�������ĳ��������
                ct++;//������������
            na[x[i][j]]++;//x[i][j]������������1
        }
        while(t[i] - t[st] >= 86400)//��st����t[i]ʱ���ǵķ�Χ��
        {
            //����ͳ�Ƶ�st��������Ϣ
            for(int i = 0; i < k[st]; ++i)
            {
                na[x[st][i]]--;
                if(na[x[st][i]] == 0)//���ĳ���������˼��ٵ�0
                    ct--;//�����������
            }
            st++;//�鿴��һ�����ļ�¼
        }
        printf("%d\n", ct);
    }
    return 0;
}
