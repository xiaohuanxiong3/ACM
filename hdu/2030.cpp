#include<iostream> 
#include<cstring>
#include<fstream>
using namespace std;

int main()
{
	int n,i,j;
	char c;
	while( cin>>n )
	{
		cin.ignore();
		int *count=new int[n];
		for(i=0;i<n;i++)
			count[i]=0;
		for(i=0;i<n;i++)
		{
			while( ( c=getchar() ) !='\n' )
			{
				if(c<0)
					count[i]++;
			}
		}
		for(i=0;i<n;i++)
		{
			cout<<count[i]/2<<endl;
		}
	} 
	return 0;
}
