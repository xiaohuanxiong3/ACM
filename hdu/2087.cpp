#include <iostream>
#include<cstring>
using namespace std; 
int main()  
{  
    int i,j; 
    string a[10000];
    string b[10000];
    int cnt=0;
    string::size_type position; 
	while( cin>>a[cnt] && a[cnt]!="#" )
	{
		cin>>b[cnt];
		cnt++;
	}
	for( i=0;i<cnt;i++ )
	{
		int flag=0;
		while( ( position=a[i].find( b[i]) )!=string::npos )
		{
			position=a[i].find( b[i] );
			flag++;
			a[i]=a[i].erase( position,b[i].length() );
		}
		cout<<flag<<endl;
	}
	return 0;
}
