#include<iostream> 
#include<cmath> 
using namespace std;
double f2area(double x1,double y1,double x2,double y2,double x3,double y3)  
{
	double temp=( (x2-x1)*(y3-y1)-(x3-x1)*(y2-y1) );
	return temp;
 } 
 double area(int **arr,int length) //求多边形的面积 
 {
 	double ans=0;
 	int i;
 	for(i=1;i<length-1;i++)
	{
		ans+=f2area(arr[0][0],arr[0][1],arr[i][0],arr[i][1],arr[i+1][0],arr[i+1][1]);
	}
	return fabs(ans)/2;
 }
int main()
{
	int n,m;
	int i,j,k;
	cin>>n;
	while( n>0 )
	{
		int **arr=new int*[n];
		double ans=0;
		for(i=0;i<n;i++)
			arr[i]=new int[2];
		for(i=0;i<n;i++)
			for(j=0;j<2;j++)
				cin>>arr[i][j];
		ans=area(arr,n);
		printf("%.1f\n",ans);
		cin>>n;
	}
	return 0;
}
