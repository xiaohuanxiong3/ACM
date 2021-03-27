#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
#define N 505
int n,m,p; 
//�Ż� 
  
struct node{
	int data;
	int parent;
	int rank;
	int rel;  //0:����,1:����(�븸�ڵ�Ĺ�ϵ) 
	node() :rank(1),rel(0){
	}
}uf[N];

//·��ѹ��
int Find(int x){  //�ݹ��������ܴ�ʱ�ᱬջ 
	if( x==uf[x].parent )
		return x;
	int pa = uf[x].parent;	
	uf[x].parent = Find( uf[x].parent );
	uf[x].rel=uf[x].rel^uf[pa].rel;
	return  uf[x].parent;
} 

int Find1(int x){  //�ǵݹ�
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
//����ʵ�ַ�ʽ

int data[N];
int rank[N];
int parent[N];

int Find(int x){
	if( x==parent[x] )
		return x;
	return find( parent[x] );
}   */

//�ϲ� 
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

