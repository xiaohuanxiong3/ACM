#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
#define N 5
char a[]={'a','b','c','d'};
int n=4; 
void dfs(int dep){
	int i;
	if( dep>=n ){
		for( i=0;i<n;i++ )
			cout<<a[i]<<" ";
		cout<<endl;
		return;
	}
	for( i=dep;i<4;i++ ){
		swap(a[dep],a[i]);
		dfs(dep+1);
		swap(a[dep],a[i]);
	}
}
int main() {
	dfs(0);
	return 0;
	}

