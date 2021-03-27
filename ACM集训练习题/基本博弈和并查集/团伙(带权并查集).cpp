#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
#define N 505
int n,m,p; 
//团伙 
  
struct node{
	int data;
	int parent;
	int rank;
	int rel;  //0:朋友,1:敌人(与父节点的关系) 
	node() :rank(1),rel(0){
	}
}uf[N];

//路径压缩
int Find(int x){  //递归数据量很大时会爆栈 
	if( x==uf[x].parent )
		return x;
	int pa = uf[x].parent;	
	uf[x].parent = Find( uf[x].parent );
	uf[x].rel=uf[x].rel^uf[pa].rel;
	return  uf[x].parent;
} 

int Find1(int x){  //非递归
	int k=x,k1,idx[N],cnt=0,i; 
	while( k!=uf[k].parent )
	{
		idx[cnt++]=k;
		k = uf[k].parent;
	}
	for(i=cnt-2;i>=0;i--){
		uf[ idx[i] ].rel=uf[ idx[i] ].rel^uf[ idx[i+1] ].rel;
		uf[ idx[i] ].parent=k;
	}
/*	while( x!= uf[x].parent ){
		k1 = uf[x].parent;
		uf[x].parent=k;
		x = k1;
	} */
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
void Union(int u,int v,int r){
	int x = Find(u);
	int y = Find(v);
	if( x!=y ){
		if( uf[x].rank<uf[y].rank )
		{
			uf[x].parent=y;
			uf[x].rel = r ^ uf[u].rel ^ uf[v].rel;
		}
		else {
			uf[y].parent=x;
			uf[y].rel = r ^ uf[u].rel ^ uf[v].rel;
			if( uf[x].rank==uf[y].rank )
				uf[x].rank++;
		}
	}
}
int main() {
	
	return 0;
	}

