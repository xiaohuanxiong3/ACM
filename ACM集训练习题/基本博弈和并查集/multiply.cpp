#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cmath> 
using namespace std;

int main() {
	double n;
	while( cin>>n ){
		while( n>18 )
			n/=18;
		if( n>=1 && n<=9 )
			cout<<"Stan wins.\n";
		else
			cout<<"Ollie wins.\n";
	} 
	return 0;
	}

