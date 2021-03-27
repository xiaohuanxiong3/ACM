#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
// k倍区间
#define N 100004
long long  a[N];
long long sum[N];  // 前缀和数组
int b[N];  // sum[i]对k取余的余数的个数 
int main(){
	int n,k,i;
	cin>>n>>k;
	sum[0] = 0;
	for( i=1;i<=n;i++ ){
		cin>>a[i];
		sum[i] = sum[i-1] + a[i] ;
	}
	for( i=1;i<=n;i++ )
	{
		sum[i] = sum[i] % k;
		b[ sum[i] ]++;
	}	
	long long res = 0;
	for( i=0;i<k;i++ ){
		res += b[i]*(b[i]-1)/2;
	}
	res += b[0];
	cout<<res<<endl;
	return 0;
}

