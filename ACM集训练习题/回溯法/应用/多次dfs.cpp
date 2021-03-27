#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
#define N 102
int m,n,ans,cnt; 
char board[N][N];
int vis[N][N];
int dir[8][2]={{-1,-1},{1,-1},{-1,1},{1,1},{1,0},{-1,0},{0,1},{0,-1}};
bool canMove(int x,int y){
	if( x<0 || x>=m || y<0 || y>=n || board[x][y]=='*' || vis[x][y] )
		return false;
	return true;
} 
void dfs(int x,int y){
 /*	for( i=0;i<m;i++ ){
		for( j=0;j<n;j++ ){
			if( board[i][j]=='@' && !vis[i][j] )
			{
				x=i,y=j;
				flag=1;
			}
		}
	}  */
		int i,dx,dy;
		for( i=0;i<8;i++ ){
			dx = x +dir[i][0];
			dy = y +dir[i][1];
			if( canMove(dx,dy) )
			{
				vis[dx][dy]=1;  //值不变回0 
				cnt++;
				dfs(dx,dy);
			}	
		}
}
int main() {
	int i,j,x,y,flag,ret;
	while( scanf("%d%d",&m,&n) && !( m==0 && n==0 ) ){
		ret=0;
		for(i=0;i<m;i++ ){
			for(j=0;j<n;j++ ){
				cin>>board[i][j];
				vis[i][j]=0;
				if( board[i][j]=='@' )
					ret++;
			}
		}
		ans=0,cnt=0;
		while( cnt!=ret ){
			ans++;
			flag=0;
			for( i=0;i<m;i++ )
			{
				for( j=0;j<n;j++ )
				{
					if( board[i][j]=='@' && !vis[i][j] ){
						x=i,y=j;
						vis[i][j]=1;
						cnt++;
						flag=1;
						break;
					}
				}
				if( flag )
					break;
			}
			dfs(x,y);
		}
		cout<<ans<<endl;
	}
	return 0;
}

