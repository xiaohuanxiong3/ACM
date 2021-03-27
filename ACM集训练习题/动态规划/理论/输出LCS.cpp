#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
string a,b;
int f[N][M];
int n,m,cnt;
char x[N];
void dfs( int i,int j){
	int k;
	if( i==0 || j==0 ){
		for( k=0;k<cnt;k++ )
			cout<<x[k]<<' ';
		cout<<endl;
		return;
	}
	if( a[i]==b[j] )
	{
		x[cnt++] = a[i];
		dfs(i-1,j-1);
	}
	else{
		if( f[i-1][j]>f[i][j-1] )
		{
			dfs(i-1,j);
		}
		else if( f[i-1][j]<f[i][j-1] )
			dfs(i,j-1);
		else
		{
			dfs(i-1,j);
			cnt--;
			dfs(i,j-1);
		}
	}	
} 
int main() {
	dfs(n,m);
	return 0;
	}

