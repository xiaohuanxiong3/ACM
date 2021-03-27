#include<iostream>
#include<cstring> 
using namespace std;
int main()
{
	int n,i,cnt=0,j;
	while(cin>>n)
	{
		string *arr=new string[n];
		for(i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<arr[i].length();j++)
			{
				if( arr[i][j]>=48 &&arr[i][j]<=57 )
					cnt++;
			}
			cout<<cnt<<endl;
			cnt=0;
		}
	}
	return 0;
}
