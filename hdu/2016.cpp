#include<iostream>
#include<iomanip>
using namespace std;
int findmin(int *arr,int length)
{
	int i;
	int temp=0;
	for(i=1;i<length;i++)
	{
		if(arr[i]<=arr[temp])
			temp=i;
	}
	return temp;
}
int main()
{
	int n,i,index,temp;
	cin>>n;
	while(n>0)
	{
		int *arr=new int[n];
		for(i=0;i<n;i++)
			cin>>arr[i];
		index=findmin(arr,n);
		temp=arr[index];  //交换最小项和第一项 
		arr[index]=arr[0];
		arr[0]=temp;
		for(i=0;i<n-1;i++)
			cout<<arr[i]<<" ";
		cout<<arr[n-1]<<endl;
		cin>>n;
	}
	return 0;
}
