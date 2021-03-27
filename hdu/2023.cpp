#include<iostream> 
#include<iomanip>
#include<memory.h>
using namespace std;
int main()
{
	int n,m,i,j;
	double score=0;
	int stu[55][6]; //n名学生 的m门课的成绩
	double xs[55]; //存储n名学生的平均成绩
	double kc[6];   //存储m门课程的平均成绩
	while(cin>>n>>m)
	{
		memset(stu,0,sizeof(stu));
		memset(xs,0.0,sizeof(xs));
		memset(kc,0.0,sizeof(kc));
			for(i=0;i<n;i++)
			{
				for(j=0;j<m;j++)
				{
					cin>>stu[i][j];
				}
			}
			for(i=0;i<n;i++)
			{
				for(j=0;j<m;j++)
				{
					xs[i]+=stu[i][j];
				}
				if(i!=n-1) 
					printf("%.2f ",xs[i]/m);
				else
					printf("%.2f",xs[i]/m);
			 }
			cout<<endl;
			
			 for(i=0;i<m;i++)
			 {
			 	for(j=0;j<n;j++)
			 	{
					kc[i]+=stu[j][i];
				}
			 	if(i!=m-1) 
					printf("%.2f ",kc[i]/n);
				else
					printf("%.2f",kc[i]/n);
			  }
			  cout<<endl;
		
			int cnt=0;
			for(i=0;i<n;i++)
			{
				int flag=1;
				for(j=0;j<m;j++)
				{
					if( stu[i][j]<kc[j]/n ) //
					{
						flag=0;
						break;
					}
				}
				if(flag)
				{
					cnt++;
				}
			  } 
			cout<<cnt<<endl<<endl;
	}
	return 0;
}
