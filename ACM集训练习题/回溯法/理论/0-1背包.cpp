#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;

#define N 15
//   !!!!!!!!!!!!!!!!   ע��˳�ƹ����иı��ֵ���ƹ�����Ҫ�ָ� 
struct node{
	int weight;
	int value;
}goods[N]; 

int n,w;  //��Ʒ�����ͱ�������
int x[N];   //x[i]=0��ʾ��ȡ��i����Ʒ,�����ʾȡ��i����Ʒ 
int cur=0;  //��ǰ�����Ѿ����õ���Ʒ���� 
int ans = 0,ans1 = 0;
int rest=0;  //û�п��ǵ���Ʒ��ֵ�ܺ� 
int ret[N];
void dfs(int dep){  //dep:��i����Ʒ 
	int i;
	if( dep>=n ){  //��0��ʼ 
	/*	for( i=0;i<n;i++ )
			if( x[i] )
				cout<<i+1<<" ";
		cout<<endl; */
		if( ans1>ans )
		{
			ans=ans1;
			for(i=0;i<N;i++)
				ret[i]=x[i];
		}
		return;
	}
	 
	//�����dep����Ʒ 
		if( cur + goods[dep].weight<=w )
		{
			x[dep] = 1;
			ans1 += goods[dep].value; 
			cur += goods[dep].weight;
			dfs(dep+1);
			cur -= goods[dep].weight;
			ans1 -= goods[dep].value;
		}
	//������
	rest-=goods[dep].value; 
	if( ans1 + rest > ans ){
		x[dep]=0;
		dfs(dep+1);
	}
	rest += goods[dep].value; 
} 
int main() {
	int i;
	cin>>n>>w;
	for( i=0;i<n;i++ )
	{
		cin>>goods[i].weight>>goods[i].value;
		rest+=goods[i].value;
	}
	dfs(0);
	for( i=0;i<N;i++ )
		if( ret[i] )
			cout<<i+1<<" ";
	cout<<endl;
	return 0;
	}

