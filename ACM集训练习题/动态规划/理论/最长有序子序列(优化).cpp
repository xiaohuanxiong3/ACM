#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
#define INF 0x3f3f3f
#define N 1002
int a[N],dp[N],c[N]; 
int main() {
	int i,j,k,m,n,cnt_c;
	cin>>n;
	for( i=0;i<n;i++ )
		scanf("%d",&a[i]);
	c[0]=-INF;
	cnt_c=1;
	for( i=0;i<n;i++ ){
		//��c���ҵ�һ����a[i]���Ԫ�ص��±� 
		k = upper_bound(c,c+cnt_c,a[i])-c;
		dp[i] = k;
		c[k]=a[i];
		if( k>=cnt_c )
			cnt_c++;
	}
	cout<<cnt_c-1<<endl;
	for( i=1;i<cnt_c;i++ )   //���(����!) 
	{
		cout<<c[i]<<' ';
	}
	return 0;
	}

