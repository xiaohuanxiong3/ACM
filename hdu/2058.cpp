#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int i,j,k;
	int n,m;
	cin>>n>>m;
	while( n>0 || m>0 )
	{
		int ans;
		for( i=sqrt(2*m);i>=1;i--)  //m是i项连续整数的和 
		{
			ans=( m-i*(i-1)/2 )/i;
			if( ans+i-1<=n )
			{
				if( ans*i+i*(i-1)/2==m )
					cout<<"["<<ans<<","<<ans+i-1<<"]"<<endl;
			}
		}
		cout<<endl;
		cin>>n>>m;
	} 
	return 0; 
}
