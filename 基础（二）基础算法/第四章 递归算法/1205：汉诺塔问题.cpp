#include <bits/stdc++.h>
using namespace std;
//������cout����ᳬʱ��ֻ����printf
char s[3];//�������Ӷ���ʲô
//����˱��Ϊa,b�����ӣ���һ�����ӵı����ʲô
int getOther(int a, int b)
{
    if(a == 0 && b == 1 || a == 1 && b == 0)
        return 2;
    else if(a == 0 && b == 2 || a == 2 && b == 0)
        return 1;
    else
        return 0;
}

//�����ӱ��Ϊs_f��ǰn���ƶ������ӱ��Ϊs_t�������ϣ�����ǰn��һ���Ǵ�С��1~n������
//��һ�����ӵı����s_o
//��Ҫ��s_f��ǰn-1���ƶ���s_o�ϣ��ٰ�s_f��1���ƶ���s_t�ϣ��ٰ�s_o��n-1���ƶ���s_t��
void move(int s_f, int n, int s_t)
{
    if(n < 1)
        return;
    int s_o = getOther(s_f, s_t);
    move(s_f, n-1, s_o);
    //��cout����ᳬʱ��ֻ����printf
    printf("%c->%d->%c\n", s[s_f], n, s[s_t]);//���κ�������Ҫ�ƶ�ǰn�㣬��ô��ʱ���ƶ���СΪn������
    move(s_o, n-1, s_t);
}

int main()
{
    int n;
    cin>>n;
    cin>>s[0]>>s[1]>>s[2];
    move(0, n, 1);
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
//�ǵݹ� ��ջ���⺺ŵ��
//������cout����ᳬʱ��ֻ����printf

//һ���ƶ���������
typedef struct Move
{
    int s_f; //����
    int n; //�ƶ�����
    int s_t; //���ٲ�
    bool isPrint; //�Ƿ�������������������Ҫ����ģ���ôֻ����������ƶ�
    Move()
    {
        Move(0, 0, 0);
    }
    Move(int a, int b, int c)
    {
        s_f = a;
        n = b;
        s_t = c;
        isPrint = false;
    }
}Move;

//ջ��ʼ��
Move stk[1000];
int p;

char s[3];//�������Ӷ���ʲô
//����˱��Ϊa,b�����ӣ���һ�����ӵı����ʲô
int getOther(int a, int b)
{
    if(a == 0 && b == 1 || a == 1 && b == 0)
        return 2;
    else if(a == 0 && b == 2 || a == 2 && b == 0)
        return 1;
    else
        return 0;
}

int main()
{
    int n, s_o;//s_o��һ������
    cin>>n;
    cin>>s[0]>>s[1]>>s[2];
    Move m0(0, n, 1), m, m1, m2;
    stk[++p] = m0;//��ʼ����ѹջ
    while(p != 0)//ջ��Ϊ��
    {
        //ȡջ��m����
        m = stk[p];
        p--;//��ջ
        if(m.isPrint == true || m.n == 1)//������ӡm���� nΪ1ʱֱ�Ӵ�ӡ
        {
            printf("%c->%d->%c\n", s[m.s_f], m.n, s[m.s_t]);//���κ�������Ҫ�ƶ�ǰn�㣬��ô��ʱ���ƶ���СΪn������
        }
        else
        {
            s_o = getOther(m.s_f, m.s_t);
            //m2���⣺��ǰn-1���s_o�ƶ���s_t
            m2.n = m.n-1;
            m2.s_f = s_o;
            m2.s_t = m.s_t;
            stk[++p] = m2;//��ѹ��m2
            //��ѹ��ֻ����ӡ����������m
            m.isPrint = true;
            stk[++p] = m;
            //m1����:��ǰn-1���s_f�ƶ���s_o
            m1.n = m.n-1;
            m1.s_f = m.s_f;
            m1.s_t = s_o;
            stk[++p] = m1;//���ѹ��m1
        }
    }
    return 0;
}
*/
