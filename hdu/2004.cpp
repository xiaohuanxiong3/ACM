#include<iostream>
using namespace std;

int main()
{
	int x;
	cout<<(-1)/10<<endl;
	while(cin>>x)
	{
		if(x<0)
			cout<<"Score is error!\n";
		else
			switch(x/10)
			{
				case 0:
				case 1:
				case 2:
				case 3:
				case 4:
				case 5:
					cout<<"E\n";
				break;
				case 6:
					cout<<"D\n";
					break;
				case 7:
					cout<<"C\n";
					break;
				case 8:
					cout<<"B\n";
					break;
				case 9:
				case 10:
					cout<<"A\n";
					break;
				default:
					cout<<"Score is error!\n";
			}
	}
	return 0;
 } 
