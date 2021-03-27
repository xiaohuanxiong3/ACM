#include<iostream>
using namespace std;
#define size 127501
int *a=new int[size];
int *b=new int[size];
int main()
{
	int N;
	int i,j,k;
	int last2,last;
	int ans;
	int v[51],n[51];
	while( cin>>N&&N>=0 )
	{
		ans=0;
		for( i=1;i<=N;i++ )
		{
			scanf("%d%d",&v[i],&n[i]);
			ans+=v[i]*n[i];
		}
		int x=ans/2;
		last=0;
		a[0]=1;
		for( i=1;i<size;i++ )
			a[i]=0;
		for( i=1;i<=N;i++ )
		{
			last2=min(last+n[i]*v[i],x);
			for( j=0;j<=last2;j++ )
				b[j]=0;
			for( j=0;j<=n[i]&&j*v[i]<=last2;j++ )
				for( k=0;k<=last&&k+j*v[i]<=last2;k++ )
					b[ k+j*v[i] ]+=a[k];
			for( j=0;j<=last2;j++ )
				a[j]=b[j];
			last=last2;
		}
		for( i=x;i>=0;i-- )
			if( a[i] )
			{
				break;
			}
		cout<<ans-i<<" "<<i<<endl;
	 } 
	delete []a;
	delete []b;
}
