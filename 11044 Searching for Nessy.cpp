#include<stdio.h>

int main ()

{
    long i , j ;
    scanf("%ld",&j) ;
    for(i=1 ; i<=j ; i++)
    {
        long p=9 , m , n , count=0 , a ;
        scanf("%ld%ld",&m,&n) ;
        a=m*n ;
        for( ; a/p>=1 ; p=p*9)
        count++ ;
        printf("%ld\n",count) ;
    }
    return 0 ;
}
