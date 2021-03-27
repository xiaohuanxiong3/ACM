#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
#define N 505
int n,m,p; 
//并查集结构实现方式 
  
struct node{
	int data;
	int parent;
	int rank;
}uf[N];

//路径压缩
int Find(int x){  //递归数据量很大时会爆栈 
	if( x==uf[x].parent )
		return x;
	uf[x].parent = Find( uf[x].parent );
	return  uf[x].parent;
} 

int Find1(int x){  //非递归
	int k=x,k1; 
	while( k!=uf[x].parent )
	{
		k = uf[x].parent;
	}
	while( x!= uf[x].parent ){
		k1 = uf[x].parent;
		uf[x].parent=k;
		x = k1;
	}
	return k;
} 
/*
//数组实现方式

int data[N];
int rank[N];
int parent[N];

int Find(int x){
	if( x==parent[x] )
		return x;
	return find( parent[x] );
}   */

//合并 
void Union(int x,int y){
	x = Find(x);
	y = Find(y);
	if( x!=y ){
		if( uf[x].rank<uf[y].rank )
			uf[x].parent=y;
		else {
			uf[y].parent=x;
			if( uf[x].rank==uf[y].rank )
				uf[x].rank++;
		}
	}
}

int main() {
	
	int i,x,y;
	cin>>n>>m>>p;
	for( i=1;i<=n;i++ )
		uf[i].parent=i;
	for( i=0;i<m;i++ ){
		cin>>x>>y;
		Union(x,y);
	}
	for( i=0;i<p;i++ ){
		cin>>x>>y;
		x = Find1(x);
		y = Find1(y);
		if( x==y )
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
	return 0;
	}

