#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
#define N 22
int w,h; 
char board[N][N];
int vis[N][N];
int dir[4][2]={ {1,0},{-1,0},{0,1},{0,-1} };
bool canMove(int x,int y){
	if( x<0 || x>=h || y<0 || y>=w || board[x][y]=='#' || vis[x][y] )
		return false;
	return true;
} 
void dfs(int x,int y){
	int i,dx,dy;
	for( i=0;i<4;i++ ){
		dx = x +dir[i][0];
		dy = y +dir[i][1];
		if( canMove(dx,dy) )
		{
			vis[dx][dy]=1;  //值不变回0 
			dfs(dx,dy);
		}	
	}
}
int main() {
	int i,j,sx,sy,ans;
	while( scanf("%d%d",&w,&h) && !( w==0 && h==0 ) ){
		for(i=0;i<h;i++ ){
			for(j=0;j<w;j++ ){
				cin>>board[i][j];
				vis[i][j]=0;
				if( board[i][j]=='@' )
				{
					sx=i;
					sy=j;
				}
			}
		}
		dfs(sx,sy);
		vis[sx][sy]=1;
		ans=0;
		for( i=0;i<h;i++ ){
			for( j=0;j<w;j++ )
				if( vis[i][j] )
					ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
	}

