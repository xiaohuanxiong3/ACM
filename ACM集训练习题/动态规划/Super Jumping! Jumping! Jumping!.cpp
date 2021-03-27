#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
//Super Jumping! Jumping! Jumping!
#define N 1002
int a[N]; 
long long dp[N];  //dp[i]表示前面 以a[i]为最后一个元素 的 和最大 的严格递增子序列 
int main() {
	int i,n,j;
	while( scanf("%d",&n),n )
	{
		for( i=0;i<n;i++ )
			scanf("%d",&a[i]);
		dp[0]=a[0];
		int m;
		for( i=1;i<n;i++ )
		{
			m=0;
			for( j=0;j<i;j++ )
				if( a[j]<a[i] && dp[j]>m )
				{
					m=dp[j];
				}
			dp[i]=m+a[i];
		} 
		m=dp[0];
		for( i=1;i<n;i++ )
			if( dp[i]>m )
				m=dp[i];
		cout<<m<<endl;
	}
	return 0;
	}

