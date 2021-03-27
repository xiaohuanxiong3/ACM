#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<vector> 
#include<iomanip>
#include<cmath>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	int i,j,k,n,flag=0;
	int mi[1002];
	int ans[1002];
	mi[3]=8;
	for( i=4;i<=1000;i++ )
	{
		if( mi[i-1]*2>=10000 )
			mi[i]=( mi[i-1]*2 )%10000;
		else
			mi[i]=mi[i-1]*2;
	}
	ans[1]=0,ans[2]=2,ans[3]=2;
	for( i=4;i<=1000;i++ )
	{
		if( ans[i-1]>mi[i-1] )
			ans[i]=mi[i-1] +10000 -ans[i-1];
		else
			ans[i]=mi[i-1]-ans[i-1]; 
	}
	while( cin>>n,n )
	{
		cout<<ans[n]<<endl;
	}
	return 0;
}

