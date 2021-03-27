#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<map>
using namespace std;
#define N 200002
struct node{
	int father;
	int rank;
	int num;
	node():rank(1),num(1){
	}
}uf[N];
int Find(int x){
	int k=x;
	while( k!=uf[k].father ){
		k=uf[k].father;
	}
	while( x!=uf[x].father ){
		int t=uf[x].father;
		uf[x].father=k;
		x=t;
	}
	return k;
}
void Union(int x,int y){
	x = Find(x);
	y = Find(y);
	if( x!=y ){
		int tmp=uf[x].num+uf[y].num;
		if( uf[x].rank<uf[y].rank ){
			uf[x].father=y;
			uf[y].num=tmp;
		}
		else{
			uf[y].father=x;
			uf[x].num=tmp;
			if( uf[x].rank==uf[y].rank ){
				uf[x].rank++;
			}
		} 
	}  
} 
int main() {
	int m,n,i,j,t;
	char arr1[22],arr2[22];
	map<string,int> s;
	while( cin>>t )
	{
		while( t-- ){
			s.clear();
				cin>>n;
				for( i=1;i<=2*n;i++ )
				{
					uf[i].father=i;
					uf[i].num=1;
				}
				int cnt=1;
				for( i=0;i<n;i++ )
				{
					scanf("%s%s",&arr1,&arr2);
					if( s[arr1]==0 )
					{
						s[arr1]=cnt;
						cnt++;
					//	cout<<arr1<<" "<<cnt-1<<endl;
					}
					if( s[arr2]==0 )
					{
						s[arr2]=cnt;
						cnt++;
					//	cout<<arr2<<" "<<cnt-1<<endl;
					}
					Union(s[arr1],s[arr2]);
				//	cout<<s[arr1]<<" "<<s[arr2]<<endl;
					printf("%d\n",uf[ Find( s[arr1] ) ].num);
				}
			}
	}
	return 0;
	}

