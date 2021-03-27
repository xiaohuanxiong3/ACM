#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
int partition(int a[],int left,int right){
	int x=a[left],i=left,j=right+1;
	while( 1 )
	{
		while( a[++i]<x );
		while( a[--j]>x );
		if( i>j )
			break;
		swap(a[i],a[j]);
	}
	a[left]=a[j];
	a[j]=x; 
	return j;
}

void qSort(int a[],int left,int right){
	int m;
	if( left==right )
		return;
	m=partition(a,left,right);
	qSort(a,left,m-1);
	qSort(a,m+1,right);
} 
int main() {
	int a[]={5,4,3,6,1},i;
	qSort(a,0,4);
	for( i=0;i<5;i++ )
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
	}

