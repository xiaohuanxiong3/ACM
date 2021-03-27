#include<iostream> 
#include<cmath> 
using namespace std;
 bool judge(int **arr1,int **arr,int length,int index)  //下标为index的节目 与arr1数组里的节目都不重合返回true，否则返回false 
 {
 	int i;
 	for(i=0;i<length;i++)  // 如果节目和数组里已有的节目有重合即返回false，否则返回true 
 	{
		 if(  !( arr1[i][1]<=arr[index][0] || arr1[i][0]>=arr[index][1] )  )  //时间重合 
		 	return false;
		}
 	return true;
  } 
int main()
{
	int n,m;
	int i,j,k;
	cin>>n;
	while( n>0 )
	{
		int **arr=new int*[n];
		int **arr1=new int*[n];
		for(i=0;i<n;i++)
		{
			arr[i]=new int[2];
			arr1[i]=new int[2];
		}
		for(i=0;i<n;i++)
			for(j=0;j<2;j++)
				cin>>arr[i][j];
		int flag=0; //记录可收看电视节目的最大个数
		 
		for(i=0;i<n;i++)  // 遍历所有可能的组合  
		{
			for(j=0;j<n;j++)  //每次循环开始时将arr1数组清空 
				for(k=0;k<2;k++)
					arr1[j][k]=0;
			arr1[0][0]=arr[i][0];
			arr1[0][1]=arr[i][1];
			int cnt=1;
			for(j=0;j<n;j++)
			{
				if(j!=i)
				{
					if(  judge(arr1,arr,cnt,j) )  
					{
							arr1[cnt][0]=arr[j][0];
							arr1[cnt][1]=arr[j][1];
							cnt++; //表示arr1数组现有元素的个数 
			 
						} 
				}
			}
			if( cnt>=flag )
			 		flag=cnt; 
		}
		cout<<flag<<endl;
		cin>>n;
	}
	return 0;
}
