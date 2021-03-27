#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
#define N 6000
int dp[N],i,j,k,m;
int min(int x1,int x2,int x3,int x4)
{
	int ret=min(min(x1,x2),min(x3,x4));
	if( x1==ret )
		i++;
	if( x2==ret )
		j++;
	if( x3==ret )
		k++;
	if( x4==ret )
		m++;
	return ret;
}
int main() {
	int n,n1;
	i=j=m=k=1;
	dp[1]=1;
	for( n1=2;n1<=5842;n1++ )
	{
		dp[n1]=min(2*dp[i],3*dp[j],5*dp[k],7*dp[m]);
	}
	while( cin>>n,n )
	{
	//	priority_queue<pair<int,int> > pq;
		printf("The %d",n);
		if( n%10==1 && n%100!=11 )
			printf("st");
		else if( n%10==2 && n%100!=12 )
			printf("nd");
		else if( n%10==3 && n%100!=13 )
			printf("rd");
		else
			printf("th");
		printf(" humble number is %d.\n",dp[n]);
	}
	return 0;
	}

