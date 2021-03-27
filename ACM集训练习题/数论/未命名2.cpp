#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
int x0,y0;
long long convert_gcd(long long a,long long b,long long &x,long long &y){
	long long m,t;
	if( a==0 && b==0 ) //没有最大公因数 
		return -1;  
	if( b==0 )
	{
		x =1 ,y = 0;
		return a;
	}
	m = convert_gcd(a,b,x,y);
	t = x, x = y, y = t - a/b*y;
	return m;
}
int main(){
	int A,B,C;
	scanf("%lld%lld%lld",&A,&B,&C);
	long long d = convert_gcd(A,B,x0,y0);
	if( C%d )
	{
		cout<<-1<<endl;
		return 0;
	}
	cout<<(-C/d*x0)<<' '<<(-C/d*y0)<<endl;
	return 0;
}

