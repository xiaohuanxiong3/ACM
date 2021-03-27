#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
#define N 105
int dp[N][N];  //记载以每个点可以滑行的最长区域
int a[N][N];
int r,c; 
int Mesch(int x,int y){
	if( dp[x][y]!=0 )
		return dp[x][y];
	if( x>1 ) //不是第一行 
	{
		 if( a[x-1][y]<a[x][y] )
			dp[x][y]=max(dp[x][y],Mesch(x-1,y)+1);
	}
	if( x<r )  //不是最后一行
	{
		 if( a[x][y]>a[x+1][y] )
			dp[x][y]=max(dp[x][y],Mesch(x+1,y)+1);	
	} 
	if( y>1 ) //不是第一列 
	{
		 if( a[x][y]>a[x][y-1])
			dp[x][y]=max(dp[x][y],Mesch(x,y-1)+1);
	} 
	if( y<c )
	{
		 if( a[x][y]>a[x][y+1] )
			dp[x][y]=max(dp[x][y],Mesch(x,y+1)+1);
	}
	return dp[x][y];
} 
int main(){	
	int i,j;
	while( scanf("%d%d",&r,&c)!=EOF ){
		for( i=1;i<=r;i++ )
			for( j=1;j<=c;j++ )
				scanf("%d",&a[i][j]);
		memset(dp,0,sizeof(dp));
		int m=-1;
		for( i=1;i<=r;i++ )
			for( j=1;j<=c;j++ )
			{	
				int tmp=Mesch(i,j);
				if( tmp>m )
					m=tmp;	
			}	
		printf("%d\n",m+1);
	}
	return 0;
}

