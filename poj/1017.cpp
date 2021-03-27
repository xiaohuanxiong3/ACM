#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;

int main() {
	int v1,v2,v3,v4,v5,v6;
	int ans,i;
	while( scanf("%d%d%d%d%d%d",&v1,&v2,&v3,&v4,&v5,&v6) && (v1+v2+v3+v4+v5+v6) )
	{
		ans=0;
		ans+=v6;
		ans+=v5;
		if( v1>=v5*11 )
			v1-=v5*11;
		else
			v1=0;
		ans+=v4;
		for( i=0;i<v4;i++ )
		{
			if( v2>=5 )
				v2-=5;
			else
			{
				if( v1>=20-4*v2 )
				{
					v1-=20-4*v2;
					v2=0;
				}
				else
				{
					v1=0;
					v2=0;
					break;
				}
			}
		}
		ans+=v3/4; //有四个3*3的先放一起 
		v3=v3%4;
		if( v3 )
		{
			ans++;
			switch( v3 )
			{
				case 1:
					if( v2>=5 )
					{
						v2-=5;
						if( v1>=7 )
							v1-=7;
						else
							v1=0;
					}
					else
					{
						if( v1>=27-4*v2 )
						{
							v1-=27-4*v2;
							v2=0;
						}
						else
						{
							v1=0;
							v2=0;
						}
					}
					break;
				case 2:
					if( v2>=3 )
					{
						v2-=3;
						if( v1>=6 )
							v1-=6;
						else
							v1=0;
					}
					else 
					{
						if( v1>=18-4*v2 )
						{
							v1-=18-4*v2;
							v2=0;
						}
						else
						{
							v1=0;
							v2=0;
						}
					}
					break;
				case 3:
					if( v2>=1 )
					{
						v2-=1;
						if( v1>=5 )
							v1-=5;
						else
							v1=0;
					}
					else
					{
						if( v1>=9 )
						{
							v1-=9;
						}
						else
						{
							v1=0;
						}
					}
			}
		}
		ans+=v2/9;  //能拼成1个6*6的优先拼好
		v2=v2%9;
		if( v2 )
		{
			ans++;
			if( v1>=36-v2*4 )
				v1-=36-v2*4;
			else
				v1=0;
		}
		ans+=v1/36;  //用剩下的1*1能拼 
		v1=v1%36;
		if( v1 )
			ans++; 
		cout<<ans<<endl;
	} 
	return 0;
	}

