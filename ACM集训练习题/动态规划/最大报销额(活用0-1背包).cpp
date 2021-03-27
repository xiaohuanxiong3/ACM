#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
#define N 3000005
int dp[N];  //前i个中取出的不大于V的最大值 
vector<int> an;
int main() {
	int i,j,n,num;
	char type,s;
	double p,V; //单项物品价值和总价值 
	double pa,pb,pc;
	while( scanf("%lf%d",&V,&n)&& n ){
		memset(dp,0,sizeof(dp));
		an.clear();
		for( i=0;i<n;i++ ){
			scanf("%d",&num);
		//	cout<<num<<' '; 
			int flag=1;
			pa=pb=pc=0;
			for( j=0;j<num;j++ ){
				scanf(" %c%c%lf",&type,&s,&p);
			//	cout<<type<<' '<<s<<' '<<p<<endl;
				if( !( type=='A' || type=='B' || type=='C' ) ) 
					flag=0;
				if( type=='A' )
				{
					pa+=p;
					if( pa>600 )
						flag=0;
				}
				if( type=='B' )
				{
					pb+=p;
					if( pb>600 )
						flag=0;
				}	
				if( type=='C' )
				{
					pc+=p;
					if( pc>600 )
						flag=0;
				}
			}
			if( pa+pb+pc<=1000 && flag && pa+pb+pc<=V )
			{
				an.push_back( int( (pa+pb+pc)*100 ) );
				//cout<<pa+pb+pc<<endl;
			}
		}
		int l=an.size();
		for( i=0;i<l;i++ )
			for( j=int(V*100);j>=an[i];j-- )
			{
			//	if( dp[j-int(an[i]*100)]+int( an[i]*100 )<=j )
					dp[j]=max( dp[j],dp[j-an[i]]+an[i] );
			}
		printf("%.2lf\n",dp[int(V*100)]*1.0/100);
	}
	return 0;
	}

