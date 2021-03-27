#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
//Constructing Roads In JGShining's Kingdom 
#define N 500002
#define INF 0x3f3f3f
struct node{
	int p,r;
}ci[N];
int c[N]; 
bool cmp(const node& n1,const node& n2){
	return n1.p<n2.p;
}
int main() {
	int i,j,n,cnt_c,k,cnt=1;
	while( scanf("%d",&n)!=EOF )
	{
		for( i=0;i<n;i++ )
			scanf("%d%d",&ci[i].p,&ci[i].r);
		sort(ci,ci+n,cmp);
		c[0]=-INF;
		cnt_c=1;
		for( i=0;i<n;i++ ){
			k=upper_bound(c,c+cnt_c,ci[i].r)-c;
		//	dp[i] = k;
			c[k] = ci[i].r;
			if( k>=cnt_c )
				cnt_c++;
		}
		printf("Case %d:\n",cnt++);
		if( cnt_c==2 )
			cout<<"My king, at most "<<cnt_c-1<<" road can be built.\n"<<endl;
		else
			cout<<"My king, at most "<<cnt_c-1<<" roads can be built.\n"<<endl;
	}
	return 0;
	}

