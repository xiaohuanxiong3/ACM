#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
/*
	& : 按位逻辑 ^(交) 
	| : 按位逻辑 v(并) 
	^ : 按位逻辑 异或
	hdu 1074 位运算+状态压缩 
	n最多只有15,可以开长度为1<<16的数组表示每种状态
	dp[i]:完成状态i所有作业所扣的最少分数 
	设i状态表示完成i1,i2...ik本书
	dp[i]=min(第ir本书最后完成所扣的分数+ i^( 1<<(ir-1) )状态所扣的最小分数) 1<=r<=k
	其中 i^( 1<<(ir-1) ) 表示k本书中没有第ir本书所扣的最小分数,
	当然第ir本书最后完成扣的最小分数与状态 i^( 1<<(ir-1) ) 有关 
	如n=4时 13的二进制表示1011 表示写第一门，第三门，第四门作业 
	n=3时 5的二进制表示为 101 表示写第一门作业和第三门作业
	dp[5]表示写第一门作业和第三门作业老师扣的最少分数
	易知dp[5]为min(在状态001的基础上最后完成第一门作业扣的分数+dp[4],
	在状态100的基础上最后完成第三门作业扣的分数+dp[1]) 
	1111=00001-1 
*/ 
#define N 1<<16
int dp[N],T[N],cost[20],dead[20],ans[20];
int order[N]; //状态i下的最优写作业顺序下最后一本书的编号 
string subject[20];
void output(int state){
	if( state==0 )
		return;
	output( state^( 1<<(order[state]-1) ) );
	cout<<subject[order[state]]<<endl;
}
int main(){
	int i,j,n,t;
	cin>>t;
	while( t-- )
	{
		cin>>n;
		for( i=1;i<=n;i++ )
		{
			cin>>subject[i]>>dead[i]>>cost[i];
		}
		for( i=1;i<(1<<n);i++ )
		{
			dp[i]=1<<26;
			for( j=n;j>=1;j-- )
			{
				int tt=1<<(j-1);
				if( !(tt&i) )	continue;
				int pre=tt^i;  //状态i中除去第j本书
				int losescore=T[pre]+cost[j]-dead[j];
				losescore=(losescore<0)?0:losescore;
				if( dp[pre]+losescore<dp[i] )
				{
					dp[i]=dp[pre]+losescore;
					T[i]=T[pre]+cost[j];
					order[i]=j;
				}
			}
		}
		//cout<<1<<n-1<<endl;
		cout<<dp[(1<<n)-1]<<endl;
		output((1<<n)-1);
	}
	return 0;
}

