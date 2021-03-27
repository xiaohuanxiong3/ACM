#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
#define N 12
#define k 5
char a[N+2];
char ans[k];
char x[k];
int vis[N],n,flag;
void dfs(int dep)
{
	if( dep>=k )
	{
		if( ans[0]-'A'+1-pow(ans[1]-'A'+1,2)+pow(ans[2]-'A'+1,3)-pow(ans[3]-'A'+1,4)+pow(ans[4]-'A'+1,5) == n )
		{
	//		cout<<ans[0]<<ans[1]<<ans[2]<<ans[3]<<ans[4]<<endl;
			if( strcmp(ans,x)>0 )
				x[0]=ans[0],x[1]=ans[1],x[2]=ans[2],x[3]=ans[3],x[4]=ans[4];
			flag=1;
		}	
		return;
	}
	int i;
	for( i=0;i<strlen(a);i++ )
	{
		if( !vis[i] )
		{
			vis[i]=1;
			ans[dep]=a[i];
			dfs(dep+1);
			vis[i]=0;
			ans[dep]=' ';
		}
	}
}
int main() {
	int i;
	while( cin>>n>>a && !( n==0 && strcmp(a,"END")==0 ) )
	{
		memset(vis,0,sizeof(vis));
		for(i=0;i<k;i++)
			x[i]=' ';
		flag=0;
		dfs(0);
		if( flag )
		{
			for(i=0;i<k;i++)
				cout<<x[i];
			cout<<endl;
		}
		else
			cout<<"no solution\n";
	}
	return 0;
	}

