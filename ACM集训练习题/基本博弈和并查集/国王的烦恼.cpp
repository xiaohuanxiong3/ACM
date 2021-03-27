//��������Ϸ
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
#define N 10005 
int n,m,p; 
//���鼯�ṹʵ�ַ�ʽ 
  
struct node{
	int data;
	int parent;
	int rank;
}uf[N];

struct node1{
	int st;
	int ed;
	int time;
	bool operator < (const node1 &n1) const{   //���������(ע��:ֻ������<,���Һ���Ҫ��const) 
			return time>n1.time;	
	}
}; 
struct imf{
	int ia,ib,t;
}is[100002];

bool cmp(const imf& i1,const imf &i2){
	return i1.t>i2.t;
}
//·��ѹ��
int Find(int x){  //�ݹ��������ܴ�ʱ�ᱬջ
	if( x==uf[x].parent )
		return x;
	uf[x].parent = Find( uf[x].parent );
	return  uf[x].parent;
} 

int Find1(int x){  //�ǵݹ� 
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

