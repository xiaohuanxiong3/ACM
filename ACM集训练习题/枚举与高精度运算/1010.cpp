#include<stdio.h>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<iostream>
using namespace std;
char y[201];
int a[102];
int main() {

	char b[100];
	int num[100];
	char s;
	int x,i; 
	while( 1 )
	{
		cin>>num[0];
		int cn=1,cb=0;
		while( scanf("%c",&s) && s!='\n' ){
			scanf("%c",&b[cb++]);
			scanf("%c",&s);
			scanf("%d",&num[cn++]);
		}
		if( cb==0 && num[0]==0 )
			break;
			int f=1;
			double p=0,q=num[0];
				for( i=0;i<cb;i++ )
			    {
						    	switch(  b[i] )
						    	{
						    		case '+':
						    			p+=q*f;
						    			f = 1;
						    			q=num[i+1];
						    		//	cout<<p<<endl;
						    			break;
						    		case '-':
						    			p+=q*f;
						    			f=-1;
						    			q=num[i+1];
						    		//	cout<<p<<endl;
						    			break;
						    		case '*':
						    			q*=num[i+1];
						    		//	cout<<p<<endl;
						    			break;
						    		case '/':	
										q/=num[i+1];
									//	cout<<p<<endl;
						    	}
			    }
			p+=q*f;
		/*	int temp=p*1000;
			if( temp%10==5 )
				p+=0.001;  */ 
			printf("%.2lf\n",p);
		}
	return 0;
	}

