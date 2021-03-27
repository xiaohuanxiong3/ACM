#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
#define N 1000000
int prime[78500],check[N],cnt;
void o_prime(){
	int i,j;
	for( i=2;i<N;i++ ){
		if( check[i]==0 ){
			prime[cnt++]=i;
		}
		for( j=0;j<cnt && i*prime[j]<N ;j++ ){
			check[ i*prime[j] ]=1;
			if( i%prime[j]==0 ) break; 
		}
	}
} 
int main() {
	o_prime();
	int n,i;
	while( scanf("%d",&n)!=EOF ){
		if( n==1 )
			printf("0\n");
		else
		{
			for( i=cnt-1;i>=0;i-- ){
				if( n%prime[i]==0 )
					break;
			}
			printf("%d\n",i+1);
		}
	}
	return 0;
	}

