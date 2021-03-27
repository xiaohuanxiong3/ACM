#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
#define N 10002
struct node{
	int st,en;
	bool operator<( const node& n) const{
		return en<n.en;
	}
}in[N];
int a,b;
int ans;
int main() {
	int n,i;
	while( scanf("%d",&n)!=EOF )
	{
		for( i=0;i<n;i++ )
		{
			scanf("%d%d",&in[i].st,&in[i].en);
		} 
		sort(in,in+n);
		a=in[0].en-1,b=in[0].en;
		ans=2;
		for( i=1;i<n;i++ )
		{
			if( b<in[i].st ) //第i个区间不包含a和b中任一个
			{
				ans+=2;
				a=in[i].en-1,b=a+1;
			} 
			if( a<in[i].st && b>=in[i].st )  //只包含一个 
			{
				ans+=1;
				a=b,b=in[i].en;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
	}

