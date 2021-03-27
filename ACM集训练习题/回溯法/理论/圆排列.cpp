#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
#define k 3
#define n 6
int a[]={1,2,3,4,5,6};
int vis[6],x[6]={0},cnt=0;
void dfs(int st,int dep)
{
	if( dep>=k ){
		int i;
		for( i=0;i<k;i++ )
			cout<<x[i]<<' ';
		cnt++;
		cout<<endl;
		return;
	}
	else
	{
		int i;
		for( i=st+1;i<n;i++ ){
			if( !vis[i] )
			{
				vis[i]=1;
				x[dep]=a[i];
				dfs(st,dep+1);  //下一次取还是从st开始 
				vis[i]=0;
			}
		}
	}
} 
int main() {
	int i;
	for(i=0;i<=n-k+1;i++){
		x[0]=a[i];  //第一层已经定下来了 
		dfs(i,1);
	}		
	cout<<cnt<<endl;
	return 0;
	}

