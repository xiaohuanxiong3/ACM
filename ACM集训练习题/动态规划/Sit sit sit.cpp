#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
#define N 102
#define mod 1000000007
long long dp[N][N],c[N][N];
int a[N];
int main() {
	int n;
	int r,i,j,k;
	for( i=1;i<=110;i++ )
	{
		c[i][0]=c[i][i]=1;
		for( j=1;j<i;j++ )
			c[i][j]=( c[i-1][j-1]+c[i-1][j] )%mod;
	}
	while( scanf("%d",&n)!=-1 ){
		memset(dp,0,sizeof(dp));
		for( i=1;i<=n;i++ )
			scanf("%d",&a[i]);
		a[0]=a[2];
		a[n+1]=a[n-1];
		for( i=1;i<=n;i++ )
			dp[i][i]=1;
		for( i=1;i<=n-1;i++ )
			dp[i][i+1]=2;
		for( r=3;r<=n;r++ ){
			for( i=1;i<=n-r+1;i++ ){
				j=i+r-1;
				dp[i][j]+=( dp[i+1][j]+dp[i][j-1] )%mod;
				for( k=i+1;k<=j-1;k++ )
					if( !a[k-1]^a[k+1] ) //最后一个坐的人两边椅子同色 
						dp[i][j]=( dp[i][j]+dp[i][k-1]*dp[k+1][j]%mod*c[j-i][k-i]%mod )%mod;
			}
		}
		printf("%lld\n",dp[1][n]);
	}
	return 0;
	}

