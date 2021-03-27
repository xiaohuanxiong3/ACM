#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
#define MAXDIGITS 35700
#define PLUS 1
#define MINUS -1
#define LL long long 
int pos[6];
class bignum {
  	char digits[MAXDIGITS];
  	int signbit;
  	int lastdigit;
public:
	bignum();
	bignum(long long k);
	bignum(char *s);
	void digit_left_move(int d);
	void zero_justify(){
		int i;
		for(i= lastdigit; i>=0; i--){
			if(digits[i] == '0')
				lastdigit --;
			else
				break;
		}
	}
	bignum operator +(bignum &a);
	bignum operator -(bignum &a);
	bignum operator *(bignum &a);
	bignum operator *(int);  //本身乘以一个整数 
	int getlastdigit()
	{
		return lastdigit;
	}
	friend int compare(const bignum &, const bignum &);
	friend ostream & operator<<(ostream &cout, bignum &bn);
};
bignum bignum:: operator *(int a)
{
	int cnt=0;
	while( a )
	{
		pos[cnt++]=a%10;
		a/=10;
	}
	bignum c;
	c.signbit=PLUS;
	c.lastdigit=lastdigit+cnt+1;
	int i,j,carry,t;
	for( i=0;i<cnt;i++ )
	{
		bignum tmp;
		carry=0;
		for( j=0;j<=lastdigit;j++ )
		{
			t= pos[i]*( digits[j] - '0' )+carry;
			tmp.digits[j]=t%10 + '0';
			carry=t/10;
		}
		if( carry>0 )
		{	
			tmp.digits[j]=carry+'0';
			tmp.lastdigit=j;
		}
		else
			tmp.lastdigit=j-1;
	//	cout<<tmp<<endl;
		tmp.digit_left_move(i);
		c=c+tmp;
	}
	c.zero_justify();
	return c;
}
bignum bignum::operator *(bignum &a){
	bignum c;
	c.signbit = signbit * a.signbit;
	c.lastdigit = lastdigit + a.lastdigit + 1;
	int i, j;
	for(i=0; i<=a.lastdigit; i++){
		bignum tmp;
		for(j=0; j<a.digits[i]-'0'; j++){
			tmp = tmp + *this;
		}
		tmp.digit_left_move(i);
		c = c + tmp;
	}
	c.zero_justify(); 
	return c;
}

void bignum::digit_left_move(int d){
	int i;
	for(i=lastdigit; i>=0; i--)
		digits[i+d] = digits[i];
	for(i=0; i<d; i++)
		digits[i] = '0';
	lastdigit+=d;
}
bignum bignum::operator -(bignum &a){
	bignum c;
	if(signbit == MINUS || a.signbit == MINUS){
		a.signbit = -1 * a.signbit;
		c = *this + a;
		a.signbit = -1 * a.signbit;
		return c;
	} else {
		if(compare(*this, a) == PLUS){
			c = a - *this;
			c.signbit = MINUS;
			return c;
		}
		c.lastdigit = max(lastdigit, a.lastdigit);
		c.signbit = PLUS;
		int borrow = 0, v;
		for(int i=0; i<=c.lastdigit; i++){
			v = digits[i] - a.digits[i] - borrow;
			if(v<0){
				v += 10;
				borrow = 1;				
			} else {
				borrow = 0;
			}
			c.digits[i] = v + '0';
		}
	}
	c.zero_justify();
	return c;
}

bignum bignum::operator +( bignum &a){
	bignum c;
	int i, carry, t;
	if(signbit == a.signbit){
		c.signbit = signbit;
		c.lastdigit = max(lastdigit, a.lastdigit) + 1;
		carry = 0;
		for(i=0; i<=c.lastdigit; i++){ 
			t = ( digits[i]-'0' ) + ( a.digits[i] - '0' ) + carry;
			c.digits[i] = t % 10 + '0';
		//	cout<<c.digits[i]<<endl;
			carry = t / 10;
		}
		c.zero_justify();
	} else {
		if(signbit == MINUS){
			signbit = PLUS;
			c = a - *this;
			signbit = MINUS;
		} else {
			a.signbit = PLUS;
			c = *this - a  ;
			a.signbit = MINUS;
		}
	}
	return c;
}

int compare(const bignum &a, const bignum &b){
	if ((a.signbit==MINUS) && (b.signbit==PLUS)) 
		return PLUS;
	if ((a.signbit==PLUS) && (b.signbit==MINUS)) 
		return MINUS;
	
	if (b.lastdigit > a.lastdigit) 
		return PLUS * a.signbit;
	if (a.lastdigit > b.lastdigit) 
		return MINUS * a.signbit;	
	for (int i = a.lastdigit; i >= 0; i--) {
		if (a.digits[i] > b.digits[i])
			return MINUS * a.signbit;
		if (b.digits[i] > a.digits[i])
			return PLUS * a.signbit;
	}
	return 0;
}
bignum::bignum(){
	lastdigit = 0;	
	signbit = 1;
	int i;
	for( i=0; i<MAXDIGITS; i++)
	{
		digits[i] ='0';
	}
}
bignum::bignum(long long k){
	int i;
	for( i=0;i<MAXDIGITS;i++ )
		digits[i]='0';
	lastdigit =0 ;
	signbit=1;
	if(k<0)
		signbit = -1, k = -k;
	else
		signbit = 1;
	lastdigit = -1;
	while(k){
		digits[++lastdigit] = k % 10 + '0' ;
		k /= 10;		
	}
}
bignum::bignum(char *s){
	bignum();
	int i;
	if(s[0]=='-'){
		signbit = -1;
		lastdigit = strlen(s) - 2;
		i = 1;
	}		
	else {
		signbit = 1;
		lastdigit = strlen(s) - 1;
		i=0;
	}	
	for(; i<lastdigit+1; i++)
		digits[i] = s[lastdigit - i];
}
ostream & operator<<(ostream &out, bignum &bn){
	int i;
	if(bn.signbit == MINUS)
		out<<'-';
	for(i=bn.lastdigit; i>=0; i--)
		out<<bn.digits[i];	
		return out;
}
int main(){
	ios::sync_with_stdio(false);
	int i,n;
	bignum ans=1;
	while( cin>>n )
	{
		ans=1;
		if( n==1 || n==0)
			cout<<"1\n";
		else
		{
			for( i=2;i<=n;i++ )
			{
				ans=ans*i;
			}
			cout<<ans<<endl<<ans.getlastdigit()+1<<endl;
		}
	}
	return 0;
}

