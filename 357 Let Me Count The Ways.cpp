#include<stdio.h>

long ways[30050] ;

void coin_change()
{
    long i , j , coins[]={1,5,10,25,50} ;
    ways[30050]={0} ;
    ways[0]=1 ;
    for(i=0 ; i<5 ; i++)
    for(j=coins[i] ; j<=30000 ; j++)
    ways[j]=ways[j]+ways[j-coins[i]] ;
}

int main()
{
    coin_change() ;
    long n , a , b ;
    while(scanf("%ld",&n)!=EOF)
    {
        if(ways[n]==1) printf("There is only %ld way to produce %ld cents change.\n",ways[n],n) ;
        else printf("There are %ld ways to produce %ld cents change.\n",ways[n],n) ;
    }
    return 0 ;
}
