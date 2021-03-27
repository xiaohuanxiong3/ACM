#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
#define N 50002
struct node{
	int x,y;
	int flag; //标记这个区间经过合并后是否有效 
	bool operator<(const node& n) const{
		return x<n.x;
	}
}an[N];
int main() {
	int i,j,n;
	scanf("%d",&n);
	for( i=0;i<n;i++ )
	{
		scanf("%d%d",&an[i].x,&an[i].y);
		an[i].flag=1;
	}
	sort(an,an+n);
	for( i=0;i<n-1;i++ )
	{
		if( an[i].y<an[i+1].x )
			continue;
		if( an[i].y>=an[i+1].x && an[i].y<an[i+1].y )
		{
			an[i+1].x=an[i].x;
			an[i].flag=0;
		}
		if( an[i].y>=an[i+1].x && an[i].y>=an[i+1].y )
		{
			an[i+1].x=an[i].x,an[i+1].y=an[i].y;
			an[i].flag=0;
		}
	}
	for( i=0;i<n;i++ )
		if( an[i].flag )
			printf("%d %d\n",an[i].x,an[i].y); 
	return 0;
	}

