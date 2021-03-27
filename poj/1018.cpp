#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
#define N 102
#define min(a,b) (a<b)?(a):(b)
#define max(a,b) (a>b)?(a):(b)
#define INF 1<<30
int dp[N][1500];
int r[N];
struct node{
	int b,p;
}a[N][N];
int main(){
	int t,i,j,b,n;
	int maxb,minb; //最小带宽和最大带宽 
	scanf("%d",&t);
	while( t-- ){
		scanf("%d",&n);
		maxb=minb=0;
		for( i=1;i<=n;i++ )
		{
			scanf("%d",&r[i]);
			for( j=1;j<=r[i];j++ ){
				scanf("%d%d",&a[i][j].b,&a[i][j].p);
				minb=min(minb,a[i][j].b);
				maxb=max(maxb,a[i][j].b);
			}
		}
		for( i=minb;i<=maxb;i++ )
			dp[0][i]=0;
		for( i=1;i<=n;i++ ){
			for( b=minb;b<=maxb;b++ )
			{
				dp[i][b]=INF;
				if( dp[i-1][b]==INF )
					continue;
				for( j=1;j<=r[i];j++ )
				{
					if( a[i][j].b>=b )
						dp[i][b]=min(dp[i][b],dp[i-1][b]+a[i][j].p);
				}	
			}
		}
		double m=minb*1.0/dp[n][minb];
		for( b=minb+1;b<=maxb;b++ ){
			if(dp[n][b]!=INF && b*1.0/dp[n][b]>m )
				m=b*1.0/dp[n][b];
		}
		printf("%.3f\n",m);	
	}
	return 0;
}

