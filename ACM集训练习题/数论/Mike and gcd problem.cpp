#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
#define N 100002
int a[N];
int stein(int a,int b){
	int r=0;
	a = abs(a),b = abs(b);  //不影响最大公因子 
	if( a<b )
		swap(a,b);
	while( b>0 ){
		if( !(a&1) && !(b&1) ) {
			a>>=1,b>>=1,r++;
		}
		else if( !(a&1) && b&1 )  //a偶b寄
			a>>=1;
		else if( a&1 && !(b&1) )  //a寄b偶
			b>>=1;
		else
			a = (a-b)>>1;
		if( a<b )
			swap(a,b); 
	}
	return a<<r;
} 
int main(){
	int n,i;
	scanf("%d",&n);
	for( i=0;i<n;i++ )
		scanf("%d",&a[i]);
	int t = stein(a[0],a[1]);
	for( i=2;i<n;i++ )
		t = stein(t,a[i]);
	printf("YES\n");
	if( t==1 )
	{
		int ans = 0;
		for( i=0;i<n;i++ )
		{
			if( a[i]&1 && a[i+1]&1 )   //先找所有的相邻奇数
			{
				a[i] = a[i+1] =2;
				ans++;
				i++;	
			} 
		}
		for( i=0;i<n;i++ )
			if( a[i]&1 )
				ans+=2;
		printf("%d\n",ans);
	}	
	else if( t>1 )
		printf("0\n");	
	return 0;
}

