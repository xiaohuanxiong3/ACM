#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
#define exp 1e-8
double k[10002];
int main() {
	int i,j,n,K;
	double sum;
	while( cin>>n>>K,n+K ){
		sum=0;
		for( i=0;i<n;i++ )
		{
			scanf("%lf",&k[i]);
			sum+=k[i];
		}
		sum/=K;
		double l=0,r=sum,mid;
		while( r-l>exp ){
			int cnt=0;
			mid=l + (r-l)/2;
			for( i=0;i<n;i++ )
			{
				cnt+=k[i]/mid;
			//	cout<<cnt<<endl;
			}
			if( cnt>=K )
			{
				l=mid;
			}
			else if( cnt<K )
				r=mid;
		}
		if( l<0.01 && l+exp<0.01 )
			cout<<"0.00"<<endl;
		else
			printf("%.2lf\n",l);
	} 
	return 0;
	}

