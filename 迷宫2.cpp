#include <bits/stdc++.h>
using namespace std;
char s[15][15];
int vis[15][15];

int sum=0;
bool judge(int x,int y)
{
    if(x>=0&&x<10&&y>=0&&y<10)
        return 0;
    return 1;
}
void dfs(int x,int y)
{
    if(judge(x,y))
    {
        sum++;
        return;
    }
    if(!vis[x][y])
    {
        vis[x][y]=1;
        if(s[x][y]=='U') dfs(x-1,y);
        else if(s[x][y]=='D') dfs(x+1,y);
        else if(s[x][y]=='R') dfs(x,y+1);
        else if(s[x][y]=='L') dfs(x,y-1);
    }
}

int main()
{
    for(int i=0; i<10; i++)
        scanf("%s",s[i]);
    for(int i=0; i<10; i++)
        for(int j=0; j<10; j++)
        {
            memset(vis,0,sizeof(vis));
            dfs(i,j);
        }
    printf("%d\n",sum);
    return 0;
}
