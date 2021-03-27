#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
//最大连续字段和
struct node{
	int l,r;
	int value;
}a[100002]; 
 node maxSeg(node a[],int left,int right){
	int mid=(left+right)>>1;
	if( left==right )
	{
		a[left].l=a[left].r=left;
		return a[left];
	}
	node max1 = maxSeg(a,left,mid);
	node max2 = maxSeg(a,mid+1,right);
	node ret;
	if( max1.value >= max2.value )
		ret=max1;
	else
		ret=max2;
	node retx;
	int temp1,temp2,ret1,ret2,i;
	temp1=ret1=a[mid].value;
	retx.l=mid;
	for( i=mid-1;i>=left;i-- ){
		temp1+=a[i].value;
		if( temp1 >= ret1 )
		{
			ret1=temp1;
			retx.l=i;
		}
	} 
	temp2 = ret2 = a[mid+1].value;
	retx.r=mid+1;
	for( i=mid+2;i<=right;i++ ){
		temp2+=a[i].value;
		if( temp2>=ret2 )
		{
			ret2=temp2;
			retx.r=i;
		}
	}
	retx.value=ret1+ret2;
	if( ret.value>retx.value )
		return ret;
	else //if( ret.value<retx.value)
		return retx;
//	else{
//		return (ret.l<retx.l)?ret:retx;
//	}
}  /* 
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
} */ 
int main() {
	int i,n,t;
	int cnt=1;
	cin>>t;
	while( t-- )
	{
		cin>>n;
		for( i=0;i<n;i++ )
		{
			scanf("%d",&a[i].value);
		}	
		node ans=maxSeg(a,0,n-1);
		printf("Case %d:\n",cnt++);
		cout<<ans.value<<" "<<ans.l+1<<" "<<ans.r+1<<endl;
		if( t>0 )
			cout<<endl;
	}
	return 0;
	}

