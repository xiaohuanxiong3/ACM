#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<vector> 
#include<iomanip>
#include<cmath>
using namespace std;
#define size 31269 
long long a[size];  //记录 第i组 数字序列的长度
long long s[size];  //记录 前i组 数字序列的长度
int ans[145238];  //记录 第31268组的每一位 
//(int)log10( (double)i )+1 表示数字i占多少位 
void play_table()
{
		int i;
		a[1]=s[1]=1;
		for( i=2;i<size;i++ )
		{
			a[i]=a[i-1]+(int)log10( (double)i )+1;
			s[i]=s[i-1]+a[i];
		}
}  //打表确定至少要有31268个组才能使得数字序列达到有第2147483647位 
int main(){
	int i,j;
	play_table();
	int cnt=1;
	for( i=1;i<size;i++ )
	{
		int bit[6];
		int k=i,num=0;
		while( 1 )
		{
			if( k>=10 )
			{
				bit[num++]=k%10;
				k/=10;
			}
			else{
				bit[num++]=k;
				break;
			}
		} 
		for( j=num-1;j>=0;j-- )
			ans[ cnt++ ]=bit[j];
	}
	int t,n;
	cin>>t;
	while( t-- )
	{
		cin>>n;
		i=1;
		while( s[i]<n )  //寻找第n个位于第i组 
			i++;
		int pos=n-s[i-1];  //确定第n个在第i组里的下标
		cout<<ans[ pos ]<<endl; 
	}
   return 0;
}


