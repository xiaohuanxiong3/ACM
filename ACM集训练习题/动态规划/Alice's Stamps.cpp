#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
#define N 2002
int dp[N][N];  //从前j套邮票里面选i套邮票最多包含多少种不同的邮票 --结果就为dp[k][m] 
int en[N][N];
struct node{
	int st,en;
	bool operator<( const node& n ) const{
		if( st==n.st ) return en>n.en;
		return st<n.st;
	}
	bool operator==( const node & n) const{
		return ( st<=n.st && en>=n.en );
	}
}a[N];
int main() {
	int i,j,t;
	int n,m,k,s,tmp,tmpe,ts,ten,r;
	int cnt=1;
	scanf("%d",&t);
	while( t-- ){
		scanf("%d%d%d",&n,&m,&k);
	/*	for( i=1;i<=m;i++ )
			for( j=1;j<=m;j++ )
				dp[i][j]=-1; */
		for( i=1;i<=m;i++ )
			scanf("%d%d",&a[i].st,&a[i].en);
		printf("Case #%d: ",cnt++);
		sort(a+1,a+1+m);
		m=unique(a+1,a+1+m)-(a+1);
	//	cout<<m<<endl;
		dp[0][0]=0;
		a[0].en=0;
		for( i=1;i<=m;i++ )
		{
			en[i][i]=a[i].en;
			if( a[i-1].en<a[i].st )
			{
				dp[i][i]=dp[i-1][i-1]+a[i].en-a[i].st+1;
			}
			else
			{
				dp[i][i]=dp[i-1][i-1]+a[i].en-en[i-1][i-1];
			}
		//	cout<<i<<' '<<dp[i][i]<<endl;
		}
		if( m<=k )
			printf("%d\n",dp[m][m]);
		else
		{
			for( i=2;i<=m;i++ )
			{
				if( dp[1][i-1]>a[i].en-a[i].st+1 )  //贪心 
				{
					dp[1][i]=dp[1][i-1];
					en[1][i]=en[1][i-1];
				}
				else if( dp[1][i-1]<a[i].en-a[i].st+1 )
				{
					dp[1][i]=a[i].en-a[i].st+1;
					en[1][i]=a[i].en;
				}	
				else
				{
					dp[1][i]=dp[1][i-1];
					en[1][i]=min(en[1][i-1],a[i].en);
				}
			//	cout<<i<<' '<<dp[1][i]<<endl;
			}
			for( i=2;i<=k;i++ )
			{
				for( j=i+1;j<=m;j++ )
				{
					ts=-1;
					for( r=i-1;r<j;r++ )
					{
						if( en[i-1][r]<a[j].st )
						{
							tmp=dp[i-1][r]+a[j].en-a[j].st+1;
						}
						else{
							tmp=dp[i-1][r]+a[j].en-en[i-1][r];
						}
						tmpe=a[j].en;
						if( tmp>ts )
						{
							ts=tmp;
							ten=tmpe;
						}
						if( tmp==ts )
						{
							ten=min(ten,tmpe);
						}
					} 
					if( dp[i][j-1]>ts )
					{
						dp[i][j]=dp[i][j-1];
						en[i][j]=en[i][j-1];
					}
					else if( dp[i][j-1]<ts )
					{
						dp[i][j]=ts;
						en[i][j]=ten;
					}
					else
					{
						dp[i][j]=ts;
						en[i][j]=min(en[i][j-1],ten);
					}
				}	
			}
			printf("%d\n",dp[k][m]);
		}
	}
	return 0;
	}

