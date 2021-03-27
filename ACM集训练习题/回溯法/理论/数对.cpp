//7¶ÔÊý×Ö 
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
#define N 14
int x[N],vis[8];
void dfs(int dep){
	if( dep>=5 ){
		int i;
		for( i=0;i<N;i++ )
			cout<<x[i]<<' ';
		cout<<endl;
		return;
	}
	int index,i;
	for(i=0;i<N;i++ )
		if( !x[i] )
		{
			index=i;
			break;
		}
	for( i=1;i<=7;i++ ){
		if( !vis[i] &&  index+i+1<N && !x[ index+i+1 ] ){
			vis[i]=1;
			x[index]=x[index+i+1]=i;
			dfs(dep+1);
			vis[i]=0;
			x[index]=x[index+i+1]=0;
		}	
	}
}
int main() {
	x[0]=x[8]=7,x[1]=x[6]=4;
	vis[7]=vis[4]=1;
	dfs(0);
	return 0;
	}

