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
	while( cin>>n )   //Ҳ�ɲ��ö�ά����,��setʵ�� 
	{
		for( i=1;i<=n;i++ )
			dp[i][0]=1;
		for( i=1;i<=n;i++ )
			for( r=0;r<i;r++ )  //���¼�ֱ��ƽ�е�����Ϊi-r 
			{
				for( j=0;j<=r*(r-1)/2;j++ )  //�б�r��ֱ�ߵ����п��ܽ����� 
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

