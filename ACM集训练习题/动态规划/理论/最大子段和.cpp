#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
#define N 10000003
int dp[N],st[N];
int main() {
	int i,n,x,t,cnt=1;
	scanf("%d",&t);
	while( t-- )
	{
		scanf("%d",&n);
		printf("Case %d:\n",cnt++);
		dp[0]=0;
		st[0]=1;
		for( i=1;i<=n;i++ )
		{
			scanf("%d",&x);
			if( dp[i-1]>=0 )
			{
				dp[i]=dp[i-1]+x;
				st[i]=st[i-1];
			}
			else
			{
				dp[i]=x;
				st[i]=i;
			}
		}
		int ans=-10000,index;
		for( i=1;i<=n;i++ )
		{
			if( dp[i]>ans )
			{
				ans=dp[i];
				index=i;
			}
		}
		cout<<ans<<' '<<st[index]<<' '<<index<<endl;
		if( t>0 )
			cout<<endl;
	}
	return 0;
	}

