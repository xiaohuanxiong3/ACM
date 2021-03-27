#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
#define N 102
#define V 10003
#define INF 0x3f3f3f3f
int c[N],w[N],dp[V];
int n,v;
int main() {
	int i,j;
	cin>>n>>v;
//	memset(dp,0,sizeof(0));  求能装进背包价值最大的方案 
	dp[0]=0;
	for( i=1;i<=v;i++ )
		dp[i]=-INF;  //求能装满背包价值最大的方案(有可能装不满) 
	for( i=0;i<n;i++ )
		cin>>c[i]>>w[i];
	for( i=0;i<n;i++ )
		for( j=v;j>=0;j-- )
		{
			if( dp[j-c[i]]!=-INF )
				dp[j]=max(dp[j],dp[j-c[i]]+w[i]);
		}
	if( dp[v]==-INF )
		cout<<"无解!\n";
	else
		cout<<dp[v]<<endl; 
	return 0;
	}

