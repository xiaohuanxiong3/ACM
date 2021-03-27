#include<iostream>
using namespace std;
bool judgeSXHS(int a,int b)  //判断a，b之间有水仙花数 
{
	int i;
	for(i=a;i<=b;i++)
		if( i== (i%10)*(i%10)*(i%10) + (i/10%10)*(i/10%10)*(i/10%10) + (i/10/10)*(i/10/10)*(i/10/10) )
			return true;
	return false;
}
int main()
{
	int m,n,i,flag=0,j;
	while(cin>>m>>n)
	{
		for(i=m;i<=n;i++)
		{
			if( i== (i%10)*(i%10)*(i%10) + (i/10%10)*(i/10%10)*(i/10%10) + (i/10/10)*(i/10/10)*(i/10/10) )
			{
				cout<<i;
				if( judgeSXHS(i+1,n) )
					cout<<" ";
				flag++;
			}
		}
		if(flag<=0)
			cout<<"no";
		cout<<endl;
		flag=0;
	}
	return 0;
}
