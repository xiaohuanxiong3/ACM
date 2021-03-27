#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
#define PI acos(-1.0) 
#define exp 1e-7
//注意圆周率精度问题 
//尽量避免浮点数运算 用整数数组做和浮点数数组做  15ms/31ms 
int p[10002];
int main() {
	int i,j,k,n,f,t;
	cin>>t;
	while( t-- ){
		cin>>n>>f;
		for( i=0;i<n;i++ )
		{
			scanf("%d",&p[i]);  //存每个馅饼的体积 
		}
		sort(p,p+n);
		double l=0,r=p[n-1]*p[n-1]*PI,mid;
		while( r-l>exp ){ //
			int cnt=0;
			mid = l + ( r - l )/2;
			for( i=0;i<n;i++ )
				cnt+=( p[i]*p[i]*PI )/mid;
			if( cnt >= f+1 )
				l = mid;
			else
				r = mid;
		}
		printf("%.4lf\n",l );
	}
	return 0;
	}

