#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<vector> 
#include<iomanip>
#include<cmath>
using namespace std;
#define size 31269 
long long a[size];  //��¼ ��i�� �������еĳ���
long long s[size];  //��¼ ǰi�� �������еĳ���
int ans[145238];  //��¼ ��31268���ÿһλ 
//(int)log10( (double)i )+1 ��ʾ����iռ����λ 
void play_table()
{
		int i;
		a[1]=s[1]=1;
		for( i=2;i<size;i++ )
		{
			a[i]=a[i-1]+(int)log10( (double)i )+1;
			s[i]=s[i-1]+a[i];
		}
}  //���ȷ������Ҫ��31268�������ʹ���������дﵽ�е�2147483647λ 
int main(){
	int i,j;
	play_table();
	int cnt=1;
	for( i=1;i<size;i++ )
	{
		int bit[6];
		int k=i,num=0;
		while( 1 )
		{
			if( k>=10 )
			{
				bit[num++]=k%10;
				k/=10;
			}
			else{
				bit[num++]=k;
				break;
			}
		} 
		for( j=num-1;j>=0;j-- )
			ans[ cnt++ ]=bit[j];
	}
	int t,n;
	cin>>t;
	while( t-- )
	{
		cin>>n;
		i=1;
		while( s[i]<n )  //Ѱ�ҵ�n��λ�ڵ�i�� 
			i++;
		int pos=n-s[i-1];  //ȷ����n���ڵ�i������±�
		cout<<ans[ pos ]<<endl; 
	}
   return 0;
}


