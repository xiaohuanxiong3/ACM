#include<iostream> 
#include<cmath>
using namespace std;
//�󼯺�A�뼯��B�Ĳ ��A-B 
void px(int *arr,int length) //��С�������� 
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
		int *arr1=new int[n];  //����A��n��Ԫ�� 
		int *arr2=new int[m];  //����B��m��Ԫ�� 
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
			if(flag)  //������A�ж��е�Ԫ�طŵ�arr������ 
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
