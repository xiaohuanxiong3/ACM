#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
#define N 1000002
#define INF 1<<30
// �о�˼���е�ѧ���� (-!-) 
// w[i][j]  ��ʾǰj��Ԫ�طֳ�i��õ������� ���ҵ�j��Ԫ���ڵ�i��
// b[i][j]  ��ʾǰj��Ԫ�طֳ�i��õ������� ��j��Ԫ�ؿ����ڵ�i��Ҳ���Բ��ڵ�i��
// ��֪����Ϊb[i][j] 
// w[i][j]=max(b[i-1][j-1],w[i][j-1])+a[j]
// b[i][j]=max(w[i][j],b[i][j-1])
int w[N],preb[N],nowb[N],a[N],sum[N]; 
int main() {
	int i,j,m;
	int n,k;
	while( scanf("%d%d",&k,&n)==2 ){
		memset(sum,0,sizeof(sum));
		memset(preb,0,sizeof(preb));
		for( i=1;i<=n;i++ )
		{
			scanf("%d",&a[i]);
		//	cout<<a[i]<<endl;
			sum[i]=sum[i-1]+a[i];
		}
		for( i=1;i<=k;i++ )
		{
			for( j=i;j<=n;j++ ){
				if( j==i )
					w[j]=nowb[j]=sum[i];
				else
				{
					w[j]=max(preb[j-1],w[j-1])+a[j];
					nowb[j]=max(w[j],nowb[j-1]);
				}	
			}
			for( j=i;j<=n;j++ )
				preb[j]=nowb[j];
		}
		printf("%d\n",nowb[n]);
	}
	return 0;
	}

