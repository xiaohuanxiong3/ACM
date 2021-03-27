#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
// help jimmy
#define N 1002
#define INF 1<<30
int n,MAX,dp[N][2];
struct node{
	int lx,rx;
	int h;
	bool operator<(const node&n1) const{
		return h<n1.h;	
	}
}layer[N];

int down(int st,int x,int h){
	int j;
	for( j=st;j>=0;j-- ){
		if( h-layer[j].h>MAX )
			return -1; 
		if( x<=layer[j].rx && x>=layer[j].lx)  //加等号和不加等号区别很大,注意题目要求 
			return j;
		}
}
int main() {
	int i,j,sx,sy,lx,rx,dl,dr,t;
	cin>>t;
	while( t-- )
	{
		cin>>n>>sx>>sy>>MAX;
		layer[0].lx = layer[0].rx = sx;
		layer[0].h=sy;
		layer[1].lx = -INF;
		layer[1].rx = INF;
		layer[1].h=0;
		for( i=2;i<=n+1;i++ ){
			cin>>layer[i].lx>>layer[i].rx>>layer[i].h;
			if( layer[i].lx>layer[i].rx )
			{
				int tmp=layer[i].lx;
				layer[i].lx=layer[i].rx;
				layer[i].rx=tmp;
			}
		}
		sort(layer,layer+n+2);
		for( i=1;i<=n+1;i++ ){
			lx = layer[i].lx,rx = layer[i].rx;
			dl = down(i-1,lx,layer[i].h);
			dr = down(i-1,rx,layer[i].h);
			if( dl>0 )
				dp[i][0] = min(dp[dl][0] + lx- layer[dl].lx,dp[dl][1] + layer[dl].rx - lx);
			else if( dl==0 )
				dp[i][0] = 0; 
			else
				dp[i][0] = INF;
			if( dr>0 )
				dp[i][1] = min(dp[dr][0] + rx -layer[dr].lx,dp[dr][1] + layer[dr].rx - rx);
			else if( dr==0 )
				dp[i][1] = 0;
			else
				dp[i][1]=INF;
		//	cout<<dp[i][0]<<" "<<dp[i][1]<<endl; 
		}
		cout<<dp[n+1][0]+sy<<endl;
	}
	return 0;
	}

