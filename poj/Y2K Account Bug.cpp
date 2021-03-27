#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
//Y2K Account Bug 
int main() {
	int i,j,s,d;
	while( cin>>s>>d ){
		if( s>=4*d )
			cout<<"Deficit\n";
		else if( 2*s>=3*d )
		{
			int max=3*s-9*d;
			if( max>=0 )
				cout<<max<<endl;
			else
				cout<<"Deficit\n";
		}
		else if( 3*s>=2*d ){
			int max=6*s-6*d;
			if( max>=0 )
				cout<<max<<endl;
			else
				cout<<"Deficit\n";
		}
		else if( 4*s>=d )
		{
			int max=8*s-4*d;
			if( max>=0 )
				cout<<max<<endl;
			else
				cout<<"Deficit\n";
		}
		else
		{
			int max=10*s-2*d;
			if( max>=0 )
				cout<<max<<endl;
			else
				cout<<"Deficit\n";
		}
		
	}
	return 0;
	}

