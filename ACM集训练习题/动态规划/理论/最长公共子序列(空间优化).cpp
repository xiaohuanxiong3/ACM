//ø’º‰”≈ªØ  
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
#define N 1003
char x[N],y[N];
int pre[N],cur[N]; 
int main() {
	int i,j;
	cin>>x+1>>y+1;
	x[0] = y[0] = '@';
	int lenx = strlen(x),leny = strlen(y); 
	for( i=0;i<lenx;i++ )
		pre[i]=0;
	for( i=1;i<lenx;i++ )
	{
	    cur[0]=0;
		for( j=1;j<leny;j++ )
		{
			if( x[i]==y[j] )
			{
				cur[j]=pre[j-1]+1;	
			}
			else
			{
				cur[j]=max(pre[j],cur[j-1]);
			}
		}
		for( j=0;j<leny;j++ )
			pre[j]=cur[j];
	}
	cout<<cur[leny-1]<<endl;
	return 0;
	}

