#include <iostream>
#include<cmath>
using namespace std;
int main()  
{  
    int i,j,k;
    int N,t,x;
    int a[41],b[41];  //a[i]存储选修i个学分组合数,b[i]存储中间数据
	int n[9],v[9]; 
	int last2,last;
    cin>>t;
    while( t-- )
    {
    	cin>>x>>N;  //要选修k学分,总共n门课
		for( i=1;i<=N;i++ )
		{
			scanf("%d%d",&v[i],&n[i]);	
			 }
		a[0]=1;
		for( i=1;i<=40;i++ )
			a[i]=0;
		last=0;
		for( i=1;i<=N;i++ )
		{
			last2=min(last+v[i]*n[i],x);
			for(j=0;j<=last2;j++)
				b[j]=0;
			for(j=0;j<=n[i]&&j*v[i]<=last2;j++)
				for( k=0;k<=last && k+j*v[i]<=last2; k++ )
					b[ k+j*v[i] ]+=a[k]; 
			for(j=0;j<=last2;j++)
				a[j]=b[j];
			last=last2;
		 } 
		 printf("%d\n",a[x]);
	}
    
	return 0;
}
