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
	memset(vis,0,sizeof(vis));  //�ж϶����Ƿ��� ���ҵ������·���ĵ�ļ���S�� (0��ʾ����,1��ʾ��) 
	int i,j,minn,pos;
	vis[0]=1;
	for( i=0;i<=n;i++ )
		cast[i]=map[0][i];
	for( i=1;i<=n;i++ )
	{
		minn=inf;
		for( j=1;j<=n;j++ )  //�Ҳ��ڼ���S�е�cast[j]��С�ĵ� 
		{
			if( cast[j]<minn && !vis[j] )
			{
				pos=j;
				minn=cast[j];
			}
		}
		vis[pos]=1;
		for( j=1;j<=n;j++ )  //���¸�cast[j]��ֵ 
			if( cast[pos]+map[pos][j]<cast[j] && !vis[j] )   //!vis[j]Ӧ���Ǵ�����Ż�
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
			if( z<map[x][y] )  //�������м�����ж�����·,ֻȡ��̵�һ�� 
				map[x][y]=map[y][x]=z;  //�������м���˫����ͨ�� 
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
