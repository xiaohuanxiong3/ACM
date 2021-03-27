#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<stack>
#include<vector>
using namespace std;
// µÚËÄÌâ 
#define N 100002
stack<int> stk;
struct node{
	int x,y;
//	bool operator<(const node& n) const{
//		return x<n.x;
//	}
	node(int x1,int y1){
		x = x1;
		y = y1; 
	}
	node(){
	}
};
bool cmp(const node& n1,const node& n2){
	return n1.x<n2.x;
}
vector<node> ret;
char a[N];
int main(){
	int i;
	node no;
	scanf("%s",&a);
	for( i=0;i<strlen(a);i++ ){
		if( a[i] == '(' )
			stk.push(i+1);
		else 
		{
			int tx = stk.top();
			no.x=tx,no.y=i+1;
			ret.push_back(no);
			stk.pop();	
		}
	}
	sort(ret.begin(),ret.end(),cmp);
	for( i=0;i<ret.size();i++ )
	{
		printf("%d %d\n",ret[i].x,ret[i].y);
	}
	return 0;
}

