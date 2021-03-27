#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
// 迷宫
#define N 12
char board[N][N];
bool DFS(int x,int y,int depth){
	if( x<1 || x>10 || y<1 || y>10 )
		return true;
	if( depth > 120 ) //走遍迷宫也没走出去 
		return false;
	switch( board[x][y] ){
		case 'U':
			if( DFS(x-1,y,depth+1) )
				return true;
			break;
		case 'D':
			if( DFS(x+1,y,depth+1) )
				return true;
			break;
		case 'L':
			if( DFS(x,y-1,depth+1) )
				return true;
			break;
		case 'R':
			if( DFS(x,y+1,depth+1) )
				return true;
	}
} 
int main(){
	int i,j;
	for( i=1;i<=10;i++ ){
		for( j=1;j<=10;j++ ){
			cin>>board[i][j];
		}
	}
	int res = 0;
	for( i=1;i<=10;i++ )
		for( j=1;j<=10;j++ ){
			if( DFS(i,j,1) )
			{	
				res++;
			//	cout<<i<<' '<<j<<endl;	
			}	 
		}
	cout<<res<<endl;
	return 0;
}

