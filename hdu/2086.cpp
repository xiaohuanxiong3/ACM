#include <iostream>
using namespace std; 
int main()  
{  
    int i,j; 
    int n;
	double c[3001];
	double a0,an_1; 
	double temp;
	while( cin>>n )
	{
		temp=0;
		cin>>a0>>an_1;
		for( i=1;i<=n;i++ )
			scanf("%lf",&c[i]);
		double an;
		an=( a0+n*an_1 )/(n+1);
		for( i=1;i<=n;i++ )
			temp+=i*c[i];
			
		an-=temp*2/(n+1);
		double a1=a0+an_1-an;
		temp=0;
		for( i=1;i<=n;i++ )
			temp+=c[i];
		a1-=2*temp;
		printf("%.2lf\n",a1);
	}
	return 0;
}
