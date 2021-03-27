#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
#define N 5
int a[]={1,1,2,3},x[5];
int n=4; 
int vis[N];  //vis[i]=0:表示第i个元素未使用过,=1表示被使用过 
void dfs(int dep){
	int i;
	if( dep>=n ){
		for( i=0;i<n;i++ )
			cout<<x[i]<<" ";
		cout<<endl;
		return;
	}
	for( i=0;i<4;i++ ){
		if( !vis[i] ){
			x[dep]=a[i];
			vis[i] = 1;
			dfs(dep+1);
			vis[i] = 0;
		}
	}
}
int main() {
	dfs(0);
	return 0;
	}

