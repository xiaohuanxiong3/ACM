#include<iostream> 
#include<cstring>
using namespace std;
int main()
{
	int n,i,j;
	while(cin>>n)
	{
		cin.ignore();
		string *arr=new string[n];
		for(i=0;i<n;i++)
			{
				//	scanf("%[^\n]",arr[i]);
				getline(cin,arr[i]);
				
			}
			
		for(i=0;i<n;i++)
		{
			if( !( arr[i][0]==95 || (arr[i][0]>=65 &&arr[i][0]<=90) || (arr[i][0]>=97 && arr[i][0]<=122 ) ) )  //不是字母或者下划线
			{
					cout<<"no\n";
					continue;
			}
			int flag=0;
			for(j=1;j<arr[i].length();j++)
			{
				if( !( arr[i][j]==95 || (arr[i][j]>=65 &&arr[i][j]<=90) || (arr[i][j]>=97 && arr[i][j]<=122 ) || (arr[i][j]>=48 && arr[i][j]<=57 ) ) )
				{
					cout<<"no\n";
					flag=1;
					break;
					}	  
			}
			if( !flag )
				cout<<"yes\n";
		}
	 } 
	return 0;
}
