#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
long long gcd(long long a,long long b){
	return b==0?a:gcd(b,a%b);
}
long long gbs(long long a,long long b,long long c){ //这个int的精度是真的迷 
	long long t = a*b/gcd(a,b);
	long long ret = t*c/gcd(t,c);
	return ret;
}
long long max(long long a,long long b){
	if( a<=b )
		return b;
	else
		return a;
} 
// n,n-1,n-2,n-3
int a;
int main(){
	long long i,n,ans;
	cout<<a<<endl; 
	while(cin>>n)
	{
		if( n<=2 )
		ans = n;
		else if( n&1 ) //n为奇数 
		{
			ans = gbs(n,n-1,n-2);
		}	
		else
		{
			ans = max(gbs(n-1,n-2,n-3),gbs(n,n-1,n-3));
			ans = max(ans,gbs(n,n-1,n-2));
			ans = max(ans,gbs(n,n-2,n-3));			
		}
		cout<<ans<<endl;	
	}
	return 0;
}

