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
    c=(n-m*2+1)%(m*2)+m*2-1,//����ķ��䷽ʽ���Էֳ������֣�ǰһ����������2*m-1����
    s=c*(c+1)/(m*2),        //���������Ҫ��k��2*m���Ƕ�����Ĳ��־͹鵽ǰһ����ȥ
    d=(n-c)/(m*2);          //��(n-m*2+1)%(m*2)+m*2-1
    puts("YES");
    for(i=1; i<=c; i++)
        v.insert(i);
    for(j=0,k=c+1;j<m;j++,putchar('\n'))
    {
        for(c=r=0;r<s;)//sΪÿ�ݵ���ǰһ���ֵĺ�
        {
            it=v.upper_bound(s-r);//ͨ��������ʹ�ܺ���ӽ�s�ĵ����С
            r+=w[c++]=*--it;
            v.erase(it);
        }
        printf("%d",c+d*2);//c+d*2��ʾÿ�鵰��ĸ�����d����������ᵽ��k��2*m��k
        for(i=0;i<c;i++)
            printf(" %d",w[i]);
        for(i=0;i<d;i++)
            printf(" %d %d",k++,n--);//��ʵ������������Ƚ��鷳�����ø��������ٵ��������������
    }
}
int main()
{
    int t;
    for(scanf("%d",&t);t--;solve());
}


