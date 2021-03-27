#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
#define N 100005
struct Point{
	double x,y;
};
Point a[N],c[N];  //c[N]为辅助数组 
double  dis(Point a,Point b){
	double x=a.x-b.x,y=a.y-b.y;
	return sqrt(x*x+y*y);
}
bool cmp(const Point &a,const Point &b){  //按x坐标排序 
	if( a.x==b.x )
		return a.y<b.y;
	return a.x<b.x;
}
bool cmp_y(const Point &a,const Point &b){  //按y坐标排序 
	return a.y<b.y;
}
double divide_conquer(Point a[],Point c[],int st,int en)
{
	if( st==en )  //一个点 
		return 0;
	if( st + 1 == en )  //两个点 
		return dis(a[st],a[en]);
	if( st + 2 == en )  //三个点 
	{
		double x=dis(a[st],a[st+1]);
		double y=dis(a[st],a[en]);
		double z=dis(a[st+1],a[en]);
		return min(x,min(y,z));
	}
	int mid = (st+en)/2;
	double d1 = divide_conquer(a,c,st,mid);
	double d2 = divide_conquer(a,c,mid+1,en);
	double d=min(d1,d2);
	int i,j,k=0;
	for( i=st;i<=mid;i++ )
		if( a[i].x + d>=a[mid].x ) c[k++]=a[i];
	for(;i<=en;i++ )
		if( a[i].x - d<=a[mid].x ) c[k++]=a[i];
	sort(c,c+k,cmp_y);
	for( i=0;i<k;i++ )
	{
		for( j=i+1;j<k && j<=i+7 ;j++ )  //按照规律一般只需要做七次比较 
		{
			if( dis(c[i],c[j])<d )
				d=dis(c[i],c[j]);	
		}  
	}
	return d;
}
int main() {
	int i,n;
	while( cin>>n,n ){
		for( i=0;i<n;i++ )
			scanf("%lf%lf",&a[i].x,&a[i].y);
		sort(a,a+n,cmp);
		double ans=divide_conquer(a,c,0,n-1);
		printf("%.2lf\n",ans/2);
	}
	return 0;
	}

