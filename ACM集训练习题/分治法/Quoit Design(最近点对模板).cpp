#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<math.h>
using namespace std;


//*************************************
//ģ��
//**************************************
const int N = 100005;
const double MAX = 10e100;
const double eps=0.00001;
struct Point
{
    double x,y;
    int index;
};
Point a[N],b[N],c[N];

double closest(Point *,Point *,Point *,int,int);
double dis(Point,Point);
int merge(Point *,Point *,int ,int ,int);
int cmp_x(const void *,const void *);
int cmp_y(const void *,const void *);
//inline double min(double ,double);

int main()
{
    int n,i;
    double d;
    while(scanf("%d",&n)!=EOF,n)
    {
        for(i = 0;i < n;i++)
          scanf("%lf %lf",&a[i].x,&a[i].y);
        qsort(a,n,sizeof(a[0]),cmp_x);//���ţ����� x ���� 
        for(i = 0;i < n;i++)
            a[i].index = i;
        memcpy(b,a,n*sizeof(a[0]));
        qsort(b,n,sizeof(b[0]),cmp_y);
        d = closest(a,b,c,0,n-1);
        printf("%.2lf\n",d/2);
    }    
    return 0;
}    


double closest(Point a[],Point b[],Point c[],int p,int q)
{//a�ǰ��� x �����С��������ģ�b �ǰ��� y �����С���������
//�� a �� p �㵽 q �����С��Ծ��� 
	if( q-p==0 ) return 0; 
    if(q - p == 1) return dis(a[p],a[q]);//������ 
    if(q - p == 2) //���������� 
    {
        double x1 = dis(a[p],a[q]);
        double x2 = dis(a[p+1],a[q]);
        double x3 = dis(a[p],a[p+1]);
        return max(x1,max(x2,x3)); 
    //    if(x1 < x2 && x1 < x3) return x1;
    //    else if(x2 < x3) return x2;
    //    else return x3;
    } 
    int i,j,k,m = (p+q) / 2;//���պ�����ֳ������� 
    double d1,d2;
    
    //�� ��ֳ������֣���ߵĴ��� c[p~m],�ұߵĴ��� c[m+1~q],�����־����� y ���� 
    for(i = p,j = p,k = m + 1;i <= q;i++)
          if(b[i].index <= m) c[j++] = b[i];
          else c[k++] = b[i];
    d1 = closest(a,c,b,p,m);//��벿�ֵ���С��Ծ��� 
    d2 = closest(a,c,b,m+1,q);//�Ұ벿�ֵ���С��Ծ��� 
    double dm = min(d1,d2);//ȡ���ߵĽ�Сֵ 
    //���� c ���Ҳ��ֱַ��Ƕԡ�����������ģ��ϲ��ء��� 
    merge(b,c,p,m,q);
    for(i = p,k = p ; i <= q;i++)
         if(fabs(b[i].x - b[m].x) < dm) c[k++] = b[i];
         //�ҳ��뻮�ֻ�׼���Ҳ�����dm�Ĳ��֣�����Ȼ�� y ���� 
    for(i = p;i < k;i++)
       for(j = i+1;j < k && c[j].y -c[i].y < dm;j++)
       {
           double temp = dis(c[i],c[j]);
           if(temp < dm) dm = temp;
       }       
    return dm;
}    

double dis(Point p,Point q)//������ľ��� 
{
    double x1 = p.x - q.x, y1 = p.y - q.y;
    return sqrt(x1 * x1 +  y1 * y1);
}
int cmp_x(const void *p,const void *q)//�ѵ㰴�� x �������� 
{
    double temp = ((Point *)p)->x - ((Point *)q)->x;
    if(temp > 0) return 1;
    else if(fabs(temp) < eps) return 0;
    else return -1;
}    
int cmp_y(const void *p,const void *q)//�ѵ㰴�� y �������� 
{
    double temp = ((Point *)p)->y - ((Point *)q)->y;
    if(temp > 0) return 1;
    else if(fabs(temp) < eps) return 0;
    else return -1;
}    

int merge(Point p[],Point q[],int s,int m,int t)
{//�� q[s~m],q[m+1~t]�ϲ��� p , ���Ұ��� y ����q[s~m],q[m+1~t]�Ѿ��ǰ��� y ������� 
    int i,j,k;
    for(i = s, j = m+1, k = s;i <= m && j <= t;)
    {
        if(q[i].y > q[j].y) p[k++] = q[j],j++;
        else p[k++] = q[i],i++;
    } 
    while( i <= m) p[k++] = q[i++];
    while( j <= t) p[k++] = q[j++];
    memcpy(q+s,p+s,(t-s+1)*sizeof(p[0]));//�� p ���� �� q 
    return 0;   
} 
/*
inline double min(double p,double q)
{
    return (p>q)?(q):(p);
}  */

