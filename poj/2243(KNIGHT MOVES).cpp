#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<queue>
using namespace std;
struct point{
	int x,y;
	int step;
}; 
queue<point> q;
int dir[8][2]={{-1,-2},{1,-2},{-2,-1},{2,-1},{-2,1},{2,1},{-1,2},{1,2}};
int main(){
	int i,flag,cnt;
	point tmp,now;
	string st,en;
	while(cin>>st>>en)
	{
		while( !q.empty() )
			q.pop();
		tmp.x = st[0]-'a'+1;
		tmp.y = st[1]-'0';
		tmp.step=0;
		q.push(tmp);
		cnt=0;
		while( !q.empty() ){
			now = q.front();
			q.pop();
			if( now.x==en[0]-'a'+1 && now.y==en[1]-'0' ) //走到目标点 
			{
				cout<<"To get from "<<st<<" to "<<en<<" takes "<<now.step<<" knight moves."<<endl;	
				break;
			}	
			for( i=0;i<8;i++ )
			{
				tmp.x = now.x + dir[i][0];
				tmp.y = now.y + dir[i][1];
				if( tmp.x<=0 || tmp.x>8 || tmp.y<=0 || tmp.y>8 )
					continue;
				tmp.step = now.step+1;
				q.push(tmp);
			}
		}
	}
	return 0;
}

