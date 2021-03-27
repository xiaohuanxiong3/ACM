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
	string str;
	int i,m,n,j;
	long long ans[503]={0};
	ans[1]=1,ans[2]=5,ans[3]=13;
	for( i=4;i<=500;i++ )
	{
		for( j=1;j<=i-1;j++ )
			ans[i]+=j;
		ans[i]+=ans[i-1];
		ans[i]+=2*i-1;
		for( j=2;j<=i/2;j++ )
		{
			ans[i]+=i+1-2*j;
		}
	}
	while( cin>>n )
	{
		cout<<ans[n]<<endl;
	} 
	return 0;
}

