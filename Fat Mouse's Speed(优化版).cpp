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
	bool operator<(const node &n) const{  //按体重从小到大排序 
			return w<n.w;
	} 
}mo[N];
int dp[N],c[N];
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
	c[0]=INF;
	int cnt_c=1;
	
	for( i=0;i<cnt;i++ )
	{
		
	}
	return 0;
	}

