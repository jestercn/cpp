#include <bits/stdc++.h>
using namespace std;
bool visited[10005];//���������4λ���ļ���
int que[50000], head, tail;

//�������飬ת��Ϊ���֣���{0,2,1}ת��Ϊ120
//arr���������� arr[0]�����λ��arr[4]�����λ�� n�����鳤�� 
int toNum(int arr[], int n)
{
    int pow = 1, s = 0; 
    for(int i = 0; i < n; ++i)
    {
        s += arr[i]*pow;
        pow *= 10;
    }
    return s;
}
int main()
{
    int n, k, x[20], y[20], num, d, count = 0;
    cin>>n>>k;
    for(int i = 0; i < k; ++i)//����任���� 
        cin>>x[i]>>y[i];
    que[++tail] = n;//������� 
    while(head!=tail)//ֱ���ӿ� 
    {
        num = que[++head];//���ֳ��� 
        if(visited[num] == false)
        {
            visited[num] = true;
            count++;
            int numArr[5], na_i = 0;//�����λ�� ��numArr[0]�����λ��numArr[4]�����λ ����nС�ڵ���2000����������4��λ�ü��� 
            for(int a = num; a > 0; a /= 10)
            {
                numArr[na_i++] = a % 10;//ĳһλ�� ���� 
            }
            for(int i = 0; i < na_i; ++i)//���ڴӵ�λ����λÿλ���� 
            {
                for(int j = 0; j < k; ++j)//j����k���任���� 
                {
                    if(numArr[i] == x[j])//���ݹ���任���� 
                    {
                        numArr[i] = y[j];//��numArr��Ϊ�任������� 
                        que[++tail] = toNum(numArr, na_i);//��numArr��ϳ������֣���� 
                        numArr[i] = x[j];//numArr��ԭ 
                    }  
                }
            }
        }
    }
    cout<<count; 
	return 0;
}
