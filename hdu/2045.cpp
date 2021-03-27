#include<iostream> 
#include<cmath> 
using namespace std;
int main()
{
	int n,m;
	int i,j,k;
	long long ans[51];
	ans[1]=3;
	ans[2]=6;
	ans[3]=6;
	for(i=4;i<=50;i++)
		ans[i]=ans[i-1]+2*ans[i-2]; 
	while( cin>>n )
	{
		cout<<ans[n]<<endl;
	}
	return 0;
}
