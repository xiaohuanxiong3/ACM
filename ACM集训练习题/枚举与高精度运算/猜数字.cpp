#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<vector> 
#include<iomanip>
#include<cmath>
#include<map>
using namespace std;
map<int,int> an;
map<int,int> bn;
int A[5];
int B[5];
bool fun(int a,int b,int x,int y)
{
	an.clear();
	bn.clear();
	int i,j;
	int cnt1=0,cnt2=0;  //cnt1记录猜对了几个数字,cnt2记录有几个数字在正确的位置 
	an[a%10]++;
	A[4]=a%10;
	a/=10;
	A[3]=a%10;
	an[a%10]++;
	a/=10;
	A[2]=a%10;
	an[a%10]++;
	a/=10;
	A[1]=a%10;
	an[a%10]++;
	
	
	B[4]=b%10;
	bn[b%10]++;
	b/=10;
	B[3]=b%10;
	bn[b%10]++;
	b/=10;
	B[2]=b%10;
	bn[b%10]++;
	b/=10;
	B[1]=b%10;
	bn[b%10]++;
/*	for( i=1;i<=4;i++ )
	{
		if( an[ B[i] ]>0 )  //a中有b的第i个数字 
		{
			if( A[i]==B[i] )
			{
				cnt2++;
				cnt1++;
				an[ B[i] ]--;
				bn[ B[i] ]--;
			}		
		}
	}
	for( i=1;i<=4;i++ )
	{
		if( an[ B[i] ]>0 )  //a中有b的第i个数字 
		{
			cnt1+=min( an[ B[i] ],bn[ B[i] ] );
		}
	} */
	for( i=1;i<=4;i++ )
		if( A[i]==B[i] )
			cnt2++;
	for( i=1;i<=4;i++ )
		for( j=1;j<=4;j++ )
		{
			if( B[i]==A[j] )
			{
				cnt1++;
				A[j]=-1;
				break;
			}
		}
	if( cnt1==x && cnt2==y )
		return true;
	else
		return false;
} 
int main(){
	int n,u,d,i,j;
	int arr[102][3];  
	while( cin>>n,n!=0 )
	{
		for( i=0;i<n;i++ )
			scanf("%d%d%d",&arr[i][0],&arr[i][1],&arr[i][2]);
		int ans;
		int ret=0;
		for( i=1000;i<=9999;i++ )
		{
			int cnt=0;
			for( j=0;j<n;j++ )
				if( fun(i,arr[j][0],arr[j][1],arr[j][2]) )
				{
				//	if( arr[j][0]==8585 )
				//		cout<<i<<"  "<<arr[j][0]<<" "<<arr[j][1]<<" "<<arr[j][2]<<endl;
					cnt++;
				}
			if( cnt>=n )
			{
				ans=i;
				ret++;
			} 
		}
		if( ret!=1 )
			cout<<"Not sure\n";
		else
			cout<<ans<<endl;
	}     
   return 0;
}


