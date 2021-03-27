#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
#define N 1002
struct node{
	int w,s;
	int index;
	bool operator<(const node &n) const{  //按体重从大到小排序 
			return w>n.w;
	} 
}mo[N];
int dp[N];
int main() {
	int w,s,cnt=0,i,j;
	while( scanf("%d%d",&w,&s)!=EOF ){
		mo[cnt].w=w;
		mo[cnt].s=s;
		mo[cnt].index=cnt+1;
		cnt++;
	}
	sort(mo,mo+cnt);
//	for( i=0;i<cnt;i++ )
//		cout<<mo[i].w<<' '<<mo[i].s<<endl;
	dp[0]=1;
	int m;
	for( i=1;i<cnt;i++ )
	{
		m=0;
		for( j=0;j<i;j++ )
		{
			if( mo[j].s<mo[i].s && dp[j]>m && mo[i].w<mo[j].w )
				m=dp[j];
		}
		dp[i]=m+1;
	}
	m=dp[0];
	for( i=1;i<cnt;i++ )
		if( dp[i]>m )
			m=dp[i];
	cout<<m<<endl;
	for( i=cnt-1;i>=0;i-- )
	{
		if( dp[i]==m )
		{
			cout<<mo[i].index<<endl;
			m--;
		}
	}
	return 0;
	}

