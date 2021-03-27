#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
/*
	& : ��λ�߼� ^(��) 
	| : ��λ�߼� v(��) 
	^ : ��λ�߼� ���
	hdu 1074 λ����+״̬ѹ�� 
	n���ֻ��15,���Կ�����Ϊ1<<16�������ʾÿ��״̬
	dp[i]:���״̬i������ҵ���۵����ٷ��� 
	��i״̬��ʾ���i1,i2...ik����
	dp[i]=min(��ir�������������۵ķ���+ i^( 1<<(ir-1) )״̬���۵���С����) 1<=r<=k
	���� i^( 1<<(ir-1) ) ��ʾk������û�е�ir�������۵���С����,
	��Ȼ��ir���������ɿ۵���С������״̬ i^( 1<<(ir-1) ) �й� 
	��n=4ʱ 13�Ķ����Ʊ�ʾ1011 ��ʾд��һ�ţ������ţ���������ҵ 
	n=3ʱ 5�Ķ����Ʊ�ʾΪ 101 ��ʾд��һ����ҵ�͵�������ҵ
	dp[5]��ʾд��һ����ҵ�͵�������ҵ��ʦ�۵����ٷ���
	��֪dp[5]Ϊmin(��״̬001�Ļ����������ɵ�һ����ҵ�۵ķ���+dp[4],
	��״̬100�Ļ����������ɵ�������ҵ�۵ķ���+dp[1]) 
	1111=00001-1 
*/ 
#define N 1<<16
int dp[N],T[N],cost[20],dead[20],ans[20];
int order[N]; //״̬i�µ�����д��ҵ˳�������һ����ı�� 
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
				int pre=tt^i;  //״̬i�г�ȥ��j����
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

