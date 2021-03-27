#include<iostream> 
#include<cmath>
using namespace std;

int main()
{
	int n,m;
	int i,j,k;
	cin>>n>>m;
	int arr1[40000]; //10000的10000次方有40000位 
	int arr2[40000];
	int arr3[40000];
	int ans[40000]; 
	while( n>0 || m>0 )
	{
		for(i=0;i<40000;i++)
		{
			arr1[i]=arr2[i]=arr3[i]=ans[i]=0;
		}
		int temp=n,cnt=39999;		
		while(1)
		{
			if(temp>=10)
			{
				arr1[cnt]=temp%10;
				arr2[cnt]=temp%10;
				arr3[cnt]=temp%10;
				cnt--;
				temp=temp/10;
			}
			else
			{
				arr1[cnt]=temp%10;
				arr2[cnt]=temp%10;
				arr3[cnt]=temp%10;
				cnt--;
				break;
			}
		}
		int cs;
		for(i=1;i<=14;i++)
		{
			if( pow(2,i)>m )
			{
				cs=i-1;
				break;
			}
		}
		for(i=0;i<cs;i++) //求n的m次幂 
		{
			for(j=0;j<40000;j++)  //
			{
				if( arr2[j]!=0 )
				{
					temp=j;
					break;
				}
			}
			for(j=39999;j>=temp;j--)
			{
				int flag=j;
				for(k=39999;k>=temp;k--)
				{
					ans[flag]+=arr1[j]*arr2[k];
					if( ans[flag]>=10 )
					{
						ans[flag-1]+=ans[flag]/10;
						ans[flag]=ans[flag]%10;
					}
					flag--;
				}
			}
			for(j=0;j<40000;j++)
			{
				arr2[j]=ans[j];
				arr1[j]=ans[j];
				ans[j]=0;
			}
		}
		for(i=pow(2,cs);i<=m-1;i++)
		{
			for(j=0;j<40000;j++)  //
			{
				if( arr2[j]!=0 )
				{
					temp=j;
					break;
				}
			}
			for(j=39999;j>cnt;j--)
			{
				int flag=j;
				for(k=39999;k>=temp;k--)
				{
					ans[flag]+=arr3[j]*arr2[k];
					if( ans[flag]>=10 )
					{
						ans[flag-1]+=ans[flag]/10;
						ans[flag]=ans[flag]%10;
					}
					flag--;
				}
			}
			for(j=0;j<40000;j++)
			{
				arr2[j]=ans[j];
				ans[j]=0;
			}
		}
		for(i=0;i<40000;i++)
		{
			if(arr2[i]!=0)
			{
				temp=i;
				break;
			}
		}
		for(i=temp;i<40000;i++)
			cout<<arr2[i];
		cout<<endl;
		
/*		if( temp<=39997 ) //n的m次幂至少为三位数
		{
			cout<<"1\n";
			cout<<ans[39997];
			if( ans[39998]!=ans[39997] )
				cout<<ans[39998];
			if( ans[39999]!=ans[39997] && ans[39999] != ans[39998] )
				cout<<ans[39999]<<endl;
		 }
		 if( temp==39998 )
		 {
		 	cout<<"2\n";
		 	cout<<ans[39998];
		 	if( ans[39999]!=ans[39998] )
		 		cout<<ans[39999]<<endl;
		  } 
		  if(temp==39999)
		  {
		  		cout<<"3\n";
			 	cout<<ans[39999]<<endl;
			 }  */
		cin>>n>>m;
	}
	return 0;
}
