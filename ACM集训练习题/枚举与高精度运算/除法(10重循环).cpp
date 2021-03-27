#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<map>
#include<cmath>
using namespace std;
#define for(i) for(a[i]=0;a[i]<10;a[i]++)
int main() {
	int n,a[10],vis[10];
	while( cin>>n ){
		memset(vis,0,sizeof(vis));
		for(0)
		{
			vis[ a[0] ]=1;
			for(1 )
			{
				if( !vis[ a[1] ] )
				{
					vis[ a[1] ]=1;
					for(2){
						if( !vis[ a[2] ] )
						{
							vis[ a[2] ]=1;
							for(3){
								if( !vis[ a[3] ] )
								{
									vis[ a[3] ]=1;
									for(4)
									{
										if( !vis[ a[4] ] )
										{
											vis[ a[4] ]=1;
											for(5)
											{
												if( !vis[ a[5] ] )
												{
													vis[ a[5] ]=1;
													for(6)
													{
														if( !vis[ a[6] ] )
														{
															vis[ a[6] ]=1;
															for(7)
															{
																if( !vis[ a[7] ] )
																{
																	vis[ a[7] ]=1;
																	for(8)
																	{
																		if( !vis[ a[8] ] )
																		{
																			vis[ a[8] ]=1;
																			for(9)
																			{
																				if( !vis[ a[9] ] )
																				{
																					if( ( a[0]*pow(10,4)+a[1]*pow(10,3)+a[2]*pow(10,2)+a[3]*10+a[4] )/( a[5]*pow(10,4)+a[6]*pow(10,3)+a[7]*pow(10,2)+a[8]*10+a[9] )==n )
																						cout<<a[0]<<a[1]<<a[2]<<a[3]<<a[4]<<" / "<<a[5]<<a[6]<<a[7]<<a[8]<<a[9]<<" = "<<n<<endl; 
																				}
																			}
																			vis[ a[8] ]=0;
																		}
																	}
																	vis[ a[7] ]=0;
																}
															}
															vis[ a[6] ]=0;
														}
													}
													vis[ a[5] ]=0;
												}
												
											}
											vis[ a[4] ]=0;
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

