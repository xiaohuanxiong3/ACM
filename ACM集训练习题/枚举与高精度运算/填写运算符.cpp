#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
//找到所有符合条件的表达式 
char ops[]={'+','-','*','/'}; 
int main() {
	
	int a[5],y,i,op[4],cnt=0;
	for( i=0;i<5;i++ )
		cin>>a[i];
	cin>>y;
	
	for( op[0]=0;op[0]<4;op[0]++ )
		for( op[1]=0;op[1]<4;op[1]++ )
			for( op[2]=0;op[2]<4;op[2]++ )
				for( op[3]=0;op[3]<4;op[3]++ )
					{
						int flag=0;
						int f=1;
						int p=0,q=a[0];
						for( i=0;i<4;i++ )
					    {
					    	switch( ops[ op[i] ] )
					    	{
					    		case '+':
					    			p+=q*f;
					    			f = 1;
					    			q=a[i+1];
					    			break;
					    		case '-':
					    			p+=q*f;
					    			f=-1;
					    			q=a[i+1];
					    			break;
					    		case '*':
					    			q*=a[i+1];
					    			break;
					    		case '/':
					    			if( a[i+1]!=0 && q%a[i+1]==0 )	
										q/=a[i+1];
									else{
										flag=1;  //碰到除数为0或者不能整除的情况 
									}
					    	}
					    	if( flag )
					    		break;
					    }
					    if( flag )
							continue; 
					    else {
					    	p+=q*f;
					    	if( p==y )
					    	{
					    		cout<<a[0]<<ops[ op[0] ]<<a[1]<<ops[ op[1] ]<<a[2]<<ops[ op[2] ]<<a[3]<<ops[ op[3] ]<<a[4]<<"="<<y<<endl;
					    			cnt++;
					    	}
					    }
					}
	if( !cnt )
		cout<<"SORRY,组合不存在!\n"; 
	return 0;
	}

