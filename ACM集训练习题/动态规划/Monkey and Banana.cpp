#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
//Monkey and Banana
#define N 200
struct node{
	long long x,y,h;
}block[N];
bool cmp(const node& n1,const node& n2){
	return n1.x>n2.x;  //从大到小排序 
} 
long long dp[N]; //dp[i]表示前i个箱子 以第i个箱子为最高的箱子 能搭的最大高度 
int main() {
	int i,j,k,n,x,y,z,cnt,Cnt=1;
	while( cin>>n,n ){
		cnt=0;
		for( i=0;i<n;i++ )
		{
			cin>>x>>y>>z;
			block[cnt].x=x,block[cnt].y=y,block[cnt].h=z;
			cnt++;
			block[cnt].x=x,block[cnt].y=z,block[cnt].h=y;
			cnt++;
			block[cnt].x=y,block[cnt].y=x,block[cnt].h=z;
			cnt++;
			block[cnt].x=y,block[cnt].y=z,block[cnt].h=x;
			cnt++;
			block[cnt].x=z,block[cnt].y=x,block[cnt].h=y;
			cnt++;
			block[cnt].x=z,block[cnt].y=y,block[cnt].h=x;
			cnt++;
		}
		printf("Case %d: maximum height = ",Cnt++);
	//	cout<<cnt<<endl;
		sort(block,block+cnt,cmp);
		dp[0]=block[0].h;
		long long m;
		for( i=1;i<cnt;i++ )
		{
			m=0;
			for( j=0;j<i;j++ )
			{
				if( block[j].y>block[i].y && block[j].x>block[i].x && dp[j]>m )
					m=dp[j];
			}
			dp[i]=block[i].h+m;
		//	cout<<dp[i]<<endl;
		}
		m=dp[0];
		for( i=1;i<cnt;i++ )
			if( dp[i]>m )
				m=dp[i];
		cout<<m<<endl;
	}
	return 0;
	}

