#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
// �������ֽ� 
void cf(int n,int a[100][2]){  //���Ӷ�ԼΪn^(1/4) 
	int i,cnt=0;
	for( i=2;i<=n;i++ ){
		while( n%i==0 && n ){
			a[cnt][0] = i,a[cnt][1]++;
			n/=i;
		} 
		cnt++;
	}
}
// ��������� 
int gcd(int a,int b){
	if( b==0 )
		return a;
	return gcd(b,a%b);
}
int stein(int a,int b){
	int r=0;
	a = abs(a),b = abs(b);  //��Ӱ��������� 
	if( a<b )
		swap(a,b);
	while( b>0 ){
		if( !(a&1) && !(b&1) ) {
			a>>=1,b>>=1,r++;
		}
		else if( !(a&1) && b&1 )  //ażb��
			a>>=1;
		else if( a&1 && !(b&1) )  //a��bż
			b>>=1;
		else
			a = (a-b)>>1;
		if( a<b )
			swap(a,b); 
	}
	return a<<r;
}
// ����󹫱���
int lcm(int a,int b){
	return abs(a)*abs(b)/stein(a,b);
} 
int extend_gcd(int a,int b,int x,int y){
	int m,tmp;
	if( a==0 && b==0 )  //��������� 
		return -1;
	if( b==0 ){
		x = 1, y = 0;
		return a;
	}
	m = extend_gcd(b,a%b,x,y);
	tmp = x,x = y,y = tmp - a/b*y;
	return m;
} 
int main(){
//	cout<<0%8<<endl;
	cout<<gcd(24,16);
	return 0;
}

