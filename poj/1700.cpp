#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
#define N 102
int a[N];
//注意将(--当前--)速度最慢的两人送到对岸的最优方法是利用 速度最快的分别将两人送到对岸 和 利用速度第一快和第二快将
//两人送到对岸的方案中选最优的 
int main() {
	int t,i,n;
	int ans;
//	cout<<(4&1)<<endl;
	scanf("%d",&t);
//	cout<<t<<endl;
	while( t-- )
	{
		scanf("%d",&n);
	//	cout<<n<<endl;
		for( i=0;i<n;i++ )
		{
			scanf("%d",&a[i]);
		//	cout<<a[i]<<endl;
		}
		sort(a,a+n);
		ans=0;
		if( n<=2 )
		{
			printf("%d\n",a[n-1]);
		} 
		else
		{
			int x=a[0],y=a[1];
			if( n&1 )  //奇数个人
			{
				int t=n-1;
				while( t>2 )
				{
					ans+=min(x+2*y+a[t],2*x+a[t]+a[t-1]);
					t-=2;
				}
				ans+=x+y+a[2]; 
			} 
			else //偶数个人 
			{
				int t=n-1;
				while( t>1 )
				{
					ans+=min(x+2*y+a[t],2*x+a[t]+a[t-1]);
					t-=2;
				}
				ans+=y;
			}
			printf("%d\n",ans);
		}
	} 
	return 0;
	}

