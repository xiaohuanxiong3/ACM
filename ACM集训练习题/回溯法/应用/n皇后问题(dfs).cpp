#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
int n;
int x[12];
int board[12][12]; 
bool canPut(int row,int col){
	int i;
	for( i=1;i<col;i++ )  //第i列 
		if( x[i]==row || abs(row-x[i])==abs(col-i) )
			return false;
	return true; 
}
void dfs(int dep){
	int i,j;
	if( dep>n ){
		for( i=1;i<=n;i++ )
		{
			for( j=1;j<=n;j++ )
				if( x[j]==i )
					printf("Q");
				else
					printf(".");
			printf("\n");
		}
		cout<<endl; 
		return;
	}
	for( i=1;i<=n;i++ ){
		if( canPut(i,dep) ){  //看当前放在第i行第dep列是否可行 
 			x[dep]=i;
		//	board[i][dep]=1;	
			dfs(dep+1);
		//	x[dep]=0;
		//	board[i][dep]=0;
		}
	}
} 
int main() {
	while( scanf("%d",&n) && n)
	{
		memset(board,0,sizeof(board));
		memset(x,0,sizeof(x));
		dfs(1);
	}
	return 0;
	}

