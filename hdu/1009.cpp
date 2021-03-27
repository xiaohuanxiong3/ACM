#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
#define N 10002
struct node{
	int Javabean;
	int catfood;
}rooms[N];
 int n,m;
 bool cmp(const node &n1,const node &n2)
 {
 	return( n1.Javabean*n2.catfood )>( n2.Javabean*n1.catfood ) ;  //¾¡Á¿±ÜÃâ³ý·¨,·ÀÖ¹¾«¶ÈËðÊ§ 
 }
int main() {
	int i;
	while( cin>>m>>n &&! (m==-1 && n==-1 ) )
	{
		double ret=0;
		for( i=0;i<n;i++ )
			cin>>rooms[i].Javabean>>rooms[i].catfood;
		sort(rooms,rooms+n,cmp);
		for( i=0;i<n;i++ )
		{
			if( m>=rooms[i].catfood )
			{
				ret+=rooms[i].Javabean;
				m-=rooms[i].catfood;
			}
			else break;
		}
		if( i<n )
			ret += 1.0*rooms[i].Javabean*m/rooms[i].catfood;
		printf("%.3lf\n",ret);
	}
	return 0;
	}

