#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
//风险评估
#define N 1005
int n,m,u,v; 
//并查集结构实现方式 
 // vector< pair<int,int> > edge;
 int edge[N][2];
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
void ini(){
	int i;
	for( i=1;i<=n;i++ )
	{
		uf[i].parent=i;	
	}
}

int main() {
	int i,x,y,ans=0,j;
	cin>>n>>m;
	ini();
	for( i=0;i<m;i++ ){
		cin>>x>>y;
		edge[i][0] = x;
		edge[i][1] = y;
		Union(x,y);
	}
	cin>>u>>v;
	if( Find1(u)!=Find1(v) )
		cout<<"-1\n";
	else{
		for( i=1;i<=n;i++){
			ini();
			if( i==u || i==v )
				continue;
			for( j=0;j<m;j++ ){
				if( edge[j][0] != i && edge[j][1]!=i )  //说明这条边不经过i 
					Union( edge[j][0],edge[j][1] );
			}
			if( Find1(u)!=Find1(v) )
				ans++; 
		}
	}
	cout<<ans<<endl;
	return 0;
	}

