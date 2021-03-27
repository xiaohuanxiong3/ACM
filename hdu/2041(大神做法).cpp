
#include<iostream>

using namespace std ;

int DP[44];

void fun()

{

    int i ;

    DP[1] = 0;

    DP[2] = 1;

    DP[3] = 2;

    for( i = 4; i <= 40 ; i ++)

        DP[i] = DP[i-1] + DP[i-2] ;

    return ;

}

 

int main(void)

{

    int t  ;

    fun();

 
	int n;
    while(cin>>n)

    {

        cout<<DP[n]<<endl<<endl;

    }

    return 0;

}
