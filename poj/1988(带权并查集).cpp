#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
#define N 30002
struct node{
	int father;
	int cnt; //记录这个cube是父节点下面第几个cube 
	int num;
//	int o_father,s_son;
}uf[N]; 
int Find(int x)
{
	int t=x,idx[100],cnt=0;
	while( t!=uf[t].father )
	{
		idx[cnt++]=t;
		t=uf[t].father;
	}
	int i;
	for( i=cnt-2;i>=0;i-- ){
		uf[ idx[i] ].cnt+=uf[ idx[i+1] ].cnt;
		uf[ idx[i] ].father = t; 
	}
	return t;
} 
void Union(int x,int y){
	x = Find(x);
	y = Find(y);
	uf[y].father=x;
	uf[y].cnt=uf[x].num;
	uf[x].num+=uf[y].num;
} 
/*
void Union(int x,int y)  // M x y
{
	int u=uf[x].o_father,v=uf[y].o_father;
	uf[v].father=uf[u].s_son;
	uf[u].num+=uf[v].num;
	int t;
	t=uf[u].s_son;
	while( t!=uf[t].father )
	{
		uf[t].cnt+=uf[v].num;
		uf[t].s_son=uf[v].s_son;
		t=uf[t].father;
	} 
	uf[t].cnt+=uf[v].num;
	uf[t].s_son=uf[v].s_son;
	
	t=uf[v].s_son;
	while( t!=uf[t].father )
	{
		uf[t].o_father=u;
		t=uf[t].father;
	}
	uf[t].o_father=u;
}  */
int main() {
	int n,a,b,i;
	char s;
	cin>>n;
	for( i=1;i<=N;i++ )
	{
		uf[i].cnt=0;
		uf[i].father=i;
		uf[i].num=1;
	//	uf[i].o_father=i;
	//	uf[i].s_son=i;
	}
	for( i=0;i<n;i++ )
	{
		scanf(" %c",&s);
		if( s=='M' )
		{
			scanf("%d%d",&a,&b);
			Union(a,b);
		}
		else
		{
			scanf("%d",&a);
			int f=Find(a);
			printf("%d\n",uf[f].num-1-uf[a].cnt);
		//	cout<<uf[ Find(a) ].cnt<<endl;
		}
	}
	return 0;
	}

