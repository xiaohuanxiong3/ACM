#include<iostream> 
#include<cmath> 
using namespace std;
 bool judge(int **arr1,int **arr,int length,int index)  //�±�Ϊindex�Ľ�Ŀ ��arr1������Ľ�Ŀ�����غϷ���true�����򷵻�false 
 {
 	int i;
 	for(i=0;i<length;i++)  // �����Ŀ�����������еĽ�Ŀ���غϼ�����false�����򷵻�true 
 	{
		 if(  !( arr1[i][1]<=arr[index][0] || arr1[i][0]>=arr[index][1] )  )  //ʱ���غ� 
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
		int flag=0; //��¼���տ����ӽ�Ŀ��������
		 
		for(i=0;i<n;i++)  // �������п��ܵ����  
		{
			for(j=0;j<n;j++)  //ÿ��ѭ����ʼʱ��arr1������� 
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
							cnt++; //��ʾarr1��������Ԫ�صĸ��� 
			 
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
