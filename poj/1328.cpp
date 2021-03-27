#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<map>
using namespace std; 
#define N 1e-6
//规定两个double型<和>均以 1e-6为标准 
struct node{
	double st;
	double en; 
}radar[1002];
bool cmp(const node &n1,const node &n2){
		if( n1.st==n2.st )
			return n1.en<n2.en;
		return n1.st<n2.st; 
}
int s[1002];
int main() {
	int n,d;
	int i,j,k;
	int x,y; 
	int cnt=1;
	while( cin>>n>>d,n+d ){
		int flag=1;
		for( i=0;i<n;i++ ){
			scanf("%d%d",&x,&y);
			if( y>d )
				flag=0;
			radar[i].st=x - sqrt( pow(d,2)-pow(y,2) );
			radar[i].en=x + sqrt( pow(d,2)-pow(y,2) );
			s[i]=0;
		}	
		if( !flag ){
			cout<<"Case "<<cnt<<": "<<"-1\n";
			cnt++;
			continue;
		}
		else{
			int ret=0;
			sort(radar,radar+n,cmp);
			for( i=0;i<n;i++ )
			{
				if( s[i]==0 )
				{
					double temp=radar[i].en;
					j=i+1;
					while( j<n && radar[j].st<=temp )
					{
						s[j]=1;
						if( radar[j].en<temp )
							temp=radar[j].en;
						j++;
					} 
					ret++;
				}
			}
			printf("Case %d: %d\n",cnt,ret);
			cnt++;
		}
	} 
	return 0;
	}

