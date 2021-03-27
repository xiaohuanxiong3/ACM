#include <iostream>
#include<cmath>
using namespace std;
int main()
{ 	
	int v[27],n[27],a[51],b[51];  //v[i]是第i个因子的权重,n[i]是第i个因子的最大个数(此处最小个数为0) a[i]最终存储和为i的组合数,b[i]存储中间系数 
	int i,j,k;
	int  last2,last,sum;  //last确定每次循环a[i]的最大系数值
	int t;
	cin>>t;
	while( t-- )
	{
		for( i=1;i<=26;i++ )
		{
			scanf("%d",&n[i]);
			v[i]=i;
		}
		a[0]=1;
		for( i=1;i<=50;i++ )
			a[i]=0;
		last=0;
		for( i=1;i<=26;i++ )
		{
			last2=min(last+n[i]*v[i],50);
			for( j=0;j<=last2;j++ )
				b[j]=0; 
			for( j=0;j<=n[i]&&j*v[i]<=last2;j++ )
				for( k=0;k<=last&&k+j*v[i]<=last2;k++ )
					b[ k+j*v[i] ]+=a[k];
			for(j=0;j<=last2;j++)
				a[j]=b[j];
			last=last2; 
		}
		sum=0;
		for( i=1;i<=50;i++)
		{
			sum+=a[i];
		}
		printf("%d\n",sum);
	 } 
	return 0;
}


