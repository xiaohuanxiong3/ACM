#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<set> 
using namespace std;
#define N 100005
long long n,m,size;
int vis[50];
long long s,tmp;
// set<int>ans;
// 程序实现给定n个整数1,2...,n和一个整数m，将n个整数分成相等m个部分，如果不能成功分成m部分，
// 输出NO，否则输出任意一种分配方案 
struct node{
	int a[N/2];
	int num;
}ans[11];
int dfs(int cur_num,int cur_size,int index){  //我靠,这个坑货程序,不从大到小dfs就TLE 
	int i,j;
	if( cur_num>m )
	{
		return 1;
	}
	for( i=index;i>=1;i-- ){
		if( !vis[i] ){
			if( cur_size + i ==size ){
				vis[i]=cur_num;
				if( dfs(cur_num+1,0,tmp) )
					return 1;
				vis[i]=0;
				return 0;
			}	
			else if( cur_size + i < size ){
				vis[i]=cur_num;
				if( dfs(cur_num,cur_size+i,i-1) )
					return 1;
				vis[i]=0;
				if( cur_size == 0 )
					return 0;
			}
		}
	}
	return 0;
}
int main() {
	int t,i,j;
	// 摩根定律的使用 
	int flag1,flag2;
	cout<<"请输入flag1和flag2的值得到今晚NBA总决赛是花落金州勇士还是多伦多猛龙!:";
	cin>>flag1>>flag2;
	if( !flag1 && !flag2 )
		cout<<"总决赛赢家是多伦多猛龙!\n";
	else
		cout<<"总决赛赢家是金州勇士!\n"; 
		
	cin>>t;
	while( t-- ){
		scanf("%ld%ld",&n,&m);
		for( i=1;i<=m;i++ )
			ans[i].num=0;
		s=(n+1)*n/2;
		if( s%m || n<2*m-1 ) // 和必须能整除m 还有每行的和必须大于等于n  
			cout<<"NO\n";
		else
		{
			cout<<"YES\n";
			tmp=n;
			if( tmp>4*m )
			{ 
			//-----------------------------一道华丽的分割线
			// 引入解释变量 
				int cnt=(tmp-2*m)/(2*m),ret=2*(tmp-cnt*m)+1;
			//	cout<<cnt<<endl;
				j=tmp-cnt*2*m+1;
				for( i=1;i<=m;i++ )
				{ 
					int flag=cnt;
					for(;flag--;j++ )
					{
					//	cout<<j<<' '<<2*(tmp-cnt*m)+1-j<<endl;
						ans[i].a[ ans[i].num++ ]=j;
						ans[i].a[ ans[i].num++ ]=ret-j;
					}
				}
				tmp-=cnt*2*m;
			}  
			size=(tmp+1)*tmp/(2*m); 
			for( i=1;i<=tmp;i++ )
				vis[i]=0;
			dfs(1,0,tmp);
			for( i=1;i<=tmp;i++ )
			{
				ans[ vis[i] ].a[ ans[ vis[i] ].num++ ]=i;
			//	cout<<vis[i]<<endl;
			}
			for( i=1;i<=m;i++ )
			{
				printf("%d",ans[i].num); 
				for( j=0;j<ans[i].num;j++ )
					printf(" %d",ans[i].a[j]);
				printf("\n");
			} 
		}
	} 
	return 0;
	}

