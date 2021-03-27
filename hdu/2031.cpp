#include<iostream> 
#include<cmath>
using namespace std;

int main()
{
	int n,m,i,j,temp;
	while( cin>>n>>m )
	{
		int x,flagn=1;
		if(n<0)
		{
			n=-n;
			flagn=0;
		}
			for(i=0;i<=32;i++)  //n转换成m进制后有x+1位 
			{
				if( n< pow(m,i) )
				{
					x=i-1;
					break;
				}
			}
				int *arr=new int[x+1];  //分别存储 m进制下 x+1位的数 
				int cnt=0,flag=x+1;
				for(i=0;i<flag;i++)
					arr[i]=0;
				while(x>=0)  //存储 
				{
					temp=pow(m,x);
					arr[cnt]=n/temp;
					cnt++;
					n=n%temp;
					x--;
				}
				if(!flagn)  //是负数前面要加负号 
					cout<<'-';
				for(i=0;i<flag;i++)
				{
					if(arr[i]==10)
						cout<<'A';
					else if(arr[i]==11)
						cout<<"B";
					else if(arr[i]==12)
						cout<<"C";
					else if(arr[i]==13)
				 		cout<<"D";
					else if(arr[i]==14)
						cout<<"E";
					else if(arr[i]==15)
						cout<<"F";
					else
						cout<<arr[i];
				}
				cout<<endl;
		}
/*		switch(m)
		{
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
			case 8:
			case 9:
				{
					for(i=0;i<=32;i++)  //n转换成m进制后有x+1位 
					{
						if( n< pow(m,i) )
						{
							x=i-1;
							break;
						}
					}
					int *arr=new int[x+1];  //分别存储 m进制下 x+1位的数 
					int cnt=0,flag=x+1;
					for(i=0;i<flag;i++)
						arr[i]=0;
					while(x>=0)  //存储 
					{
						temp=pow(m,x);
						arr[cnt]=n/temp;
						cnt++;
						n=n%temp;
						x--;
					}
					if(!flagn)  //是负数前面要加负号 
						cout<<'-';
					for(i=0;i<flag;i++)
						cout<<arr[i];
					cout<<endl;
				}
			break;
			case 11:
				{
					for(i=0;i<=32;i++)  //n转换成m进制后有x+1位 
					{
						if( n< pow(m,i) )
						{
							x=i-1;
							break;
						}
					}
					int *arr=new int[x+1];  //分别存储 m进制下 x+1位的数 
					int cnt=0;flag=x+1;
					for(i=0;i<flag;i++)
						arr[i]=0;
					while(x>=0)  //存储 
					{
						temp=pow(m,x);
						arr[cnt]=n/temp;
						cnt++;
						n=n%temp;
						x--;
					}
					if(!flagn)  //是负数前面要加负号 
						cout<<'-';
					for(i=0;i<flag;i++)
					{
						if(arr[i]==11)
							cout<<'A';
						else
							cout<<arr[i];
					}
					cout<<endl;
				}
				break;
			case 12:
				{
					for(i=0;i<=32;i++)  //n转换成m进制后有x+1位 
					{
						if( n< pow(m,i) )
						{
							x=i-1;
							break;
						}
					}
					int *arr=new int[x+1];  //分别存储 m进制下 x+1位的数 
					int cnt=0;flag=x+1;
					for(i=0;i<flag;i++)
						arr[i]=0;
					while(x>=0)  //存储 
					{
						temp=pow(m,x);
						arr[cnt]=n/temp;
						cnt++;
						n=n%temp;
						x--;
					}
					if(!flagn)  //是负数前面要加负号 
						cout<<'-';
					for(i=0;i<flag;i++)
					{
						if(arr[i]==11)
							cout<<'A';
						else if(arr[i]==12)
							cout<<"B";
						else
							cout<<arr[i];
					}
					cout<<endl;
				}
				break;
			case 13:
				{
					for(i=0;i<=32;i++)  //n转换成m进制后有x+1位 
					{
						if( n< pow(m,i) )
						{
							x=i-1;
							break;
						}
					}
					int *arr=new int[x+1];  //分别存储 m进制下 x+1位的数 
					int cnt=0;flag=x+1;
					for(i=0;i<flag;i++)
						arr[i]=0;
					while(x>=0)  //存储 
					{
						temp=pow(m,x);
						arr[cnt]=n/temp;
						cnt++;
						n=n%temp;
						x--;
					}
					if(!flagn)  //是负数前面要加负号 
						cout<<'-';
					for(i=0;i<flag;i++)
					{
						if(arr[i]==11)
							cout<<'A';
						else if(arr[i]==12)
							cout<<"B";
						else if(arr[i]==13)
							cout<<"C";
						else
							cout<<arr[i];
					}
					cout<<endl;
				}
				break;
			case 14:
				{
					for(i=0;i<=32;i++)  //n转换成m进制后有x+1位 
					{
						if( n< pow(m,i) )
						{
							x=i-1;
							break;
						}
					}
					int *arr=new int[x+1];  //分别存储 m进制下 x+1位的数 
					int cnt=0;flag=x+1;
					for(i=0;i<flag;i++)
						arr[i]=0;
					while(x>=0)  //存储 
					{
						temp=pow(m,x);
						arr[cnt]=n/temp;
						cnt++;
						n=n%temp;
						x--;
					}
					if(!flagn)  //是负数前面要加负号 
						cout<<'-';
					for(i=0;i<flag;i++)
					{
						if(arr[i]==11)
							cout<<'A';
						else if(arr[i]==12)
							cout<<"B";
						else if(arr[i]==13)
							cout<<"C";
						else if(arr[i]==14)
							cout<<"D";
						else
							cout<<arr[i];
					}
					cout<<endl;
				}
				break;
			case 15:
				{
					for(i=0;i<=32;i++)  //n转换成m进制后有x+1位 
					{
						if( n< pow(m,i) )
						{
							x=i-1;
							break;
						}
					}
					int *arr=new int[x+1];  //分别存储 m进制下 x+1位的数 
					int cnt=0;flag=x+1;
					for(i=0;i<flag;i++)
						arr[i]=0;
					while(x>=0)  //存储 
					{
						temp=pow(m,x);
						arr[cnt]=n/temp;
						cnt++;
						n=n%temp;
						x--;
					}
					if(!flagn)  //是负数前面要加负号 
						cout<<'-';
					for(i=0;i<flag;i++)
					{
						if(arr[i]==11)
							cout<<'A';
						else if(arr[i]==12)
							cout<<"B";
						else if(arr[i]==13)
							cout<<"C";
						else if(arr[i]==14)
							cout<<"D";
						else if(arr[i]==15)
							cout<<"E";
						else
							cout<<arr[i];
					}
					cout<<endl;	
				}
				break;
			case 16:
				{
					for(i=0;i<=32;i++)  //n转换成m进制后有x+1位 
					{
						if( n< pow(m,i) )
						{
							x=i-1;
							break;
						}
					}
					int *arr=new int[x+1];  //分别存储 m进制下 x+1位的数 
					int cnt=0;flag=x+1;
					for(i=0;i<flag;i++)
						arr[i]=0;
					while(x>=0)  //存储 
					{
						temp=pow(m,x);
						arr[cnt]=n/temp;
						cnt++;
						n=n%temp;
						x--;
					}
					if(!flagn)  //是负数前面要加负号 
						cout<<'-';
					for(i=0;i<flag;i++)
					{
						if(arr[i]==11)
							cout<<'A';
						else if(arr[i]==12)
							cout<<"B";
						else if(arr[i]==13)
							cout<<"C";
						else if(arr[i]==14)
							cout<<"D";
						else if(arr[i]==15)
							cout<<"E";
						else if(arr[i]==16)
							cout<<"F";
						else
							cout<<arr[i];
					}
					cout<<endl;	
				}
			break;	
		} */
		 
	
	return 0;
}
