#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
//数独
#define N 9
int board[N][N];
int cnt=0;
bool judge(int row,int col,int value){
	int r=row/3*3,c=col/3*3,i,j;
	for( i=r;i<=r+2;i++ )  //九宫格的判断 
		for( j=c;j<=c+2;j++ )
			if( value==board[i][j] )
			{	
				return false;
			}
	for( i=0;i<N;i++ )
		if( i!=row && value==board[i][col] )  //这列有元素重复 
			{
				return false;
			}
	for( i=0;i<N;i++ )
		if( i!=col && value==board[row][i] )  //这行有元素重复
		{
			return false;
		}
	return true; 
}
void dfs(int dep){
	int i,j;
	if( dep>=cnt ){	
		cout<<endl;
		for( i=1;i<=20;i++ )
			cout<<"-";
		cout<<endl;
		for( i=0;i<N;i++ )
		{
			for( j=0;j<N;j++ )
			{
				cout<<board[i][j]<<" ";
			}
			cout<<endl;
		}
		return;
	}
	int row,col,flag=1;
	for( i=0;i<N;i++ )
	{
		for( j=0;j<N;j++ )
		{
			if( board[i][j]==0 )
			{
				row=i;
				col=j;
				flag=0;
				break;
			}
		}
		if( !flag )
			break;
	}
	for( i=1;i<=9;i++ ){
		if( judge(row,col,i) )
		{
			board[row][col]=i;
			dfs(dep+1);
			board[row][col]=0;
		}
	}
}
int main() {
	int i,j;
	for( i=0;i<N;i++ ){
		for(j=0;j<N;j++ )
		{
			cin>>board[i][j];
			if( !board[i][j] )
				cnt++;
			}
	}
//	cout<<cnt<<endl;
	dfs(0);
	return 0;
	}

