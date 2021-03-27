#include <iostream>
#include<algorithm>
using namespace std;
int main()  
{  
    int i,j;
	int arr[101][101]; 
	int dp[101][100];
    int n,t;
    cin>>t;
    while( t-- )
    {
    	cin>>n;
    	for( i=1;i<=n;i++ )
    	{
    		for( j=1;j<=i;j++ )
    		{
    			scanf("%d",&arr[i][j]);
			}
		}
		for( i=1;i<=n;i++ )
			dp[n][i]=arr[n][i];
		for( i=n-1;i>=1;i-- )
		{
			for( j=i;j>=1;j-- )
				dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+arr[i][j];
		}
		cout<<dp[1][1];
			cout<<endl;
	}
    
	return 0;
}
