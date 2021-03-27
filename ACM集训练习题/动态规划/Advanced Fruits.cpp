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
// "�I"(��ζ��xi=yi��LCS��һ��Ԫ��)��ʾai��bj�����������������ai-1��bj-1���������������β������a[i](��b[j])�õ��������У�
// ��"��"��ʾai��bj������������к�ai-1��bj���������������ͬ��
// "��"��ʾai��bj������������к�ai��bj-1���������������ͬ��
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
			if( a[i-1]==b[j-1] )  // "�I"
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

