#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<queue>
using namespace std;
//�����������̰���ҳ��Ӹ����������������m��ǽ���Ƴ���m��ǽʹ�ø����ܴ����� 
struct Node{
	int cnt;
	int index;
	bool operator<(const Node& n) const{
		return cnt<n.cnt;
	}
}tmp[101];
int wall[102][102]; 
int f[102][102];
int main() {
	int t,sc,sr,ec,er,i,j,k,n,row,col;
	scanf("%d",&t);
	while( t-- )
	{
		memset(wall,0,sizeof(wall));
		memset(f,0,sizeof(f));
		scanf("%d%d",&n,&k);
		col=-1;
		row=-1;
		for( i=0;i<n;i++ ) 
		{
			scanf("%d%d%d%d",&sc,&sr,&ec,&er);
			if( sc>ec )
			{
				int tmp=sc;
				sc=ec;
				ec=tmp;
			}
			f[sr][ec]=1;  //��ʾ���ש��һ��ǽ�����һ��ש 
			for( j=sc;j<=ec;j++ )
			{
				wall[ sr ][j]=1;
			}
			col=max(col,ec);
			row=max(row,sr);
		}
		int ans=0,ret;
		for( i=0;i<=col;i++ )
		{
			ret=0;
			for( j=0;j<=row;j++ )
				if( wall[j][i] )
					ret++;
			if( ret>k )  //����ǽҪ��ret-k��ǽ 
			{
				for( j=0;j<=row;j++ )
				{
					tmp[j].cnt=0;
					tmp[j].index=j;
				}
				priority_queue<Node> p;
				for( j=0;j<=row;j++ )
				{
					if( wall[j][i] )
					{
						int i1=i;  //�����˱������һ��ǽ�Ľ�β����� 
						while( wall[j][i1] && !f[j][i1] && i1<=col )
						{
							i1++;
							tmp[j].cnt++;
						}
						if( f[j][i1] )
						{
							tmp[j].cnt++;
						}
						p.push(tmp[j]);
					}
				}
				for( j=0;j<ret-k;j++ )  //��ret-k�� 
				{
					Node t=p.top();
					int i1=i,t_row=t.index;
					while( wall[t_row][i1] && !f[t_row][i1] && i1<=col )
					{
						wall[t_row][i1]=0;
						i1++;
					}
					if( f[t_row][i1] )
					{
						wall[t_row][i1]=0;
					}
					p.pop();
				}
				ans+=ret-k;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
	}

