#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<vector> 
#include<cmath>
using namespace std;
int main() {
	
	ios::sync_with_stdio(false);
	int i,j,k;
	int m,t;
	int a[155],b[155];
	int n[36]={0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149}; 
	cin>>t; 
	while( t-- )
	{
		cin>>m;
		int ans=0;
		int flag;
		if( m>=149 )
			flag=35;
		else
		{
			for( i=1;i<=35;i++ )
			{
				if( n[i]>m )
				{
					flag=i-1;
					break;
				}
			}
		}
		a[0]=1;
		for( i=1;i<=150;i++)
			a[i]=0;
		for( i=1;i<=flag;i++ )  //最多有n/2组
		{
			for( j=0;j<=m;j++ )
			{
				b[j]=0;
			}
			for( j=0;j*n[i]<=m;j++)
			{
				for( k=0;k+j*n[i]<=m;k++ )
				{
					b[k+j*n[i]]+=a[k];
				}
			}
			for( j=0;j<=m;j++ )
			{
				a[j]=b[j];
			}
		} 
		cout<<a[m]<<endl;
	} 
	return 0;
	}

