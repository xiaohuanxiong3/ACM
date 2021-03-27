#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
#define N 120008
#define INF 1<<30
#define min(a,b) (a)<(b)?a:b 
//转化为0-1背包 
int f[N],a[N];
int main() {
	int k[6];
	int i,j,v;
	int cnt=1;
	while( scanf("%d%d%d%d%d%d",&k[0],&k[1],&k[2],&k[3],&k[4],&k[5]) && ( k[0]+k[1]+k[2]+k[3]+k[4]+k[5] ) )
	{
		printf("Collection #%d:\n",cnt++);
		int V=0,t=0;
		for( i=0;i<6;i++ )
		{
			V+=k[i]*(i+1);
			for( j=1;j<=k[i];j<<=1 )  //二进制优化 
			{
				a[t++]=j*(i+1);
				k[i]-=j;
			}
			if( k[i]>0 )
				a[t++]=k[i]*(i+1);
		}
		if( V%2 )
		{
			printf("Can't be divided.\n\n");
			continue;
		}
		V/=2;
		f[0]=0;
		for( i=1;i<=V;i++ )
			f[i]=INF;
		for( i=0;i<t;i++ )
		{
			for( v=V;v>=a[i];v-- )
				if( f[v-a[i]]!=INF )
					f[v]=min(f[v],f[v-a[i]]+a[i]);
		}
		if( f[V]!=INF )
			printf("Can be divided.\n\n");
		else
			printf("Can't be divided.\n\n");
	}
	return 0;
	}

