#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
#define N 1003
char x[N],y[N];
int dp[N][N],cnt; 
char X[N];
int dfs( int i,int j){
	int k;
	if( i==0 || j==0 ){
		for( k=cnt-1;k>=0;k-- )
			cout<<X[k];
		cout<<endl;
		return 1;
	}
	if( x[i]==y[j] )
	{
		X[cnt++] = x[i];
		if( dfs(i-1,j-1) )
			return 1;
		cnt--;
	}
	else{
		if( dp[i-1][j]>dp[i][j-1] )
		{
			if( dfs(i-1,j) )
				return 1;
		}
		else if( dp[i-1][j]<dp[i][j-1] )
		{
			if( dfs(i,j-1) )
				return 1;
		}
		else
		{
			if( dfs(i-1,j) )
				return 1;
			if( dfs(i,j-1) )
				return 1;
		}
	}	
} 
int main() {
	int i,j;
	while( cin>>x+1>>y+1 )
	{
		x[0] = y[0] = '@';
		int lenx = strlen(x),leny = strlen(y); 
		for( i=0;i<lenx;i++ )
			dp[i][0]=0;
		for( j=0;j<leny;j++ )
			dp[0][j]=0;
		for( i=1;i<lenx;i++ )
			for( j=1;j<leny;j++ )
			{
				if( x[i]==y[j] )
					dp[i][j]=dp[i-1][j-1]+1;
				else
				{
					dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
				}
			}
		cout<<dp[lenx-1][leny-1]<<endl;
		dfs(lenx-1,leny-1);
	}
	return 0;
	}

