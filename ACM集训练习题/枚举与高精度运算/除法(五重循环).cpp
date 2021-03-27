#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<map>
#include<cmath>
using namespace std;
int main() {
	int n,a[10],vis[10],i;
	while( cin>>n ){
		memset(vis,0,sizeof(vis));
		for(a[0]=0;a[0]<10;a[0]++)
		{
			vis[ a[0] ]=1;
			for(a[1]=0;a[1]<10;a[1]++ )
			{
				if( !vis[ a[1] ] )
				{
					vis[ a[1] ]=1;
					for(a[2]=0;a[2]<10;a[2]++){
						if( !vis[ a[2] ] )
						{
							vis[ a[2] ]=1;
							for(a[3]=0;a[3]<10;a[3]++){
								if( !vis[ a[3] ] )
								{
									vis[ a[3] ]=1;
									for(a[4]=0;a[4]<10;a[4]++)
									{
										if( !vis[ a[4] ] )
										{
											vis[ a[4] ]=1;
											int tmp=( a[0]*pow(10,4)+a[1]*pow(10,3)+a[2]*pow(10,2)+a[3]*10+a[4] )*n;
											if( tmp>=100000 )
												continue;
										//	cout<<tmp<<endl;
											int t=tmp;
											for( i=0;i<5;i++ )
											{
												a[9-i]=t%10;
												vis[ a[9-i] ]=1;  //为后面判定做准备 
												t/=10;
											}
											int flag=1;
											for( i=0;i<10;i++ )
												if( !vis[i] )  //只要0-9有一个数字没有出现过就说明有相同的数字
												{
													flag=0;
												//	cout<<vis[i]<<" "<<i<<endl;
													break;
												}
											if( flag )  //满足条件 
											{
												cout<<a[5]<<a[6]<<a[7]<<a[8]<<a[9]<<" / "<<a[0]<<a[1]<<a[2]<<a[3]<<a[4]<<" = "<<n<<endl;	
											}
											memset(vis,0,sizeof(vis));
											for(i=0;i<4;i++ )
												vis[ a[i] ]=1;
										}
									}
									vis[ a[3] ]=0;
								}
							}
							vis[ a[2] ]=0;
						}	
					}
					vis[ a[1] ]=0;
				}  
			}
			vis[ a[0] ]=0;
		}
	}
	return 0;
	}

