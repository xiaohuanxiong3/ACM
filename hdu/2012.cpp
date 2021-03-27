#include<iostream>
#include<cmath>
using namespace std;
bool judgeprime(int x)
{
	int i;
	for(i=2;i<=sqrt(x);i++)
		if(x%i==0)
			return false;
	return true;
}
int main()
{
	int x,y,i;
	int flag=0;
	cin>>x>>y;
	while( x!=0 || y!=0 )
	{
		
		for(i=x;i<=y;i++)
			if( judgeprime(i*i+i+41) )
				flag++;
		if(flag>=y-x)
			cout<<"OK\n";
		else
			cout<<"Sorry\n";
		flag=0;
		cin>>x>>y;	
	}
	return 0;
}
