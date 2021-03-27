#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
#define N 10005 
#define exp 1e-10
struct node{
	int a,b,c;
}cur[N];
int n,b,i,t;
double fun(double x,int index){
	return cur[index].a*x*x+cur[index].b*x+cur[index].c;
}
double get_val(double mid){  //求F(x)在mid点处的函数值 
	int i;
	double max=fun(mid,0);
	for( i=0;i<n;i++ )
	{
		double tmp=fun(mid,i);
		if( tmp>max )
			max=tmp;
	}
	return max;
}
int main() {
	
	cin>>t; 
	while( t-- ){
		cin>>n;
		for( i=0;i<n;i++ )
		{
			scanf("%d%d%d",&cur[i].a,&cur[i].b,&cur[i].c);
		}
		double l=0,r=1000;
		while( l+exp<r ){
			double rl=l+(r-l)/3,rr=r-(r-l)/3;
			if( get_val(rl)<get_val(rr) )
				r=rr;
			else
				l=rl;
		}
		printf("%.4lf\n",get_val(l));
	}
	return 0;
	}

