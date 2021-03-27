#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
#define N 100002
#define INF 0x3f3f3f
int a[N],c[N]; 
int binary_search(int size,int x){
	int st=0,en=size-1;
	while( st<=en )
	{
		int mid=(st+en)>>1;
	//	cout<<mid<<endl;
		if( c[mid]>=x )
		{
			st=mid+1;
		}
		else
			en=mid-1;
	}
	return st;
}
int main() {
	int i,j,t,n,k,cnt_c,ind;
	cin>>t;
	while( t-- ){
		cin>>n>>k;
		for( i=0;i<n;i++ )
			scanf("%d",&a[i]);
		c[0]=-INF;
		cnt_c=1;
		for( i=0;i<n;i++ )
		{
			ind=upper_bound(c,c+cnt_c,a[i])-c;
			c[ind]=a[i];
			if( ind>=cnt_c )
				cnt_c++;
		}
		int k1=cnt_c-1;
		c[0]=INF;
		cnt_c=1;
		for( i=0;i<n;i++ )
		{
			ind=binary_search(cnt_c,a[i]);
			c[ind]=a[i];
			if( ind>=cnt_c )
				cnt_c++;
		}
		int k2=cnt_c-1; 
	//	cout<<k1<<' '<<k2<<endl;
		if( k1>=n-k || k2>=n-k )
			printf("A is a magic array.\n");
		else
			printf("A is not a magic array.\n");
		
	}
	return 0;
	}

