#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
#define N 22
int n,cnt; 
int vis[N],a[N];
bool isprime(int a){
	int i;
	if( a%2==0 && a!=2 ) return false;
	if( a==2 ) return true;
	for(i=3;i*i<=a;i+=2)
		if( a%i==0 )
			return false;
	return true;
}
void dfs(int dep){
	int i;
	if( dep>=n ){
		for( i=0;i<n;i++ )
		{
			cout<<a[i];
			if( i!=n-1 )
				cout<<" ";
		}
		cout<<endl; 
		return;
	}
	for( i=1;i<=n;i++ )
	{
		if( !vis[i] )
		{
			if( dep<n-1 ){
				if( isprime( i + a[dep-1] ) ){
					vis[i]=1;
					a[dep]=i;
					dfs(dep+1);
					vis[i]=0;				
				}
			}
			if( dep==n-1 )
			{
				if( isprime( i + a[dep-1] ) && isprime( i + a[0] ) )
				{
					vis[i]=1;
					a[dep]=i;
					dfs(dep+1);
					vis[i]=0;
				} 
			}
		}
	}
}
int main() {
	int i;
	cnt=1;
	while( cin>>n )
	{
		memset(vis,0,sizeof(vis));
		memset(a,0,sizeof(a));
		a[0]=1;
		vis[1]=1;
		printf("Case %d:\n",cnt++);
		dfs(1);
		cout<<endl;
	}
	return 0;
	}

