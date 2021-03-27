#include<iostream>
using namespace std;
void sort(char a,char b,char c) //a最小,c的ASCII码最大 
{
	char temp;
	if(int(a)>=int(b))
	{
		temp=a;
		a=b;
		b=temp;
	}
	if( int(a)>=int(c) )
	{
		temp=a;
		a=c;
		c=temp;
	}
	if( int(b)>=int(c) )
	{
		temp=b;
		b=c;
		c=temp;
	}
	cout<<a<<" "<<b<<" "<<c<<endl;
}
int main()
{
	char a,b,c;
	while(cin>>a>>b>>c)
		sort(a,b,c);
	return 0;
 } 
