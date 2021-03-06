#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
void print_permutation(int n,int *A,int cur){
	if( cur==n ){
		for(int i=0;i<n;i++ ) printf("%d ",A[i]);
		printf("\n");
	}
	else{
		for(int i=1;i<=n;i++ )  //尝试在A[cur]中填各种整数i
		{
			int ok=1;
			for(int j=0;j<cur;j++ )
				if( A[j]==i ) ok=0;  //如果i已经在A[0]~A[cur-1]中出现过,则不能再选
			if( ok ){
				A[cur]=i;
				print_permutation(n,A,cur+1);
			} 
		} 
	}
}
int main() {
	int n;
	cin>>n;
	int *A=new int[n];
	print_permutation(n,A,0);
	return 0;
	}

