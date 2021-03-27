#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<map>
using namespace std;
#define N 50005
struct node{
	int dis;  //表示到父节点的顺时针距离 
	int father;
	int rank;
}uf[N]; 
int Find(int x){  //加权并查集的路径压缩 
	int k=x,i,cnt=0,idx[10];
	while( k!=uf[k].father )
	{
		idx[cnt++]=k;
		k=uf[k].father;
	}
	for( i=cnt-2;i>=0;i-- ){
		uf[ idx[i] ].dis=( uf[ idx[i] ].dis+uf[ idx[i+1] ].dis )%300;
		uf[ idx[i] ].father=k;
	}	
	return k;
}
void Union(int u,int v,int dis){
	int	x = Find(u);
	int y = Find(v);
	if( x!=y ){
		if( uf[x].rank<uf[y].rank )
		{
			uf[x].father=y;
			int tmp=( uf[u].dis+dis-uf[v].dis )%300;
			if( tmp<0 )
				tmp+=300;
			uf[x].dis=300-tmp;
			//cout<<uf[x].dis<<endl;
		}
		else
		{
			uf[y].father=x;
			int tmp=( uf[u].dis+dis-uf[v].dis )%300;
			if( tmp<0 )
				tmp+=300;
			uf[y].dis=tmp;
			//cout<<uf[y].dis<<endl;
			if( uf[x].rank==uf[y].rank )
				uf[x].rank++;
		}
	}
}
int main() {
	int m,n,i,j,a,b,x;
	while( cin>>n>>m )
	{
		for( i=1;i<=n;i++ )
		{
			uf[i].father=i;
			uf[i].dis=0;
		}
		int ans=0;
		for( i=0;i<m;i++ )
		{
			scanf("%d%d%d",&a,&b,&x);
			if( Find(a)!=Find(b) )
			{
				Union(a,b,x);
			//	cout<<uf[a].dis<<" "<<uf[b].dis<<endl;
			}
			else
			{
				int tmp=uf[b].dis-uf[a].dis;
				if( tmp<0 )
					tmp+=300;
				if( tmp!=x )
				{
					ans++;
				//	cout<<"正确:"<<tmp<<' '<<"错误:"<<x<<endl;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
	}

