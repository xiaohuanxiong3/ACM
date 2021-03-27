#include<iostream>  
using namespace std;
int cnm(int n,int m)
{
	int i,j;
	int *arr1=new int[n+2];
	int *arr2=new int[n+2];
	for(i=1;i<=n+1;i++)
	{
		if(i==1)
			arr1[1]=1;
		else if(i==2)
			arr2[1]=1,arr2[2]=1;	
		if(i%2!=0)  //奇数个 行 
		{
			arr1[1]=1;
			for(j=2;j<=i/2+1;j++)
				arr1[j]=arr2[j]+arr2[j-1];
			for(j=i/2+2;j<i;j++)
				arr1[j]=arr1[i+1-j];
			 arr1[i]=1;
		}
		if(i%2==0)  //偶数个 行 
		{
			arr2[1]=1;
			for(j=2;j<=i/2;j++)
			{
				arr2[j]=arr1[j]+arr1[j-1];
			}
			for(j=i/2+1;j<i;j++)
			{
				arr2[j]=arr2[i+1-j];
			 } 
			 arr2[i]=1;
		}
	}
	if( n%2==0 )
	{
		return arr1[m+1];
	}
	else
	{
		return arr2[m+1];
	}
 } 
int main()
{
	int n,m;
	int i,j,k;
	while( cin>>n )
	{
		int *arr=new int[n];
		for(i=0;i<n;i++)
			cin>>arr[i];
		for(i=0;i<n;i++)
		{
			int flag=0;
			if( arr[i]!=1 )
			{
				for(j=0;j<=19;j++)
				{
					for(k=0;k<=39;k++)
					{
						if( 2*j+k==arr[i]-1)
						{
							if(	j*k!=0 )
							{
								flag+=cnm(j+k,j);	
							}
							else
							{
								flag+=1;
							}
						}
					}
				}
				cout<<flag<<endl;
			}
			else
				cout<<"0\n";
		}
	}
	return 0;
}
