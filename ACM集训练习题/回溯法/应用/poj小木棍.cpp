#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
#define N 65
int a[N],vis[N];
int n,len,num,rest;
int dfs(int k,int cur_len,int st){ // k��ʾ��ǰƴ��k��ľ�� 
	if( k>num-1 ){
		return 1;
	}
	int i,pre=0;
	for( i=st;i<n;i++ ){
		if( vis[i] || a[i]==pre ) // pre��ʾ��Ϊpre��ľ���Ѿ����ǹ� 
			continue;
		pre=0;
		if( cur_len+a[i]==len ){
			vis[i]=1;
			if( dfs(k+1,0,0) )
				return 1;
			vis[i]=0;
			return 0;   //������ӻᳬʱ 
		}else if( cur_len+a[i]<len ){
			vis[i]=1;
			if( dfs(k,cur_len+a[i],i+1) )
				return 1;
			vis[i]=0;
			if( cur_len==0 )  //��һ��ľͷ����ƴ��Ŀ�곤�Ⱥ���Ͳ���Ҫ������(��ǿ��֦)  ----����Ҳ�ᳬʱ...... 
				return 0; 
		}
		pre=a[i];  //ǿ��֦(������һ�����ɹ�,���������ͬ��Ҳ��Ҫ����) 
	}
	return 0;
}
int main() {
	int i,s;
	while( scanf("%d",&n) && n )
	{
		s=0;
		for( i=0;i<n;i++ ){
			scanf("%d",&a[i]);
			s+=a[i];  
		}
		sort(a,a+n,greater<int>());
		for( i=a[0];i<=s;i++ ){
			if( s%i==0 ){  //���i������Ϊ���� 
				len=i;   //Сľ���ĳ��� 
				num=s/i;  //Сľ���ĸ��� 
				memset(vis,0,sizeof(vis));
				if( dfs(1,0,0) )
				{
					printf("%d\n",i);
					break;
				}
			}
		}
	}
	return 0;
}

