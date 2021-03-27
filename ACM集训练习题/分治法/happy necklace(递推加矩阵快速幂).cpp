#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<set> 
using namespace std; 
#define size 3
#define mod 1000000007
struct matrix{
	long long a[size][size];
};
matrix plu(const matrix &m1,const matrix &m2){
	matrix ret={0,0,0,0,0,0,0,0,0};
	long long i,j,k;
	for( i=0;i<size;i++ )
		for( j=0;j<size;j++ )
		{
			for( k=0;k<size;k++ )
			{
				ret.a[i][j]+=( m1.a[i][k]*m2.a[k][j] )%mod;
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
	cin>>t;
	while( t-- ){
		cin>>n;
		if( n==2 )
			cout<<3<<endl;
		else if( n==3 )
			cout<<4<<endl;
		else
		{
			matrix m={1,0,1,1,0,0,0,1,0};
			matrix ans=mq_mod(m,n-3);
		//	cout<<ans.a[0][0]<<" "<<ans.a[0][1]<<" "<<ans.a[0][2]<<endl;
			long long ret=( ans.a[0][0]*4%mod + ans.a[0][1]*3%mod +ans.a[0][2]*2%mod )%mod;
			cout<<ret<<endl;
		}
	}
	return 0;
	}

