#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
//最大连续字段和
int a[100002];

/* int maxSeg(int a[],int left,int right){
	int mid=(left+right)>>1,ret,max1,max2;
	if( left==right )
	{
		return a[left];
	}
	max1 = maxSeg(a,left,mid);
	max2 = maxSeg(a,mid+1,right);
	ret = max(max1,max2);
	int temp1,temp2,ret1,ret2,i;
	temp1=ret1=a[mid];
	for( i=mid-1;i>=0;i-- ){
		temp1+=a[i];
		if( temp1>ret1 )
		{
			ret1=temp1;
		}
	} 
	temp2 = ret2 = a[mid+1];
	for( i=mid+2;i<left;i++ ){
		temp2+=a[i];
		if( temp2>ret2 )
		{
			ret2=temp2;
		}
	}
	return max(ret,ret1+ret2);
}  */
int Kadane(int a[],int length,int &left,int &right)
{
	int i;
	int cur_left,cur_right,cur_max,max;
	cur_left=0,cur_right=0,cur_max=0,max=-1<<30;
	for( i=0;i<length;i++ ){
		cur_max+=a[i];
		if( cur_max >= 0 ){
			cur_right=i;
			if( cur_max>max )
			{
				max=cur_max;
				left=cur_left;
				right=i;
			}
		}
		else{
			if( cur_max>max )
			{
				max=cur_max;
				left=right=i;
			}
			cur_max=0;
			cur_left=cur_right=i+1;	
		}
	}
	return max;
}
int main() {
	int i,n,t;
	int cnt=1;
	cin>>t;
	while( t-- )
	{
		cin>>n;
		for( i=0;i<n;i++ )
		{
			scanf("%d",&a[i]);
		}	
		int left,right;
		int ans=Kadane(a,n,left,right);
		printf("Case %d:\n",cnt++);
		cout<<ans<<" "<<left+1<<" "<<right+1<<endl;
		if( t>0 )
			cout<<endl;
	}
	return 0;
	}

