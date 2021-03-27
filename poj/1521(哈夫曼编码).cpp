#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<queue>
using namespace std;
#define N 50000
char s[N];
int counts[N];
int main() {
	int ans,i;
	while( 1 )
	{
		cin.getline(s,10000);
		if( !strcmp(s,"END") )
			break;
		memset(counts,0,sizeof(counts));
		priority_queue<int,vector<int>,greater<int> > pq;  //优先队列里greater<int>规定从小到大排序,less<int>则是从大到小 
		int len=strlen(s);
		for( i=0;i<len;i++ )
		{
		//	cout<<int(s[i])<<endl;
			counts[int(s[i])]++;
		}
		for( i=0;i<200;i++ )  //ASCII码字符最多有200个
		{
			if( counts[i] )  //(十进制)ASCII码字符出现过 
			{
			//	cout<<count[i]<<endl;
				pq.push(counts[i]);
			}
		} 
		ans=0;
		while( pq.size()>1 )
		{
			int a=pq.top();
		//	cout<<a<<endl;
			pq.pop();
			int b=pq.top();
		//	cout<<a<<endl;
			pq.pop();
			ans+=a+b;
			pq.push(a+b);
		}
		if( !ans )  //s中只有一种字符
			ans=len;
		printf("%d %d %.1f\n",8*len,ans,8*len*1.0/ans); 
	}
	return 0;
}

