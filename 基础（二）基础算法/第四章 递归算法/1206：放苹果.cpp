#include <bits/stdc++.h>
using namespace std;
//������ȼ�������������⣬�Ҳ�ֳɵ���������
//��һ������M���Ϊn������ӵ���ʽ(n <= N)�����ж����ֲ�ַ�ʽ�� ��3 = 1 + 2 �� 3 = 2 + 1��һ�ֲ�֣�

//�����ʵ��ʱ��Ҫ���ֳ�����������
int numCount;//��¼�Ѿ�����˶�������
int methodNum;//��ַ�ʽ����
int M, N;

//������a����һ�β��,  Ҫ���ֳ�������>=minNum
void sepNum(int a, int minNum)
{
    if(a == 0)
        methodNum++;
    else
    {
        if(numCount < N)//����������������С��N�����Խ��в�֡�
        {
            for(int i = minNum; i <= a; ++i)//���β�֣���ֳ�����i
            {
                numCount++;
                sepNum(a - i, i);
                numCount--;
            }
        }
    }
}

int main()
{
    int t;
    cin>>t;
    for(int i = 0; i < t; ++i)
    {
        cin>>M>>N;
        methodNum = 0;
        sepNum(M, 1);//������M����һ�β��,  Ҫ���ֳ�����С������1
        cout<<methodNum<<endl;
    }
    return 0;
}
