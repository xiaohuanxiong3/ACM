#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<vector> 
#include<iomanip>
#include<cmath>
#include<map>
using namespace std;
map<char,int> num;  //统计要搜集的某个字母最多出现的个数
int score[40002]={0};  //统计分数
map<char,int> ::iterator it;
int main(){
	int i;
	map<char,int> le;
	le['a']=2;
	le['b']=5;
	le['c']=4;
	le['d']=4;
	le['e']=1;
	le['f']=6,le['g']=5,le['h']=5,le['i']=1,le['j']=7,le['k']=6,le['z']=7;
	le['l']=3,le['m']=5,le['n']=2,le['o']=3,le['p']=5,le['q']=7,le['r']=2;
	le['s']=1,le['t']=2,le['u']=4,le['v']=6,le['w']=6,le['x']=7,le['y']=5; 
	char a[7];
	string str;
	cin>>str;  //输入要搜集的字母 
	for( i=0;i<str.length();i++ )
	{
		a[i]=str[i];
		num[ a[i] ]++;
	}
	int cnt=0;
	char x;
	int m=-10000;
	map<char,int> s;
	while( scanf("%c",&x),x!='.' )
	{
		s.clear();
		s[x]++;
		while( scanf("%c",&x),x!='\n' )
			s[x]++;
		for( it=s.begin();it!=s.end();it++ )
		{
			if( num[ it->first ]>0 )  //说明这个这个字母是要收集的字母 
				score[ cnt ]+=le[ it->first ]*min( num[ it->first ],s[ it->first ] );
		}
		if( score[cnt]>m )
			m=score[cnt];
		cnt++;
	}
	cout<<m<<endl;
   return 0;
}


