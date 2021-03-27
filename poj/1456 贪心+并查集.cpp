#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
//1456 ̰������ 
#define N 10002
struct node{
	int val;
	int date;
	bool operator<(const node& n) const{
		return val>n.val;
	}
}goods[N];
int F[N];
int Find(int x){
	int t=x;
	while( t!=F[t] )
	{
		t=F[t];
	}
	return t;
}
int main() {
	int i,n,j;
	while( scanf("%d",&n)!=EOF )
	{
		int da=-1;  //�ҵ�������� 
		for( i=0;i<n;i++ )
		{
			scanf("%d%d",&goods[i].val,&goods[i].date);
			if( goods[i].date>da )
				da=goods[i].date;
		}
		for( i=1;i<=da;i++ )
			F[i]=i;
		sort(goods,goods+n);  //���۸�Ӵ�С����
		int sum=0;
		for( i=0;i<n;i++ )
		{
			int t=Find(goods[i].date);
			if( t>0 )
			{
				F[t]=t-1;  //��������Ѿ���������Ʒ��,���ҽ����ڵ�ĸ��ڵ���Ϊ���ڵ��ǰһ�� 
				sum+=goods[i].val;
			}
		}
		cout<<sum<<endl; 
	}
	return 0;
	}

