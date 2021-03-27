#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
#define N 1002
int a[N],dp[N]; 
int main() {
	int i,j,k,m,n;
	cin>>n;
	for( i=0;i<n;i++ )
		scanf("%d",&a[i]);
	dp[0]=1;
	for( i=1;i<n;i++ ){
		m=0;	
		for( k=0;k<i;k++ ){
			if( a[i]>=a[k] && dp[k]>m )
				m=dp[k];
		}
		dp[i]=m+1;
	}
	m = dp[0];
	for( i=1;i<n;i++ )
		if( m<dp[i] )
			m=dp[i];
	cout<<m<<endl;
	m=1;
	for( i=0;i<n;i++ )   //Êä³ö(ÇÉÃî!) 
	{
		if( dp[i]==m )
		{
			cout<<a[i]<<' ';
			m++;
		}
	}
	return 0;
	}

