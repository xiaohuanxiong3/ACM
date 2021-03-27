#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
struct node{
	int father;
	int rank;
	node():rank(1){
	}
}uf[2502];
int Find(int x){
	int k=x;
	while( k!=uf[k].father ){
		k=uf[k].father;
	}
	while( x!=uf[x].father ){
		int t=uf[x].father;
		uf[x].father=k;
		x=t;
	}
	return k;
}
void Union(int x,int y){
	x = Find(x);
	y = Find(y);
	if( x!=y ){
		if( uf[x].rank<uf[y].rank ){
			uf[x].father=y;
		}
		else{
			uf[y].father=x;
			if( uf[x].rank==uf[y].rank ){
				uf[x].rank++;
			}
		}
	}  
} 
int main() {
	int m,n,i,j;
	char s[52][52];
	char x;
	while( cin>>m>>n ){
		if( n<0 || m<0 )
			break;
		for( i=1;i<=m*n;i++ )
			uf[i].father=i;
		for( i=1;i<=m;i++ ){
			for( j=1;j<=n;j++ ){
				cin>>s[i][j];
			//	cout<<i<<" "<<j<<" "<<s[i][j]<<endl;
			}
		}
		for( i=1;i<=m;i++ ){  //m行n列 
			for( j=1;j<=n;j++ ){
				int index=j + (i-1)*n;
				switch(s[i][j]){
					case 'A':
						if( i-1>=1 && ( s[i-1][j]=='C' || s[i-1][j]=='D' || s[i-1][j]=='E' || s[i-1][j]=='H' || s[i-1][j]=='I' || s[i-1][j]=='J' || s[i-1][j]=='K') )
							Union(index,index-n);
						if( j-1>=1 && ( s[i][j-1]=='B' || s[i][j-1]=='D' || s[i][j-1]=='F' || s[i][j-1]=='G' || s[i][j-1]=='I' || s[i][j-1]=='J' || s[i][j-1]=='K') )
							Union(index,index-1);
						break;
					case 'B':
						if( i-1>=1 && ( s[i-1][j]=='C' || s[i-1][j]=='D' || s[i-1][j]=='E' || s[i-1][j]=='H' || s[i-1][j]=='I' || s[i-1][j]=='J' || s[i-1][j]=='K') )
							Union(index,index-n);
						if( j+1<=n && ( s[i][j+1]=='A' || s[i][j+1]=='C' || s[i][j+1]=='F' || s[i][j+1]=='G' || s[i][j+1]=='H' || s[i][j+1]=='I' || s[i][j+1]=='K') )
							Union(index,index+1);
						break;
					case 'C':
						if( j-1>=1 && ( s[i][j-1]=='B' || s[i][j-1]=='D' || s[i][j-1]=='F' || s[i][j-1]=='G' || s[i][j-1]=='I' || s[i][j-1]=='J' || s[i][j-1]=='K') )
							Union(index,index-1);
						if( i+1<=m && ( s[i+1][j]=='A' || s[i+1][j]=='B' || s[i+1][j]=='E' || s[i+1][j]=='G' || s[i+1][j]=='H' || s[i+1][j]=='J' || s[i+1][j]=='K') )
							Union(index,index+n);
						break;
					case 'D':
						if( j+1<=n && ( s[i][j+1]=='A' || s[i][j+1]=='C' || s[i][j+1]=='F' || s[i][j+1]=='G' || s[i][j+1]=='H' || s[i][j+1]=='I' || s[i][j+1]=='K') )
							Union(index,index+1);
						if( i+1<=m && ( s[i+1][j]=='A' || s[i+1][j]=='B' || s[i+1][j]=='E' || s[i+1][j]=='G' || s[i+1][j]=='H' || s[i+1][j]=='J' || s[i+1][j]=='K') )
							Union(index,index+n); 
						break;
					case 'E':
						if( i-1>=1 && ( s[i-1][j]=='C' || s[i-1][j]=='D' || s[i-1][j]=='E' || s[i-1][j]=='H' || s[i-1][j]=='I' || s[i-1][j]=='J' || s[i-1][j]=='K') )
							Union(index,index-n);
						if( i+1<=m && ( s[i+1][j]=='A' || s[i+1][j]=='B' || s[i+1][j]=='E' || s[i+1][j]=='G' || s[i+1][j]=='H' || s[i+1][j]=='J' || s[i+1][j]=='K') )
							Union(index,index+n);	
						break;
					case 'F':
						if( j-1>=1 && ( s[i][j-1]=='B' || s[i][j-1]=='D' || s[i][j-1]=='F' || s[i][j-1]=='G' || s[i][j-1]=='I' || s[i][j-1]=='J' || s[i][j-1]=='K') )
						{
						//	cout<<"我靠1!\n"; 
							Union(index,index-1);
						}
						if( j+1<=n && ( s[i][j+1]=='A' || s[i][j+1]=='C' || s[i][j+1]=='F' || s[i][j+1]=='G' || s[i][j+1]=='H' || s[i][j+1]=='I' || s[i][j+1]=='K') )
						{
						//	cout<<"我靠2\n"; 
							Union(index,index+1);
						}
						break;
					case 'G':
						if( i-1>=1 && ( s[i-1][j]=='C' || s[i-1][j]=='D' || s[i-1][j]=='E' || s[i-1][j]=='H' || s[i-1][j]=='I' || s[i-1][j]=='J' || s[i-1][j]=='K') )
							Union(index,index-n);
						if( j-1>=1 && ( s[i][j-1]=='B' || s[i][j-1]=='D' || s[i][j-1]=='F' || s[i][j-1]=='G' || s[i][j-1]=='I' || s[i][j-1]=='J' || s[i][j-1]=='K') )
							Union(index,index-1);
						if( j+1<=n && ( s[i][j+1]=='A' || s[i][j+1]=='C' || s[i][j+1]=='F' || s[i][j+1]=='G' || s[i][j+1]=='H' || s[i][j+1]=='I' || s[i][j+1]=='K') )
							Union(index,index+1);
						break;
					case 'H':
						if( j-1>=1 && ( s[i][j-1]=='B' || s[i][j-1]=='D' || s[i][j-1]=='F' || s[i][j-1]=='G' || s[i][j-1]=='I' || s[i][j-1]=='J' || s[i][j-1]=='K') )
							Union(index,index-1);
						if( i-1>=1 && ( s[i-1][j]=='C' || s[i-1][j]=='D' || s[i-1][j]=='E' || s[i-1][j]=='H' || s[i-1][j]=='I' || s[i-1][j]=='J' || s[i-1][j]=='K') )
							Union(index,index-n);
						if( i+1<=m && ( s[i+1][j]=='A' || s[i+1][j]=='B' || s[i+1][j]=='E' || s[i+1][j]=='G' || s[i+1][j]=='H' || s[i+1][j]=='J' || s[i+1][j]=='K') )
							Union(index,index+n);
						break;
					case 'I':
						if( j-1>=1 && ( s[i][j-1]=='B' || s[i][j-1]=='D' || s[i][j-1]=='F' || s[i][j-1]=='G' || s[i][j-1]=='I' || s[i][j-1]=='J' || s[i][j-1]=='K') )
							Union(index,index-1);
						if( j+1<=n && ( s[i][j+1]=='A' || s[i][j+1]=='C' || s[i][j+1]=='F' || s[i][j+1]=='G' || s[i][j+1]=='H' || s[i][j+1]=='I' || s[i][j+1]=='K') )
							Union(index,index+1);
						if( i+1<=m && ( s[i+1][j]=='A' || s[i+1][j]=='B' || s[i+1][j]=='E' || s[i+1][j]=='G' || s[i+1][j]=='H' || s[i+1][j]=='J' || s[i+1][j]=='K') )
							Union(index,index+n);
						break;
					case 'J':
						if( i-1>=1 && ( s[i-1][j]=='C' || s[i-1][j]=='D' || s[i-1][j]=='E' || s[i-1][j]=='H' || s[i-1][j]=='I' || s[i-1][j]=='J' || s[i-1][j]=='K') )
							Union(index,index-n);
						if( i+1<=m && ( s[i+1][j]=='A' || s[i+1][j]=='B' || s[i+1][j]=='E' || s[i+1][j]=='G' || s[i+1][j]=='H' || s[i+1][j]=='J' || s[i+1][j]=='K') )
							Union(index,index+n);
						if( j+1<=n && ( s[i][j+1]=='A' || s[i][j+1]=='C' || s[i][j+1]=='F' || s[i][j+1]=='G' || s[i][j+1]=='H' || s[i][j+1]=='I' || s[i][j+1]=='K') )
							Union(index,index+1);
						break;
					case 'K':
						if( i-1>=1 && ( s[i-1][j]=='C' || s[i-1][j]=='D' || s[i-1][j]=='E' || s[i-1][j]=='H' || s[i-1][j]=='I' || s[i-1][j]=='J' || s[i-1][j]=='K') )
							Union(index,index-n);
						if( i+1<=m && ( s[i+1][j]=='A' || s[i+1][j]=='B' || s[i+1][j]=='E' || s[i+1][j]=='G' || s[i+1][j]=='H' || s[i+1][j]=='J' || s[i+1][j]=='K') )
							Union(index,index+n);
						if( j-1>=1 && ( s[i][j-1]=='B' || s[i][j-1]=='D' || s[i][j-1]=='F' || s[i][j-1]=='G' || s[i][j-1]=='I' || s[i][j-1]=='J' || s[i][j-1]=='K') )
							Union(index,index-1);
						if( j+1<=n && ( s[i][j+1]=='A' || s[i][j+1]=='C' || s[i][j+1]=='F' || s[i][j+1]=='G' || s[i][j+1]=='H' || s[i][j+1]=='I' || s[i][j+1]=='K') )
							Union(index,index+1);
						break;
					}
				}
			}
			int ret=0;
			for( i=1;i<=m*n;i++ )
				if( uf[i].father==i )
					ret++;
			cout<<ret<<endl;
		}
	
	return 0;
	}

