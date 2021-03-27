#include<iostream> 
#include<cstring>
using namespace std;
void hz(int &a,int &b) //将不互质的两个数化为互质
{
	int temp,i;
	if(a>=b)
		temp=a;
	else
		temp=b;
	for(i=temp;i>=2;i--)
	{
		if(a%i==0 && b%i==0)
		{
			b/=i;
			return;
		}
	}
} 
int main()
{
	int n,i,j;
	
	while( cin>>n )
	{
		int ans=1;
		int *arr=new int[n];
		for(i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		for(i=0;i<n-1;i++)
		{
			for(j=i+1;j<n;j++)
			{
					hz( arr[i],arr[j] );
			}
		}
		for(i=0;i<n;i++)
		{
			ans*=arr[i];
		}
		cout<<ans<<endl;
	} 
	return 0;
}
