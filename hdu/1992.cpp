#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<vector> 
#include<iomanip>
#include<cmath>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	string str;
	int i,m,n,j;
	long long ans[503]={0};
	ans[1]=1,ans[2]=5,ans[3]=11;
	for( i=4;i<=500;i++ )
	{
		if( i%2==1 ) //ÆæÊý 
		{
			for( j=1;j<=i-3;j++ )
			{
				if( j%2==0 )
					ans[i]+=2*ans[j];
				else
					ans[i]+=3*ans[j];
			}
			ans[i]+=2; 
		} 
		else
		{
			for( j=1;j<=i-3;j++ )
			{
				if( j%2==0 )
					ans[i]+=3*ans[j];
				else
					ans[i]+=2*ans[j];
			}
			ans[i]+=3;
		}
		ans[i]+=4*ans[i-2]+ans[i-1];
	}
	int t;
	int cnt=1;
	cin>>t;
	while( t-- )
	{
		cin>>n;
		cout<<cnt++<<" "<<ans[n]<<endl;
	} 
	return 0;
}

