#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	double x;
	cout<<setprecision(2)<<fixed;
	while(cin>>x)
	{
		if(x>=0)
			cout<<x<<endl;
		else
			cout<<x*(-1)<<endl;
	}
	return 0;
 } 
