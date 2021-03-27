#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
#define N 10002 
int vis[N]; 
int main(){
	int n,m,cnt=1,i,k;
	cin>>n>>m;
	k=0;
	while( cnt<n ){
		if( vis[k] )
			continue;
		k = (k+1)%n;
		c++;
		if( c==m )
		{
			vis[k] = 1;
			c=0;
			cnt++;
		}
	}
	return 0;
}

