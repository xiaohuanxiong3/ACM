#include<iostream> 
#include<cstring>
using namespace std;
int main()
{
	int i,j;
	string arr;
	while( getline(cin,arr) )
	{
		if(arr[0]!=' ')
		{
				arr[0]-=32;
				cout<<arr[0];
			}	
		else
			cout<<arr[0];
		for(i=1;i<arr.length();i++)
		{
			if( arr[i]!=' ' && arr[i-1]==' ')
			{
				arr[i]-=32;
				cout<<arr[i];
			}
			else
				cout<<arr[i];
		}
		cout<<endl;
	 } 
	return 0;
}
