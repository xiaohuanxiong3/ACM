#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
#define N 202
#define INF 1<<30
long long dp[N][N];
int a[N],b[N];
int main() {
	int i,j,r,k;
	int t,n;
	int cnt=1;
	scanf("%d",&t);
	while( t-- ){
		scanf("%d",&n);
		a[0]=0;
		for( i=1;i<=n;i++ )
			scanf("%d",&a[i]);
		a[n+1]=0;
		b[0]=0;
		for( i=1;i<=n;i++ )
			scanf("%d",&b[i]);
		b[n+1]=0;
		for( i=1;i<=n;i++ )
			dp[i][i]=a[i]+b[i-1]+b[i+1];
		for( r=2;r<=n;r++ )
		{
			for( i=1;i<=n-r+1;i++ )
			{
				j=i+r-1;
				dp[i][j]=min(dp[i+1][j]+a[i]+b[i-1]+b[j+1],dp[i][j-1]+a[j]+b[i-1]+b[j+1]);
				for( k=i+1;k<=j-1;k++ )
				{
					dp[i][j]=min(dp[i][j],dp[i][k-1]+dp[k+1][j]+a[k]+b[i-1]+b[j+1]);
				}
			}
		}
		printf("Case #%d: %lld\n",cnt++,dp[1][n]);
	}
	return 0;
	}

