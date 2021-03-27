#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
#define n 6
#define k 3
int a[]={1,2,3,4,5,6};
int vis[6],x[6]={0},cnt=0;
void dfs(int st,int dep)
{
	if( dep>=3 ){
		int i;
		for( i=0;i<3;i++ )
			cout<<x[i]<<' ';
		cnt++;
		cout<<endl;
		return;
	}
	else
	{
		int i;
		for( i=st;i<n;i++ ){
			x[dep]=a[i];
		//	dfs(i+1,dep+1);  //组合
			dfs(i,dep+1);  //重组合 
		}
	}
} 
int main() {
	dfs(0,0);
	cout<<cnt<<endl;
	return 0;
	}

