#include<iostream> 
using namespace std;
int main()
{
	int n,temp,i,j;
	cin>>n;
	while(n>0)
	{
		int *arr=new int[n];
		int *arr1=new int[n];
		for(i=0;i<n;i++)
			cin>>arr[i];
		for(i=0;i<n;i++)
			if(arr[i]<0)
				arr1[i]=-arr[i];
			else
				arr1[i]=arr[i];
		for(i=0;i<n-1;i++) //������ð������ 
		{
			temp=i;
			for(j=i+1;j<n;j++)
			{
				if(arr1[temp]<=arr1[j])
					temp=j;
			}
			if(temp!=i) //�����ǰλ�ò��Ǵӵ�ǰλ��������Ԫ��,���� ԭ���� �е�ǰλ�õ�Ԫ�غ�����Ԫ�� 
			{
				int a;
				
				a=arr1[i]; 
				arr1[i]=arr1[temp];
				arr1[temp]=a;
				
				a=arr[i];
				arr[i]=arr[temp];
				arr[temp]=a;
			}
		}
		for(i=0;i<n-1;i++)
			cout<<arr[i]<<" ";
		cout<<arr[n-1]<<endl;
		cin>>n;
	}
	return 0;
}
