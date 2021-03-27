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
	long long ans[42];
	ans[1]=3,ans[2]=9;
	for( i=3;i<=40;i++ )
		ans[i]=2*ans[i-1]+ans[i-2]; 
	int t;
	cin>>t;
	while( t-- )
	{
		cin>>n;
		cout<<ans[n]<<endl;
	}
	return 0;
}

