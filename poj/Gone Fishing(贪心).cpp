#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<queue> 
using namespace std;
#define N 30
struct node{
	long long f;
	int index;
	bool operator<( const node& n) const{
		return f<n.f;
	}
}f[N];
long long d[N],t[N],ans[N],ans1[N];
int main() {
	int n,i,h,j,cnt;
	long long ret,m;
	while( scanf("%d",&n) && n )
	{
		scanf("%d",&h);
		for( i=1;i<=n;i++ )
		{
			scanf("%ld",&f[i].f);
			f[i].f=f[i].f*100+n+1-i; 
		//	cout<<f[i].f<<endl;
			f[i].index=i;
		}
		for( i=1;i<=n;i++ )
		{
			scanf("%ld",&d[i]);
			d[i]*=100;
		}
		for( i=1;i<=n-1;i++ )
			scanf("%ld",&t[i]);
		m=-1;
		for( i=1;i<=n;i++ )  //在第i个湖泊结束钓鱼！ (学习思想 @ ) 
		{
			memset(ans1,0,sizeof(ans1));
			ret=0;
			priority_queue<node> num;
			int h1=h*12;  //钓鱼的次数
			for( j=1;j<i;j++ )
				h1-=t[j];   
			for( j=1;j<=i;j++ )
				num.push(f[j]);
			for( j=1;j<=h1;j++ )  //
			{
				node tmp=num.top();
			//	cout<<tmp.f<<' '<<tmp.index<<endl;
				if( tmp.f>100 )
				{
					ans1[tmp.index]++; //在能钓到鱼最多的湖里钓鱼  维护在这个湖里钓鱼的次数
					ret+=tmp.f/100; 
					if( tmp.f>=d[tmp.index] )
					{
						tmp.f-=d[tmp.index];
					}
					else
						tmp.f=tmp.index;
					num.pop();
					num.push(tmp);
				//	cout<<tmp.f<<' '<<tmp.index<<endl;
				}
				else //所有湖里都没有鱼了 
				{
					ans1[1]+=h1-j+1;
					break;
				} 
			}
			if( ret>m )
			{
				m=ret;
				for( j=1;j<=i;j++ )
					ans[j]=ans1[j];
				for( j=i+1;j<=n;j++ )
					ans[j]=0;
			}
		}
		for( i=1;i<=n;i++ )
		{
			printf("%d",ans[i]*5);
			if( i!=n )
				printf(", ");
		}
		printf("\nNumber of fish expected: %d\n\n",m);
	}
	return 0;
	}

