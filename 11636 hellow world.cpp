#include<stdio.h>

int main ()

{
    long n , i=1 ;
    while(scanf("%ld",&n)!=EOF)
    {
        if(n<0) break ;
        long count=0 , p=1 ;
        while(p<n)
        {
           p=2*p ;
           count++ ;
        }
        printf("Case %ld: %ld\n",i,count) ;
        i++ ;
    }
    return 0 ;
}
