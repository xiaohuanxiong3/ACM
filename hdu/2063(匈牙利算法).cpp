#include <iostream>
#include<string.h>
using namespace std;
//������������㷨�����̣������������Ǹ��ݹ�Ĺ��̣�����ؼ����־��ǡ��ڡ���
// ��ԭ�����ǣ��л����ϣ�û���ᴴ�����ҲҪ��
int i,j,k,n,m;
int boys[501];
int link[501][501];
int used[501];
int a,b;
bool find(int x)
{
	int i;
	for( i=1;i<=m;i++ )
	{
		if( link[x][i]==1 && used[i]==0 )
		{
			used[i]=1;
			if( boys[i]==0 || find( boys[i] ) )  //�������������ڳ���λ���� 
			{
				boys[i]=x;
				return true;
			}
		}
	}
	return false;
}
int main()  
{  
    while( cin>>k && k!=0 )
    {
    	cin>>n>>m;
    	memset(boys,0,sizeof(boys));
		memset(link,0,sizeof(link));
 		for( i=1;i<=k;i++ )
 		{
 			scanf("%d%d",&a,&b);  //aŮ����b�����кø� 
 			link[a][b]=1;	
		 }
		int sum=0;
		for( i=1;i<=n;i++ )
		{
			memset(used,0,sizeof(used));
			if( find(i) ) sum++;
		 }
		 cout<<sum<<endl; 	 
    }  
	return 0;
}
