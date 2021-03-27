#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<map>
#include<cmath>
using namespace std;
#define N 1000002
int a[N];
int main() {
	int i,j,n;
	int cnt=1;
	for( i=2;i<N;i++ )
	{
		if( !a[i] )
		{
			a[i]=cnt;
			for( j=i;j<N;j+=i )
				a[j]=cnt;
			cnt++;
		}
	}
	while( scanf("%d",&n)!=EOF ){
		printf("%d\n",a[n]);
	}
	return 0;
	}

