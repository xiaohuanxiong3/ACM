#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
#define N 1003
double dis[N][N];
struct Point{
	int x,y;
}po[N];
struct node{
	int father;
	int flag;  //标记是否修好
	int rank; 
}uf[N];
int Find(int x){
	int k=x;
	while( k!=uf[k].father )
	{
		k=uf[k].father;
	}
	while( x!=uf[x].father )
	{
		int t=uf[x].father;
		uf[x].father=k;
		x=t;
	}
	return k;
} 
double Dis(Point p1,Point p2)  //求两点间距离 
{
	int x=p1.x-p2.x;
	int y=p1.y-p2.y;
	return  sqrt(x*x+y*y);
}
void Union(int x,int y)
{
	x = Find(x);
	y = Find(y);
	if( x!=y )
	{
		if( uf[x].rank<uf[y].rank )
		{
			uf[x].father=y;
		}
		else
		{
			uf[y].father=x;
			if( uf[x].rank==uf[y].rank )
				uf[x].rank++;
		}
	}
}
int main() {
	int n,d,i,j,x,y;
	char s;
	scanf("%d%d",&n,&d);
	for( i=1;i<=n;i++ )
	{
		uf[i].father=i;
		uf[i].flag=0;
		uf[i].rank=1;
	}
	for( i=1;i<=n;i++ )
	{
		scanf("%d%d",&po[i].x,&po[i].y);
	}
	for( i=1;i<=n;i++ )
	{
		for( j=1;j<=n;j++ )
		{
			dis[i][j]=Dis(po[i],po[j]);
		//	cout<<i<<' '<<j<<' '<<dis[i][j]<<endl;
		}
	} 
	while( scanf(" %c",&s)!=EOF )
	{
		if( s=='O' )
		{
			scanf("%d",&x);
			if( !uf[x].flag )
			{
				uf[x].flag=1;
				for( i=1;i<=n;i++ )
				{
					if( i!=x && uf[i].flag && dis[i][x]<=d )
					{
						Union(i,x); 
					}
				}
			}
		}
		else if( s=='S' )
		{
			scanf("%d%d",&x,&y);
		//	cout<<x<<' '<<y<<endl;
			if( !uf[x].flag || !uf[y].flag )
			{
				printf("FAIL\n");
				continue;
			}
			if( Find(x)==Find(y) )
				printf("SUCCESS\n");
			else
				printf("FAIL\n");
		}
	}
	return 0;
	}

