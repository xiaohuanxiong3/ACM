#include<iostream>
using namespace std;

int main()
{
	int a,b,c;
	char str;
	while(cin>> a >> str >> b >> str >>c)
	{
		if( (a%4==0 && a%100!=0) || a%400==0 ) //闰年
		{
			switch(b)
			{
				case 1:
					cout<<c<<endl;
					break;
				case 2:
					cout<<31+c<<endl;
					break;
				case 3:
					cout<<31+29+c<<endl;
					break;
				case 4:
					cout<<31+29+31+c<<endl;
					break;
				case 5:
					cout<<31+29+31+30+c<<endl;
					break;
				case 6:
					cout<<31+29+31+30+31+c<<endl;
					break;
				case 7:
					cout<<31+29+31+30+31+30+c<<endl;
					break;
				case 8:
					cout<<31+29+31+30+31+30+31+c<<endl;
					break;
				case 9:
					cout<<31+29+31+30+31+30+31+31+c<<endl;
					break;
				case 10:
					cout<<31+29+31+30+31+30+31+31+30+c<<endl;
					break;
				case 11:
					cout<<31+29+31+30+31+30+31+31+30+31+c<<endl;
					break;
				case 12:
					cout<<31+29+31+30+31+30+31+31+30+31+30+c<<endl;
				
			}
		}
		else //不是闰年 
		{
			switch(b)
			{
				case 1:
					cout<<c<<endl;
					break;
				case 2:
					cout<<31+c<<endl;
					break;
				case 3:
					cout<<31+28+c<<endl;
					break;
				case 4:
					cout<<31+28+31+c<<endl;
					break;
				case 5:
					cout<<31+28+31+30+c<<endl;
					break;
				case 6:
					cout<<31+28+31+30+31+c<<endl;
					break;
				case 7:
					cout<<31+28+31+30+31+30+c<<endl;
					break;
				case 8:
					cout<<31+28+31+30+31+30+31+c<<endl;
					break;
				case 9:
					cout<<31+28+31+30+31+30+31+31+c<<endl;
					break;
				case 10:
					cout<<31+28+31+30+31+30+31+31+30+c<<endl;
					break;
				case 11:
					cout<<31+28+31+30+31+30+31+31+30+31+c<<endl;
					break;
				case 12:
					cout<<31+28+31+30+31+30+31+31+30+31+30+c<<endl;
			} 
		}
	}
	return 0;
 } 
