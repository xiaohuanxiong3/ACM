#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
struct point{
	int x,y;
	point(int x1=0,int y1=0):x(x1),y(y1){
		
	} 
};
double len(point p1,point p2){
	return ( (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y) );
}
// ���������ĵ�� 
int mul_sc(point p1,point p2){
	return p1.x*p2.x+p1.y*p2.y;
}
// �����������нǵ�����
double angle_cos(point p1,point p2){
	return mul_sc(p1,p2)/len(p1,point(0,0))*len(p2,point(0,0));
}
// �������������ļн� 
double angle(point p1,point p2){
	return acos(angle_cos(p1,p2));
} 
// �ж�p0 p1,��p0 p2�ķ���(�ò��,�˻�>0:��ʱ��,=0:ͬ��,<0:˳ʱ��) 
int dir(point p0,point p1,point p2){
	int ret = mul_across()
}
int main(){
	point p1(2,3),p2;
	p2 = point(5,7);
	return 0;
}

