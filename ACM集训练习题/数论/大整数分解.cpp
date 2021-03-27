#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
#define LL long long
// 求a*bmodc 
LL gcd(LL a,LL b){
	return b==0?a:gcd(b,a%b);
}
LL mod(LL a,LL b,LL c){
	LL ret = 0,t = a;
	while( b ){
		if( b&1 ){
			ret += t;
		}
		ret %= c;
		t <<= 1;
		t %= c;
		b >>= 1;
	}
	return ret;
}
// 返回n的一个因子 
LL factor(LL n,LL k){
	LL x1 = rand()%n,p,x2;
	while( 1 ){
		x2 = (mod(x1,x1,n) + k)%n;
		p = gcd(abs(x2-x1),n);
		if( p==n )
			return 0;
		if( p>1 )
			return p;
		if( x1==x2 )  
			return -1;
		x1 = x2;
	}
}
LL f[1002];
LL cnt=0;
void all_factor(LL n){
	LL p = factor(n,1);
	if( p==0 ) f[cnt++] = n;
	else if( p>0 ) all_factor(p),all_factor(n/p);
	else all_factor(n);
}
int main(){
	
	return 0;
}

