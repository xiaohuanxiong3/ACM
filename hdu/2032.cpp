#include<iostream> 
#include<cmath>
using namespace std;

int main()
{
	int n,i,j;
	while( cin>>n )
	{
		int *arr1=new int[n+1];
		int *arr2=new int[n+1];
		arr1[1]=1;
		arr2[1]=1,arr2[2]=1;
		for(i=1;i<=n;i++)
		{
			if(i==1)
				cout<<arr1[1]<<endl;
			else if(i==2)
				cout<<arr2[1]<<" "<<arr2[2]<<endl;
			else if(i%2!=0)  //奇数行 
			{
				arr1[1]=1;
				cout<<arr1[1]<<" ";
				for(j=2;j<=i/2+1;j++)
				{
				 	arr1[j]=arr2[j]+arr2[j-1];
				 	cout<<arr1[j]<<" "; 
				}
				for(j=i/2+2;j<i;j++)
				{
					arr1[j]=arr1[i+1-j];
					cout<<arr1[j]<<" ";
				 } 
				 arr1[i]=1;
				 cout<<arr1[i]<<endl;
			}
			else if(i%2==0)  //偶数行 
			{
				arr2[1]=1;
				cout<<arr2[1]<<" ";
				for(j=2;j<=i/2;j++)
				{
				 	arr2[j]=arr1[j]+arr1[j-1];
				 	cout<<arr2[j]<<" "; 
				}
				for(j=i/2+1;j<i;j++)
				{
					arr2[j]=arr2[i+1-j];
					cout<<arr2[j]<<" ";
				 } 
				 arr2[i]=1;
				 cout<<arr2[i]<<endl;
			}
		}
		cout<<endl; 
	}
	return 0;
}
