#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
#define N 100002
int soda[N];
int f[N][2];  //[0]表示向左给的状态,[1]表示向右给的状态 
int main() {
	int i,j,t,n;
	cin>>t;
	while( t-- ){
		cin>>n;
		memset(f,0,sizeof(f));
		long long ret=0;
		for( i=0;i<n;i++ )
		{
			scanf("%d",&soda[i]);
			ret+=soda[i];
		}
		if( n==1 )
		{
			cout<<"YES\n0\n";
			continue;
		}
		if( ret%n!=0 )
		{
			cout<<"NO\n";
			continue;
		}
		int ave=ret/n,flag=1;
		for( i=0;i<n;i++ )
		{
			soda[i]-=ave;
			if( abs( soda[i] )>=3 )
			{
				flag=0;
				break;
			}
		}
		if( !flag )
		{
			cout<<"NO\n";
			continue;
		}
		else{
			int x,y;
			for( i=0;i<2*n;i++ )
			{
				x=i%n;
				y=(i+1)%n;
				if( soda[x]>0 && soda[y]<=0 && !f[x][1] )  //第x个苏打没有进行过给下一个苏打糖果的操作
				{
					soda[x]--;
					soda[y]++;
				//	cout<<soda[x]<<" "<<soda[y]<<endl;
					if( !f[y][0] )
						f[x][1]=1;
					else
						f[x][1]=f[y][0]=0;  //将重复的步骤去掉 
				}
				else if( soda[x]<0 && soda[y]>=0 && !f[y][0] ) //第y个苏打没有进行过给上一个苏打糖果的操作
				{
					soda[x]++;
					soda[y]--;
				//	cout<<soda[x]<<" "<<soda[y]<<endl;
					if( !f[x][1] )
						f[y][0]=1;
					else
						f[x][1]=f[y][0]=0;
				}
			}
			flag=1;
			int cnt=0;
			for( i=0;i<n;i++ ) 
			{
				if( soda[i]!=0 )  //尽可能地进行了分配,但分配后不满足条件 
				{
					flag=0;
					break;
				}
				cnt+=f[i][0]+f[i][1];
			}
			if( !flag )
			{
				cout<<"NO\n";
				continue;
			}
			//满足条件地分配存在
			cout<<"YES\n";
			cout<<cnt<<endl;
			for( i=1;i<=n;i++ )
			{
				x=i-1;
				y=i+1;
				if( x==0 )
					x=n;
				if( y==n+1 )
					y=1;
				if( f[i-1][0] )
					cout<<i<<" "<<x<<endl;
				if( f[i-1][1] )
					cout<<i<<" "<<y<<endl;	
			} 
		}
	}
	return 0;
	}

