#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
#define N 22
int a[N];  
int s[N];
int state[530000];
int cchange(int d[])
{
    int x=0;
    for(int i=2;i<=20;i++,x<<=1)
    	if(d[i])
    		x|=1;
    return x>>1;
} 
int dfs(int a[],int move){
	int t[22];
	int i;
	for( i=2;i<=20;i++ )
		t[i]=a[i];
	t[move]=0;
	for( i=2;i+move<=20;i++ )
	{
		if( !t[i] )
			t[i+move]=0;   
	}
	int sg=cchange(t);
	if( state[sg]!=0 ) //状态已确定
	{
		if( state[sg]>0 ) //必胜点 
			return true;
		else
			return false;
	}
	else
	{
		for( i=2;i<=20;i++ ){
			if( t[i] && !dfs(t,i) ){ //必胜点 
				state[sg]=1;
				return true;
			}
		}	
	} 
	state[sg]=-1;
	return false;
}
int main(){
	int n,i;
	int x;
	int cnt=1;
	while( scanf("%d",&n) && n ){
		memset(a,0,sizeof(a));
		for( i=0;i<n;i++ )
		{
			scanf("%d",&x);
			a[x]=1;
		}
		printf("Test Case #%d\n",cnt++);
		int ret=0;
		for( i=2;i<=20;i++ )
			if( a[i] && !dfs(a,i) )
				s[++ret]=i;
		if( !ret )
			printf("There's no winning move.\n\n");
		else
		{
			printf("The winning moves are:");
			for( i=1;i<=ret;i++ )
			{
				printf(" %d",s[i]);
			}
			printf("\n\n");
		}
	}
	return 0;
}

