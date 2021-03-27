#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;

#define N 15
//   !!!!!!!!!!!!!!!!   注意顺推过程中改变的值回推过程中要恢复 
struct node{
	int weight;
	int value;
}goods[N]; 

int n,w;  //物品数量和背包容量
int x[N];   //x[i]=0表示不取第i个物品,否则表示取第i个物品 
int cur=0;  //当前背包已经放置的物品重量 
int ans = 0,ans1 = 0;
int rest=0;  //没有考虑的物品价值总和 
int ret[N];
void dfs(int dep){  //dep:第i个物品 
	int i;
	if( dep>=n ){  //从0开始 
	/*	for( i=0;i<n;i++ )
			if( x[i] )
				cout<<i+1<<" ";
		cout<<endl; */
		if( ans1>ans )
		{
			ans=ans1;
			for(i=0;i<N;i++)
				ret[i]=x[i];
		}
		return;
	}
	 
	//加入第dep个物品 
		if( cur + goods[dep].weight<=w )
		{
			x[dep] = 1;
			ans1 += goods[dep].value; 
			cur += goods[dep].weight;
			dfs(dep+1);
			cur -= goods[dep].weight;
			ans1 -= goods[dep].value;
		}
	//不加入
	rest-=goods[dep].value; 
	if( ans1 + rest > ans ){
		x[dep]=0;
		dfs(dep+1);
	}
	rest += goods[dep].value; 
} 
int main() {
	int i;
	cin>>n>>w;
	for( i=0;i<n;i++ )
	{
		cin>>goods[i].weight>>goods[i].value;
		rest+=goods[i].value;
	}
	dfs(0);
	for( i=0;i<N;i++ )
		if( ret[i] )
			cout<<i+1<<" ";
	cout<<endl;
	return 0;
	}

