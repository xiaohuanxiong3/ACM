#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
// 线段树模板 
#define N 50003
int tree[N<<2];
int a[N];
// 向上更新 
void push_up(int rt){
	tree[rt] = tree[rt<<1] + tree[rt<<1|1];
}
// left:当前线段的左端点,right:右端点,rt:区间的编号 
void build(int left,int right,int rt){
	if( right==left )
	{
		tree[rt] = a[left];
		return; 
	}
	int mid = (left+right)>>1;
	build(left,mid,rt<<1);
	build(mid+1,right,rt<<1|1);
	push_up(rt);
}
// 将第k个元素的值加v 
void update(int left,int right,int rt,int k,int v){
	if( left==right )
	{
		tree[rt] += v;
	}
	int mid = (left+right)>>1;
	if( k<=mid )
		update(left,mid,rt<<1,k,v);
	else
		update(mid+1,right,rt<<1|1,k,v);
	push_up(rt);
}
int query(int left,int right,int rt,int L,int R){
	if( left == L && right == R ){
		return tree[rt];
	}
	int mid = (left+right)>>1;
	int ret = 0;
	if( R<=mid )
		ret+=query(left,mid,rt<<1,L,R);
	else if( L>=mid ){
		ret+=query(mid+1,right,rt<<1|1,L,R);	
	}
	else{
		ret+=query(left,mid,rt<<1,L,mid);
		ret+=query(mid+1,right,rt<<1|1,mid+1,R);
	}
	return ret;
}
int main(){
	int n,i,i1,j1;
	string order;
	cin>>n;
	for( i=0;i<n;i++ )
		cin>>a[i];
	build(0,n-1,1);
	while( cin>>order,order!="End"){
		cin>>i1>>j1;
		if( order=="Add" ){
			update(0,n-1,1,i1,j1);
		}
		else if( order=="Sub" ){
			update(0,n-1,1,i1,-j1);
		}
		else if( order=="Query" ){
			
		}
	}
	return 0;
}

