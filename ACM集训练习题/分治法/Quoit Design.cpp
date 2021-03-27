#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 100007

using namespace std;

struct Point
{
    double x,y;
}pt[N];
int a[N];

int n;

bool cmp(Point a, Point b)
{
    if (a.x != b.x) return a.x < b.x;
    else return a.y < b.y;
}
bool cmp_y(int id1, int id2){
    return pt[id1].y < pt[id2].y;
}
double getDis(const Point &a, const Point &b)
{
   double x = a.x - b.x;
   double y = a.y - b.y;
   return sqrt(x*x + y*y);
}
double solve(int l, int r)
{
    double ans = 0;
    if (r - l + 1 <= 3)
    {
        if (r - l + 1 == 1) return ans;
        ans = getDis(pt[l], pt[l + 1]);
        if (r - l + 1 == 2) return ans;
        for (int i = l; i < r; ++i)
        {
            for (int j = i + 1; j <= r; ++j)
            {
                ans = min(ans, getDis(pt[i],pt[j]));
            }
        }
        return ans;
    }
    int m = (l + r) >> 1;
    double s1 = solve(l, m);
    double s2 = solve(m + 1,  r);
    ans = min(s1,s2);
    int k = 0;
    for (int i = m - 1; i >= l && pt[m].x - pt[i].x <= ans; --i) a[k++] = i;
    for (int i = m + 1; i <= r && pt[i].x - pt[m].x <= ans; ++i) a[k++] = i;
    sort(a, a + k, cmp_y);
    for (int i = 0; i < k; ++i)
    {
        for (int j = i + 1; j < k && j<=i+7 ; ++j)
        {
            ans = min(ans, getDis(pt[a[i]], pt[a[j]]));
        }
    }
    return ans;
}
int main()
{
    while (~scanf("%d",&n))
    {
        if (!n) break;
        for (int i = 0; i < n; ++i) scanf("%lf%lf",&pt[i].x, &pt[i].y);
        sort(pt, pt + n, cmp);
        printf("%.2lf\n",solve(0, n - 1)/2.0);
    }
    return 0;
}

