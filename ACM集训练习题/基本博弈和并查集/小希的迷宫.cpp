#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
#define N 100005
// 注意要保证只有一个集合 
struct node{
	int father;
	int rank;
	node():rank(1){
	}
}uf[N];
int k[N];
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
int Union(int x,int y){
	x = Find(x);
	y = Find(y);
	if( x!=y ){
		if( uf[x].rank<uf[y].rank ){
			uf[x].father=y;
		}
		else{
			uf[y].father=x;
			if( uf[x].rank==uf[y].rank ){
				uf[x].rank++;
			}
		}
		return 1;
	}
	return 0;   //如果两个集合已经有同一个祖先,再合并会形成环 
} 
int main() {
	int n,m,a,b,i;
	while( scanf("%d%d",&a,&b) && !( a==-1 && b==-1 ) ){
		if( a==0 && b==0 )  //空的满足要求 
		{	
			cout<<"Yes\n";
			continue;
		}
		for( i=1;i<N;i++ )
			uf[i].father=i;
		memset(k,0,sizeof(k));
		Union(a,b);
		k[a]=1;
		k[b]=1;
		int flag=1;
		while( scanf("%d%d",&a,&b ) && !( a==0 && b==0 ) )
		{
			int t=Union(a,b);
			k[a]=1;
			k[b]=1;
			if( t==0 )
				flag=0;
		}
		if( flag==0 )
		{
			cout<<"No\n";
			continue;
		}
		else  //注意要保证只有一个集合 
		{
			int ret=0;
			for( i=1;i<N;i++ ){
				if( k[i] && uf[i].father==i )  //搜索一遍看有多少个集合
					ret++; 
			}
			if( ret==1 )
				cout<<"Yes\n";
			else
				cout<<"No\n";
		}
	}
	return 0;
	}

