#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
#define N 66
int a[N];
int vis[N];
int num,n;
bool dfs(int curlength,int dep,int index,int length){ //dep��ʾ��ƴ�õ�ľ����Ŀ��curlength��ʾ��һ��ľ����ƴ�õĳ��� 
	if( dep>=num-1 )
		return true;  
	int i;
	for( i=index;i<n;i++ ){
		if( !vis[i] ){
			if( curlength + a[i] < length )
			{
				vis[i] = 1;
				if( dfs(curlength+a[i],dep,i+1,length) )
				{
					return true;
				}	
				vis[i] = 0;
				if( curlength == 0 )
					return false;
			}
			else if( curlength + a[i] == length ){
				vis[i] = 1;
				if( dfs(0,dep+1,0,length) )
				{
					return true;
				}	
				vis[i] = 0;
			}
			while( a[i] == a[i+1] )
				i++;
		}
	}
	return false;	
} 
int main(){
	int i,sum;
	while( cin>>n,n ){
		sum = 0;
		for( i=0;i<n;i++ )
		{
			cin>>a[i];
			sum += a[i];	
		}
		sort(a,a+n,greater<int>());
		for( i=a[0];i<=sum;i++ ) // �������ܵ����г��� 
		{
			if( sum%i == 0 ){
				memset(vis,0,sizeof(vis));
				num = sum/i;
			//	vis[0] = 1; 
				if( dfs(0,0,0,i) ) //��ƴ��
				{
					cout<<i<<endl;
					break;
				}
			}
		}	
	}
	return 0;
}

