#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
#define N 65
int a[N],vis[N];
int n,len,num,rest;
int dfs(int k,int cur_len,int st){ // k表示当前拼第k根木棍 
	if( k>num-1 ){
		return 1;
	}
	int i,pre=0;
	for( i=st;i<n;i++ ){
		if( vis[i] || a[i]==pre ) // pre表示长为pre的木棍已经考虑过 
			continue;
		pre=0;
		if( cur_len+a[i]==len ){
			vis[i]=1;
			if( dfs(k+1,0,0) )
				return 1;
			vis[i]=0;
			return 0;   //这个不加会超时 
		}else if( cur_len+a[i]<len ){
			vis[i]=1;
			if( dfs(k,cur_len+a[i],i+1) )
				return 1;
			vis[i]=0;
			if( cur_len==0 )  //第一块木头不能拼成目标长度后面就不需要考虑了(超强剪枝)  ----不加也会超时...... 
				return 0; 
		}
		pre=a[i];  //强剪枝(当考虑一个不成功,后面和它相同的也不要考虑) 
	}
	return 0;
}
int main() {
	int i,s;
	while( scanf("%d",&n) && n )
	{
		s=0;
		for( i=0;i<n;i++ ){
			scanf("%d",&a[i]);
			s+=a[i];  
		}
		sort(a,a+n,greater<int>());
		for( i=a[0];i<=s;i++ ){
			if( s%i==0 ){  //这个i可以作为长度 
				len=i;   //小木棍的长度 
				num=s/i;  //小木棍的根数 
				memset(vis,0,sizeof(vis));
				if( dfs(1,0,0) )
				{
					printf("%d\n",i);
					break;
				}
			}
		}
	}
	return 0;
}

