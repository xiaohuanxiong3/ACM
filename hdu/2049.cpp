#include<iostream> 
#include<cmath> 
using namespace std; 
int main()
{
	int n,m;
	int N,M;
	int i,j,k;
	long long ans[21];
	long long jiecheng[21]={1,1,2};
	ans[1]=0;
	ans[2]=1;
	for(i=3;i<=20;i++)
	{
		ans[i]=(i-1)*( ans[i-1]+ans[i-2] );
		jiecheng[i]=jiecheng[i-1]*i;
	}
	 cin>>n;
	while( n-- )
	{
		cin>>N>>M;
		cout<<jiecheng[N]/( jiecheng[N-M]*jiecheng[M])*ans[M]<<endl;
	} 
	return 0; 
}
