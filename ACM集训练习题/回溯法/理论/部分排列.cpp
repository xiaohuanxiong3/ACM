#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
int a[]={1,2,3,4,5,6};
int vis[6],x[6]={0},cnt=0;
void dfs(int dep)
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
		for( i=0;i<6;i++ ){
			if( !vis[i] )
			{
				vis[i]=1;
				x[dep]=a[i];
				dfs(dep+1); 
				x[dep]=0;
				vis[i]=0;
			}
		}
	}
} 
int main() {
	dfs(0);
	cout<<cnt<<endl;
	return 0;
	}

