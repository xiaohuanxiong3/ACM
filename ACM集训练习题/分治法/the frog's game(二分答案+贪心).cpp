#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
#define N 500005
int l,n,m,i;
int sto[N];
bool play(int mid){
	int i,ret=0,last=0;
	for( i=1;i<=n;i++ ){
		if( sto[i]-last>mid )
		{
		//	cout<<sto[i-1]<<" "<<sto[i]<<endl;
			ret++;
			last=sto[i-1];
			if( sto[i]-sto[i-1]>mid )
				return false;
			i--;
		}
	}
	ret++;
	if( ret>m )
		return false;
	return true;
}
int main() {
	
	while( cin>>l>>n>>m ){
		for( i=0;i<n;i++ )
			scanf("%d",&sto[i]);
		sto[n]=l;
		sort(sto,sto+n+1);
		int l=0,r=sto[n];
		while( l<r ){
			int mid=(l+r)>>1;
		//	cout<<mid<<endl;
			if( play(mid) )
				r=mid;
			else
				l=mid+1;
		}
		cout<<l<<endl;
	} 
	return 0;
	}

