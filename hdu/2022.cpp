#include<iostream> 
using namespace std;
int main()
{
	int n,m,i,j,flag1,flag2;
	while(cin>>m>>n)
	{
		int **arr=new int*[m+1]; //数组元素类型为 int * 
		int **arr1=new int*[m+1];
		for(i=1;i<=m;i++)
		{
			arr[i]=new int[n+1]; 
			arr1[i]=new int[n+1];
		}
		int *x=new int[m+1];  //存储每一行绝对值最大的元素的下标 
		for(i=1;i<=m;i++)
			for(j=1;j<=n;j++)
			{
				cin>>arr[i][j];
				if(arr[i][j]>=0)
					arr1[i][j]=arr[i][j];
				else if(arr[i][j]<0)
					arr1[i][j]=-arr[i][j];
			}
		for(i=1;i<m+1;i++)  //找出每一行 绝对值最大 的元素的列下标 
		{
			x[i]=1;
			for(j=2;j<=n;j++)
			{
				if( arr1[i][j]>arr1[i][ x[i] ])  // >保证 最大的元素 有多个时列下标靠前取 
					x[i]=j;
			}
		}
		flag1=1,flag2=x[1];
		for(i=2;i<=m;i++)
		{
			if(arr1[i][ x[i] ]>arr1[flag1][flag2] )
				{
					flag1=i;
					flag2=x[i];
				}
		}
		cout<<flag1<<" "<<flag2<<" "<<arr[flag1][flag2]<<endl;
		for(i=0;i<m+1;i++)
		{
			delete [] arr[i];
			delete [] arr1[i];
		} 
	}
	return 0;
}
