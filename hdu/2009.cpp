#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
	int m,n,i;
	double ans=0;
	cout<<setprecision(2)<<fixed;
	while(cin>>n>>m)
	{
		double x=n;
		ans+=x;
		for(i=1;i<=m-1;i++)
		{
			x=sqrt(x);
			ans+=x;
		}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
} 
