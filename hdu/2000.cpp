#include<iostream>
using namespace std;
void sort(char a,char b,char c) //a��С,c��ASCII����� 
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
