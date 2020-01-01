#include<stdio.h>

int main ()

{
    long long n ;
    while(scanf("%lld",&n)!=EOF)
    {
        n=n*n*(n+1)*(n+1) ;
        n=n/4 ;
        printf("%lld\n",n) ;
    }
    return 0 ;
}
