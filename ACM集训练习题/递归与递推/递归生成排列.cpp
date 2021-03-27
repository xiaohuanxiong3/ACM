#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
int cnt;
void print_permutation(string s,string A){
	if( A.empty() ) 
	{
		cout<<s<<endl;
		cnt++;
	}
	else{
		int i;
		for( i=0;i<A.length();i++ ) 
		{
			string tmp1=s,tmp2=A;
			tmp1+=A[i];
			tmp2.erase( tmp2.begin() + i );
			print_permutation(tmp1,tmp2);
		}
	}
} 
int main() {
	string s,A="123456789";
	print_permutation(s,A); 
	cout<<cnt<<endl;
	return 0;
	}

