#include <iostream>
#include<cmath>    
using namespace std;
double fun(int x1,int y1,int x2,int y2)
{
	return sqrt( pow(x2-x1,2)+pow(y2-y1,2) );
   }   
int main()  
{  
    int n,i,t;
    int x1,y1,x2,y2;
    int temp;
    double length;
    cin>>t; 
	while(t-- )
	{
		length=0;
		cin>>x1>>y1>>x2>>y2;
		int temp1=x1+y1,temp2=x2+y2;
		if( temp1==temp2 )
		{
			length=fun(x1,y1,x2,y2);
			printf("%.3lf\n",length);
		}
		else   //保证在折线上(x1,y1)在(x2,y2)前面 
		{
			if( temp1>temp2 )
			{
				temp=x1;
				x1=x2;
				x2=temp;
				temp=y1;
				y1=y2;
				y2=temp;
				temp=temp1;
				temp1=temp2;
				temp2=temp;
			}
			length+=fun(x1,y1,temp1,0);
			for(i=temp1;i<temp2;i++)
			{
				length+=fun(i,0,0,i+1)+fun(0,i+1,i+1,0);
			 } 
			 length-=fun(x2,y2,temp2,0);
			 printf("%.3lf\n",length);
		}
	} 
	return 0;
}
