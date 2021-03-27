#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
#define PI acos(-1.0)
#define exp 1e-9
//注意bottom 为底部的 
int main() {
	int t;
	double r,R,H,V;
	int n;
	cin>>t;
	while( t-- ){
		cin>>r>>R>>H>>V;
		double h0,mid,left,right;		
		if( R==r )
		{
			left=0,right=H;
			while( right-left>exp ){
				mid=left + ( right-left )/2;
				double v=PI*R*R*mid;
				if( v<V )
					left=mid;
				else if( v>=V )
					right=mid;
			}
		}
		else
		{
			h0=( r*H )/(R-r);
		//	cout<<h0<<endl;
			double v0=1.0/3*PI*r*r*h0;
		//	cout<<v0<<endl;
			left=0,right=H;
			while( right-left>exp ){
				mid=left + ( right-left )/2;
		//		cout<<mid<<endl;
				double rx=(mid+h0)*R/(H+h0);
				double v=PI/3*rx*rx*(mid+h0);
				v-=v0;
				if( v<V )
					left=mid;
				else
					right=mid;
			}
		}
		printf("%.6lf\n",mid);
	} 
	return 0;
	}

