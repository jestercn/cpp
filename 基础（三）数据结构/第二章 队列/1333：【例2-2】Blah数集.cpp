#include <bits/stdc++.h>
using namespace std;
/*Ҫ����Blah������һ����������
��һ�ࣺ��2x+1���ɵ�
�ڶ��ࣺ��3x+1���ɵ�
��ô����������que2,que3���ֱ�洢��2x+1��3x+1���ɵ����֡�
Ȼ�����������ж��ױȽϣ��ĸ�С���ĸ����ӡ�
��һ������lastNum������һ�γ��ӵ����֣�����ʱ���ӵ����ֵ���lastNum����ô���������ӣ���Ϊ��������ͬ������1����������������ӡ�
�������Ӻ󣬽��ոճ��ӵ�������ΪlastNum������2*lastNum+1, 3*lastNum+1�ֱ����
ֱ������������n����ʱlastNum��Ϊ�����е�nС��Ԫ��
*/
//������������
int que2[1000005], que3[1000005];
int h_2, t_2, h_3, t_3;//�������е�ͷβָ��

//��ȡBlah�����ĵ�n������initNumΪ��ʼ����
int getBlahN(int initNum, int n)
{
    h_2=t_2=h_3=t_3=0;//�����������
    int count = 0, lastNum = initNum, tempNum;//count������lastNum��һ�γ��ӵ����֣�tempNum��ʱ����
    count++;
    que2[++t_2] = 2*lastNum + 1;//���
    que3[++t_3] = 3*lastNum + 1;
    while(count<n)
    {
        if(que2[h_2+1] < que3[h_3+1])//���ױȽ�
        {
            tempNum = que2[++h_2];//����2����
        }
        else if(que2[h_2+1] > que3[h_3+1])
        {
            tempNum = que3[++h_3];//����3����
        }
        else//������ȣ�������
        {
            tempNum = que2[++h_2];
            ++h_3;
        }
        if(lastNum != tempNum)//���ȡ������������һ�����ֲ���
        {
            count++;
            lastNum = tempNum;
            que2[++t_2] = 2*lastNum + 1;//���
            que3[++t_3] = 3*lastNum + 1;
        }
    }
    return lastNum;
}

int main()
{
    int a, n;
    while(cin>>a>>n)
    {
        cout<<getBlahN(a, n)<<endl;
    }
	return 0;
}
