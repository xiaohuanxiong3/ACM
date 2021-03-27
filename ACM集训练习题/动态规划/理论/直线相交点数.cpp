#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
#define N 22
int dp[N][N*(N-1)/2]; 
int main() {
	int n,i,r,j;
	while( cin>>n )   //也可不用二维数组,用set实现 
	{
		for( i=1;i<=n;i++ )
			dp[i][0]=1;
		for( i=1;i<=n;i++ )
			for( r=0;r<i;r++ )  //与新加直线平行的数量为i-r 
			{
				for( j=0;j<=r*(r-1)/2;j++ )  //判别r条直线的所有可能交点数 
				{
					if( dp[r][j] )
						dp[i][(i-r)*r+j]=1;
				}
			}
		for( i=0;i<=n*(n-1)/2;i++ )
			if( dp[n][i] )
			{
				cout<<i;
				if( i!=n*(n-1)/2 )
					cout<<' '; 
			} 
		cout<<endl;
	}
	return 0;
	}

