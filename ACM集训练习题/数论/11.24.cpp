#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
long long inv(long long a,long long m){
	return a==1?1:(m-m/a)*inv(m%a,m) %m;
}
bool isprime(int x){
	if( !(x&1) && x!=2 )
		return false;
	if( x==1 )
		return false;
	if( x==2 )
		return true;
	int i;
	for( i=2;i*i<=x;i++ )
	{
		if( x%i==0 )
			return false;
	}
	return true;
}
int main(){
	int n,i,m;
	cin>>n;
	if( isprime(n) )
	{
		cout<<"YES\n";
		cout<<1<<endl;
		for( i=2;i<n;i++ )
			cout<<i*inv(i-1,n)%n<<endl;
		cout<<n<<endl;
	}
	else if( n==4 ){
		cout<<"YES\n";
		cout<<"1\n3\n2\n4\n";
	}
	else if( n==1 )
	{
		cout<<"YES\n1\n";
	}
	else{
		cout<<"NO\n";
	}
	return 0;
}
