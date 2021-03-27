#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
#define N 8
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}}; 
int vis[N][N];
char map[N][N];
 // vector<char> map[N];  //ͼ������ͨ��ʹ��vector 
int n,m,s,sx,sy,ex,ey,ans;

bool canMove(int x,int y){
	if( x<0 || x>=n || y<0 || y>=m || vis[x][y] ){
		return false;
	}
	else if( map[x][y]=='X' )
		return false;
	return true;
}
int dfs(int x,int y,int dep){
	int i,dx,dy;
	if( x==ex && y==ey ){
		ans=dep;
		cout<<ans<<endl;
		return 1;
	}	
	for( i=0;i<4;i++ ){
		dx = x + dir[i][0];
		dy = y + dir[i][1];
		if( !canMove(dx,dy) ){
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
	cin>>n>>m>>s;
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
	vis[sx][sy]=1;
	if( dfs(sx,sy,0) )
		cout<<"���Ե���\n";
	else
		cout<<"���ɵ���\n"; 
	return 0;
	}

