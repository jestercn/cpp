#include <bits/stdc++.h>
using namespace std;
#define N 1005
//˼·����ͼ���������
//���죺����ö��
//����ÿ�����������룬��ͼ������С����������ҵ�һ����ƥ���ͼ����룬�������
int mi[10];//�洢10����
//ͼ�����bk��������rd�Ƿ�ƥ�䣬��rd�Ƿ���bk��ĩβ��λ���֡�l��rd��λ��
//�㷨ʾ����bkΪ2123��rdΪ123����bk % 10^3�Ľ���ǲ���rd������ǣ���ôbk��ĩβ��rd�������ǡ�
bool isMatch(int bk, int rd, int l)
{
    return bk % mi[l] == rd;
}
//��ʼ��mi���飬�洢10����
void initMi()
{
    int num = 10;
    for(int i = 1; i <= 9; ++i)
    {
        mi[i] = num;
        num *= 10;
    }
}

int main()
{
    initMi();
    int n, q, num;
    int len, reader;//len:����������ĳ���, reader:���ߵ�������
    int book[N];//book[i]:��i����ı���
    cin>>n>>q;
    for(int i = 1; i <= n; ++i)//�����ͬʱ�����������γɴ�С���������
    {
        scanf("%d", &num);
        int j;
        for(j = i; j > 1; --j)
        {
            if(num < book[j - 1])
                book[j] = book[j - 1];
            else
                break;
        }
        book[j] = num;
    }
    for(int i = 1; i <= q; ++i)//��������������
    {
        cin>>len>>reader;//���������볤�ȣ���������
        bool isShow = false;
        for(int j = 1; j <= n; ++j)//�����ź����ͼ���������
        {
            if(isMatch(book[j], reader, len))//���ͼ������������ƥ��
            {
                cout<<book[j]<<endl;//���ͼ�����
                isShow = true;
                break;
            }
        }
        if(isShow == false)//���û��ͼ����룬���-1
            cout<<-1<<endl;
    }
    return 0;
}
