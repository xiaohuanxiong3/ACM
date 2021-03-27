#include <iostream>
#include <algorithm>
#include<string.h>
using namespace std;
const int inf=1<<30;
int T,S,D,n;
int map[1111][1111];
int vis[1111];
int cast[1111];
int e[1111];
void Dijkstra()
{
	memset(vis,0,sizeof(vis));  //判断顶点是否在 已找到了最短路径的点的集合S中 (0表示不在,1表示在) 
	int i,j,minn,pos;
	vis[0]=1;
	for( i=0;i<=n;i++ )
		cast[i]=map[0][i];
	for( i=1;i<=n;i++ )
	{
		minn=inf;
		for( j=1;j<=n;j++ )  //找不在集合S中的cast[j]最小的点 
		{
			if( cast[j]<minn && !vis[j] )
			{
				pos=j;
				minn=cast[j];
			}
		}
		vis[pos]=1;
		for( j=1;j<=n;j++ )  //重新给cast[j]赋值 
			if( cast[pos]+map[pos][j]<cast[j] && !vis[j] )   //!vis[j]应该是代码的优化
				cast[j]=cast[pos]+map[pos][j]; 		
	}
 } 
int main()  
{ 
	int i,j,x,y,z,start;
	while( cin>>T>>S>>D )
	{
		n=0;
		for( i=0;i<1111;i++ )
		{
			for(j=0;j<1111;j++)
			{
				if( j!=i )
					map[i][j]=inf;
				else
					map[i][j]=0;
			}
		}
		for( i=0;i<T;i++ )
		{
			scanf("%d%d%d",&x,&y,&z);
			n=max( max(n,x),y );
			if( z<map[x][y] )  //两个城市间可能有多条道路,只取最短的一条 
				map[x][y]=map[y][x]=z;  //两个城市间是双向联通的 
		}
		for( i=0;i<S;i++ )
		{
			scanf( "%d",&start );
			map[0][start]=map[start][0]=0;
		}
		for( i=0;i<D;i++ )
		{
			scanf( "%d",&e[i]);
		}
		Dijkstra();
		int minn=inf;
		for( i=0;i<D;i++ )
			minn=min( minn,cast[ e[i] ] );
		cout<<minn<<endl;
	}
	
	return 0;
}
