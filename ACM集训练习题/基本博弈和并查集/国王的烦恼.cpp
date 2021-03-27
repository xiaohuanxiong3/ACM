//国王的游戏
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
#define N 10005 
int n,m,p; 
//并查集结构实现方式 
  
struct node{
	int data;
	int parent;
	int rank;
}uf[N];

struct node1{
	int st;
	int ed;
	int time;
	bool operator < (const node1 &n1) const{   //重载运算符(注意:只能重载<,并且后面要加const) 
			return time>n1.time;	
	}
}; 
struct imf{
	int ia,ib,t;
}is[100002];

bool cmp(const imf& i1,const imf &i2){
	return i1.t>i2.t;
}
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
int Union(int x,int y){
	x = Find(x);
	y = Find(y);
	if( x!=y ){
		uf[x].parent=y;
		return 1;
	}
	return 0;
}
int main() {
	
	int i,x,y;
	while( cin>>n>>m ) 
	{
		for( i=1;i<=n;i++ )
			uf[i].parent=i;
		for( i=0;i<m;i++ ){
			scanf("%d%d%d",&is[i].ia,&is[i].ib,&is[i].t);
		} 
		sort(is,is+m,cmp);
		int last=-1;
		int ret=0;
		for( i=0;i<m;i++ )
		{
			int rng=Union(is[i].ia,is[i].ib);
			if( rng==1 && is[i].t!=last )
			{
				ret++;
				last=is[i].t;
			}
		}
		cout<<ret<<endl;
	}
	return 0;
}

