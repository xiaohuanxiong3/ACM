#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<set> 
using namespace std; 
#define size 2 
#define mod 998244353
struct matrix{
	long long a[size][size];
};
matrix plu(const matrix &m1,const matrix &m2){
	matrix ret={0};
	long long i,j,k;
	for( i=0;i<size;i++ )
		for( j=0;j<size;j++ )
		{
			for( k=0;k<size;k++ )
			{
				ret.a[i][j]+= m1.a[i][k]*m2.a[k][j] ;
			}
		}
	for( i=0;i<size;i++ )
	{
		for( j=0;j<size;j++ )
		{
			ret.a[i][j]%=mod;
		}
	}
	return ret;
}
matrix mq_mod(matrix m,long long n){
	if( n==1 )
		return m;
	matrix tmp=mq_mod(m,n/2);
	matrix ret=plu(tmp,tmp);
	if( n&1 ) return plu(m,ret);
	else
		return ret;
}
int main() {
	int i,l,m,t;
	long long n;
	while( cin>>n ){
		if( n==1 )
			cout<<4<<endl;
		else if( n==2 )
			cout<<12<<endl;
		else
		{
			matrix m={1,1,1,0};
			matrix ans=mq_mod(m,2*n-3);
			long long ret=( ans.a[0][0]*8 + ans.a[0][1]*5 )%mod;
			cout<<ret-1<<endl;
		}
	}
	return 0;
	}

