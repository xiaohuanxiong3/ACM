#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
bool isY(char a)
{
	if( a=='a' || a=='e' || a=='i' || a=='o' || a=='u' )
		return true;
	else
		return false;
}
int main() {
	int i,j,k,t;
	char arr[25];
	int l=0; 
	while( cin>>arr )
	{
		if( strcmp( arr,"end")==0 )
			break;
		else
		{
			int cnt=0; //记录元音的个数
			int flag1=1,flag2=1;
			int le=strlen(arr); 
			if( le==1 )
			{
				if( isY( arr[0] ) )
					cout<<"<"<<arr<<"> is acceptable.\n";
				else
					cout<<"<"<<arr<<"> is not acceptable.\n";
			}
			else if( le==2 )
			{
				if( ( !isY( arr[0] ) && !isY( arr[1] ) ) || ( arr[0]==arr[1] && arr[0]!='e' && arr[1]!='o' ) )
					cout<<"<"<<arr<<"> is not acceptable.\n";
				else
					cout<<"<"<<arr<<"> is acceptable.\n";
			}
			else
			{
				for( j=0;j<le-2;j++ )
				{
					if(  (isY(arr[j]) && isY(arr[j+1]) && isY(arr[j+2]) ) || ( !isY(arr[j]) && !isY(arr[j+1]) && !isY(arr[j+2])) )  //出现三个连续的字母
					{
						flag1=0;
						break; 
					}
				}
				for( j=1;j<=le-1;j++ )
				{
					if( ( arr[j]==arr[j-1] && arr[j]!='e' && arr[j]!='o' ) ) 
						{
							flag2=0;
						}
				}
				for( j=0;j<le;j++ )
				{
					if( isY(arr[j]) )
						cnt++;
				}
				if( flag1==1 && flag2==1 && cnt>=1 )
					cout<<"<"<<arr<<"> is acceptable.\n";
				else
					cout<<"<"<<arr<<"> is not acceptable.\n";
			}
		}
	}
	return 0;
	}

