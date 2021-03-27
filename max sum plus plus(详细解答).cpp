#include<iostream>
#include<cstdio>
using namespace std;
const int MAX=1000001;
int dp[2][MAX];
int w[MAX];
int sum[MAX];//不做不知道，一做吓一跳，原来在主函数里开个sum[MAX]，是不行的，因为MAX是在太大！
 
/*这是我的老师贴出的提示！现在才理解到内涵！
VC定义数组时请注意大小!定义时,局部数组大小<=1MB,全局数组<=2GB,定义时如果超过这个限制将会出现如"segment error"之类的错误.以下的程序可以帮助你证明这一点.
以下程序数组如果再大点，运行出错，说明局部变量分配内存<=1MB
#include<stdio.h>
int main()
{
int a[1024*1024/4-4000];
int i;
for(i=0;i<1024*1024/4-4000;i++)
{
a[i]=i;
printf("%d\n",a[i]);
}
return 0;
} 
以下程序数组如果再大点，运行出错，说明全局变量分配内存<=2GB
#include<stdio.h>
int a[1024*1024*470];
int main()
{
long int i;
for(i=0;i<1024*1024*470;i++)
{
a[i]=i;
printf("%d\n",a[i]);
}
return 0;
}
内存的三种分配方式：静态存储区分配，栈上分配，堆上分配。 全局数组是在静态存储区分配,而局部数组是在栈上分配,所以大小受到的限制不一样.
*/
 
int cmax(int a,int b)//求最大值
{
	return a>b?a:b;
}
 
int main()
{
	int i,k;
	int m,n;
	
	while(scanf("%d%d",&m,&n)>0)
	{
		sum[0]=0;
		for(i=1;i<=n;i++)
		{
			cin>>k;
			sum[i]=sum[i-1]+k;//sum[i]里存的是前i个元素的和
			dp[0][i]=0;//从前i个元素中取0段，最大值为0
		}
//我们假设a[i]中存放该序列第i个值，w[i][k]表示前k个数分为i段，第k个数必须选这种情况下取得的最大值
//b[i][k]表示在前k个数中取i段这种情况下取得的最大值
 
//w[i][k]：前k个数分为i段，第k个数必须选；1：第k个数单独为1段；2：第k个数与前面的数连一块。w[i][k]=max(b[i-1][k-1],w[i][k-1])+a[k];
//b[i][k]：前k个数分为i段，第k个数可选可不选；1：选第k个数，2：不选第k个数。b[i][k]=max(b[i][k-1],w[i][k])
//w[i][k]=max(b[i-1][k-1],w[i][k-1])+a[k];
//b[i][k]=max(b[i][k-1],w[i][k])；
//w[i][k],b[i][i]容易求得，所以由b[i-1][k-1]->w[i][k]->b[i][k],只要知道b[0][k]，全部都能成功运行！
 
//当从k个元素中取j段，可以分为两种情况，即第k个元素可以取，也可以不取，取，那么a[k]要么是单独为一段b[i-1][k-1]+a[k];
//要么是第k个数与前面的数连一块，即w[i][k-1]+a[k]，故w[i][k]=max(b[i-1][k-1],w[i][k-1])+a[k];
 
//要么不取 即b[i][k]=b[i][k-1];
//综合起来，b[i][k]=max(b[i][k-1],w[i][k]);
       int t=1;
       for(i=1;i<=m;i++)//i表示在取i段,自然i<=m;
	   {
		   
		   for(k=i;k<=n;k++)//为什么k从i开始？dp[i][k](k<i)是没有意义的！
		   {
			   if(i==k)
			   dp[t][k]=w[k]=sum[k];//从k个数中取k段的最大值是前k个数的和
			   else
			   {
				   w[k]=cmax(dp[1-t][k-1],w[k-1])+sum[k]-sum[k-1];//w[k]表示k个元素取i段，a[k]必须取时的最大值
		//w[i][k]=max(b[i-1][k-1],w[i][k-1])+a[k];
				   dp[t][k]=cmax(dp[t][k-1],w[k]);//dp[t][k]表示在a[k]可取可不取这两种情况下取得的最大值
				   //自然，dp[t][k]记录的就是在前k个元素中取i段时取得的最大值！
			   }
		   }
		   t=1-t;//t在1,0之间交替变换
  //为什么要交替呢？这是为了节省空间
  //仔细观察递归式
  //w[i][k]=max(b[i-1][k-1],w[i][k-1])+a[k];
  //b[i][k]=max(b[i][k-1],w[i][k])；
  //我们发现，对于取i段，w[i][j]只与b[i-1][k-1]和w[i][k-1]有关，与之前的那一些项没有关系
  //因此我们数组可以开小一点，用更新来覆盖掉前面的值！
	   }
	   cout<<dp[m%2][n]<<endl;//奇次轮还是偶次轮
	}
	system("pause");
	return 0;
}


