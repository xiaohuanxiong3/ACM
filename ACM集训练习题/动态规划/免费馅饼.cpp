#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
#define N 100005
int dp[N][13];
int main() {
	int i,n,x,t,j,T;
	while( cin>>n,n ){
		memset(dp,0,sizeof(dp));
		T=-1;
		for( i=0;i<n;i++ )
		{
			scanf("%d%d",&x,&t);
			dp[t][x+1]++;  //��������Ϊ0ʱ����������� 
			if( t>T )
				T=t;
		}
		//ֻ�������λ����ȷ����,����! 
		for( i=T-1;i>=0;i-- )
			for( j=11;j>=1;j-- )
				dp[i][j]+=max(dp[i+1][j],max(dp[i+1][j+1],dp[i+1][j-1]));
		cout<<dp[0][6]<<endl;
	}
	return 0;
	}

