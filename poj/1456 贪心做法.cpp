#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
//1456 贪心做法 
#define N 10002
struct node{
	int val;
	int date;
	bool operator<(const node& n) const{
		return val>n.val;
	}
}goods[N];
int vis[N];
int main() {
	int i,n,j;
	while( scanf("%d",&n)!=EOF )
	{
		int da=-1;  //找到最大期限 
		for( i=0;i<n;i++ )
		{
			scanf("%d%d",&goods[i].val,&goods[i].date);
			if( goods[i].date>da )
				da=goods[i].date;
		}
		for( i=1;i<=da;i++ )
			vis[i]=0;
		sort(goods,goods+n);  //按价格从大到小排序
		int sum=0;
		for( i=0;i<n;i++ )
		{
			if( !vis[ goods[i].date ] )
			{
				vis[ goods[i].date ]=1;
				sum+=goods[i].val;
			}
			else
			{
				for( j=goods[i].date-1;j>=1;j-- )
				{
					if( !vis[j] )
					{
						vis[j]=1;
						sum+=goods[i].val;
						break;
					}
				}
			}
		}
		cout<<sum<<endl; 
	}
	return 0;
	}

