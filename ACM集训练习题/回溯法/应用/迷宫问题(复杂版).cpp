#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cmath> 
using namespace std;
#define N 8
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}}; //�������� 
int vis[N][N];
char map[N][N];
 // vector<char> map[N];  //ͼ������ͨ��ʹ��vector 
int n,m,s,sx,sy,ex,ey,ans,t;
bool canMove(int x,int y,int cur){
	if( x<0 || x>=n || y<0 || y>=m || vis[x][y] ){
		return false;
	}
	else if( map[x][y]=='X' )
		return false;
	else if( x==ex && y==ey && t!=cur )
		return false;
	else if( abs(x-ex)+abs(y-ey) > t-cur )  //��ǰ�����յ����̾��������ʣ��ʱ��(��֦) 
		return false;
	else if( ( (x+y)&1 ) ^ ( (ex+ey)&1 ) ^ ( (t-cur)&1 ) ) //��ʱ������ʱ��ż��֦�Ǳ���� 
		return false;
	return true;
}
int dfs(int x,int y,int dep){
	int i,dx,dy;
	if( x==ex && y==ey && dep==t ){
		return 1;
	}	
	for( i=0;i<4;i++ ){
		dx = x + dir[i][0];
		dy = y + dir[i][1];
		if( !canMove(dx,dy,dep+1) ){
			continue;
		}
		vis[dx][dy]=1;
		if( dfs(dx,dy,dep+1) ) //ע���з���ֵ�Ĳ���ֱ�ӵ���dfs 
			return 1;
		vis[dx][dy]=0;
	}
	return 0;
}
int main() {
	int i,j;
	char ch;
	while( cin>>n>>m>>t,n+m+t )
	{
		for( i=0;i<n;i++ ){
			for( j=0;j<m;j++ ){
				cin>>ch;
				map[i][j]=ch;
				vis[i][j]=0;
				if( ch=='S' )   //�����������յ���������� 
				{
					sx=i;
					sy=j;
				}
				if( ch=='D' ){
					ex=i;
					ey=j;
				}
			}
		}
		if( !canMove(sx,sy,0) )
		{
			cout<<"NO\n";
			continue;
		}  
		vis[sx][sy]=1;
		if( dfs(sx,sy,0) )
			cout<<"YES\n";
		else
			cout<<"NO\n"; 
	}
	return 0;
	}

