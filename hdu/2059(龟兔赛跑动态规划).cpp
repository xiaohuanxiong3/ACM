#include<iostream>
#include<algorithm>
#define INF 1e7
using namespace std;
int main()
{
	int i,j,k;
	int L,c,t,vr,vt1,vt2;
	int n;
	double dp[102];
	int p[102];
	while( cin>> L >> n >> c >> t >> vr >> vt1 >> vt2 )
	{
		dp[0]=0;
		p[0]=0,p[n+1]=L;
		for(i=1;i<=n;i++)
			cin>>p[i];
		double ans_r=L*1.0/vr,time;
		for(i=1;i<=n+1;i++)   //到达每个站点所需时间的最小值( dp[i] )为 到达第j(0<=j<i)个站点所需时间最小值( dp[j] )和在第j个站点充电后直接到达第i个站点所需时间的和的最小值 
		{
			dp[i]=INF;
			for(j=0;j<i;j++)
			{
				int length=p[i]-p[j];
				if( length<=c )
				{
					time=length*1.0/vt1;
				}
				else
				{
					time=c*1.0/vt1+(length-c)*1.0/vt2;
				}
				if( j!=0 )  //刚开始已经充满电了 
					time+=t;
				dp[i]=min( dp[i], dp[j]+time );
			}
		}
		cout<<dp[n+1]<<endl;
		if( ans_r<dp[n+1] )
			cout<<"Good job,rabbit!\n";
		else if( ans_r>dp[n+1] )
			cout<<"What a pity rabbit!\n";	
	} 
	return 0; 
}
