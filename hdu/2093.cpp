#include <iostream>
#include<cstring>   
#include<sstream> 
#include<iomanip>
using namespace std;  
int main()  
{  
    int n,i,j,m;
    int temp;
    string name[1000];  //��¼ѧ������ 
    string score[1000][12]; //��¼ѧ������ 
	int position[1000][2];  //��¼ѧ��AC������ʱ��� 
    int ans;
    string str1="(",str2=")";
    stringstream ss;
	while( cin>>n>>m )
	{
		int cnt=0;
		string::size_type show;
		while( cin>>name[cnt] )  //���������Ͷ�Ӧ�ķ���  ����EOFʱ����ѭ�� 
		{
			position[cnt][0]=position[cnt][1]=0;
			for(i=0;i<n;i++)
			{
				cin>>score[cnt][i];
				if( score[cnt][i][0]!='-' && score[cnt][i]!="0" )
				{
					position[cnt][0]++;
					show=score[cnt][i].find(str1);
					if( show!=string::npos )
					{
						ss<<score[cnt][i].substr(0,show);
						ss>>temp;
						position[cnt][1]+=temp;
						ss.clear();
						ss<<score[cnt][i].substr( show+1,score[cnt][i].find(str2)-show-1 );
						ss>>temp;
						position[cnt][1]+=temp*m;
						ss.clear();	
					}
					else
					{
						ss<<score[cnt][i];
						ss>>temp;
						
						position[cnt][1]+=temp;
						ss.clear();
					}
				}
			} 
			cnt++;
		}
		int flag;
		for(i=0;i<cnt-1;i++)
		{
			flag=i;  // 
			for(j=i+1;j<cnt;j++)
			{
				if( position[j][0]>position[flag][0] )
					flag=j;
				else if( position[j][0]==position[flag][0] )  //AC��Ŀ��ͬ 
				{
					if( position[j][1]<position[flag][1] )
						flag=j;
					else if( position[j][1]==position[flag][1] ) //ʱ�����ͬ 
					{
						if( name[j]<name[flag] )
							flag=j;
					}
				}
			}
			if( flag!=i )  //���� 
			{
				str1=name[flag];
				name[flag]=name[i];
				name[i]=str1; //�������� 
				temp=position[i][0];
				position[i][0]=position[flag][0];
				position[flag][0]=temp; //����AC��Ŀ
				temp=position[i][1];
				position[i][1]=position[flag][1];
				position[flag][1]=temp; //����ʱ��� 
			}
		}
		for( i=0;i<cnt;i++ )
		{
			cout<<setw(10)<<left<<name[i]<<" "<<setw(2)<<right<<position[i][0]<<" "<<setw(4)<<right<<position[i][1]<<endl;
		}
	}
	return 0;
}
