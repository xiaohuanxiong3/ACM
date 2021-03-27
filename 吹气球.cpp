#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<vector> 
#include<iomanip>
#include<cmath>
using namespace std;
#define N 15
#define PI 3.1415926
struct point{
    int x,y,z;
}bo[N],ul,rd;
int main() {
	ios::sync_with_stdio(false);
	int i,j,k;
/*	for( i=0;i<=100/3;i++ )
		for( j=0;j<=100/2;j++ )
			if( (100-i*3-j*2)>=0 && i+j+(100-i*3-j*2)*3==100 )
				cout<<i<<" "<<j<<" "<<(100-i*3-j*2)*3<<endl;   */
	int a[]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
	int n;
	double ra,disret=0,retT=0;
	cin>>n;
	cin>>ul.x>>ul.y>>ul.z;
	cin>>rd.x>>rd.y>>rd.z;
	for( i=0;i<n;i++ ){
		cin>>bo[i].x>>bo[i].y>>bo[i].z;
	}
	do{
		for( i=0;i<n;i++ ){
			ra=min(rd.x-bo[ a[i] ].x,bo[ a[i] ].x-ul.x);
			ra=min( ra,min( ul.y-bo[ a[i] ].y,bo[ a[i] ].y-rd.y) );
			ra=min( ra,min( ul.z-bo[ a[i] ].z,bo[ a[i] ].z-rd.z) );
			for( j=0;j<i;j++ ){
			
				dis=sqrt( ( bo[ a[i] ].x-bo[ a[j] ].x )* (bo[ a[i] ].x-bo[ a[j] ].x ) +
						  ( bo[ a[i] ].y-bo[ a[j] ].y )* (bo[ a[i] ].y-bo[ a[j] ].y ) +
						  ( bo[ a[i] ].z-bo[ a[j] ].z )* (bo[ a[i] ].z-bo[ a[j] ].z ) );
				dis-=ras[j];
				ra=max( 0,min( ra,dis) );		
			}
			ras[i]=ra;	
			retT+=4.0/3*PI*ra*ra*ra;	
		}
		ret=max( ret,retT);
	}while( next_permutation(a,a+n) );
	cout<<ret<<endl;
	return 0;
}

