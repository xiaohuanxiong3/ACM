#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<queue>
#include<math.h>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<string>
#include<algorithm>
#include<iostream>
#define exp 1e-10
#define ll __int64
using namespace std;
const int N = 100005;
const int inf = 1000000000;
const int mod = 1000000007;
int solve()
{
    __int64 n,m;
    int i,j,k,c,s,d,r,w[32];
    set<int> v;
    set<int>::iterator it;
    scanf("%I64d%I64d",&n,&m);
    if(((n+1)*n/2)%m||m*2-1>n)
        return puts("NO");
    c=(n-m*2+1)%(m*2)+m*2-1,//蛋糕的分配方式可以分成两部分，前一部分至少有2*m-1个，
    s=c*(c+1)/(m*2),        //而后面必须要有k个2*m，那多出来的部分就归到前一部分去
    d=(n-c)/(m*2);          //即(n-m*2+1)%(m*2)+m*2-1
    puts("YES");
    for(i=1; i<=c; i++)
        v.insert(i);
    for(j=0,k=c+1;j<m;j++,putchar('\n'))
    {
        for(c=r=0;r<s;)//s为每份蛋糕前一部分的和
        {
            it=v.upper_bound(s-r);//通过二分找使总和最接近s的蛋糕大小
            r+=w[c++]=*--it;
            v.erase(it);
        }
        printf("%d",c+d*2);//c+d*2表示每组蛋糕的个数，d即是题解中提到的k个2*m的k
        for(i=0;i<c;i++)
            printf(" %d",w[i]);
        for(i=0;i<d;i++)
            printf(" %d %d",k++,n--);//其实代码解释起来比较麻烦，还得根据上述举的例子来加深理解
    }
}
int main()
{
    int t;
    for(scanf("%d",&t);t--;solve());
}


