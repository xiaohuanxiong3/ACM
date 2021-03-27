#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<vector> 
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	int a,b,n;
	int k[7][7];
	int f[53];
	int i;

	while(  cin>>a>>b>>n,a+b+n )
	{
		memset(f,0,sizeof(f));
		memset(k,0,sizeof(k));
		f[1]=1,f[2]=1;
		k[1][1]=2;
		for( i=3;i<=51;i++ )  // 确定循环节 并算出一个循环节的所有f[i]的值 
		{
			f[i]=a*f[i-1]+b*f[i-2];
			f[i]=f[i]%7;
		//	cout<<k[ f[i] ][ f[i-1] ]<<endl;
			if( k[ f[i] ][ f[i-1] ]>0 ) break;
			k[ f[i] ][ f[i-1] ]=i;
		}
		int j=i-k[ f[i] ][ f[i-1] ];  //循环节大小 
		n=n-k[ f[i] ][ f[i-1] ];
		n%=j; //第n个是一个循环中的第几个 
		n+=k[ f[i] ][ f[i-1] ]; 
		cout<<f[n]<<endl;
	} 
	return 0;
	}

