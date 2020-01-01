#include<stdio.h>

int main ()

{
    long n ;
    while(scanf("%ld",&n)!=EOF)
    {
        if(n<0) break ;
        if(n==0)
        {
            printf("0\n") ;
            continue ;
        }
        long c=0 , ara[100]={0} ;
        while(n!=0)
        {
          ara[c]=n%3 ;
          n=n/3 ;
          c++ ;
        }
        c=c-1 ;
        for( ; c>=0 ; c--)
        printf("%ld",ara[c]) ;
        printf("\n") ;
    }
    return 0 ;
}
