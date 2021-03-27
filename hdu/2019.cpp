#include<iostream> 
using namespace std;
int main()
{
	int n,m,i,j;
	cin>>n>>m;
	while(n>0 || m!=0 )
	{
		int *arr=new int[n+1];
		for(i=0;i<n;i++)
			cin>>arr[i];
		for(i=0;i<n;i++)
		{
			if(arr[i]<=m && arr[i+1]>=m && i!=n-1)
			{
				for(j=n-1;j>=i+1;j--)
					arr[j+1]=arr[j];
				arr[i+1]=m;
				break;	
			}
			else if(arr[i]<=m && i==n-1)
			{
				arr[n]=m;
			}
		}
		if(arr[0]>m)  //第一项都比m大 
		{
			for(j=n-1;j>=0;j--)
				arr[j+1]=arr[j];
			arr[0]=m;
		}
		for(i=0;i<n;i++)
			cout<<arr[i]<<" ";
		cout<<arr[n]<<endl;
		cin>>n>>m;
	}
	return 0;
}
