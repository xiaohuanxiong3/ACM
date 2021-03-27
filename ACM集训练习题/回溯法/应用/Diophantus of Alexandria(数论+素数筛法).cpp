#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
#define N 40002
int n,ans;
int prime[4205],check[N],cnt;
void o_prime()
{
	int i,j;
	for( i=2;i<N;i++ ){
		if( check[i]==0 )
			{
				prime[cnt++]=i;
			}
			for(j=0;j<cnt && i*prime[j]<N ;j++){
				check[ i*prime[j] ]=1;
				if( i%prime[j]==0 ) break;
			}
	}
}
int main() {
	int i,t,num;
//	cout<<( 12&(1<<3) )<<endl;
	o_prime();
	cin>>t;
	int cnt1=1;
	while( t-- ){
		cin>>n;
		ans=1;
		for( i=0;i<cnt;i++ ){
			int flag=int( sqrt(n*1.0) )+1;
			if( prime[i]>flag )
				break;
			num=0;
			while( n%prime[i]==0 ){
				num++;
				n/=prime[i];
			}
			ans*=( 1+2*num );
		}
		if( n>1 ) ans*=3;
		printf("Scenario #%d:\n",cnt1++);
		cout<<(ans+1)/2<<endl;
			cout<<endl;
	}
	return 0;
	}

