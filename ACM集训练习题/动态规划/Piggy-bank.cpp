#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
#define N 10002
#define INF 1<<30
int dp[N];
int w[502],c[502];
int main() {
	int i,j,k;
	int E,F,n;
	int t;
	scanf("%d",&t);
	while( t-- )
	{
		scanf("%d%d",&E,&F);
		int V=F-E;
//		int flag=0,value=INF,cnt=0; // flag表示是否有重量为1的,value记录所有重量为1的硬币的最小面值 
		scanf("%d",&n);
		for( i=1;i<=n;i++ ){
			scanf("%d%d",&w[i],&c[i]);
		}
		dp[0]=0;
		for( i=1;i<=V;i++ )
			dp[i]=INF;
		for( i=1;i<=n;i++ )
		{
			for( j=c[i];j<=V;j++ )
			{
				if( dp[j-c[i]]!=INF )
					dp[j]=min(dp[j],dp[j-c[i]]+w[i]);
			}
		}
		if( dp[V]==INF )
			printf("This is impossible.\n");
		else
			printf("The minimum amount of money in the piggy-bank is %d.\n",dp[V]);	
	}
	return 0;
	}

