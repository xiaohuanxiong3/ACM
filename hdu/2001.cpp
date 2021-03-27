#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main()
{
	double x1,y1,x2,y2;
	cout<<setprecision(2)<<fixed;
	while(cin>>x1>>y1>>x2>>y2)
	{
		cout<<sqrt( (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1) )<<endl;
	}
	return 0;
 } 
