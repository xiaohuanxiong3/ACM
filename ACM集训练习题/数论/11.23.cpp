#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
#define mod 1000000007
int convert_gcd(int a,int b,int &x,int &y){
	if( a==0 && b==0 )	return -1;
	if( b==0 ){
		x = 1, y=0;
		return a;
	}
	int m,t;
	m = convert_gcd(b,a%b,x,y);
	t = x,x = y, y = t-a/b*y;
	return m;
}
long long inv(long long a,long long m){
	return a==1?1:(m-m/a)*inv(m%a,m) %m;
}
//返回组合数c(m,n)对mod取模 
long long com(int m,int n){
	long long ret = m;
	for( i=m-1;i>=m-n+1;i-- )
		ret = (ret*i)%mod;
	for( i=2;i<=n;i++ )
		ret = ( ret * inv(i,mod) )%mod;
	return ret;
}
int main(){
	int a,b,m,x0,y0,d,i;
//	cin>>a>>b>>m;
//	d = convert_gcd(a,m,x0,y0);
//	if( b%d )
//		cout<<"无解!\n";
//	else
//	{
//		cout<<"解为:";
//		for( i=0;i<d;i++ )
//			cout<<( x0*b/d+i*m/d )%m<<' ';
//	}
	cout<<com(4,3)<<endl;
	return 0;
}

