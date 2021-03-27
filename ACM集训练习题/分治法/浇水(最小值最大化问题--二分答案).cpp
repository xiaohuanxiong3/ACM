#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
#define N 100005
long long a[N],b[N];
int n,w,m,t,i;
bool fun(long long b[],long long mid){
	long long i,ret=0,j;
	for( i=0;i<n;i++ )
	{
		if( b[i]<mid )
		{
			long long tmp=b[i];
			for( j=i;j<=i+w-1 && j<n;j++ )
			{
				b[j]+=mid-tmp;  //Òª½½mid-tmp´ÎË® 
			}
			ret+=mid-tmp;
		}
		if( ret>m )
			return false;	
	}
	return true;
}
int main() {
	
	cin>>t;
	 while( t-- ){
	 	cin>>n>>m>>w;
	 	for( i=0;i<n;i++ )
	 	{
	 		scanf("%ld",&a[i]);
	 	}
	 	long long l=0,r=pow(10,14);
	 	long long mid=(l+r)>>1;
		 while( l<=r ){
		 //	cout<<mid<<endl;
		 	for( i=0;i<n;i++ )
		 		b[i]=a[i];
		 	if( fun(b,mid) ) l=mid+1;
		 	else
		 		r=mid-1;
		 	mid=(l+r)>>1;
		 //	cout<<l<<" "<<r<<endl;
		 } 
		 cout<<mid<<endl;
	 }
	return 0;
	}

