#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
#define N 1000000
int n;
int a[N]; 
int main() {
	a[0]=0;	
	int i,b,c,d,j; 
	cout<<(22^51^37)<<endl;  //Òì»òÔËËã 
	cin>>n;
	cout<<a[0]<<endl;
	for( i=1;i<=n;i++ )
	{
		if( a[i-1]==0 )
			a[i]=1;
		else if( i>=4 && a[i-4]==0 )
			a[i]=1;
		else if( i>=7 && a[i-7]==0 )
			a[i]=1;
		else
			a[i]=0;
		cout<<a[i]<<endl;
	}
	int st=max(b,max(c,d));
	for( i=2*st;;i++)
	{
		int i1=i;
		for( j=0;j<i-st;j++ ){
			int j1=j;
			while(1)
				if( a[i1++]!=a[j1++] )
					break;
		}		
	}
	return 0;
	}

