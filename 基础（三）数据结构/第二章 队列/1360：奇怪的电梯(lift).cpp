#include <bits/stdc++.h>
using namespace std;
//�������� 
//˼·�����ó�ʼ¥����ӣ�ÿ��¥�����ʱ���ôӸ�¥����ܴﵽ��¥����ӣ���¼¥���Ƿ��ѷ��ʹ���
//ֱ������Ŀ��¥�㣬��ӿգ��޷��ﵽĿ��¥�㣩����������� 
typedef struct Data
{
    int s;//�ڼ��� 
    int t;//�Ѿ����˼���
    Data(int _s, int _t)
    {
        s = _s;
        t = _t;
    }
    Data()
    {
        Data(0, 0);
    }
}Data; 
int K[205];
Data que[2000];
int head, tail;
bool visited[205];
int main()
{
    int n, a, b, count = 0;
    Data d;
    cin>>n>>a>>b;
    for(int i = 1; i <= n; ++i)
        cin>>K[i];
    que[++tail] = Data(a, 0);//���
    visited[a] = true; 
    while(head != tail)//�Ӳ�Ϊ�� 
    {
        d = que[++head];//s:��ʱȡ����¥��
        visited[d.s] = true;
        if(d.s == b)//����ﵽĿ��¥�� 
        {
            cout<<d.t;
            return 0;
        } 
        if(d.s + K[d.s] <= n && visited[d.s + K[d.s]] == false)//���ϰ���ťҪ����¥����ڣ���ûȥ�� 
            que[++tail] = Data(d.s + K[d.s], d.t + 1);//��� 
        if(d.s - K[d.s] >= 1 && visited[d.s - K[d.s]] == false)//���°���ťҪ����¥����ڣ���ûȥ��
            que[++tail] = Data(d.s - K[d.s], d.t + 1);//���  
    }
    cout<<-1;
	return 0;
}
