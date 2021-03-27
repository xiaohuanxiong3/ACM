#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
#define N 404
char board[22][22];
struct node{
	int father;
	int rank;
	int num;
}uf[N]; 
int Find(int x){
	int k=x;
	while( k!=uf[k].father )
	{
		k=uf[k].father;
	}
	while( x!=uf[x].father ){
		int t=uf[x].father;
		uf[x].father=k;
		x=t;
	}
	return k;
}
void Union(int x,int y){
	x = Find(x);
	y = Find(y);
	if( x!=y ){
		if( uf[x].rank<uf[y].rank ){
			uf[x].father=y;
			uf[y].num += uf[x].num;
		}
		else
		{
			uf[y].father=x;
			uf[x].num += uf[y].num;
			if( uf[x].rank==uf[y].rank )
				uf[x].rank++;
		}
	}
}
int main() {
	int w,h,i,j,sx,sy;
	while( cin>>w>>h,w+h ){
		for( i=1;i<=w*h;i++ ){
			uf[i].father=i;
			uf[i].num=1;
			uf[i].rank=1;
		}
		for( i=1;i<=h;i++ ){
			for( j=1;j<=w;j++ ){
				cin>>board[i][j];
				if( board[i][j]=='@' )
				{
					sx=i,sy=j;
				}
			}
		}
		for( i=2;i<=w;i++ )
		{
			if( board[1][i]=='.' || board[1][i]=='@' ){
				if( ( i-1>=0 && board[1][i-1]=='.' ) || ( i-1>=0 && board[1][i-1]=='@' ) )
					Union(i,i-1);
			}
		}
		for( i=2;i<=h;i++ )
			for( j=1;j<=w;j++ ){
				int index=j+(i-1)*w; 
				if( board[i][j]=='.' || board[i][j]=='@' )
				{
					if( ( j-1>=0 && board[i][j-1]=='.' ) || ( j-1>=0 && board[i][j-1]=='@' ) )
						Union(index,index-1);
					if( ( i-1>=0 && board[i-1][j]=='.' ) || ( i-1>=0 && board[i-1][j]=='@' ) )
						Union(index,index-w);
				}
			}
		int e=Find(sy+(sx-1)*w);  //找到@对应节点的根节点 
		printf("%d\n",uf[e].num);
	//	cout<<uf[ Find(w*h) ].num<<endl;;
	}
	return 0;
	}

