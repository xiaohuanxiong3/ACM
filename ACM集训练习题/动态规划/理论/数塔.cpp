#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
#define N 102
int a[N][N],dp[N][N];
int n; 
int main() {
	int i,t,j;
	cin>>t;
	while( t-- )
	{
		memset(a,0,sizeof(a));
		memset(dp,0,sizeof(dp));
		cin>>n;
		for( i=1;i<=n;i++ ){
			for( j=1;j<=i;j++ ){
				cin>>a[i][j];
			}
		}
		dp[1][1]=a[1][1];
		for( i=2;i<=n;i++ ){
			for( j=1;j<=i;j++ ){
				dp[i][j]=max( dp[i-1][j-1],dp[i-1][j] ) + a[i][j];
			}
		}
		int ret=0;
		for( i=1;i<=n;i++ )
			if( dp[n][i]>ret )
				ret=dp[n][i];
		cout<<ret<<endl;
	}
	return 0;
	}

