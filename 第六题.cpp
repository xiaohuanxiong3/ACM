#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
// µÚÁùÌâ 
#define N 100002
#define INF 1<<30
int b[N]; 
int vis[N];
vector<int> ret;
int main(){
	int n,m,i;
	scanf("%d %d",&n,&m);
	for( i=0;i<m;i++ )
	{
		scanf(" %d",&b[i]);
		vis[ b[i] ] = 1;	
	}	
	b[m] = INF;
	int l,r;
	l = 0,r = b[0];
	int cnt = 1;
	for( i=1;i<=n+1;i++ ){
		if( vis[i] )
			continue;
		else
		{
			if( i>l && i<r )
			{
				ret.push_back(i);
			//	cout<<i<<endl;
				l = i;
			}	
			else
			{
				while( i>r && i<=n+1 ){
					ret.push_back(r);
					l = r;
					r = b[cnt++];
				}
				ret.push_back(i);
				l = i;
			}
		}
	}
	for( i=0;i<ret.size()-1;i++ )
		printf("%d\n",ret[i]);
	return 0;
}

