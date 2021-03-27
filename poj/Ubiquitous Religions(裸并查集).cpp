#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
//Ubiquitous Religions
#define N 50002
struct node{
	int father;
	int rank;
}uf[N];
int Find(int x){
	int k=x;
	while( k!=uf[k].father ){
		k=uf[k].father;
	}
	while( x!=uf[x].father ){
		int t=uf[x].father;
		uf[x].father=k;
		x=t;
	}
	return k;
}
void Union(int x,int y){
	x = Find(x);
	y = Find(y);
	if( x!=y ){
		if( uf[x].rank<uf[y].rank )
			uf[x].father=y;
		else
		{
			uf[y].father=x;
			if( uf[x].rank==uf[y].rank )
				uf[x].rank++;
		}
	}
}
int main() {
	int i,x,y;
	long long n,m;
	int Cnt=1;
	while( cin>>n>>m,n+m )
	{
		for( i=1;i<=n;i++ )
		{
			uf[i].father=i;
			uf[i].rank=1;
		}
		for( i=0;i<m;i++ )
		{
			scanf("%d%d",&x,&y);
			Union(x,y);
		}
		printf("Case %d: ",Cnt++);
		int cnt=0;
		for( i=1;i<=n;i++ )
			if( uf[i].father==i )
				cnt++;
		printf("%d\n",cnt);
	}
	return 0;
	}

