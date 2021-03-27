#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
//Zipper dfs
#define N 202 
char a[N],b[N],c[2*N];
int vis[2*N];
int dfs(int dep,int index)
{
	int i;
	if( dep>=strlen(a) )
	{
		int cnt_b=0,flag=1;
		for( i=0;i<strlen(c);i++ )
		{
			if( !vis[i] && c[i]!=b[cnt_b] )
			{
				flag=0;
				break;
			}
			if( !vis[i] && c[i]==b[cnt_b] )
				cnt_b++;
		}
		if( flag )
			return 1;
		else
			return 0;
	}
	for( i=index;i<strlen(c);i++ )
	{
		if( !vis[i] )
		{
			if( c[i]==a[dep] )
			{
				vis[i]=1;
				if( dfs(dep+1,i+1) )
					return 1;
				vis[i]=0;		
			}
		}
	}
	return 0;
}
int main() {
	int i,j,t,cnt=1;
	cin>>t;
	while( t-- ){
		scanf("%s%s%s",&a,&b,&c);
		memset(vis,0,sizeof(vis));
		printf("Data set %d: ",cnt++); 
		if( dfs(0,0) )
			cout<<"yes\n";
		else
			cout<<"no\n";
	}
	return 0;
	}

