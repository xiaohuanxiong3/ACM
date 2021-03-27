#include <iostream>    
using namespace std;   
int main()  
{  
    int n,i,t;
    long long m;
    long long c[21];
    c[0]=0;
    for(i=1;i<21;i++)
    	c[i]=(i-1)*c[i-1]+1;
	int s[21]; 
	while( cin>>n>>m )
	{
		for(i=0;i<21;i++)
			s[i]=i;
		while( n>0 && m>0 )
		{
			t=m/c[n]+( (m%c[n]==0)?0:1 );  //确定位于第几组
			if( t>0 )
			{
				cout<<s[t];
				for(i=t;i<n;i++)
					s[i]=s[i+1];
				m-=( (t-1)*c[n] + 1);
				putchar( (m==0)?'\n':' '); 
			}
			n--;
		}
		
	} 
	return 0;
}
