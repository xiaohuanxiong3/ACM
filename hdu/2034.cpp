#include<iostream> 
#include<cmath>
using namespace std;
//求集合A与集合B的差集 即A-B 
void px(int *arr,int length) //从小到大排序 
{
	int i,j;
	int a;
	for(i=0;i<length-1;i++)
	{
		int temp=i;
		for(j=i+1;j<length;j++)
		{
			if( arr[j]<=arr[temp] )
				temp=j;
		}
		if( temp!=i )
		{
			a=arr[i];
			arr[i]=arr[temp];
			arr[temp]=a;
		}
	 } 
}
int main()
{
	int n,m,i,j;
	cin>>n>>m;
	while( n>0 || m>0 )
	{
		int *arr1=new int[n];  //集合A有n个元素 
		int *arr2=new int[m];  //集合B有m个元素 
		int *arr=new int[n];
		for(i=0;i<n;i++)
			cin>>arr1[i];
		for(i=0;i<m;i++)
			cin>>arr2[i];
		int cnt=0;
		for(i=0;i<n;i++)
		{
			int flag=1;
			for(j=0;j<m;j++)
			{
				if(arr1[i]==arr2[j])
				{
					flag=0;
					break;
				}
			}
			if(flag)  //将集合A中独有的元素放到arr数组里 
			{
				arr[cnt]=arr1[i];
				cnt++;	
			}		
		}
		if( !cnt )
		{
			cout<<"NULL\n";
		}
		else
		{
			px(arr,cnt);
			for(i=0;i<cnt;i++)
				cout<<arr[i]<<" ";
			cout<<endl;
		}
		cin>>n>>m;
	}
	return 0;
}
