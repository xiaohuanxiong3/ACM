#include<iostream> 
using namespace std;
int main()
{
	int n,i;
	cin>>n;
	while(n>0)
	{
		int *arr1=new int[n+1];
		int *arr2=new int[n+1];
		arr1[1]=1,arr2[1]=0;
		arr1[2]=1,arr2[2]=1;
		arr1[3]=1,arr2[3]=2;
		for(i=4;i<=n;i++)
		{
			arr1[i]=arr2[i-2];
			arr2[i]=arr1[i-1]+arr2[i-1];
		}
		cout<<arr1[n]+arr2[n]<<endl;
		cin>>n;
	}
	return 0;
}
