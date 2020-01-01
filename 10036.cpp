#include<stdio.h>

int main ()

{
    long i , j , n , k , sum , ara[10000] , a ;
    scanf("%ld",&j) ;
    for(i=1 ; i<=j ; i++)
    {
        scanf("%ld%ld",&n,&k) ;
        sum=0 ;
        for(a=0 ; a<n ; a++)
        {
            scanf("%ld",&ara[a]) ;
            sum=sum+ara[a] ;
        }
        if(sum%k==0) printf("Divisible\n") ;
        else printf("Not divisible\n") ;
    }
    return 0 ;
}
