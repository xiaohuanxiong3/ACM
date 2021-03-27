#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<ctime>
using namespace std;
#define N 6
#define k 3
#define M 1000004
int a[]={12,34,13,54,75,36};
int vis[6],x[6]={0},cnt=0;
long long prime[M],check[M];
int tot=0;
//埃氏筛法 
void A_prime()
{
	int i,j;
	for( i=2;i<M;i++ )
	{
		if( check[i]==0 ){
			prime[tot++]=i;
			for( j=2;i*j<M;j++ )
				check[i*j]=1;
		}
	}
}
//欧拉筛法
void O_prime()
{
	int i,j;
	for( i=2;i<M;i++ )
	{
		if( check[i]==0 ){
			prime[tot++]=i;
			}
		for( j=0;j<tot;j++ ){
			if( prime[j]*i>=M )
				break;
			check[ prime[j]*i ]=1;
			if( i%prime[j]==0 )
				break;
		}
	}
}
long long qpow(long long a,long long n,long long p){
	if( n==1 )
		return a;
	long long tmp=qpow(a,n>>1,p);
	long long ret=tmp*tmp%p;
	if( n&1 ) return a*ret%p;
	return ret;
}
//随机测试法
bool isprime(int x){
	int i;
	long long a;
	for( i=0;i<4;i++ ){
		a = 2+rand()%(x-2);
		if(  qpow(a,x-1,x)!=1 )
			return false;
	}
	return true;
} 
bool isprime1(int x){
	int i;
	if( !( x&1 ) && x!=2 ) return false;
	if( x==2 ) return true;
	for(i=3;i*i<=x;i+=2)
		if( x%i==0 )
			return false;
	return true;
}
void dfs(int st,int dep)
{
	if( dep>=3 ){
		int i,sum=0;
		for(i=0;i<k;i++)
			sum+=x[i];
		// 判定sum是不是素数 
		if( isprime(sum) )
			cnt++;
		return;
	}
	else
	{
		int i;
		for( i=st;i<N;i++ ){
			x[dep]=a[i];
			dfs(i+1,dep+1);  //组合
		//	dfs(i,dep+1);  //重组合 
		}
	}
} 
int main() {
	srand( time(0) );
	dfs(0,0);
	cout<<cnt<<endl;
	return 0;
	}
