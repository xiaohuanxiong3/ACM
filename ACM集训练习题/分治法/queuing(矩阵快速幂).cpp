#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<set> 
using namespace std; 

 int q_mod(int n,int mod){
	if( n==0 )
		return 1;
	int temp=q_mod(n/2,mod);
	if( n&1 ) return 2*temp*temp%mod;
	else
		return temp*temp%mod;
} 
struct matrix{
	int a[5][5];
};
matrix plu(const matrix &m1,const matrix &m2,int m){
	matrix ret={0};
	int i,j,k;
	for( i=0;i<5;i++ )
		for( j=0;j<5;j++ )
			for(k=0;k<5;k++ )
				ret.a[i][j]+=m1.a[i][k]*m2.a[k][j];   //md
	for( i=0;i<5;i++ )
		for( j=0;j<5;j++ )
			ret.a[i][j]%=m;
	return ret;
}
matrix mq_mod(matrix ma,int n,int m){
	if( n==1 )
		return ma;
	matrix tmp=mq_mod(ma,n/2,m);
	matrix ret=plu(tmp,tmp,m);
	if( n&1 ) return plu(ma,ret,m);
	else
		return ret;
}
int main() {
	int i,l,m;
	while(cin>>l>>m ){
		if( l==0 )
			cout<<1<<endl;
		else if( l==1 )
			cout<<2%m<<endl;
		else if( l==2 )
			cout<<4%m<<endl;
		else if( l==3 )
			cout<<6%m<<endl;
		else if( l==4 )
			cout<<9%m<<endl;
		else
		{
			matrix ma={1,0,1,1,1,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,2};
			matrix ans=mq_mod(ma,l-3,m);
			int ret=( ans.a[0][0]*2+ans.a[0][4]*5 )%m;
			int tmp=q_mod(l,m);
			if( tmp<ret )
				tmp+=m;
			cout<<tmp-ret<<endl; 
		}
	}
	return 0;
	}

