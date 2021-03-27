#include<iostream>
#include<iomanip>
using namespace std;
int findmax(int *arr,int length)
{
	int i,temp=0;
	for(i=1;i<length;i++)
	{
		if(arr[i]>=arr[temp])
			temp=i;
	}
	return temp;
}
int findmin(int *arr,int length)
{
	int i,temp=0;
	for(i=1;i<length;i++)
	{
		if(arr[i]<=arr[temp])
			temp=i;
	}
	return temp;
}
int main()
{
	int n,i;
	int index1,index2;
	double ans=0;
	cout<<setprecision(2)<<fixed;
	while(cin>>n)
	{
		int *arr=new int[n];
		for(i=0;i<n;i++)  //输入n位评委的打分 
			cin>>arr[i];
		index1=findmax(arr,n);
		index2=findmin(arr,n);
		for(i=0;i<n;i++)
		{
			if( i!=index1 && i!=index2 )
				ans+=arr[i];
		}
		ans=ans/(n-2);
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
