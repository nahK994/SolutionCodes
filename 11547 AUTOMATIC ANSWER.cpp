#include<stdio.h>

int main ()

{
    long long i , j , n ;
    scanf("%lld",&j) ;
    for(i=1 ; i<=j ; i++)
    {
        scanf("%lld",&n) ;
        n=n*567 ;
        n=n/9 ;
        n=n+7492 ;
        n=n*235 ;
        n=n/47 ;
        n=n-498 ;
        n=n/10 ;
        if(n>=0) printf("%lld\n",n%10) ;
        else printf("%lld\n",-1*n%10) ;
    }
    return 0 ;
}
