#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<vector> 
#include<iomanip>
#include<cmath>
using namespace std;
int fun(int m,int n)
{
	if( m==0 || n==1 )
		return 1;
	else if( n>m )
		return fun(m,m);
	else
	{
		return fun(m-n,n)+fun(m,n-1);  //每个盘子里面至少放一个或至少有一个盘子放0个 
	}
} 
int main() {
	ios::sync_with_stdio(false);
	string str;
	int i,m,n;
	int t;
	cin>>t;
	while( t-- )
	{
		cin>>m>>n;
		int ans=fun(m,n);
		cout<<ans<<endl;
	} 
	return 0;
}

