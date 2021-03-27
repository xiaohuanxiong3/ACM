#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
#define N 100005
struct node{
	int p;
	int y;
	int order;
	int index;
	bool operator<(const node& n) const{
		if( p==n.p )
			return y<n.y;
		return p<n.p;
	}
}c[N];
bool cmp(const node& n1,const node& n2){
	return n1.index<n2.index;
}
int main(){
	int n,m,i,j;
	scanf("%d%d",&n,&m);
	for( i=0;i<m;i++ )
	{
		scanf("%d%d",&c[i].p,&c[i].y);
		c[i].index = i+1;
	}	
	sort(c,c+m);
	int tmp=1;
	for( i=0;i<m;i++ )
	{
		if( i!=0 && c[i].p>c[i-1].p )
		{
			tmp = 1;	
		}
		c[i].order=tmp++;
	}
	sort(c,c+m,cmp);
	int f[6],l[6];
	for( i=0;i<m;i++ )
	{
		int fi=c[i].p,la=c[i].order;
		for( j=5;j>=0;j-- )
		{
			f[j]=fi%10;
			fi/=10;
		}
		for( j=5;j>=0;j-- )
		{
			l[j]=la%10;
			la/=10;
		}
		for( j=0;j<6;j++ )
		{
			printf("%d",f[j]);
		}
		for( j=0;j<6;j++ )
		{
			printf("%d",l[j]);
		}
		printf("\n");
	}
	return 0;
}

