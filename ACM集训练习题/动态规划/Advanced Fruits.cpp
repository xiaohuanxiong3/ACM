#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
//Advanced Fruits
#define N 104
int pre[N][N],dp[N][N];
char a[N],b[N]; 
// "↖"(意味着xi=yi是LCS的一个元素)表示ai与bj的最长公共子序列是由ai-1与bj-1的最长公共子序列在尾部加上a[i](或b[j])得到的子序列；
// 当"↑"表示ai与bj的最长公共子序列和ai-1与bj的最长公共子序列相同；
// "←"表示ai与bj的最长公共子序列和ai与bj-1的最长公共子序列相同。
void LCS()
{
	int i,j;
	int L1=strlen(a),L2=strlen(b);
	for( i=0;i<=L2;i++ )
	{
		dp[0][i]=0;
		pre[0][i]=1;
	}
	for( i=1;i<=L1;i++ )
	{
		dp[i][0]=0;
		pre[i][0]=3;
	}
	for( i=1;i<=L1;i++ )
	{
		for( j=1;j<=L2;j++ )
		{
			if( a[i-1]==b[j-1] )  // "↖"
			{
				dp[i][j]=dp[i-1][j-1]+1;
				pre[i][j]=2;
			}
			else if( dp[i][j-1]>=dp[i-1][j] )
			{
				dp[i][j]=dp[i][j-1];
				pre[i][j]=1;
			}
			else
			{
				dp[i][j]=dp[i-1][j];
				pre[i][j]=3;	
			}
		}
	}
}
void print(int l1,int l2)
{
	if( l1==0 && l2==0 )
		return;
	switch( pre[l1][l2] )
	{
		case 2:
			print(l1-1,l2-1);
			cout<<a[l1-1];
			break;
		case 1:
			print(l1,l2-1);
			cout<<b[l2-1];
			break;
		case 3:
			print(l1-1,l2);
			cout<<a[l1-1];
	}
}
int main() {
	while( scanf("%s%s",&a,&b)!=EOF )
	{
		int l1=strlen(a),l2=strlen(b);
		LCS();
		print(l1,l2);
		cout<<endl;
	}
	return 0;
	}

