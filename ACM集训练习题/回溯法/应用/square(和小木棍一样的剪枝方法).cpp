#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
#define N 22
int m,n,num,le; 
int a[N];
int vis[N];
int dfs(int cur_num,int cur_length,int index){
	if( cur_num>=4 )
	{
		return 1;
	}
	int i;
	for( i=index;i<n;i++ ){
		if( !vis[i] )
		{
			if( a[i] + cur_length== le )
			{
				vis[i]=1;
				if( dfs(cur_num+1,0,0) )
					return 1;
				vis[i]=0;  //ƴ���ɹ� 
				return 0;  // ???????????????????????????
			}
			if( a[i] + cur_length < le ){
				vis[i]=1;
				if( dfs(cur_num,a[i]+cur_length,i+1) )
					return 1;
				vis[i]=0;
				if( cur_length==0 )  //��һ��ƴ���ú���Ҳ����Ҫ���� 
					return 0;
				while( a[i+1]==a[i] && i+1<n )  //a[i]ƴ���ɹ�,�����a[i]��ͬ�ľͲ���Ҫ������ 
					i++;
			}
		}
	}
	return 0;
}
int main() 
{
	int i,j,t,s;
	cin>>t;
	while( t-- )
	{
		cin>>n;
		s=0;
		for( i=0;i<n;i++ ){
			scanf("%d",&a[i]);
			vis[i]=0;
			s+=a[i];
		}
		sort(a,a+n,greater<int>()); //���Ӵ�С���� 
		if( s%4==0 ){  //�п���ƴ���ĸ��ȳ���ľ�� 
			num=4;
			le=s/4;
			if( dfs(1,0,0) )
				printf("yes\n");
			else
				printf("no\n");
		}
		else
			printf("no\n");
	}
	return 0;
}

