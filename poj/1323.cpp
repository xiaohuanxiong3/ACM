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
		printf("Case %d: ",Cnt++);  //�����Ӧ�ð�,���˺ü�����(�´��ٴ��гͷ�-->ȥ�ܲ�!!!) 
		sort(card,card+n);
		int cnt=0,ret=0,index=n-1;  //cnt��¼��ǰ�ж������Ʊ������������ƶ��� 
		for( i=n*m;i>=card[0];i-- )  //û�ӵȺž�WR��...... 
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

