#include<iostream>
using namespace std;
void change(double &x1,double &y1,double &x2,double &y2)  //保证x1,y1位于左下角，x2,y2位于右上角 
{
	double temp;
	if(x1>=x2)
	{
		temp=x1;
		x1=x2;
		x2=temp;
	}
	if( y1>= y2)
	{
		temp=y1;
		y1=y2;
		y2=temp;
	}
}
int main()
{
	char x;
//	int i,j,k;
	int ans;
	int n,i;
	double x1,x2,x3,x4,y1,y2,y3,y4; 
	double maxz,miny,maxx,mins;
	while( cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4 )
	{
		change(x1,y1,x2,y2);
		change(x3,y3,x4,y4);
		if( x1>=x3 )  //左边最大 
			maxz=x1;
		else
			maxz=x3;
			
		if( x2<=x4)  //右边最小 
			miny=x2;
		else
			miny=x4;
			
		if( y1>=y3 ) //下方最大 
			maxx=y1;
		else
			maxx=y3;
			
		if( y2<=y4 ) //上方最小 
			mins=y2;
		else
			mins=y4;
		if( maxz<miny && maxx<mins )
			printf("%.2lf\n",(miny-maxz)*(mins-maxx) );
		else
			cout<<"0.00\n";
	} 
	return 0; 
}
