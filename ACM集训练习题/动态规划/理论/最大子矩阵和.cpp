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
	int i,j,k,n,m;
	int max,stx,sty,enx,eny; //����Ӿ��� ��ʼ����(��������) 
	while( scanf("%d%d",&n,&m) )
	{
		memset(ret,0,sizeof(ret));
		for( i=1;i<=n;i++ )
		{
			for( j=1;j<=m;j++ ){
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
				st[0]=1;
				for( k=1;k<=m;k++ ){  //�� 
					if( dp[k-1]>=0 )
					{
						dp[k]=dp[k-1]+ret[j+i-1][k]-ret[j-1][k];
						st[k]=st[k-1];
					}
					else
					{
						dp[k]=ret[j+i-1][k]-ret[j-1][k];
						st[k]=k;
					}
				}
				int sindex=1,eindex=1,tm=dp[1];
				for( k=2;k<=m;k++ )
					if( dp[k]>tm )
					{
						tm=dp[k];
						sindex=st[k];
						eindex=k;	
					}
				if( tm>max )
				{
					max=tm;
					stx=j,sty=sindex;
					enx=j+i-1,eny=eindex;
				//	cout<<stx<<' '<<sty<<' '<<enx<<' '<<eny<<endl;
				}
			}
		} 
		cout<<max<<endl;
	//	for( i=stx;i<=enx;i++ )
	//	{
	//		for( j=sty;j<=eny;j++ ){
	//			cout<<matrix[i][j]<<' ';
	//		}
	//		cout<<endl;
		}
	} 
	return 0;
	}

