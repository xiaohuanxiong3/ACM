#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	int n,m,i,j;
	int num;
	double ans=0;
	int x;
	while(cin>>n>>m)
	{
		num=n/m;
		x=2;
		for(i=1;i<=num;i++)  //num个 m个连续整数
		{
			for(j=1;j<=m;j++)
			{
				ans+=x;
				x+=2;
			}
			cout<<ans/m;
			if(i<num)
			{
				cout<<" ";
			}
			else if(i>=num)
				{
					if(num*m<n)
						cout<<" ";
				}
			ans=0;
		}
		if(m*num>=n)
			cout<<endl;
		for(i=num*m+1;i<=n;i++)
		{
			ans+=x;
			x+=2;
		}
		if(ans!=0)
			cout<<ans/(n-m*num)<<endl;
		ans=0;
	}
	return 0;
}
