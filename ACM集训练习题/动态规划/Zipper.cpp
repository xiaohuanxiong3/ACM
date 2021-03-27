#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<map>
using namespace std;
//dp[i][j]表示从a串中取了i个,b串中取了j个的情况能否构成不改变顺序地构成c[i+j] 
#define N 202 
char a[N],b[N],c[402];
int dp[N][N]; 
int main() {
	int i,j,t;
	cin>>t;
	int Cnt=1;
	while( t-- )
	{ 
		cin>>a+1>>b+1>>c+1;
		a[0]=b[0]=c[0]='@';
		printf("Data set %d: ",Cnt++);
		int l_a=strlen(a),l_b=strlen(b);
		for( i=0;i<l_a;i++ )
		{
			for( j=0;j<l_b;j++ )
			{
				if( !i && !j )
					dp[i][j]=1;
				else
				{
					if( !i )
						dp[i][j]=dp[i][j-1]&&(b[j]==c[i+j]);
					else if( !j )
						dp[i][j]=dp[i-1][j]&&(a[i]==c[i+j]);
					else
						dp[i][j]=( dp[i-1][j] && a[i]==c[i+j] )||( dp[i][j-1] && b[j]==c[i+j] );
				}
			//	cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
			}
		}
		if( dp[l_a-1][l_b-1] )
			cout<<"yes\n";
		else
			cout<<"no\n";
	}
	return 0;
	}

