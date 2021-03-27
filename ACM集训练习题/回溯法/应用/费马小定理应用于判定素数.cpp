#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<map>
#include<cmath>
#include<time.h>
#include<stdlib.h>
using namespace std;
long long q_mod(long long a,int n,int p){
	if( n==0 )
		return 1;
	long long tmp=q_mod(a,n/2,p);
	long long ret=tmp*tmp%p;
	if( n&1 ) return a*ret%p;
	return ret;
} 
bool isprime(int p){
	int i;
	for( i=0;i<4;i++ )
	{
		long long ax=2 + ( rand()%(p-2) );
		if( q_mod(ax,p-1,p)!=1 )
			return false;
	}
	return true;
}
int main() {
	int i,j,n;
	int p;
	srand( time(0) );
	while( cin>>n ){
		int cnt=0;
		for( i=0;i<n;i++ )
		{
			scanf("%d",&p);
			if( p==2 )
				cnt++;
			else if( isprime(p) )
			{
				cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	
	return 0;
	}

