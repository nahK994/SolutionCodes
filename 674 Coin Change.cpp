#include <stdio.h>

long ways [7500]={0} ;

void coin_change()
{

	long i , j , coins[]={1,5,10,25,50} ;
    ways[0]=1 ;
    for (i=0 ; i<5 ; i++ )
	{
		for(j=coins[i] ; j<7500 ; j++)
        ways[j]=ways[j]+ways[j-coins[i]] ;
	}
}

int main()
{
	coin_change() ;
	long n ;
	while(scanf("%ld",&n)!=EOF)
    printf("%ld\n",ways[n]) ;
    return 0 ;
}
