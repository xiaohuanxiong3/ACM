#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
#define N 10002
int pre[N],n[N];
int main() {
	int i,j;
	string a,b;
	while( cin>>a>>b )
	{
		int row=a.length(),col=b.length();
		for( i=0;i<=col;i++ )
			pre[i]=0;
		for( i=1;i<=row;i++ )
		{
			n[0]=0;
			for( j=1;j<=col;j++ )
			{
				if( a[i-1]==b[j-1] )
					n[j]=pre[j-1]+1;
				else
					n[j]=max(n[j-1],pre[j]);
			}
			for( j=0;j<=col;j++ )
				pre[j]=n[j];
		//	cout<<n[col]<<endl;
		}
		cout<<n[col]<<endl;
	} 
	return 0;
	}

