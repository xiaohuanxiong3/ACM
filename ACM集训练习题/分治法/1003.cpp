#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std; 
int a[502],b[502],c[502];
long long s[250002];
// 注意测试数据有负数,且a[i]+b[j]的结果要用long long 存 
int main() {
	int i,j,k,l,m,n,N;
	int cnt=1;
	while( cin>>l>>m>>n ){
		for(i=0;i<l;i++){
			scanf("%d",&a[i]);
		} 
		for( i=0;i<m;i++ ){
			scanf("%d",&b[i]);
		}
		for( i=0;i<n;i++){
			scanf("%d",&c[i]);
		}
		int cs=0;
		for( i=0;i<l;i++ )
			for( j=0;j<m;j++ )
				s[cs++]=a[i]+b[j];
		sort(c,c+n);
		sort(s,s+cs);  
		int t;
		cout<<"Case "<<cnt++<<":\n";
		cin>>t;
		while( t-- )
		{
			cin>>N;
			int flag=0;
		//	cout<<x<<endl;
			for( i=0;i<n;i++ )
			{
					int index=lower_bound(s,s+cs,N-c[i])-s;
					if( index!=cs && s[index]==N-c[i] )
					{
					//	cout<<index<<" "<<s[index]<<endl;					
						flag=1;
						break;
					}
			}
			if( flag )
				cout<<"YES\n";
			else
				cout<<"NO\n";
		}
	}
	return 0;
	}

