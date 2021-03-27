#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
int main(){
	long long a,b;
	while( cin>>a>>b ){
		int x = a%10;
		switch(x){
			case 0:
				cout<<0<<endl;
				break;
			case 1:
				cout<<1<<endl;
				break;
			case 2:
				if( b%4==1 )
					cout<<2<<endl;
				else if(b%4==2)
					cout<<4<<endl;
				else if(b%4==3)
					cout<<8<<endl;
				else
					cout<<6<<endl;
				break;
			case 3:
				if( b%4==1 )
					cout<<3<<endl;
				else if(b%4==2)
					cout<<9<<endl;
				else if(b%4==3 )
					cout<<7<<endl;
				else
					cout<<1<<endl;
				break;
			case 4:
				if( b%2==1 )
					cout<<4<<endl;
				else
					cout<<6<<endl;
				break;
			case 5:
				cout<<5<<endl;
				break;
			case 6:
				cout<<6<<endl;
				break;
			case 7:
				if( b%4==1 )
					cout<<7<<endl;
				else if(b%4==2)
					cout<<9<<endl;
				else if(b%4==3 )
					cout<<3<<endl;
				else
					cout<<1<<endl;
				break;
			case 8:
				if( b%4==1 )
					cout<<8<<endl;
				else if(b%4==2)
					cout<<4<<endl;
				else if(b%4==3 )
					cout<<2<<endl;
				else
					cout<<6<<endl;
				break;
			case 9:
				if( b%4==1 )
					cout<<9<<endl;
				else 
					cout<<1<<endl;
		}
	}
	return 0;
}

