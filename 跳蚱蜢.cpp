#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<set>
using namespace std;
// ������
struct node{
	string a;
	int p; // ��ʾ0���ĸ�λ�� 
	int step; //��ʾ�����״̬���˼��� 
};
set<node> state;
queue<node> qu;
int main(){
	int i;
	node st,te;
	st.a = "012345678";
	st.p = 0;
	st.step = 0;
	qu.push(st);
	state.insert(st);
	int cnt = 0;
	while( !qu.empty() ){
		node cur = qu.front();
		qu.pop();
		if( cur.a == "087654321" )
		{
			cout<<cur.step<<endl;
			break;
		}	
		string t;
		char temp;
		
		int p = cur.p;
		t = cur.a ;
		temp = t[p];
		t[p] = t[(p+1)%9];
		t[(p+1)%9] = temp;
		te.a = t,te.p = (p+1)%9;
		te.step = cur.step + 1;
		if( state.count(te)==0 ){  //���״̬û�г��ֹ� 
			qu.push(te);
			state.insert(te);
		}
		
		t = cur.a ;
		temp = t[p];
		t[p] = t[(p+2)%9];
		t[(p+2)%9] = temp;
		te.a = t,te.p = (p+2)%9;
		te.step = cur.step + 1;
		if( state.count(te)==0 ){  //���״̬û�г��ֹ� 
			qu.push(te);
			state.insert(te);
		}
		
		t = cur.a ;
		temp = t[p];
		t[p] = t[(p-1+9)%9];
		t[(p-1+9)%9] = temp;
		te.a = t,te.p = (p-1+9)%9;
		te.step = cur.step + 1;
		if( state.count(te)==0 ){  //���״̬û�г��ֹ� 
			qu.push(te);
			state.insert(te);
		}
		
		t = cur.a ;
		temp = t[p];
		t[p] = t[(p-2+9)%9];
		t[(p-2+9)%9] = temp;
		te.a = t,te.p = (p-2+9)%9;
		te.step = cur.step + 1;
		if( state.count(te)==0 ){  //���״̬û�г��ֹ� 
			qu.push(te);
			state.insert(te);
		}	
	}
	return 0;
}

