#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
#define N 15
int n;
int dir[8][2] = {{-2,-1},{-2,1},{2,1},{2,-1},{1,2},{1,-2},{-1,2},{-1,-2}}; 
int vis[N][N],flag;

struct point{
	int x,y;
	int num;
	point():num(0){
	}
	bool operator < (point p) const{
		return num<p.num;
	}
};
bool canPut(int dx,int dy){
	if( dx<0 || dx>=n || dy<0 || dy>=n )
		return false;
	if( vis[dx][dy] )
		return false;
	return true;
}
int canPut_num(int x,int y){
	int i,dx,dy,cnt=0;
	for( i=0;i<8;i++ ){
		dx = x + dir[i][0];
		dy = y + dir[i][1];
		if( canPut(dx,dy) ){
			cnt++;
		}
	}
	return cnt;
}
int next(int x,int y,point ne[8]){
	int i,dx,dy,cnt=0;
	for( i=0;i<8;i++ ){
		dx = x + dir[i][0];
		dy = y + dir[i][1];
		if( canPut(dx,dy) ){
			ne[cnt].x = dx;
			ne[cnt].y = dy;
			ne[cnt++].num = canPut_num(dx,dy);
		}
	}
	sort(ne,ne+cnt);
	return cnt;
}
void dfs(int x,int y,int dep){
	int i,dx,dy,k;
	point ne[8];
	if( flag )
		return;
	if( dep>=n*n-1 ){
		cout<<"YES\n";
		flag=1;
		return;	
	}
	k = next(x,y,ne);
	for( i=0;i<k;i++ ){
		dx = ne[i].x;
		dy = ne[i].y;
		vis[dx][dy] = 1;
		dfs(dx,dy,dep+1);
		vis[dx][dy] = 0;
	} 
}
int main() {
	int x,y;
	cin>>n>>x>>y; 
	vis[x][y]=1;
	dfs(x,y,0);
	return 0;
	}

