#include<stdio.h>

int main ()

{
    long n ;
    while(scanf("%ld",&n)!=EOF)
    {
        if(n<0) break ;
        n=(n*(n+1)/2)+1 ;
        printf("%ld\n",n) ;
    }
    return 0 ;
}
