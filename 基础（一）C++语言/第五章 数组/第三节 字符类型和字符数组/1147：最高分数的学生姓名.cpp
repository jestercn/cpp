#include<bits/stdc++.h>
using namespace std;
typedef struct
{
	int score;
	char name[21];
}Student;

int main()
{
    int n, mx_i = 0;//mx_i:分数最高的学生的下标 
    cin>>n;
    Student stu[105];
    for(int i = 0; i < n; ++i)
    {
    	cin>>stu[i].score>>stu[i].name;
    	if(stu[i].score > stu[mx_i].score)
    		mx_i = i;
	}
	cout<<stu[mx_i].name;
	return 0;
}
