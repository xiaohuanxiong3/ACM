#include<iostream> 
#include<cstring>
using namespace std;

int main()
{
	int n,i,j;
	while( cin>>n )
	{
		cin.ignore();
		string *arr=new string[n];
		for(i=0;i<n;i++)
		{
			
			getline(cin,arr[i]);
		}
		for(i=0;i<n;i++)
		{
			int flag=1;
			if( arr[i].length()%2==0 ) 
			{
				for(j=0;j<arr[i].length()/2;j++)
				{
					if( arr[i][j]!= arr[i][ arr[i].length()-1-j ] )
					{
						cout<<"no\n";
						flag=0;
						break;
					}
				}
			}
			else 
			{
				for(j=0;j<=arr[i].length()/2;j++)
				{
					if( arr[i][j]!= arr[i][ arr[i].length()-1-j ] )
					{
						cout<<"no\n";
						flag=0;
						break;
					}
				}
			}
			if(flag)
				cout<<"yes\n";
		}
	} 
	return 0;
}
