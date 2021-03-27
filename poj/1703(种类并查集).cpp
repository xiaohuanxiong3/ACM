#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
#define N 200002
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
	int i,t,n,m,a,b;
	char cr;
	scanf("%d",&t);
	while( t-- ){
		scanf("%d%d",&n,&m);
		for( i=1;i<=2*n;i++ )
		{
			uf[i].father=i;
			uf[i].rank=1;
		}
		for( i=0;i<m;i++ )
		{
			scanf(" %c%d%d",&cr,&a,&b);
			if( cr=='A' )
			{
				if( Find(a)==Find(b) )
					printf("In the same gang.\n");
				else if( Find(a)==Find(b+n) || Find(a+n)==Find(b) )
					printf("In different gangs.\n");
				else
					printf("Not sure yet.\n");
			}
			else
			{
				Union(a,b+n);
				Union(a+n,b);	
				}
		}
	}
	return 0;
	}

