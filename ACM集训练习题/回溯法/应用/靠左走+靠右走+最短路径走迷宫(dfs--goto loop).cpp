#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
#define N 42
#define INF 1<<30
char board[N][N];
int vis[N][N],w,h,sx,sy,ex,ey,cnt_z,cnt_y,cnt,ret,flag;
int po;  //表示某一刻游客面向何方 0:西方,1:北方,2:东方,3:南方
int dir[4][2]={{0,-1},{-1,0},{0,1},{1,0}};
int ini(){ //初始化游客的面向 
	if( sx-1>=0 && board[sx-1][sy]=='.')  //初始面向北方 
		return 1;
	else if( sx+1<h && board[sx+1][sy]=='.' )  //南方
		return 3;
	else if( sy-1>=0 && board[sx][sy-1]=='.' ) //西方
		return 0;
	else if( sy+1<w && board[sx][sy+1]=='.' )  //东方
		return 2; 
}
bool canMove(int x,int y){
	if( board[x][y]=='#' || x<0 || x>=h || y<0 || y>=w || vis[x][y] )
		return false;
	return true;
}
void dfs_z(int x,int y){
	if( x==ex && y==ey )
	{
		flag=1;
		return;
	}
	int i;
	loop:switch( po ){
		case 0:  //面向西方 
			if( canMove(x+1,y) )  //优先向左走,否则向前走 (注意是沿墙向左走) 
			{
				po=3;
				cnt_z++;
				vis[x+1][y]=1;
				dfs_z(x+1,y);
				if( flag )
					return;
				cnt_z++;
				po=1;
				goto loop; 
			}
			if( canMove(x,y-1) ){
				cnt_z++;
				vis[x][y-1]=1;
				dfs_z(x,y-1);
				if( flag )
					return;
				cnt_z++;
				po=2;
				goto loop;
			}
			if( canMove(x-1,y))
			{
				po=1;
				cnt_z++;
				vis[x-1][y]=1;
				dfs_z(x-1,y);
				if( flag )
					return;
				cnt_z++;
				po=3;
				goto loop;
			}
			break;
		case 1:
			if( canMove(x,y-1) )
			{
				cnt_z++;
				po=0;
				vis[x][y-1]=1;
				dfs_z(x,y-1);
				if( flag )
					return;
				cnt_z++;
				po=2;
				goto loop;
			}
			if( canMove(x-1,y) ){
				cnt_z++;
				vis[x-1][y]=1;
				dfs_z(x-1,y);
				if( flag )
					return;
				cnt_z++;
				po=3;
				goto loop;
			}
			if( canMove(x,y+1) ){
				po=2;
				cnt_z++;
				vis[x][y+1]=1;
				dfs_z(x,y+1);
				if( flag )
					return;
				cnt_z++;
				po=0;
				goto loop;	
			}
			break;
		case 2:
			if( canMove(x-1,y) )
			{
				cnt_z++;
				po=1;
				vis[x-1][y]=1;
				dfs_z(x-1,y);
				po=2;
				if( flag )
					return;
				cnt_z++;
				po=3;
				goto loop;
			}
			if( canMove(x,y+1) ){
				cnt_z++;
				vis[x][y+1]=1;
				dfs_z(x,y+1);
				if( flag )
					return;
				cnt_z++;
				po=0;
				goto loop;
			}
			if( canMove(x+1,y) ){
				po=3;
				cnt_z++;
				vis[x+1][y]=1;
				dfs_z(x+1,y);
				if( flag )
					return;
				cnt_z++;
				po=1;
				goto loop;
			}
			break;
		case 3:
			if( canMove(x,y+1) ){
				cnt_z++;
				po=2;
				vis[x][y+1]=1;
				dfs_z(x,y+1);
				if( flag )
					return;
				cnt_z++;
				po=0;
				goto loop;
			}
			if( canMove(x+1,y) )  //优先向左走,否则向前走 
			{
				cnt_z++;
				vis[x+1][y]=1;
				dfs_z(x+1,y);
				if( flag )
					return;
				cnt_z++;
				po=1;
				goto loop;
			}
			if( canMove(x,y-1) )
			{
				cnt_z++;
				po=0;
				vis[x][y-1]=1;
				dfs_z(x,y-1);
				if( flag )
					return;
				cnt_z++;
				po=2;
				goto loop;
			}
			break;
	}
}
void dfs_y(int x,int y){
	if( x==ex && y==ey )
	{
		flag=1;
		return;
	}
	int i;
	loop:switch( po ){
		case 0:  //面向西方 
			if( canMove(x-1,y))
			{
				po=1;
				cnt_y++;
				vis[x-1][y]=1;
				dfs_y(x-1,y);
				if( flag )
					return;
				cnt_y++;
				po=3;
				goto loop;
			}
			if( canMove(x,y-1) ){
				cnt_y++;
				vis[x][y-1]=1;
				dfs_y(x,y-1);
				if( flag )
					return;
				cnt_y++;
				po=2;
				goto loop;
			}
			if( canMove(x+1,y) )  //优先向左走,否则向前走 (注意是沿墙向左走) 
			{
				po=3;
				cnt_y++;
				vis[x+1][y]=1;
				dfs_y(x+1,y);
				if( flag )
					return;
				cnt_y++;
				po=1;
				goto loop; 
			}
			break;
		case 1:
			if( canMove(x,y+1) ){
				po=2;
				cnt_y++;
				vis[x][y+1]=1;
				dfs_y(x,y+1);
				if( flag )
					return;
				cnt_y++;
				po=0;
				goto loop;	
			}
			if( canMove(x-1,y) ){
				cnt_y++;
				vis[x-1][y]=1;
				dfs_y(x-1,y);
				if( flag )
					return;
				cnt_y++;
				po=3;
				goto loop;
			}
			if( canMove(x,y-1) )
			{
				cnt_y++;
				po=0;
				vis[x][y-1]=1;
				dfs_y(x,y-1);
				if( flag )
					return;
				cnt_y++;
				po=2;
				goto loop;
			}
			break;
		case 2:
			if( canMove(x+1,y) ){
				po=3;
				cnt_y++;
				vis[x+1][y]=1;
				dfs_y(x+1,y);
				if( flag )
					return;
				cnt_y++;
				po=1;
				goto loop;
			}
			if( canMove(x,y+1) ){
				cnt_y++;
				vis[x][y+1]=1;
				dfs_y(x,y+1);
				if( flag )
					return;
				cnt_y++;
				po=0;
				goto loop;
			}
			if( canMove(x-1,y) )
			{
				cnt_y++;
				po=1;
				vis[x-1][y]=1;
				dfs_y(x-1,y);
				po=2;
				if( flag )
					return;
				cnt_y++;
				po=3;
				goto loop;
			}
			break;
		case 3:
			if( canMove(x,y-1) )
			{
				cnt_y++;
				po=0;
				vis[x][y-1]=1;
				dfs_y(x,y-1);
				if( flag )
					return;
				cnt_y++;
				po=2;
				goto loop;
			}
			if( canMove(x+1,y) )  //优先向左走,否则向前走 
			{
				cnt_y++;
				vis[x+1][y]=1;
				dfs_y(x+1,y);
				if( flag )
					return;
				cnt_y++;
				po=1;
				goto loop;
			}
			if( canMove(x,y+1) ){
				cnt_y++;
				po=2;
				vis[x][y+1]=1;
				dfs_y(x,y+1);
				if( flag )
					return;
				cnt_y++;
				po=0;
				goto loop;
			}
			break;
	}
}
void dfs(int x,int y){
	if( x==ex && y==ey )
	{
		ret=min(ret,cnt);
		return;
	}
	int i,dx,dy;
	for( i=0;i<4;i++ ){
		dx = x + dir[i][0];
		dy = y + dir[i][1];
		if( canMove(dx,dy) )
		{
			cnt++;
			vis[dx][dy]=1;
			dfs(dx,dy);
			vis[dx][dy]=0;
			cnt--; 
		}
	}
}
int main() {
	int i,j,t;
	cin>>t;
	while( t-- )
	{
		scanf("%d%d",&w,&h);
		for( i=0;i<h;i++ )
			for( j=0;j<w;j++ )
			{
				cin>>board[i][j];
				vis[i][j]=0;
				if( board[i][j]=='S' ){
					sx=i,sy=j;
				}
				else if( board[i][j]=='E' ){
					ex=i,ey=j;
				}
			}
		int pot=ini();  //求出初始面向何方 
		
		po=pot,cnt_z=0,flag=0;
		dfs_z(sx,sy);
		for( i=0;i<h;i++ ){
			for( j=0;j<w;j++ )
				vis[i][j]=0;
		}
		po=pot,cnt_y=0,flag=0;
		dfs_y(sx,sy);
		for( i=0;i<h;i++ ){
			for( j=0;j<w;j++ )
				vis[i][j]=0;
		}
		po=pot,cnt=0,ret=INF,flag=0;
		dfs(sx,sy);
		cout<<cnt_z+1<<" "<<cnt_y+1<<" "<<ret+1<<endl;
	}
	return 0;
	}

