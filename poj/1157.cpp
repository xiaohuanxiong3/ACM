#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
// dp[i][j] 前j个花瓶放i束花最大的aesthetic values
// dp[i][j]=max(dp[i-1][j-1]+a[i][j],dp[i][j-1]); 
// dp[i][i]=sum(a[k][k]) 1<=k<=i;
#define N 102
int dp[N][N];
int a[N][N]; //第i束花放在第j个花瓶产生的美学价值 
int main(){
	int f,v,i,j,r;
	scanf("%d%d",&f,&v);
	for( i=1;i<=f;i++ )
		for( j=1;j<=v;j++ )
			scanf("%d",&a[i][j]);
	dp[1][1]=a[1][1];
	for( i=2;i<=f;i++ )
	{
		dp[i][i]=dp[i-1][i-1]+a[i][i];
	}
	for( i=2;i<=v;i++ )
		dp[1][i]=max(dp[1][i-1],a[1][i]);
	for( i=2;i<=f;i++ )
	{
		for( j=i+1;j<=v;j++ )
		{
			dp[i][j]=max(dp[i-1][j-1]+a[i][j],dp[i][j-1]);
		}
	}
	printf("%d\n",dp[f][v]);
	return 0;
}

