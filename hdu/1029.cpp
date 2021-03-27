#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<map> 
using namespace std;
#define N 1000000
int an[N];
int main() { 
	int n,i,x;
	while( cin>>n )
	{
		for( i=0;i<n;i++ )
		{
			scanf("%d",&an[i]);
		}
		sort(an,an+n);
		printf("%d\n",an[(n-1)/2]);
	}
	return 0;
	}

