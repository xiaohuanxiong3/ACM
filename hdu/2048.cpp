#include<iostream> 
#include<cmath> 
using namespace std;
//算出来的概率小数点后第五位是5的话加一 
int main()
{
	int n,m;
	int i,j,k;
	double ans[21];
	ans[1]=0;
	ans[2]=1;
	double a=0.35465;
	int x=a*pow(10,4);
	cout<<( a*pow(10,4) -x )<<endl;
/*	double jiecheng[21]={1,1,2};
	for(i=3;i<=20;i++)
	{
		ans[i]=(i-1)*( ans[i-1]+ans[i-2] );
		jiecheng[i]=jiecheng[i-1]*i;
	 } 
	 cin>>n;
	while( n-- )
	{
		cin>>m;
		double a=ans[m]/jiecheng[m];
		int x=a*pow(10,4);
		if( ( a*pow(10,4) -x)>=0.5 && ( a*pow(10,4) -x )<0.6 )
			a+=0.00001;
		printf("%.2lf%\n",ans[m]/jiecheng[m]*100);
	} 
	return 0; */
}
