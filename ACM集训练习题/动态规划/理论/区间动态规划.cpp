#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
#define N 102
#define INF 0x3f3f3f
//
int p[N],dp[N][N] = {0};
int main() {
	int i,j,k,r;
	int n;
	cin>>n;
	for( i=1;i<=n+1;i++ )
		cin>>p[i];
	for( i=1;i<=n;i++ )
		for( j=i+1;j<=n;j++ )
			dp[i][j]=INF;
	for( r=2;r<=n;r++ )
	{
		for( i=1;i<=n-r+1;i++ ){  //区间的左端点 
			j = i+r-1; //区间的右端点
			if( j>n )
				break;
			for( k=i;k<j;k++ ){
				dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]+p[i]*p[k+1]*p[j+1]); //考虑是p[j+1]还是p[j] 
			}
		}
	}
	return 0;
	}

