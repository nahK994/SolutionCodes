#include<stdio.h>

int main ()

{
    long n , a ;
    while(scanf("%ld%ld",&n,&a)!=EOF)
    {
        if(n==0)
        {
            printf("0\n") ;
            continue ;
        }
        long count=0 , c , b=n ;
        while(n>=a)
        {
            c=n/a ;
            count=count+c ;
            n=c+n%a ;
        }
        printf("%ld\n",count+b) ;
    }
    return 0 ;
}


