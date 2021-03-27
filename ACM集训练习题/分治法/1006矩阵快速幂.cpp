#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
long long x,m,c;
int k;


struct matrix{
	int a11,a12,a21,a22;
};

matrix mplus(const matrix &m1,const matrix &m2,int k){
	matrix ans;
	ans.a11=( m1.a11*m2.a11+m1.a12*m2.a21 )%k;
	ans.a12=( m1.a11*m2.a12+m1.a12*m2.a22 )%k;
	ans.a21=( m1.a21*m2.a11+m1.a22*m2.a21 )%k;
	ans.a22=( m1.a21*m2.a12+m1.a22*m2.a22 )%k;
//	cout<<ans.a11<<'\t'<<ans.a12<<'\t'<<ans.a21<<'\t'<<ans.a22<<endl;
	return ans;
} 
matrix matrixq_mod(matrix &m,long long n,int k){
	if( n==1 )
		return m;
	matrix tmp=matrixq_mod(m,n/2,k);
	if( n&1 )
		return mplus(m, mplus(tmp,tmp,k),k );
	else
		return mplus(tmp,tmp,k);
}

/* 
long long quickmod_10(long long mid,long long m)
{
	if( mid==0 )
		return 1;
	long long temp=quickmod_10(mid/2,m);
	if( mid&1 ) return 10*temp*temp%m;
	else
		return temp*temp%m; 
} 
long long fun(long long x,long long m,long long k){
	long long mid=m/2;
	if( m==1 )
		return x%k;
	long long tmp=quickmod_10(mid,k);
	return ( fun(x,mid,k)%k+( fun(x,m-mid,k)%k * tmp  )%k )%k;	
}   */ 
int main() {
	int t;
	cin>>t;
	int cnt=1;
	while( t-- ){
		cin>>x>>m>>k>>c;
		printf("Case #%d:\n",cnt++);
		/*	memset(kb,0,sizeof(kb));
			long long flag1=0,flag2=0;
			f[1]=fun(x,1,k); 
			for( i=2;i<=1000;i++ )
			{
				f[i]=fun(x,i,k);
				if( kb[ f[i] ][ f[i-1] ] ){
					flag1=kb[ f[i] ][ f[i-1] ];
					flag2=i;
				//	cout<<f[i-1]<<" "<<f[i]<<endl<<flag1<<" "<<flag2<<endl; 
					break;
				}
				kb[ f[i] ][ f[i-1] ]=i;
			}
			long long length=flag2-flag1; //循环节长度
			long long index=m-flag1;
			index%=length;
			index+=flag1;
			if( f[index]==c )
				cout<<"Yes\n";
			else
				cout<<"No\n";   */ 
				
		matrix ma,ans;
		ma.a11=10,ma.a12=1,ma.a21=0,ma.a22=1;
		ans=matrixq_mod(ma,m-1,k);
		int ret=( ans.a11 + ans.a12 )*x%k;
	//	cout<<ret<<endl;
		if( ret==c )
			cout<<"Yes\n";
		else
			cout<<"No\n"; 
	} 
	return 0;
	}

