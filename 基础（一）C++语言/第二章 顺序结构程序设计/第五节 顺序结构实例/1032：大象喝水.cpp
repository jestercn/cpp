#include <bits/stdc++.h>
using namespace std;

int main()
{
	int h, r;
	const double PI = 3.14159;
	cin>>h>>r;
	cout<< ceil(20/(PI*r*r*h/1000));//PI*r*r*h是圆柱体积 单位立方厘米，即毫升。除1000后，单位为升。
	//ceil()是向上取整函数，20/圆柱体积，该值向上取整，即为周少喝几桶水，喝到的水才大于等于20升，即才能解渴 
	return 0;
}

