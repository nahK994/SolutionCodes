#include<stdio.h>

int main()
{
    long ara[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97} ;
    long n ;
    while(scanf("%ld",&n)!=EOF)
    {
        if(n==0) break ;
        long a , b=n , c , d=1 ;
        if(n<10) printf("  %ld! =",n) ;
        else if(n<100) printf(" %ld! =",n) ;
        else printf("%ld! =",n) ;
        for(a=0 ; a<25 ; a++)
        {
            c=0 ;
            b=n ;
            while(b!=0)
            {
                b=b/ara[a] ;
                c=c+b ;
            }
            if(c<10) printf("  %ld",c) ;
            else printf(" %ld",c) ;
            d++ ;
            if(d==16 && n>=ara[a+1]) printf("\n      ") ;
            if(n<ara[a+1])
                break ;
        }
        printf("\n") ;
    }
}
