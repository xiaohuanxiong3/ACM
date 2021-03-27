#include<iostream>  
using namespace std;
int main()
{
	int n,m;
	int i,j,k;
	int a,b;
	long long arr[51];
	cin>>n;
	while( n-- )
	{
		for(i=0;i<51;i++)
			arr[i]=0;
		cin>>a>>b;
		 arr[a+1]=1;
		 arr[a+2]=2;
		 for(i=a+3;i<=b;i++)
		 	arr[i]=arr[i-1]+arr[i-2];
		cout<<arr[b]<<endl;
	}
	return 0;
}
