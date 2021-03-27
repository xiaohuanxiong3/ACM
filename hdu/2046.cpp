#include<iostream> 
#include<cmath> 
using namespace std;
int main()
{
	int n,m;
	int i,j,k;
	long long ans[51];
	ans[1]=1;
	ans[2]=2;
	ans[3]=3;
	for(i=4;i<=50;i++)
		ans[i]=2*ans[i-2]+ans[i-3]; 
	while( cin>>n )
	{
		cout<<ans[n]<<endl;
	}
	return 0;
}
