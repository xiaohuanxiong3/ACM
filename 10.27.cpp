#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
#define N 100002
long long a[N];
int main(){
	int n,i;
	long long ret;
	scanf("%d",&n);
	for( i=0;i<n;i++ )
		scanf("%d",&a[i]);
	if( n==2 )
		printf("%d\n",abs(a[0]-a[1]));
	else
	{
		sort(a,a+n);
		int left,right;
		int ps=1,pe=n-1,cnt=1;
		left = right =0;
		long long ret1=0;
		while( ps<pe ){
			if( cnt&1 )
			{
				if( abs( a[pe]-a[left] )+ abs( a[pe-1]-a[right] ) < abs( a[pe]-a[right] )+ abs( a[pe-1]-a[left] ))
				{
					ret1+=abs( a[pe]-a[right] )+ abs( a[pe-1]-a[left] );
					left = pe-1,right = pe;
				}
				else
				{
					ret1+=abs( a[pe]-a[left] )+ abs( a[pe-1]-a[right] );
					left = pe,right = pe-1;
				}
				pe-=2;
			}
			else
			{
				if( abs( a[ps]-a[left] )+ abs( a[ps+1]-a[right] ) < abs( a[ps]-a[right] )+ abs( a[ps+1]-a[left] ))
				{
					ret1+=abs( a[ps]-a[right] )+ abs( a[ps+1]-a[left] );
					left = ps+1,right = ps;
				}
				else
				{
					ret1+=abs( a[ps]-a[left] )+ abs( a[ps+1]-a[right] );
					left = ps,right = ps+1;
				}
				ps+=2;
			}
			cnt++;
		}
		if( ps==pe )
			ret1+=max(abs(a[left]-a[ps]),abs(a[right]-a[ps])); 
		long long ret2=0;
		cnt=0;
		left = right =n-1;
		ps = 0,pe = n-2;
		while( ps<pe ){
			if( cnt&1 )
			{
				if( abs( a[pe]-a[left] )+ abs( a[pe-1]-a[right] ) < abs( a[pe]-a[right] )+ abs( a[pe-1]-a[left] ))
				{
					ret2+=abs( a[pe]-a[right] )+ abs( a[pe-1]-a[left] );
					left = pe-1,right = pe;
				}
				else
				{
					ret2+=abs( a[pe]-a[left] )+ abs( a[pe-1]-a[right] );
					left = pe,right = pe-1;
				}
				pe-=2;
			}
			else
			{
				if( abs( a[ps]-a[left] )+ abs( a[ps+1]-a[right] ) < abs( a[ps]-a[right] )+ abs( a[ps+1]-a[left] ))
				{
					ret2+=abs( a[ps]-a[right] )+ abs( a[ps+1]-a[left] );
					left = ps+1,right = ps;
				}
				else
				{
					ret2+=abs( a[ps]-a[left] )+ abs( a[ps+1]-a[right] );
					left = ps,right = ps+1;
				}
				ps+=2;
			}
			cnt++;
		} 
		if( ps==pe )
			ret2+=max(abs(a[left]-a[ps]),abs(a[right]-a[ps]));
		ret=max(ret1,ret2);
		printf("%lld\n",ret);
	}	
	return 0;
}

