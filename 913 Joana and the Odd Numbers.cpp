#include<stdio.h>

int main ()

{
    long long n ;
    while(scanf("%lld",&n)!=EOF)
    {
        long long i , sum=0 , a ;
        for(i=1 ; i<=n ; i=i+2)
            sum=sum+i ;
        a=2*sum-1 ;
        a=a+(a-2)+(a-4) ;
        printf("%lld\n",a) ;
    }
    return 0 ;
}
