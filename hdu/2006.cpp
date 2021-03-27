#include<iostream>
using namespace std;
int main()
{
	int n,i,ans=1;
	while(cin>>n)
	{
		int *arr=new int[n];
		for(i=0;i<n;i++)
		{
			cin>>arr[i];
			if( arr[i]%2!= 0 ) //输入的是奇数
				ans*=arr[i]; 
		}
		cout<<ans<<endl;
		ans=1;
	}
	return 0;
 } 
