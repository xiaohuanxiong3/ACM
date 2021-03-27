#include <iostream>
using namespace std;
int flag;
long long fun(int n)//将n个从 x1柱子 移动到 x3柱子 
{
	if( n==1 )
	{
		return 2;
	}
	else
	{
		if( flag==1 )
		{
			flag++;
			return fun(n-1)+2;
		}
		else if( flag>1 )
		{
			return fun(n-1)*3+2; 
		}
	}
} 
int main()  
{  
    int i,j,k;
    int n,t,x;
    long long ans;
    cin>>t;
    while( t-- )
    {
    	cin>>n;
    	flag=1;
    	ans=fun(n);
    	printf("%lld\n",ans);
    } 
    
	return 0;
}
