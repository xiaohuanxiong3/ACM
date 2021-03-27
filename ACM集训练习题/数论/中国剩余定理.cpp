#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
long long inv(int a,int m){
	while( a>m )
		a-=m;
	return a==1?1:(m-m/a)*inv(m%a,m) %m;
}
long long chinaRem(int b[],int m[],int n){
	long long ret=0,M=1,M1;
	int i;
	for( i=0;i<n;i++ )
		M*=m[i];
	for( i=0;i<n;i++ ){
		M1 = M / m[i];
		ret = ( ret + b[i]*M1*inv(M1,m[i])%M)%M;
	}
	return ret;
}
int main(){
	int b[]={2,3,2},m[]={3,5,7};
	cout<<chinaRem(b,m,3)<<endl; 
	return 0;
}

