#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
#define N 150005
struct node{
	int father;
	int rank;
	node():rank(1){
	}
}uf[N];
int Find(int x){  //加上路径压缩 
	int k=x;
	while( k!=uf[k].father )
	{
		k=uf[k].father;
	}
	while( x!=uf[x].father )
	{
		int t=uf[x].father;
		uf[x].father=k;
		x=t;
	}
	return k;
} 
void Union(int x,int y){
	x=Find(x);
	y=Find(y);
	if( x!=y ){
		if( uf[x].rank<uf[y].rank )
		{
			uf[x].father=y;
		}
		else
		{
			uf[y].father=x;
			if( uf[y].rank==uf[x].rank )
				uf[x].rank++;
		}
	}
}

int main() {
		int n,k,i,d,x,y;
		cin>>n>>k;
		int ans=0;
		for( i=1;i<=3*n;i++ )
			uf[i].father=i;
		for( i=0;i<k;i++ )
		{
			scanf("%d%d%d",&d,&x,&y);
			if( x>n || y>n )
				ans++;
			else
			{
				if( d==1 )
				{
					if(  ( Find(x+n)==Find(y) || Find(x+2*n)==Find(y) )  )//若前面推出x和y不同类则x和y同类就是假话 
					{
						ans++;
					//	cout<<d<<" "<<x<<" "<<y<<" 同类错"<<endl;
					}
					else
					{
						Union(x,y);  //合并同类 
						Union(x+n,y+n);  // x和y是同类,吃x和吃y的也是同类 
						Union(x+2*n,y+2*n);  //被吃x和被y吃的也是同类 
					}
				}
			    if( d==2 && x!=y )
				{
					if( (  Find(y)==Find(x+n) ) ||  Find(x)==Find(y)  )//前面已经推出y吃x,那么x吃y就是假话 
					{
						ans++;
					//	cout<<d<<" "<<x<<" "<<y<<" x吃y错"<<endl;
					}
					else
					{
						Union(x,y+n);
						Union(x+2*n,y);
						Union(x+n,y+2*n);
					}
				} 
				if(d==2 && x==y )
					ans++;
			}
		}
		cout<<ans<<endl;
	
	return 0;
	}

