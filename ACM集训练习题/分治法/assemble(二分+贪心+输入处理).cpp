#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
#define N 1005
#define M 25
struct node{
	char type[M];
	int p,q;
}a[N];
bool cmp(const node& n1,const node& n2){
	if( strcmp( n1.type,n2.type )==0 ){ //������ͬ�������Ӵ�С����,������ͬ���۸��С�������� 
		if( n1.q==n2.q )
			return n1.p<n2.p;
		return n1.q>n2.q;
	}
	return strcmp(n1.type,n2.type)<0;
}
int k; //�洢���ж����ֲ�ͬ�����
int ol[N];  //�洢ÿ�����������
int i,j,n,b;
char arr[M];
int t;
struct Node{  //�洢ÿ������ļ۸������ 
	int p,q;
};
vector<Node> u[N];  //�洢ÿ����������ͺŵļ۸������ 
bool ok(int x){
	long long mon=0;
	for( i=0;i<k;i++ ){
		int mn=INT_MAX;
		for( j=0;j<u[i].size() ;j++)
		{
			if( u[i][j].q>=x ) mn=min(mn,u[i][j].p); 
			else	break;
		}
		mon+=mn;
		if( mon>b )
			return false;
	}
	return true;
}
int main() {
	cin>>t;
	while( t-- ){
		cin>>n>>b;
		for( i=0;i<n;i++ )
		{
			u[i].clear();
			scanf("%s%s%d%d",&a[i].type,&arr,&a[i].p,&a[i].q);
			ol[i]=a[i].q;
		}
		sort(ol,ol+n);
		sort(a,a+n,cmp);
		k=0;
		for( i=0;i+1<n;i++ ){
			while( i+1<n && strcmp(a[i].type,a[i+1].type)==0 ){
				Node tmp;
				tmp.p=a[i].p,tmp.q=a[i].q;
				u[k].push_back(tmp);
				i++;
			}
			Node tmp;
			tmp.p=a[i].p,tmp.q=a[i].q;
			u[k].push_back(tmp);
			k++;
		}
		int l=0,r=n-1;
		int mid=(l+r)>>1;
		while( l<=r ){
			if( ok( ol[mid] ) ) l=mid+1;
			else
				r=mid-1;
			mid=(l+r)>>1;
		}
		cout<<ol[mid]<<endl;
	}
	return 0;
	}

