#include <bits/stdc++.h>
using namespace std;

//�ⷨ1������˼�����������ʾ�ƣ�ģ�⿪�صƵ���Ϊ 
int main()
{
	bool light[5005];//��ʾ��״�������飬trueΪ���ƣ�falseΪ�ص� 
    int n, m;
    cin>>n>>m;
    for(int i = 1; i <= n; ++i)
        light[i] = true;
    for(int i = 1; i <= m; ++i)//iΪ�˱��
    {
        for(int j = 1; j <= n; ++j)//jΪ�ƺ�
        {
            if (j % i == 0)//����ƺ����˱�ŵı��� 
            { 
                if(light[j])//�ı�Ƶ�����״̬ 
                	light[j] = false;
                else
                	light[j] = true;
            } 
        }
    }
    
    bool firstNum = true;//��־λ���Ƿ������һ���� 
    for(int j = 1; j <= n; ++j)
    {
        if (light[j] == false)
        {
            if(firstNum)
                firstNum = false;
            else
                cout<<',';//���������һ����ʱ��Ҫ��������� 
            cout<<j; 
        }
    }
    return 0;
}
/* 
//�ⷨ2���������飬����˼��������ÿ���ƻᱻ�����Ĵ���
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;//nյ�� m���� 
    cout<<1;//1�ŵ�ֻ����һ���˲�����һ���ǹرյ� 
    for(int i = 2;i <= n; ++i)//��i�ᱻ���Ϊi�������˲��� 
    {
    	int c = 0;//�������ƸõƱ��������ٴ� 
        for(int j = 1;j <= m && j <= i; ++j)//��ô����1~m��1~i���м�������i����������ô�õƾͱ��������ٴΡ� 
        {
        	if(i % j == 0)
            	c++;
        }
        if(c % 2 == 1)//��ԭ�������ŵģ����������β����󣬵ƻ��� 
        	cout<<','<<i;
    }
    return 0;
} 
*/
