#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
#define N 103
int f[N][N];
int num[N][N]; 
int c[N],w[N];
int main() {
	int n,m,k,s;
	int i,j,v;
	while( scanf("%d%d%d%d",&n,&m,&k,&s)!=EOF ){
		for( i=1;i<=k;i++ )
			scanf("%d%d",&w[i],&c[i]);
		memset(f,0,sizeof(f));
		memset(num,0,sizeof(num));
		for( i=1;i<=k;i++ )  // 前i种怪物 
		{
			for( v=0;v<=m;v++ ) //  消耗k个忍耐度  
			{
				for( j=0;j*c[i]<=v;j++ )  //打j次 
				{
					if(  j+num[i-1][v-j*c[i]]<=s )
					{
						if( f[i-1][v-j*c[i]]+j*w[i]>f[i][v] )
						{
							f[i][v]=f[i-1][v-j*c[i]]+j*w[i];
							num[i][v]=j+num[i-1][v-j*c[i]];
						}
						else if( f[i-1][v-j*c[i]]+j*w[i]==f[i][v] )
							num[i][v]=min(num[i][v],j+num[i-1][v-j*c[i]]);
					}
				}
			}
		}
		int ma=m+1;
		for( i=1;i<=k;i++ )
		{
			for( j=0;j<=m;j++ )
			{
			//	cout<<f[i][j]<<' ';
				if( f[i][j]>=n )
					ma=min(ma,j);
			}
		//	cout<<endl;
		}
		printf("%d\n",m-ma);
	}
	return 0;
	}

