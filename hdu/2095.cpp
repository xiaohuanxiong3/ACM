#include <iostream>
using namespace std; 
int fun(int **ans,int length,int a) //�ж�Ԫ���Ƿ���ans������(�������,�����±꣬���򷵻�0) 
{
	int i;
	for(i=1;i<length;i++)
		if( ans[i][0]==a )
			return i;
	return 0;
}
int main()  
{  
    int i,j,cnt,n; 
	while( cin>>n && n>0 )
	{
		int x=n/2+2;
		int **ans=new int*[x];   //��һ��Ԫ�ش洢��Ӧ������,�ڶ���Ԫ�ش洢���������ֵĴ��� 
		for(i=0;i<x;i++)
		{
			ans[i]=new int[2];
			ans[i][0]=ans[i][1]=0;
		}
		int index=1;
		for(i=0;i<n;i++)
		{
			scanf("%d",&cnt);
			if( fun(ans,index,cnt)==0 ) //������
			{
				ans[index][0]=cnt;
				ans[index][1]=1;
				index++;
			} 
			else
			{
				int temp=fun(ans,index,cnt);
				ans[temp][1]++;
			}  
		}
		for( i=1;i<index;i++ )
		{
			if( ans[i][1]==1 )
			{
				cout<<ans[i][0]<<endl;
				break;
			}
		} 
	}
	return 0;
}
