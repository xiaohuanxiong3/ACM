#include<iostream>
using namespace std;
int main()
{
	int a,b,i,ans1=0,ans2=0,temp;
	while(cin>>a>>b)
	{
		if(a>=b)  //确保a<=b 
		{
			temp=a;
			a=b;
			b=temp;
		}
		for(i=a;i<=b;i++)
		{
			if(i%2==0)
				ans1+=i*i; //偶数的平方和
				 
			else
				ans2+=i*i*i; //奇数的立方和 
		}
		cout<<ans1<<" "<<ans2<<endl;
		ans1=ans2=0;
	}
} 
