#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
#define N 22
int t,n,k,w;
int ans,ma,we;
int ret;
int vis[N],x[N];
struct node{
	int value;
	int weight;
}st[N];
bool cmp(const node &n1,const node &n2){
	return n1.value*n2.weight>n2.value*n1.weight;
}
void dfs(int index,int dep){
	if( dep>=k )
	{
		if( ma>ans ){
			ans=ma;
		}
		return;
	}
	int i;
	for( i=index;i<n;i++ )
	{
		if( !vis[i] )
		{
			if( we + st[i].weight<=w )  //放第index个物品 
			{
					vis[i]=1;
					ma+=st[i].value;
					we+=st[i].weight;
				//	cout<<"深度:"<<dep<<" 所取物品下标:"<<i<<"  价值:"<<st[i].value<<"  重量:"<<st[i].weight<<"  当前总价值:"<<ma<<"  当前总重量:"<<we<<endl; 
					dfs(i+1,dep+1);
					ma-=st[i].value;
					we-=st[i].weight;
					vis[i]=0;
			}
		}
	}
/*	ret-=st[index].value;  //不放第index个物品
	if( ma + ret > ans ){
		dfs(index+1,dep+1);
	} 
	ret+=st[index].value; */
}
int main() {
	cin>>t;
	while( t-- )
	{
		int i;
		ret=0;
		memset(vis,0,sizeof(vis));
		scanf("%d%d",&n,&k);
		for( i=0;i<n;i++ ){
			scanf("%d%d",&st[i].value,&st[i].weight);
			ret+=st[i].value;
		}
		sort(st,st+n,cmp);
		scanf("%d",&w);
		ans=-1;
		ma=0,we=0;
		dfs(0,0);
		cout<<ans<<endl;
	}
	return 0;
	}

