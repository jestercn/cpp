#include <bits/stdc++.h>
using namespace std;
//����a>0�����κ����������ϣ�����λ�ú�����Ϊ-b/(2a)����֪������a,b,x��Ϊ����������ô����������ڸ�����
//��x>0�ķ�Χ�ڣ����κ����������������ڸú�����˵��x=1ʱ����ֵ��С��x=2ʱ����ֵ�ڶ�С������
//ʹ�ö�����
//�Ѷ�Ԫһ�η�����Ϊ��㣬�Է��̵�ֵ��С���ж����򣬹���С���ѡ�ÿ��ȡ�Ѷ�����ø������е���Сֵ���ø÷����뿪�ѣ�Ȼ��÷��̵�x��1���ټ�������ѡ�
typedef struct Equation//��ʾһ����Ԫһ�η���
{
    int a, b, c, x;
    Equation(int _a, int _b, int _c, int _x):a(_a), b(_b), c(_c), x(_x)
    {
    }
    Equation()
    {
    }
    int getVal()
    {
        return a*x*x + b*x + c;
    }
    bool operator<(Equation& e)//��������� 
    {
        return this->getVal() < e.getVal();
    }
    bool operator>(Equation& e)
    {
        return this->getVal() > e.getVal();
    }
}Equation;

//С����
//����С��������ȫ��������ʹ��˳��洢�ṹ��ʾ������
typedef struct Heap
{
    Equation tree[10005];//�ӵ�1λ�ÿ�ʼ����
    int len;//����Ԫ�ظ���
    Heap()
    {
        len = 0;
    }
    void addVal(Equation e)//���һ��ֵ��������
    {
        tree[++len] = e;
        adjUp(len);
    }
    void adjUp(int pos)//�ӵ�posλ�ÿ�ʼ���������ϵ���
    {
        if(pos > 1)
        {
            if(tree[pos] < tree[pos/2])//������ӱȸ���С
            {
                swap(tree[pos], tree[pos/2]);
                adjUp(pos/2);
            }
        }
    }
    void adjDown(int pos)//�ӵ�posλ�ÿ�ʼ���������µ���
    {
        int nextPos;
        if(pos * 2 > len && pos*2 + 1 > len)//posΪҶ�ӽ��
            return;
        else if(pos*2 + 1 > len)//������û���Һ���
            nextPos = pos * 2;
        else
        {
            if(tree[pos*2] > tree[pos*2 + 1])
                nextPos = pos*2 + 1;
            else
                nextPos = pos*2;
        }
        if(tree[pos] > tree[nextPos])
        {
            swap(tree[pos], tree[nextPos]);
            adjDown(nextPos);
        }
    }
    Equation getAndRemoveTop()//��ȡ��������ֵ��ȥ���������
    {
        Equation top = tree[1];
        swap(tree[len], tree[1]);//��������ĩβ������
        len--;
        adjDown(1);
        return top;
    }
}Heap;
int main()
{
    Heap heap;
    Equation e;
    int n, m, a, b, c;
    cin>>n>>m;
    for(int i = 0; i < n; ++i)
    {
        cin>>a>>b>>c;
        heap.addVal(Equation(a, b, c, 1));
    }
    for(int i = 0;i < m; ++i)
    {
        e = heap.getAndRemoveTop();
        cout<<e.getVal()<<' ';
        e.x++;
        heap.addVal(e);
    }
    return 0;
}
