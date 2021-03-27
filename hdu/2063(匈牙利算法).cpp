#include <iostream>
#include<string.h>
using namespace std;
//这就是匈牙利算法的流程，其中找妹子是个递归的过程，最最关键的字就是“腾”字
// 其原则大概是：有机会上，没机会创造机会也要上
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
			if( boys[i]==0 || find( boys[i] ) )  //名草无主或能腾出个位置来 
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
 			scanf("%d%d",&a,&b);  //a女生对b男生有好感 
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
