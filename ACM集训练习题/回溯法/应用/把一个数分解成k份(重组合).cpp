#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
#define N 7 
int x[N],n,k,ans,sum;
void dfs(int st,int dep)
{
	int i;
	if( dep>=k-1 ){
	/*	sum=0;
		for( i=0;i<k-1;i++ )
			sum+=x[i]; */           
		if( n-sum>=x[k-2] )
		{
			ans++;
		}
		return;
	}
	for( i=st;i<n;i++ ){
		if( n-sum < i*(k-dep) )  //强剪枝
			break;
		else{
			x[dep]=i;
		//	dfs(i+1,dep+1);  //组合
			sum += i;
			dfs(i,dep+1);  //重组合 
			sum -= i;
		}
	}
} 
int main() {
	cin>>n>>k;
	dfs(1,0);
	cout<<ans<<endl;
	return 0;
	}

