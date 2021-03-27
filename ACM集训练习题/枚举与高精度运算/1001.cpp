#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
char a[40005]={0};
int main() {
	int i;
	while( scanf("%s",&a) )
	{
		int ans=0;
		int length=0;
		for( i=40004;i>=0;i-- )
			if( a[i]>'0' )
			{
				length=i+1;
				break;
			}
		if( length==0 )
			break;
		for( i=0;i<length;i++ )
			ans+=a[i]-'0';
		while( ans>=10 )
		{
			int temp=ans;
			ans=0;
			while( temp>0 )
			{
				ans+=temp%10;
				temp/=10;
			}
		}
		cout<<ans<<endl;
		memset(a,0,sizeof(a));
	}
	return 0;
	}

