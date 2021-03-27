#include <iostream>
#include<cstring> 
using namespace std;
bool fun(string *arr,int length,string a)
{
	int i;
	for( i=0;i<length;i++)
		if( arr[i]==a )
			return false;
	return true;
}
int main()  
{  
    int i,j,k;
    string n;
    int p;
    string ans[5000];
    string arr[5000];
    int cnt;
    while( getline(cin,n) && n!="#" )
    {
    	n[ n.length() ]=' ';
    	cnt=0;
    	p=0;
    	for( i=1;i<=n.length();i++ )
    	{
    		if( n[i]!=' ' && n[i-1]==' ' )
    			p=i;
    		if( n[i]==' ' && n[i-1]!=' ' )
    		{
    			arr[cnt++]=n.substr(p,i-p);
			}
		}
		int length=0;
		for( i=0;i<cnt;i++ )
		{
			if( fun(ans,length,arr[i]) )
			{
				ans[length]=arr[i];
				length++;
			}
		}
		cout<<length<<endl;
    } 
    
	return 0;
}
