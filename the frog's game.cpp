#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
// frog's game
#define N 500002
int dis[N];
int m,n,l; //最多跳m次 
bool fun( int di ){
	int i;
	int cnt = 0;
	int d = 0;
	for( i=0;i<=n;i++ ){
		if( dis[i] - d > di )
			return false;
		if( dis[i] - d <= di ){
			while( i<=n && dis[i+1] - d <= di )
			{
				i++;
			}
			cnt++;
			if( cnt>m )
				return false;
			d = dis[i];
		}
	}
	return true;	
}
int main(){
	int i;
	while( cin>>l>>n>>m ){
		for( i=0;i<n;i++ )
			cin>>dis[i];
		dis[n] = l;
		sort(dis,dis+n+1);
		int left = 1,right = l,mid;
		while( left<right ){
			mid = (left+right)>>1;
			if( fun(mid) ) // 距离为mid可以跳
				right = mid;
			else
				left = mid + 1; 
		}
		cout<<mid<<endl;
	}
	return 0;
}

