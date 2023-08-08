#include <bits/stdc++.h>
using namespace std;
//˼·�����ڽ���ǲ���ֵ��ĳ�����ĸı�ֻ�ᵼ�����ֽ�������ս�� �仯 �� ���䡣
//������ʽ��������д洢�������ֵ�ĸı��ܷ�ʹ���ڵ��ֵ�ı䡣
//����isChange���飬�洢��i�������仯���ܷ�Ӱ�����ս�������췽��Ϊ��isChange��ʼֵ��Ϊ0���Ӹ�������±������������ֵ�ı仯����Ӱ�츸�ڵ㣬��ô�������±�����
//���򲻶ϱ�����ֱ��������Ҷ�ӽ�㡣��Щ��������Ҷ�ӽ���Ӧ�ı�����������ı�����Ӱ�����ս���ı�����
//��󣬸������룬��isChange�����в�ѯ���
typedef struct Node
{
    int left, right;//���Һ��ӵ�ַ
    bool val;//ֵ
    bool inf;//���ڵ�ֵ�ĸı��Ƿ���Ӱ�츸���
    int x;//�ý��ı������(ָx��������ֱ�ţ���x1, x2, x3...)
}Node;
bool val[100005];//��x����ȡֵ
char s[1000005];
Node node[1000005];//����
int ni = 1;//�����±�
bool isChange[100005];//isChange[i] ��i�������仯���ܷ�Ӱ�����ս��

//isChAnd[a][b][c]: ����1������ֵ��a����2����ֵ��bʱ����c+1������ֵ�仯�ܷ�Ӱ������Ľ����
//��:0&0 = 0 ��һ����0��Ϊ1����ʽ��Ϊ1&0 = 0������Ӱ������������ô��isChAnd[0][0][0] = false;
bool isChAnd[2][2][2], isChOr[2][2][2];
void initIsCh()//��ʼ������isCh����
{
    isChAnd[0][0][0] = 0;  isChAnd[0][0][1] = 0;
    isChAnd[0][1][0] = 1;  isChAnd[0][1][1] = 0;
    isChAnd[1][0][0] = 0;  isChAnd[1][0][1] = 1;
    isChAnd[1][1][0] = 1;  isChAnd[1][1][1] = 1;

    isChOr[0][0][0] = 1;  isChOr[0][0][1] = 1;
    isChOr[0][1][0] = 0;  isChOr[0][1][1] = 1;
    isChOr[1][0][0] = 1;  isChOr[1][0][1] = 0;
    isChOr[1][1][0] = 0;  isChOr[1][1][1] = 0;
}

//���ظ��ڵ�ĵ�ַ
int initTree()
{
    stack<int> stk;//ջ����Ž���ַ
    int xNum = 0, np, lp, rp;
    char cal;//���������
    int len = strlen(s);
    for(int i = 0; i <= len; ++i)
    {
        if(s[i] >= '0' && s[i] <= '9')
            xNum = xNum * 10 + s[i] - '0';
        else if(s[i] == '&' || s[i] == '|' || s[i] == '!')
            cal = s[i];
        else if(s[i] == ' ' || s[i] == '\0')
        {
            if(xNum > 0)//��ȡ������x
            {
                np = ni++;//�ӽ���������
                node[np].val = val[xNum];//����ֵ
                node[np].x = xNum;//���ñ������
                stk.push(np);
                xNum = 0;
            }
            else//��ȡ�������
            {
                np = ni++;//�ӽ���������
                if(cal == '!')
                {
                    lp = stk.top();
                    stk.pop();
                    node[lp].inf = true;
                    node[np].val = !node[lp].val;
                    node[np].left = lp;
                }
                else
                {
                    rp = stk.top();//���ӵ�ַ
                    stk.pop();
                    lp = stk.top();//�Һ��ӵ�ַ
                    stk.pop();
                    node[np].left = lp;
                    node[np].right = rp;
                    if(cal == '&')//�����½�㣬���ý��ֵ�����ܷ�Ӱ���丸�ڵ�
                    {
                        node[np].val = node[lp].val && node[rp].val;
                        node[lp].inf = isChAnd[node[lp].val][node[rp].val][0];
                        node[rp].inf = isChAnd[node[lp].val][node[rp].val][1];
                    }
                    else if(cal == '|')
                    {
                        node[np].val = node[lp].val || node[rp].val;
                        node[lp].inf = isChOr[node[lp].val][node[rp].val][0];
                        node[rp].inf = isChOr[node[lp].val][node[rp].val][1];
                    }
                }
                stk.push(np);
            }
        }
    }
    return stk.top();//���ջ��ʣ�µ��Ǹ��ڵ�
}

//��������������ʼ��isChange����
void initIsChange(int p)
{
    if(node[p].inf)//����������Ӱ�츸�ڵ�
    {
        if(node[p].left == 0 && node[p].right == 0)
        {
            isChange[node[p].x] = true;
        }
        else
        {
            if(node[p].left != 0)
                initIsChange(node[p].left);
            if(node[p].right != 0)
                initIsChange(node[p].right);
        }
    }
}

int main()
{
    initIsCh();//��ʼ������isCh����
    int n, q, qi;
    bool res;//��������Ľ��
    gets(s);
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
        scanf("%d", &val[i]);
    int root = initTree();//����������ø����
    res = node[root].val;//���ݸ�������ʼֵ�õ��ļ�����
    node[root].inf = true;//Ϊ�����initIsChange��������������һ��
    initIsChange(root);//����isChange����
    scanf("%d", &q);
    for(int i = 1; i <= q; ++i)
    {
        scanf("%d", &qi);
        if(isChange[qi])//���qi�ı仯���������ս���ı仯
            printf("%d\n", !res);//���ս���仯��
        else
            printf("%d\n", res);//���ս��û��
    }
    return 0;
}
