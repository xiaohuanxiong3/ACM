#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
// 逆向递推 + 离散化 
#define N 502
#define INF 1<<30
int paper[N]; 
int vis[N];
int t,m,k,cnt;
bool fun(int mid)
{
	memset(vis,0,sizeof(vis));
	int i,tmp=0;
	cnt=0;
	for( i=m-1;i>=0;i-- )
	{
		if( tmp+paper[i]>mid )
		{
			vis[i+1]=1;  //表示第i本书前面要加'/'线 
			cnt++;
			tmp=paper[i];
		} 
		else
			tmp+=paper[i];
	} 
/*	for( i=0;i<m;i++ )
	{
		if( tmp+paper[i]>=mid )
		{
			vis[i]=1;  //表示第i本书前面要加'/'线 
			cnt++;
			tmp=paper[i];
		} 
		else
			tmp+=paper[i];
	} */
	if( cnt<=k-1 )
		return true;
	return false;
}
int main() {
	int i;
	scanf("%d",&t);
	long long ret;
	while( t-- )
	{
		scanf("%d%d",&m,&k);
	//	memset(vis,0,sizeof(vis));
		ret=0;
		int mi=0;
		for( i=0;i<m;i++ )
		{
			scanf("%d",&paper[i]);
			if( paper[i]>mi )
				mi=paper[i];
			ret+=paper[i];
		}
		int l=mi,r=ret,mid,flag;
		while( l<r )
		{
			flag=0;
			mid=( l+r )>>1;
		//	cout<<l<<' '<<mid<<' '<<r<<endl;
			if( fun(mid) )
			{
				r=mid;
				flag=1;
			}
			else
				l=mid+1;
		}
		fun(r);
	//	cout<<l<<' '<<mid<<' '<<r<<endl;
	//	cout<<cnt<<endl;
		if( cnt==k-1 )
		{
			for( i=0;i<m;i++ )
			{
				if( vis[i] )
					printf("/ ");
				printf("%d",paper[i]);
				if( i!=m-1 )
					printf(" ");
			}
			cout<<endl;
		}
		else
		{
			int t=k-1-cnt;
			for( i=0;i<m;i++ )
			{
				if( !vis[i] && i && t>0 )
				{
					t--;
					printf("/ ");
				}
				if( vis[i] )
					printf("/ ");
				printf("%d",paper[i]);
				if( i!=m-1 )
					printf(" ");
			}
			cout<<endl;
		}
	}
	return 0;
	}

