#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
#define N 55
int card[N]; 
int main() {
	int n,m,i,Cnt=1;
	while( scanf("%d%d",&m,&n) && (m+n) )
	{
		for( i=0;i<n;i++ )
			scanf("%d",&card[i]);
		printf("Case %d: ",Cnt++);  //这个不应该啊,错了好几回了(下次再错有惩罚-->去跑步!!!) 
		sort(card,card+n);
		int cnt=0,ret=0,index=n-1;  //cnt记录当前有多少张牌比你手上所有牌都大 
		for( i=n*m;i>=card[0];i-- )  //没加等号就WR了...... 
		{
			if( i==card[index] )
			{
				if( !cnt )
					ret++;
				else
					cnt--;
				index--;
			}
			else
				cnt++;
		}
		cout<<ret<<endl;
	}
	return 0;
	}

