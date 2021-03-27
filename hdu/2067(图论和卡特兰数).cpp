#include <iostream>
using namespace std;
// 图论和卡特兰数 
int main()  
{ 
	int i,j;
	int n[36];
	long long ans[36]={0};
	ans[0]=1,ans[1]=1;
	for( i=2;i<=35;i++ )
	{
		for( j=0;j<i;j++ )
			ans[i]+=ans[j]*ans[i-1-j]; 
	 } 
	 int cnt=0;
    while( cin>>n[cnt] && n[cnt]!=-1 )
    {
    	cnt++; 	 
    }  
    for( i=0;i<cnt;i++ )
    {
    	cout<<i+1<<" "<<n[i]<<" "<<ans[ n[i] ]*2;
    		cout<<endl;
	}
	return 0;
}
