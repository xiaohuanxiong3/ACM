#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
#define max 35700
int a[max]; 
int main() {
	int i,j,n,carry,digit;
	while( cin>>n )
	{
		memset(a,0,sizeof(a));
		if( n==0 || n==1 )
			cout<<"1\n";
		else
		{
			memset(a,0,sizeof(a));
			a[0]=1;
			digit=1;
			int temp;
			for( i=2;i<=n;i++ )
			{
				carry=0;
				for( j=0;j<digit;j++ )
				{
					temp=a[j] * i + carry;
					a[j]=temp%10;
					carry=temp/10;
				}
				while( carry )
				{
					a[ digit++ ]=carry%10;
					carry/=10;
				}
			}
			for( i=digit-1;i>=0;i-- )
				cout<<a[i];
			cout<<endl;
		}
	}
	return 0;
	}

