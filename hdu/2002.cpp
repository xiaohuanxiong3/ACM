#include<iostream>
#include<cmath>
#include<iomanip>
#define PI 3.1415927
using namespace std;

int main()
{
	double x;
	cout<<setprecision(3)<<fixed;
	while(cin>>x)
	{
		cout<<( PI*x*x*x*4/3 )<<endl; 
	}
	return 0;
 } 
