#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
#define N 1002
#define INF 1<<30
int matrix[N][N];
int ret[N][N]; //�洢����ǰi�еĺ� 
int dp[N],st[N];
int main() {
	int i,j,k,n;
	int max; //����Ӿ��� ��ʼ����(��������) 
	while( scanf("%d",&n)!=EOF )
	{
		memset(ret,0,sizeof(ret));
		for( i=1;i<=n;i++ )
		{
			for( j=1;j<=n;j++ ){
				scanf("%d",&matrix[i][j]);
				ret[i][j]=ret[i-1][j]+matrix[i][j]; 
			//	cout<<ret[i][j]<<' ';
			}
			// cout<<endl;
		}
		max=-INF;
		for( i=1;i<=n;i++ )  //n��
		{
			for( j=1;j<=n-i+1;j++ )  //�ӵ�j�е���n-i+1��  ÿ����ʼ��Ϊj,������Ϊj+i-1 
			{
			//	cout<<i<<' '<<j<<endl;
				dp[0]=0;
				for( k=1;k<=n;k++ ){  //�� 
					if( dp[k-1]>=0 )
					{
						dp[k]=dp[k-1]+ret[j+i-1][k]-ret[j-1][k];
					}
					else
					{
						dp[k]=ret[j+i-1][k]-ret[j-1][k];
					}
				}
				int tm=dp[1];
				for( k=2;k<=n;k++ )
					if( dp[k]>tm )
					{
						tm=dp[k];	
					}
				if( tm>max )
				{
					max=tm;
				}
			}
		} 
		cout<<max<<endl;
	}
	return 0;
	}


