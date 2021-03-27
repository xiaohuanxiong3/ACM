#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
#define N 26
int board[N][N];
int dir[8][2]={{-1,-2},{1,-2},{-2,-1},{2,-1},{-2,1},{2,1},{-1,2},{1,2}};
int ans[N][2];  //0:存储第i步跳到第几行,1:第几列 
int t,p,q,flag;
bool canMove(int dx,int dy){
	if( dx<0 || dx>=p || dy<0 || dy>=q || board[dx][dy] )
		return false;
	return true;
}
void dfs(int x,int y,int dep){
	int i,dx,dy;
	if( dep>=p*q ){
		flag=1;
		for( i=0;i<p*q;i++ )
		{
			cout<<char(ans[i][1]+'A')<<ans[i][0]+1;
		}
		cout<<endl;
		return;
	}
	for( i=0;i<8;i++ ){
		dx = x + dir[i][0];
		dy = y + dir[i][1];
		if( canMove(dx,dy) ){
			board[dx][dy]=1;
			ans[dep][0]=dx,ans[dep][1]=dy;
			dfs(dx,dy,dep+1);
			board[dx][dy]=0;
			ans[dep][0]=0,ans[dep][1]=0;
			if( flag )
				return;
		}
	}
}
int main() {
	int i,j;
	cin>>t;
	int cnt1=1;
	while( t-- ){
		scanf("%d%d",&p,&q);
		flag=0;
		memset(ans,0,sizeof(ans));
		for(i=0;i<p;i++){
			for(j=0;j<q;j++ )  //p行q列
			{
				board[i][j]=0;
			} 
		}
		printf("Scenario #%d:\n",cnt1++);
		board[0][0]=1;
		ans[0][0]=0,ans[0][1]=0;
		dfs(0,0,1);
		if( !flag )
			printf("impossible\n");
		if( t>0 )
			cout<<endl;
	}
	return 0;
	}

